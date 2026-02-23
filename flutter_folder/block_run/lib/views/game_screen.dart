import 'dart:ffi';
import 'dart:ui' as ui;
import 'package:ffi/ffi.dart'; 
import 'package:flutter/material.dart';
import 'package:flutter/scheduler.dart'; 
import '../core/ffi_bindings.dart';
import '../game_engine/game_controller.dart';

class GameScreen extends StatefulWidget {
  const GameScreen({super.key});

  @override
  _GameScreenState createState() => _GameScreenState();
}

class _GameScreenState extends State<GameScreen> with SingleTickerProviderStateMixin {
  late Ticker _ticker;
  final GameController _game = GameController();
  final GameRendererFfi _ffi = GameRendererFfi();
  
  ui.Image? _renderedFrame;
  final int width = 500;
  final int height = 800;
  
  late Pointer<Uint32> _pixelBuffer;

@override
  void initState() {
    super.initState();
    _pixelBuffer = calloc<Uint32>(width * height);
    
    // Create a loop to spawn blocks so the game doesn't feel empty
    _ticker = createTicker((elapsed) {
      // Logic to spawn a block every 2 seconds
      if (elapsed.inMilliseconds % 2000 < 20) {
         _game.objects.add(GameObject((elapsed.inSeconds % 5) - 2, 0.0, false));
      }
      _tick(elapsed);
    })..start();
  }

  @override
  void dispose() {
    _ticker.dispose();
    calloc.free(_pixelBuffer); 
    super.dispose();
  }

  void _tick(Duration elapsed) {
    _game.updateGame(0.016); 
    
    var renderData = _game.getRenderData(width.toDouble(), height.toDouble());
    
    Pointer<GameRenderObj> cObjects = calloc<GameRenderObj>(renderData.length);
    
    for (int i = 0; i < renderData.length; i++) {
      final item = renderData[i];
      final ref = (cObjects + 1).ref;
      
      ref.x = (item['x'] as num).toDouble();
      ref.y = (item['y'] as num).toDouble();
      ref.w = (item['w'] as num).toDouble();
      ref.h = (item['h'] as num).toDouble();
      ref.color = (item['color'] as num).toInt();
    }

    _ffi.renderFrame(_pixelBuffer, width, height, cObjects, renderData.length);
    
    calloc.free(cObjects);

    ui.decodeImageFromPixels(
      _pixelBuffer.cast<Uint8>().asTypedList(width * height * 4),
      width, 
      height, 
      ui.PixelFormat.bgra8888, 
      (img) {
        if (mounted) {
          setState(() => _renderedFrame = img);
        }
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[900],
      body: Column(
        children: [
          Expanded(
            child: Center(
              child: _renderedFrame == null 
                ? const CircularProgressIndicator()
                : Container(
                    decoration: BoxDecoration(
                      border: Border.all(color: Colors.white, width: 2),
                    ),
                    child: RawImage(
                      image: _renderedFrame, 
                      fit: BoxFit.contain,
                      width: width.toDouble(),
                      height: height.toDouble(),
                    ),
                  ),
            ),
          ),
          
          Container(
            color: Colors.black,
            height: 120,
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                _gameButton(Icons.arrow_back, "Left", () => _game.moveLeft()),
                _gameButton(Icons.arrow_downward, "Slide", () => _game.slide()),
                _gameButton(Icons.arrow_upward, "Jump", () => _game.jump()),
                _gameButton(Icons.arrow_forward, "Right", () => _game.moveRight()),
                
                // FIX: Icon name changed from 3d_rotation to threed_rotation
                IconButton(
                    icon: Icon(
                      Icons.threed_rotation, // Corrected Name
                      color: _game.is3D ? Colors.blue : Colors.grey
                    ),
                    onPressed: () {
                        _game.is3D = !_game.is3D;
                    },
                )
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _gameButton(IconData icon, String label, VoidCallback onPressed) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        IconButton(
          icon: Icon(icon, color: Colors.white, size: 30),
          onPressed: onPressed,
        ),
        Text(label, style: const TextStyle(color: Colors.white, fontSize: 10))
      ],
    );
  }
}
