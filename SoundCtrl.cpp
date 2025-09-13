#include <Windows.h>

// 媒体键虚拟码定义
#define NEXT 0xB0  // 下一首
#define STOP 0xB2  // 停止
#define PREV 0xB1  // 上一首
#define PAUSE 0xB3 // 播放/暂停
#define UP 0xAF    // 增加音量
#define DOWN 0xAE  // 减少音量
#define MUTE 0xAD  // 静音

// 全局变量
bool is_back = false;
bool is_rightCtrl = false;

// 模拟按键按下和释放
void Press(byte keyCode)
{
    // 按下按键
    keybd_event(keyCode, 0, 0, 0);
    // 短暂延迟，确保系统能识别按键动作
    Sleep(10);
    // 释放按键
    keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    { // nCode >= 0 表示消息可处理
        KBDLLHOOKSTRUCT *pKeyData = (KBDLLHOOKSTRUCT *)lParam;
        bool isKeyDown = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);
        bool isKeyUp = (wParam == WM_KEYUP || wParam == WM_SYSKEYUP);

        // 1. 更新右Ctrl键的按下/弹起状态
        if (pKeyData->vkCode == VK_RCONTROL)
        {
            is_rightCtrl = isKeyDown;
        }

        // 2. 右Ctrl + Q：退出程序
        if (is_rightCtrl && isKeyDown && pKeyData->vkCode == 0x51)
        {                       // 0x51 是 'Q' 的虚拟键码
            PostQuitMessage(0); // 发送退出消息，终止消息循环
        }

        // 3. 右Ctrl + F1~F5：输出对应内容（仅“键按下”时触发一次）
        if (is_rightCtrl && isKeyDown)
        {
            switch (pKeyData->vkCode)
            {
            case VK_F1:
                Press(PAUSE);
                break;
            case VK_F2:
                Press(PREV);
                break;
            case VK_F3:
                Press(NEXT);
                break;
            case VK_F4:
                Press(UP);
                break;
            case VK_F5:
                Press(DOWN);
                break;
            case VK_F6:
                Press(MUTE);
                break;
            case VK_F7:
                Press(STOP);
                break;
            default:
                break; // 其他键不处理
            }
        }
    }

    // 必须传递钩子消息，确保系统其他程序正常接收键盘事件
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void Back()
{
    // 1. 安装低级键盘钩子（全局监听所有键盘事件，无需DLL）
    HHOOK hKeyHook = SetWindowsHookEx(
        WH_KEYBOARD_LL,          // 钩子类型：低级键盘钩子
        LowLevelKeyboardProc,    // 自定义钩子处理函数
        GetModuleHandle(NULL),   // 当前程序句柄
        0                        // 0 = 监听系统所有线程（全局生效）
    );

    // 2. 消息循环（阻塞主线程，保持程序运行，同时接收钩子消息）
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg); // 转换虚拟键消息为字符消息
        DispatchMessage(&msg);  // 分发消息到窗口过程（此处无窗口，仅维持循环）
    }

    // 3. 程序退出：卸载钩子（避免内存泄漏，恢复系统键盘正常状态）
    UnhookWindowsHookEx(hKeyHook);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 处理命令行参数（不创建控制台窗口）
    LPWSTR *argv;
    int argc;
    argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    // 根据参数执行相应操作
    if (argc < 2)
    {
        is_back = true;
        Back();
    }
    else if (_wcsicmp(argv[1], L"play") == 0)
    {
        Press(PAUSE);
    }
    else if (_wcsicmp(argv[1], L"prev") == 0)
    {
        Press(PREV);
    }
    else if (_wcsicmp(argv[1], L"next") == 0)
    {
        Press(NEXT);
    }
    else if (_wcsicmp(argv[1], L"stop") == 0)
    {
        Press(STOP);
    }
    else if (_wcsicmp(argv[1], L"up") == 0)
    {
        Press(UP);
    }
    else if (_wcsicmp(argv[1], L"down") == 0)
    {
        Press(DOWN);
    }
    else if (_wcsicmp(argv[1], L"mute") == 0)
    {
        Press(MUTE);
    }
    else if (_wcsicmp(argv[1], L"back") == 0)
    {
        is_back = true;
        Back();
    }

    LocalFree(argv);
    return 0;
}
