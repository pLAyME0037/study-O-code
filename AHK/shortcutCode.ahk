#Requires AutoHotkey v2.0
#SingleInstance Force
SetWorkingDir A_ScriptDir

;--------------------------------------
; GLOBAL VARIABLES & INIT
;--------------------------------------
global VimMode := false
global VimLeaderActive := false

;--------------------------------------
; KEY REMAPPING (Global)
;--------------------------------------


;--------------------------------------
; BLUEPRINT GENERATOR (::g.pt::)
;--------------------------------------
::g.md::{
    SendText "
    (
    Create a comprehensive Architectural Blueprint inside a markdown file (Format: YYYY-MM-DD_HHmm_FeatureName.md) to serve as the project's Memory Bank for this task. Requirements:
    1. Decomposition: Break the problem down into isolated objects, modules, and interfaces to ensure Single Responsibility (SOLID) and easier debugging.
    2. Strategy: Outline the Logical Implementation Pathways and Pseudocode before writing actual code.
    3. Verification: Define specific test cases and success criteria for each module.
    4. Reference: Do not start coding until this plan is reviewed. Once approved, use this file as the absolute reference for execution, checking off items as they are completed.
    )"
}

::g.sg::{
    SendText "
    (
    Execute the approved plan strictly Step-by-Step, Phase-by-Phase.
    Protocol:
    1. Atomic Progress: Complete one logical unit at a time. STOP and request my confirmation before proceeding to the next phase.
    2. Quality Gate: Do not proceed if the current step contains errors, bugs, or failing tests. Refine immediately until green.
    3. Logic First: Implement core backend logic, data modeling, and unit tests first. Do not implement UI (Blade/Alpine/Tailwind) until the backend logic is secure, validated, and stable.
    4. Update Context: Mark steps as "Completed" in the planning file after finishing them.
    )"
}
::g.pt::
{
    ; Configuration
    planName := "PLAN"
    saveDir := A_Desktop

    ; Generate Filename
    timestamp := FormatTime(, "dd_MM_yyyy_HH_mm")
    fullPath := saveDir "\" timestamp "_" planName ".md"

    ; Template Content
    templateContent := "
    (
    # Project: {planName}
    - Date: {Date}
    - Status: Planning
    
    ## Objective
    
    ## Breakdown
    - [ ] Phase 1
    
    ## Notes
    )"

    ; Replace placeholders
    templateContent := StrReplace(templateContent, "{planName}", planName)
    templateContent := StrReplace(templateContent, "{Date}", timestamp)

    ; Write File
    try {
        if FileExist(fullPath)
            FileDelete(fullPath)
        FileAppend(templateContent, fullPath, "UTF-8")

        ; Open
        Run('"' fullPath '"')

        ; Notify
        TrayTip "Blueprint Created", fullPath, 1
        SetTimer () => TrayTip(), -3000
    } catch as err {
        MsgBox "Error creating file: " err.Message
    }
}

;--------------------------------------
; SHORTCUT KEYS
;--------------------------------------
; Used EnvGet or A_ variables to make paths robust
#n:: Run "C:\Users\USER\AppData\Local\Programs\@notesnookdesktop\Notesnook.exe"
#b:: Run "brave.exe"
#t:: Run A_AppData "\Telegram Desktop\Telegram.exe"
#Enter:: Run('pwsh.exe -NoExit -Command "cd $env:USERPROFILE"')
#!x:: Run "https://x.com/i/grok?conversation="
#w:: Run "https://github.com/playme0037/"
#y:: Run "C:\Users\USER\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Brave Apps\YouTube.lnk"
;--------------------------------------
; VIRTUAL DESKTOP MANAGER
; Checks if DLL exists to prevent crash
;--------------------------------------
global VDAModule := 0
global GoToDesktopProc := 0
global MoveWindowProc := 0

if FileExist("VirtualDesktopAccessor.dll") {
    VDAModule := DllCall("LoadLibrary", "Str", "VirtualDesktopAccessor.dll", "Ptr")
    GoToDesktopProc := DllCall("GetProcAddress", "Ptr", VDAModule, "AStr", "GoToDesktopNumber", "Ptr")
    MoveWindowProc := DllCall("GetProcAddress", "Ptr", VDAModule, "AStr", "MoveWindowToDesktopNumber", "Ptr")
} else {
    ; Optional: Warn user only once
    ; MsgBox "VirtualDesktopAccessor.dll not found. Desktop switching disabled."
}

SwitchDesktop(num) {
    if (GoToDesktopProc)
        DllCall(GoToDesktopProc, "Int", num - 1)
}

MoveToDesktop(num) {
    if (MoveWindowProc) {
        activeWin := WinExist("A")
        DllCall(MoveWindowProc, "Ptr", activeWin, "Int", num - 1)
    }
}

#1:: SwitchDesktop(1)
#2:: SwitchDesktop(2)
#3:: SwitchDesktop(3)
#4:: SwitchDesktop(4)

*#!1:: MoveToDesktop(1)
*#!2:: MoveToDesktop(2)
*#!3:: MoveToDesktop(3)
*#!4:: MoveToDesktop(4)

;--------------------------------------
; VIM MODE IMPLEMENTATION
;--------------------------------------

; Toggle Vim Mode
!i:: {
    global VimMode
    VimMode := !VimMode
    ShowModeTooltip(VimMode ? "NORMAL" : "INSERT")
}

ShowModeTooltip(text) {
    ToolTip "VIM: " text
    SetTimer () => ToolTip(), -1500
}

; --- Conditional Hotkeys for Vim Mode ---
; Active only if VimMode is ON and NOT inside a real editor (VSCode/Vim/Neovim)
#HotIf VimMode
    && !WinActive("ahk_exe Code.exe")
    && !WinActive("ahk_exe vim.exe")
    && !WinActive("ahk_exe nvim.exe")
; && !WinActive("ahk_exe VSCodium.exe")

; --- Mode Switching ---
i:: {
    global VimMode := false
    ShowModeTooltip("INSERT")
}
+i:: { ; Shift+I (Insert at line start)
    Send "{Home}"
    global VimMode := false
    ShowModeTooltip("INSERT")
}
a:: { ; Append
    Send "{Right}"
    global VimMode := false
    ShowModeTooltip("INSERT")
}
+a:: { ; Shift+A (Append at line end)
    Send "{End}"
    global VimMode := false
    ShowModeTooltip("INSERT")
}
o:: { ; Open line below
    Send "{End}{Enter}"
    global VimMode := false
    ShowModeTooltip("INSERT")
}
+o:: { ; Open line above
    Send "{Up}{End}{Enter}"
    global VimMode := false
    ShowModeTooltip("INSERT")
}

; --- Navigation ---
h::Left
j::Down
k::Up
l::Right
w:: Send "^{Right}"    ; Next word
b:: Send "^{Left}"     ; Prev word
e:: Send "^{Right}"    ; End of word
0::Home        ; Start of line
$::End         ; End of line
^u::PgUp       ; Half page up (approx)
^d::PgDn       ; Half page down (approx)

; --- Undo/Redo ---
u::^z
^r::^y

; --- Visual ---
v::+Right      ; Visual char (basic)
+v:: Send "{Home}+{End}"    ; Visual line (basic)

; --- Actions (d, y, c, g, etc) ---
; Uses InputHook to wait for the second key safely

d:: {
    ih := InputHook("L1 T1") ; Wait 1 second for 1 key
    ih.Start(), ih.Wait()

    if (ih.Input = "d") {
        Send "{Home}+{End}{Del}" ; dd: Delete line
        ; Send "{Del}" ; Remove extra newline if needed
    } else if (ih.Input = "w") {
        Send "+^{Right}{Del}"    ; dw: Delete word
    }
}

c:: {
    ih := InputHook("L1 T1")
    ih.Start(), ih.Wait()

    if (ih.Input = "c") {
        Send "{Home}+{End}{Del}" ; cc: Change line
        global VimMode := false  ; Switch to insert
        ShowModeTooltip("INSERT")
    } else if (ih.Input = "w") {
        Send "+^{Right}{Del}"    ; cw: Change word
        global VimMode := false
        ShowModeTooltip("INSERT")
    }
}

y:: {
    ih := InputHook("L1 T1")
    ih.Start(), ih.Wait()

    if (ih.Input = "y") {
        Send "{Home}+{End}^c{End}" ; yy: Yank line (and deselect)
        ShowModeTooltip("Yanked Line")
    }
}

p:: Send "^v" ; Paste
x::Del       ; Delete char

; --- Go Actions ---
g:: {
    ih := InputHook("L1 T1")
    ih.Start(), ih.Wait()
    if (ih.Input = "g") {
        Send "^{Home}" ; gg: Top of file
    }
}
+g:: Send "^{End}" ; G: Bottom of file

; --- Search ---
/::^f
n::F3
+n::+F3

#HotIf ; End Vim Mode Context

; This makes Esc/CapsLock turn Normal Mode back ON.
#HotIf !VimMode
$!i:: {
    global VimMode := true
    ShowModeTooltip("NORMAL")
}
#HotIf
;--------------------------------------
; CLEANUP ON EXIT
;--------------------------------------
OnExit ExitFunc
ExitFunc(*) {
    if (VDAModule)
        DllCall("FreeLibrary", "Ptr", VDAModule)
}

;--------------------------------------
; COMPILER INCLUDE (Optional)
;--------------------------------------
#Include "*i CompileRun.ahk"
