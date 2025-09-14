# SoundCtrl / Audio Control
A lightweight Windows media control tool that allows you to quickly control media playback via the command line or global hotkeys.

README Language: English(Current) / [简体中文](https://github.com/SLSYSL/SoundCtrl/blob/main/README_schinese.md) / [繁體中文](https://github.com/SLSYSL/SoundCtrl/blob/main/README_tchinese.md)

## Features
- 🎵 Media Playback Control (Play/Pause, Previous Track, Next Track, Stop)
- 🔊 Volume Control (Increase, Decrease, Mute Toggle)
- ⌨️ Global Hotkey Support (Background Mode)
- 🚀 Lightweight, no dependencies, implemented with native Windows APIs

## System Requirements
- Windows 7 or later

## Usage
### Background Mode (Default Mode)
#### Method 1:
- Run the program directly.

#### Method 2:
- Run in Command Prompt (CMD) or PowerShell: `.\SoundCtrl.exe back`

### Command Line Mode
Run in Command Prompt (CMD) or PowerShell:

```bash
.\SoundCtrl.exe <command>
```

Command Examples:

- `.\SoundCtrl.exe play` - Play/Pause

- `.\SoundCtrl.exe next` - Next Track

- `.\SoundCtrl.exe back` - Background Mode

### Command
- `play` - Play/Pause
- `next` - Next Track
- `prev` - Previous Track
- `up` - Increase Volume (increases by 2 levels each time)
- `down` - Decrease Volume (decreases by 2 levels each time)
- `mute` - Mute/Unmute
- `stop` - Stop Playback

## Hotkeys for Background Mode

- <kbd>Right Ctrl + Q</kbd> - Exit the program
- <kbd>Right Ctrl + F1</kbd> - Play/Pause
- <kbd>Right Ctrl + F2</kbd> - Previous Track
- <kbd>Right Ctrl + F3</kbd> - Next Track
- <kbd>Right Ctrl + F4</kbd> - Increase Volume (increases by 2 levels each time)
- <kbd>Right Ctrl + F5</kbd> - Decrease Volume (decreases by 2 levels each time)
- <kbd>Right Ctrl + F6</kbd> - Mute/Unmute
- <kbd>Right Ctrl + F7</kbd> - Stop Playback

## Virtual Key Code Correspondence

- 0xB0 - Next Track
- 0xB1 - Previous Track
- 0xB2 - Stop Playback
- 0xB3 - Play/Pause
- 0xAF - Increase Volume (increases by 2 levels each time)
- 0xAE - Decrease Volume (decreases by 2 levels each time)
- 0xAD - Mute/Unmute

## Notes

- Do not run multiple instances of this program, as it may cause hotkey conflicts.
- Hotkeys may not respond in certain scenarios.

## Developer
- SLSYSL (LANREN)

## License
This project is licensed under the MIT License. For details, please refer to the LICENSE file.
