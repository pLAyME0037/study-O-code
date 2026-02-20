import 'dart:ffi';
import 'dart:io';

// 1. RENAME class to GameRenderObject
final class GameRenderObject extends Struct {
  @Float() external double x;
  @Float() external double y;
  @Float() external double w;
  @Float() external double h;
  @Uint32() external int color;
}

// 2. UPDATE typedefs to use GameRenderObject
typedef RenderFrameC = Void Function(Pointer<Uint32> pixels, Int32 width, Int32 height, Pointer<GameRenderObject> objects, Int32 objCount);
typedef RenderFrameDart = void Function(Pointer<Uint32> pixels, int width, int height, Pointer<GameRenderObject> objects, int objCount);

class GameRendererFfi {
  late RenderFrameDart renderFrame;

  GameRendererFfi() {
    final DynamicLibrary nativeAddLib = Platform.isAndroid
        ? DynamicLibrary.open('libgame_renderer.so')
        : Platform.isWindows
            ? DynamicLibrary.open('game_renderer.dll')
            : DynamicLibrary.process(); 

    renderFrame = nativeAddLib.lookupFunction<RenderFrameC, RenderFrameDart>('render_frame');
  }
}
