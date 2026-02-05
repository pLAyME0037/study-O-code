; ---------------------------------------------------------
; CompileRun.ahk - Helper module for C/C++ Compiling
; ---------------------------------------------------------

; Function to get the active file path from VS Code
GetVSCodeActiveFilePath() {
    if !WinActive("ahk_exe Code.exe") && !WinActive("ahk_exe VSCodium.exe") {
        MsgBox("VS Code/VSCodium is not active.", "Error")
        return ""
    }

    ; 1. Save the file first
    Send "^s"
    Sleep 100

    ; 2. Clear Clipboard
    A_Clipboard := ""

    ; 3. Try VS Code Default Shortcut (Shift + Alt + C)
    Send "+!c"

    ; 4. Wait for clipboard
    if !ClipWait(0.5) {
        ; Fallback: Ctrl+K then P (Copy Path of Active File)
        Send "^k"
        Sleep 50
        Send "p"
        if !ClipWait(0.5) {
            MsgBox("Failed to get file path. Ensure 'Copy Path' shortcut works.", "Error")
            return ""
        }
    }

    return A_Clipboard
}

; Function to compile and run
CompileAndRun(compiler) {
    filePath := GetVSCodeActiveFilePath()
    if (filePath = "")
        return

    SplitPath filePath, &fileName, &fileDir, &fileExtension, &fileNameNoExt

    if (fileExtension != "c" && fileExtension != "cpp") {
        MsgBox("File is not C or C++. Extension: " . fileExtension, "Error")
        return
    }

    outputExe := fileDir . "\" . fileNameNoExt . ".exe"
    safePath := '"' . filePath . '"'
    safeExe := '"' . outputExe . '"'

    ; Construct Command: compiler input -o output && output & pause
    cmd := compiler . " " . safePath . " -o " . safeExe . " && " . safeExe

    try {
        Run(A_ComSpec ' /c "' . cmd . ' & pause"')
    } catch as err {
        MsgBox("Failed to run compiler.`nError: " . err.Message)
    }
}

; ---------------------------------------------------------
; Hotstrings / Hotkeys
; ---------------------------------------------------------

#HotIf WinActive("ahk_exe Code.exe") || WinActive("ahk_exe VSCodium.exe")

; Type 'fcc' then Space to compile C
::fcc:: {
    CompileAndRun("gcc")
}

; Type 'foo' then Space to compile C++
::foo:: {
    CompileAndRun("g++")
}

#HotIf