import 'dart:ffi';
import 'dart:io';

// 1. RENAME class to GameRenderObject
final class GameRenderObj extends Struct {
    @Float()  external double x;
    @Float()  external double y;
    @Float()  external double w;
    @Float()  external double h;
    @Uint32() external int color;
}

// 2. UPDATE typedefs to use GameRenderObject
typedef RenderFrameC = Void Function(Pointer<Uint32> pixels, Int32 width, Int32 height,
                                     Pointer<GameRenderObj> objects, Int32 objCount);
typedef RenderFrameDart = void Function(Pointer<Uint32> pixels, int width, int height, 
                                        Pointer<GameRenderObj> objects, int objCount);

class GameRendererFfi {
    late RenderFrameDart renderFrame;

    GameRendererFfi() {
        DynamicLibrary nativeAddLib; 
        if (Platform.isWindows) {
            nativeAddLib = DynamicLibrary.open('build/game_renderer.dll');
        } else if (Platform.isAndroid) {
            nativeAddLib = DynamicLibrary.open('build/libgame_renderer.so');
        } else {
            try {
                nativeAddLib = DynamicLibrary.open("build/libgame_renderer.so");
            } catch (e) {
                nativeAddLib = DynamicLibrary.open("./build/libgame_renderer.so");
            }
        }

        renderFrame = nativeAddLib.lookupFunction<RenderFrameC, RenderFrameDart>('render_frame');
    }
}
