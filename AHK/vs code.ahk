#Requires AutoHotkey v2.0
#SingleInstance Force
;--------------------------------------
    ; $h::Send("{Left}")
    ; $j::Send("{Down}")
    ; $k::Send("{Up}")
    ; $l::Send("{Right}")
;--------------------------------------

; #1::Run "E:\\Program Files\\Everything 1.5a\\Everything64.exe"

;--------------------------------------

global bindingMode := false

!h:: {
    global bindingMode

    bindingMode := !bindingMode ; Invert the value (true -> false, false -> true)
    ToolTip("Binding Mode: " . (bindingMode ? "ON" : "OFF"))
    SetTimer(ToolTip, -2000) ; Optional: Hide the tooltip after 2 seconds
}

; Esc:: {
;     global bindingMode

;     if (bindingMode) { ; Only turn off if it's currently on
;         bindingMode := false
;         ToolTip("Binding Mode: OFF")
;         SetTimer(ToolTip, -2000) ; Optional: Hide the tooltip after 2 seconds
;     }
;     ToolTip("") ; Immediately hide any active tooltip
; }

#HotIf bindingMode

    $h::Send("{Left}")
    $j::Send("{Down}")
    $k::Send("{Up}")
    $l::Send("{Right}")

    $+h::Send("{Ctrl down}{Shift down}{Left}{Shift up}{Ctrl up}")
    $+l::Send("{Ctrl down}{Shift down}{Right}{Shift up}{Ctrl up}")
    $+i::Send("{Home}")
    $+a::Send("{End}")

#HotIf