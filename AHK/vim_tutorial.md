# AutoHotkey VIM Mode Tutorial

This document explains how to use the VIM-like keybindings in your `shortcutCode.ahk` script.

## 1. Toggling VIM Mode (Normal/Insert)

*   **Alt + I**: Toggles between **NORMAL** mode and **INSERT** mode.
    *   In **NORMAL** mode, VIM-like keybindings are active.
    *   In **INSERT** mode, all VIM-like keybindings are disabled, and you can type normally.

## 2. The Leader Key (Spacebar)

Many VIM commands are sequences of keys. To avoid conflicts with normal typing, a **Leader Key** is used.
*   **Press `Spacebar` (Leader Key)**: This activates a temporary "leader mode" for 500ms, during which subsequent key presses will trigger VIM commands. If no VIM command is recognized within 500ms, the `Spacebar` will be sent as a normal space.

## 3. Basic Navigation (NORMAL Mode)

These commands work directly in NORMAL mode (after toggling with Alt+I).

*   **h**: Move cursor **Left**
*   **j**: Move cursor **Down**
*   **k**: Move cursor **Up**
*   **l**: Move cursor **Right**
*   **0**: Go to **start of line**
*   **$**: Go to **end of line**
*   **u**: **Undo** (Ctrl+Z)
*   **Ctrl + R**: **Redo** (Ctrl+R)
*   **x**: **Delete character** under cursor

## 4. Insert/Append Modes (NORMAL Mode)

These commands switch you to INSERT mode after performing an action.

*   **i**: Insert text **before** the cursor (sends Left, then switches to INSERT mode)
*   **a**: Append text **after** the cursor (sends Right, then switches to INSERT mode)
*   **Shift + I**: Insert text at the **start of the line** (sends Home, then switches to INSERT mode)
*   **Shift + A**: Append text at the **end of the line** (sends End, then switches to INSERT mode)
*   **o**: Open a **new line below** and switch to INSERT mode (sends End, Enter, then switches to INSERT mode)
*   **Shift + O**: Open a **new line above** and switch to INSERT mode (sends Home, Enter, Up, then switches to INSERT mode)

## 5. Leader Key Commands (NORMAL Mode, after pressing Spacebar)

Press `Spacebar` (Leader Key), then one of the following sequences:

*   **`Spacebar` + d + d**: **Delete current line** (selects line, then deletes)
*   **`Spacebar` + y + y**: **Yank (copy) current line** (selects line, then copies)
*   **`Spacebar` + p**: **Paste**
*   **`Spacebar` + g + g**: Go to **start of file**
*   **`Spacebar` + Shift + G**: Go to **end of file**
*   **`Spacebar` + n**: Go to **next search result** (F3)
*   **`Spacebar` + Shift + N**: Go to **previous search result** (Shift+F3)
*   **`Spacebar` + d + w**: **Delete word** (selects word, then deletes)
*   **`Spacebar` + c + c**: **Change current line** (deletes line, then switches to INSERT mode)
*   **`Spacebar` + >**: **Indent current line** (Ctrl+])
*   **`Spacebar` + <**: **Outdent current line** (Ctrl+[)
*   **`Spacebar` + Shift + V**: Enter **Visual Line Mode** (selects to end of line)

## 6. Other Useful Commands (NORMAL Mode)

*   **Ctrl + P**: Fuzzy file finder (VS Code's Quick Open)
*   **Ctrl + Shift + F**: Search in files (VS Code's Search)

---
*This tutorial is generated automatically and can be updated by modifying the `vim_tutorial.md` template.*
