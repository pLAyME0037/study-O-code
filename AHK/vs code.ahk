#Requires AutoHotkey v2.0
#SingleInstance Force

!h::Send("{Left}")
!l::Send("{Right}")
!k::Send("{Up}")
!j::Send("{Down}")

;--------------------------------------

+!h::Send("{Ctrl down}{Shift down}{Left}{Shift up}{Ctrl up}")
+!l::Send("{Ctrl down}{Shift down}{Right}{Shift up}{Ctrl up}")
+!i::Send("{Home}")
+!a::Send("{End}")

;--------------------------------------

; #1::Run "E:\\Program Files\\Everything 1.5a\\Everything64.exe"
