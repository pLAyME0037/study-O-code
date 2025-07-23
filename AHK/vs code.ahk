#Requires AutoHotkey v2.0
#SingleInstance Force
;--------------------------------------
#w:: Run "C:\Users\USER\AppData\Local\Programs\Microsoft VS Code\Code.exe"
;--------------------------------------
; Auto-disable nvim-like shortcuts when Vim or Neovim window is active
; --- Mode Handling ---
global bindingMode := false

; Toggle bindingMode (normal/insert mode) with Alt+I
!i:: {
    global bindingMode
    bindingMode := !bindingMode
    ToolTip("Mode: " . (bindingMode ? "NORMAL" : "INSERT"))
    SetTimer(() => ToolTip(), -2000)
}

; Only enable bindings if bindingMode is ON and not in Vim/Neovim windows
#HotIf bindingMode && !WinActive("ahk_exe vim.exe") && !WinActive("ahk_exe nvim-qt.exe") && !WinActive("ahk_exe nvim.exe")

; --- Basic Navigation ---
$h:: Send("{Left}")
$j:: Send("{Down}")
$k:: Send("{Up}")
$l:: Send("{Right}")

; --- Word Navigation ---
$w:: Send("^{Right}")             ; Next word
$b:: Send("^{Left}")              ; Previous word
$e:: Send("^{Right}{Ctrl up}")    ; End of word (approximate)

; --- Line Navigation ---
$0:: Send("{Home}")               ; Line start
$^:: Send("{Home}")               ; Line start (caret)
$$:: Send("{End}")                ; Line end

; --- Undo/Redo ---
$u:: Send("^z")                   ; Undo
$^r:: Send("^y")                  ; Redo

; --- Editing ---
$x:: Send("{Del}")                ; Delete character under cursor
::dd:: Send("^{l}")               ; Delete line
::yy:: Send("^{c}")               ; Copy line
$p:: Send("^{v}")                 ; Paste

; --- File Navigation ---
::gg:: Send("^{Home}")            ; File start
$+G:: Send("^{End}")              ; File end

; --- Search Navigation ---
$n:: Send("{F3}")                 ; Next search result
$+N:: Send("+{F3}")               ; Previous search result

; --- Word Editing ---
::dw:: Send("+^{Right}{Del}")     ; Delete word
::ciw:: Send("+^{Right}{Del}")    ; Change inner word

; --- Insert/Append Modes ---
$i:: {
    Send("{Left}")                ; Insert after cursor
    Send("!i")
}
$a:: {
    Send("{Right}")               ; Append after cursor
    Send("!i")
}
$+I:: {
    Send("{Home}")                ; Insert at line start
    Send("!i")
}
$+A:: {
    Send("{End}")                 ; Append at line end
    Send("!i")
}


$o:: {
    Send("{End}{Enter}")         ; Open new line below (simulate 'o')
    Send("!i")
}
$+O:: {
    Send("{Home}{Enter}{Up}")    ; Open new line above (simulate 'O')
    Send("!i")
}
::cc:: {
    Send("^{l}")                 ; Change line (delete line, enter insert mode)
    Send("!i")
}
$+J:: Send("+{Down}{End}{Space}")  ; Join lines (select next line, join)
$>>:: Send("^]")                  ; Indent line (Ctrl+])
$<<:: Send("^[")                  ; Outdent line (Ctrl+[)
$V:: Send("+{End}")               ; Visual line mode (select to end of line)
^p:: Send("^p")                   ; Fuzzy file finder (Ctrl+P in VSCode)
^+f:: Send("^+f")                 ; Search in files (Ctrl+Shift+F)

#HotIf