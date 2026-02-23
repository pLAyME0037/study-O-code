import 'dart:math';
import 'package:flutter/material.dart';

class GameObject {
    int lane; 
    double distanceY; // 0.0 (Horizon) -> 1.0 (Player)
    bool isPoint; 
    bool isCollected = false; 
    GameObject(this.lane, this.distanceY, this.isPoint);
}

class GameController extends ChangeNotifier {
    bool is3D = true;
    bool isGameOver = false;

    int playerLane = 0;
    bool isJumping = false;
    bool isSliding = false;

    int score = 0;
    double durationSeconds = 0;

    List<GameObject> objects = [];
    double _spawnTimer = 0.0;
    final Random _rng = Random();

    void moveLeft() { if (playerLane > -2) { playerLane--; notifyListeners(); }}
    void moveRight() { if (playerLane < 2) { playerLane++; notifyListeners(); }}
    void jump() {
        isJumping = true;
        notifyListeners();
        Future.delayed(const Duration(milliseconds: 500), () {
            isJumping = false;
            notifyListeners();
        });
    }
    void slide() { 
        isSliding = true;
        notifyListeners();
        Future.delayed(const Duration(milliseconds: 500), () { 
                isSliding = false;
                notifyListeners();
                });
    }

    void updateGame(double dt) {
        if (isGameOver) return;
        durationSeconds += dt;
        double speed = 0.3 + (durationSeconds * 0.005); 
        if (speed > 0.8) speed = 0.8; 

        // Move
        for (var obj in objects) { obj.distanceY += dt * speed; }
        objects.removeWhere((obj) => obj.distanceY > 1.2);

        // Spawn
        _spawnTimer -= dt * speed;
        if (_spawnTimer <= 0) {
            objects.add(GameObject(_rng.nextInt(5) - 2, 0.0, _rng.nextBool())); 
            _spawnTimer = 0.8; // Slower spawn for testing
        }

        notifyListeners();
    }

    List<Map<String, dynamic>> getRenderData(double sw, double sh) {
        List<Map<String, dynamic>> data = [];

        // 1. Draw Objects (Sort by distance so far objects draw first)
        objects.sort((a, b) => a.distanceY.compareTo(b.distanceY));

        for (var obj in objects) {
            if (obj.isCollected) continue;
            data.add(_project(obj.lane, obj.distanceY, sw, sh, obj.isPoint ? 0xFF00FF00 : 0xFFFF0000));
        }

        // 2. Draw Player (MANUALLY ADDED AT END)
        // Cyan color: 0xFF00FFFF. White: 0xFFFFFFFF.
        data.add(_project(playerLane, 1.0, sw, sh, 0xFFFFFFFF));

        return data;
    }

    Map<String, dynamic> _project(int lane, double distance, 
                                  double screenW, double screenH, 
                                  int color) {
        if (!is3D) {
            double laneWidth = screenW / 5;
            return {
                'x': (lane + 2) * laneWidth + (laneWidth * 0.1),
                'y': distance * (screenH * 0.8),
                'w': laneWidth * 0.8,
                'h': 40.0,
                'color': color
            };
        }

        // --- Better Pseudo-3D Math ---
        // distance 0.0 = horizon, 1.0 = player position

        // 1. Perspective factor (Z). Ensure it never hits 0.
        // Near objects (distance 1.0) have z = 1.0. Far objects (distance 0.0) have z = 0.1.
        double z = 0.1 + (distance * 0.9);

        // 2. Vertical position. Horizon is at 40% height.
        double horizonY = screenH * 0.4;
        double y = horizonY + (distance * screenH * 0.5);

        // 3. Horizontal position. 
        // Lanes converge at the center (screenW / 2) at the horizon.
        double centerX = screenW / 2;
        double x = centerX + (lane * 60 * z) - ( (40 * z) / 2 );

        // 4. Size scaling. Objects get smaller as they get further away.
        double w = 40 * z;
        double h = 30 * z;

        return {'x': x, 'y': y, 'w': w, 'h': h, 'color': color};
    } 
}
