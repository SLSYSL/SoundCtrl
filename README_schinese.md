# SoundCtrl / 音频控制
一个轻量级的 Windows 媒体控制工具，允许您通过命令行或全局热键快速控制媒体播放。

README 语言: [English](https://github.com/SLSYSL/SoundCtrl/blob/main/README.md) / 简体中文(当前语言) / [繁體中文](https://github.com/SLSYSL/SoundCtrl/blob/main/README_tchinese.md)

## 功能特点
- 🎵 媒体播放控制（播放/暂停、上一首、下一首、停止）
- 🔊 音量控制（增加、减少、静音切换）
- ⌨️ 全局热键支持（后台模式）
- 🚀 轻量级，无依赖，原生 Windows API 实现

## 系统要求
- Windows 7 或更高版本

## 使用方法
### 后台模式（默认模式）
#### 方法一:
- 直接运行程序

#### 方法二:
- 命令提示符(CMD)或PowerShell中运行: `.\SoundCtrl.exe back`

### 命令行模式
在命令提示符(CMD)或PowerShell中运行:
```bash
.\SoundCtrl.exe <命令>
```
命令示例:
- `.\SoundCtrl.exe play` - 播放/暂停
- `.\SoundCtrl.exe next` - 下一首
- `.\SoundCtrl.exe back` - 后台模式

### 命令
- `play` - 播放/暂停
- `next` - 下一首
- `prev` - 上一首
- `up` - 增加音量 (每次增加两格音量)
- `down` - 减少音量 (每次减少两格音量)
- `mute` - 静音/取消静音
- `stop` - 停止播放

## 后台模式热键
- <kbd>右Ctrl + Q</kbd> - 退出程序
- <kbd>右Ctrl + F1</kbd> - 播放/暂停
- <kbd>右Ctrl + F2</kbd> - 上一首
- <kbd>右Ctrl + F3</kbd> - 下一首
- <kbd>右Ctrl + F4</kbd> - 增加音量 (每次增加两格音量)
- <kbd>右Ctrl + F5</kbd> - 减少音量 (每次减少两格音量)
- <kbd>右Ctrl + F6</kbd> - 静音/取消静音
- <kbd>右Ctrl + F7</kbd> - 停止播放

## 虚拟键码对应
- 0xB0 - 下一首
- 0xB1 - 上一首
- 0xB2 - 停止播放
- 0xB3 - 播放/暂停
- 0xAF - 增加音量 (每次增加两格音量)
- 0xAE - 减少音量 (每次减少两格音量)
- 0xAD - 静音/取消静音

## 注意事项
- 请勿多开此程序，否则可能导致热键冲突
- 在某些场景下可能不响应热键

## 开发者
- SLSYSL(LANREN)

## 许可证
本项目采用MIT许可证。详情请参阅LICENSE文件。
