
ERROR: lib/views/game_screen.dart:55:13: Error: 'GameRenderObject' isn't a type.
ERROR:     Pointer<GameRenderObject> cObjects = calloc<GameRenderObject>(renderData.length);
ERROR:             ^^^^^^^^^^^^^^^^
ERROR: lib/views/game_screen.dart:55:49: Error: 'GameRenderObject' isn't a type.
ERROR:     Pointer<GameRenderObject> cObjects = calloc<GameRenderObject>(renderData.length);
ERROR:                                                 ^^^^^^^^^^^^^^^^
ERROR: lib/views/game_screen.dart:60:28: Error: The method 'elementAt' is defined in multiple extensions for 'Pointer<invalid-type>' and neither is more specific.
ERROR:  - 'Pointer' is from 'dart:ffi'.
ERROR: Try using an explicit extension application of the wanted extension or hiding unwanted extensions from scope.
ERROR:       final ref = cObjects.elementAt(i).ref;
ERROR:                            ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:559:17: Context: This is one of the extension members.
ERROR:   Pointer<Int8> elementAt(int index) =>
ERROR:                 ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:638:18: Context: This is one of the extension members.
ERROR:   Pointer<Int16> elementAt(int index) =>
ERROR:                  ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:719:18: Context: This is one of the extension members.
ERROR:   Pointer<Int32> elementAt(int index) =>
ERROR:                  ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:791:18: Context: This is one of the extension members.
ERROR:   Pointer<Int64> elementAt(int index) =>
ERROR:                  ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:866:18: Context: This is one of the extension members.
ERROR:   Pointer<Uint8> elementAt(int index) =>
ERROR:                  ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:945:19: Context: This is one of the extension members.
ERROR:   Pointer<Uint16> elementAt(int index) =>
ERROR:                   ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:1026:19: Context: This is one of the extension members.
ERROR:   Pointer<Uint32> elementAt(int index) =>
ERROR:                   ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:1098:19: Context: This is one of the extension members.
ERROR:   Pointer<Uint64> elementAt(int index) =>
ERROR:                   ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:1179:18: Context: This is one of the extension members.
ERROR:   Pointer<Float> elementAt(int index) =>
ERROR:                  ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:1251:19: Context: This is one of the extension members.
ERROR:   Pointer<Double> elementAt(int index) =>
ERROR:                   ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/ffi/ffi.dart:1318:17: Context: This is one of the extension members.
ERROR:   Pointer<Bool> elementAt(int index) =>
ERROR:                 ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/_internal/vm/lib/ffi_patch.dart:1483:23: Context: This is one of the extension members.
ERROR:   Pointer<Pointer<T>> elementAt(int index) =>
ERROR:                       ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/_internal/vm/lib/ffi_patch.dart:1524:14: Context: This is one of the extension members.
ERROR:   Pointer<T> elementAt(int index) =>
ERROR:              ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/_internal/vm/lib/ffi_patch.dart:1561:14: Context: This is one of the extension members.
ERROR:   Pointer<T> elementAt(int index) =>
ERROR:              ^^^^^^^^^
ERROR: org-dartlang-sdk:///flutter/third_party/dart/sdk/lib/_internal/vm/lib/ffi_patch.dart:1593:14: Context: This is one of the extension members.
ERROR:   Pointer<T> elementAt(int index) =>
ERROR:              ^^^^^^^^^
ERROR: lib/views/game_screen.dart:55:48: Error: Expected type 'invalid-type' to be a valid and instantiated subtype of 'NativeType'.
ERROR:     Pointer<GameRenderObject> cObjects = calloc<GameRenderObject>(renderData.length);
ERROR:                                                ^
ERROR: Target kernel_snapshot_program failed: Exception
Error: Build process failed
#0      throwToolExit (package:flutter_tools/src/base/common.dart:34:3)
#1      _runBuild (package:flutter_tools/src/linux/build_linux.dart:219:5)
<asynchronous suspension>
#2      buildLinux (package:flutter_tools/src/linux/build_linux.dart:100:5)
<asynchronous suspension>
#3      LinuxDevice.buildForDevice (package:flutter_tools/src/linux/linux_device.dart:67:5)
<asynchronous suspension>
#4      DesktopDevice.startApp (package:flutter_tools/src/desktop_device.dart:108:7)
<asynchronous suspension>
#5      FlutterDevice.runCold (package:flutter_tools/src/resident_runner.dart:572:33)
<asynchronous suspension>
#6      ColdRunner.run (package:flutter_tools/src/run_cold.dart:56:28)
<asynchronous suspension>
#7      RunCommand.runCommand (package:flutter_tools/src/commands/run.dart:904:26)
<asynchronous suspension>
#8      FlutterCommand.run.<anonymous closure> (package:flutter_tools/src/runner/flutter_command.dart:1590:27)
<asynchronous suspension>
#9      AppContext.run.<anonymous closure> (package:flutter_tools/src/base/context.dart:154:19)
<asynchronous suspension>
#10     CommandRunner.runCommand (package:args/command_runner.dart:212:13)
<asynchronous suspension>
#11     FlutterCommandRunner.runCommand.<anonymous closure> (package:flutter_tools/src/runner/flutter_command_runner.dart:496:9)
<asynchronous suspension>
#12     AppContext.run.<anonymous closure> (package:flutter_tools/src/base/context.dart:154:19)
<asynchronous suspension>
#13     FlutterCommandRunner.runCommand (package:flutter_tools/src/runner/flutter_command_runner.dart:431:5)
<asynchronous suspension>
#14     FlutterCommandRunner.run.<anonymous closure> (package:flutter_tools/src/runner/flutter_command_runner.dart:307:33)
<asynchronous suspension>
#15     run.<anonymous closure>.<anonymous closure> (package:flutter_tools/runner.dart:104:11)
<asynchronous suspension>
#16     AppContext.run.<anonymous closure> (package:flutter_tools/src/base/context.dart:154:19)
<asynchronous suspension>
#17     main (package:flutter_tools/executable.dart:103:3)
<asynchronous suspension>

