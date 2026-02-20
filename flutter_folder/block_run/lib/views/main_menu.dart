import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:sqflite/sqflite.dart'; // To get the path for debugging
import '../database/database_helper.dart';

class MainMenu extends StatefulWidget {
  const MainMenu({super.key});

  @override
  State<MainMenu> createState() => _MainMenuState();
}

class _MainMenuState extends State<MainMenu> {
  // Use a Future to load stats when the menu opens
  late Future<Map<String, int>> _statsFuture;

  @override
  void initState() {
    super.initState();
    _statsFuture = _loadStatsAndDebug();
  }

  Future<Map<String, int>> _loadStatsAndDebug() async {
    // 1. Force DB initialization
    final dbPath = await getDatabasesPath();
    print("--------------------------------------------------");
    print("📍 DATABASE LOCATED AT: $dbPath/game_scores.db");
    print("--------------------------------------------------");

    // 2. Fetch stats
    return await DatabaseHelper.instance.getBestStats();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFF222222), // Match C renderer background
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // Title
            const Text(
              "COLOR BLOCK RUNNER",
              style: TextStyle(
                fontSize: 40, 
                fontWeight: FontWeight.bold, 
                color: Colors.white,
                letterSpacing: 2.0,
              ),
            ),
            const SizedBox(height: 50),

            // Stats Card
            FutureBuilder<Map<String, int>>(
              future: _statsFuture,
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const CircularProgressIndicator();
                }

                final stats = snapshot.data ?? {'highest_score': 0, 'longest_time': 0};
                return Container(
                  padding: const EdgeInsets.all(20),
                  decoration: BoxDecoration(
                    color: Colors.white10,
                    borderRadius: BorderRadius.circular(10),
                    border: Border.all(color: Colors.cyanAccent),
                  ),
                  child: Column(
                    children: [
                      _statRow("High Score", "${stats['highest_score']} pts"),
                      const SizedBox(height: 10),
                      _statRow("Longest Run", "${stats['longest_time']} sec"),
                    ],
                  ),
                );
              },
            ),

            const SizedBox(height: 80),

            // Play Button
            ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.cyanAccent,
                padding: const EdgeInsets.symmetric(horizontal: 50, vertical: 20),
                foregroundColor: Colors.black,
              ),
              onPressed: () {
                // Use GoRouter to push the game screen
                context.push('/game'); 
              },
              child: const Text("START RUN", style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
            ),
          ],
        ),
      ),
    );
  }

  Widget _statRow(String label, String value) {
    return SizedBox(
      width: 200,
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(label, style: const TextStyle(color: Colors.grey)),
          Text(value, style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
        ],
      ),
    );
  }
}
