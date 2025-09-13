# SoundCtrl / 音訊控制
一個羽量級的 Windows 媒體控制工具，允許您通過命令列或全域熱鍵快速控制媒體播放。

README 語言：[English](https://github.com/SLSYSL/SoundCtrl/blob/main/README.md) / [简体中文](https://github.com/SLSYSL/SoundCtrl/blob/main/README_schinese.md) / 繁體中文(當前語言)

## 功能特點
- 🎵 媒體播放控制（播放/暫停、上一首、下一首、停止）
- 🔊 音量控制（新增、减少、靜音切換）
- ⌨️ 全域熱鍵支持（後臺模式）
- 🚀 羽量級，無依賴，原生 Windows API 實現

## 系統要求
- Windows 7 或更高版本

## 使用方法
### 後臺模式（默認模式）
#### 方法一：
- 直接運行程式

#### 方法二：
- 命令提示符（CMD）或 PowerShell 中運行：`.\SoundCtrl.exe back`

### 命令列模式
在命令提示符（CMD）或 PowerShell 中運行：
```bash
.\SoundCtrl.exe <命令>
```
命令示例：
- `.\SoundCtrl.exe play` - 播放/暫停
- `.\SoundCtrl.exe next` - 下一首
- `.\SoundCtrl.exe back` - 後臺模式

## 後臺模式熱鍵
- <kbd>右Ctrl + Q</kbd> - 退出程式
- <kbd>右Ctrl + F1</kbd> - 播放/暫停
- <kbd>右Ctrl + F2</kbd> - 上一首
- <kbd>右Ctrl + F3</kbd> - 下一首
- <kbd>右Ctrl + F4</kbd> - 新增音量（每次新增兩格音量）
- <kbd>右Ctrl + F5</kbd> - 减少音量（每次减少兩格音量）
- <kbd>右Ctrl + F6</kbd> - 靜音/取消靜音
- <kbd>右Ctrl + F7</kbd> - 停止播放

## 虛擬鍵碼對應
- 0xB0 - 下一首
- 0xB1 - 上一首
- 0xB2 - 停止播放
- 0xB3 - 播放/暫停
- 0xAF - 新增音量（每次新增兩格音量）
- 0xAE - 减少音量（每次减少兩格音量）
- 0xAD - 靜音/取消靜音

## 注意事項
- 請勿多開此程式，否則可能導致熱鍵衝突
- 在某些場景下可能不響應熱鍵

## 開發者
- SLSYSL(LANREN)

## 許可證
本項目採用MIT許可證。 詳情請參閱LICENSE檔案。
