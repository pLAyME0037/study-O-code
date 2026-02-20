import 'package:flutter/material.dart';

class GameObject {
  int lane; // -2, -1, 0, 1, 2 (5 lanes)
  double distanceY; // 0.0 (far away) to 1.0 (at player)
  bool isPoint; // true = points, false = obstacle
  bool gameOver = false;
  GameObject(this.lane, this.distanceY, this.isPoint);
}

class GameController extends ChangeNotifier {
  bool is3D = true; // Toggle between 2D and 3D!
  
  int playerLane = 0; // Starts in middle lane (0)
  bool isJumping = false;
  bool isSliding = false;

  int score = 0;
  List<GameObject> objects =[];

  void moveLeft() { if (playerLane > -2) playerLane--; notifyListeners(); }
  void moveRight() { if (playerLane < 2) playerLane++; notifyListeners(); }
  void jump() async { isJumping = true; notifyListeners(); await Future.delayed(Duration(milliseconds: 500)); isJumping = false; }
  void slide() async { isSliding = true; notifyListeners(); await Future.delayed(Duration(milliseconds: 500)); isSliding = false; }

  void updateGame(double dt) {
    // Move objects towards player
    for (var obj in objects) {
      obj.distanceY += dt * 0.5; // Speed
    }

    // Basic Collision & Scoring logic would go here
    objects.removeWhere((obj) => obj.distanceY > 1.2); // Remove off-screen
    notifyListeners();
  }

  // The Magic: Translating game logic to Screen Pixels
  List<Map<String, dynamic>> getRenderData(double screenW, double screenH) {
    List<Map<String, dynamic>> renderData =[];
    
    // Render Obstacles/Points
    for (var obj in objects) {
      renderData.add(_project(obj.lane, obj.distanceY, screenW, screenH, obj.isPoint ? 0xFF00FF00 : 0xFFFF0000));
    }
    
    // Render Player (Distance = 1.0)
    int playerColor = isJumping ? 0xFF00FFFF : (isSliding ? 0xFFFF00FF : 0xFF0000FF);
    renderData.add(_project(playerLane, 1.0, screenW, screenH, playerColor));
    
    return renderData;
  }

  // Projects mathematical game coordinates to Screen Pixels
  Map<String, dynamic> _project(int lane, double distance, double screenW, double screenH, int color) {
    double x, y, w, h;

    if (!is3D) {
      // Standard Top-Down 2D 
      double laneWidth = screenW / 5;
      w = laneWidth * 0.8;
      h = 50.0;
      x = (lane + 2) * laneWidth + (laneWidth * 0.1); // center in lane
      y = distance * screenH;
    } else {
      // Pseudo-3D Perspective!
      // 'distance' 0 = horizon, 1 = bottom screen
      double z = 1.0 - distance + 0.1; // Prevent div by 0. z gets smaller as it gets closer
      
      double horizonY = screenH * 0.3; 
      y = horizonY + (distance * screenH * 0.7) / z;
      
      double centerX = screenW / 2;
      double projectedLaneOffset = (lane * 100) / z;
      x = centerX + projectedLaneOffset - (50 / z); // center object
      
      w = 100 / z;
      h = 100 / z;
    }

    return {'x': x, 'y': y, 'w': w, 'h': h, 'color': color};
  }
}
