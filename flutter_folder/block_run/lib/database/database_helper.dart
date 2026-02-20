import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import 'package:flutter/services.dart' show rootBundle;

class DatabaseHelper {
  static final DatabaseHelper instance = DatabaseHelper._init();
  static Database? _database;

  DatabaseHelper._init();

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDB('game_scores.db');
    return _database!;
  }

  Future<Database> _initDB(String filePath) async {
    final dbPath = await getDatabasesPath();
    final path = join(dbPath, filePath);

    return await openDatabase(
      path,
      version: 1,
      onCreate: _createDB,
    );
  }

  Future _createDB(Database db, int version) async {
    // Read the raw SQL migration from our assets
    String migration = await rootBundle.loadString('assets/migrations/0001_init.sql');
    await db.execute(migration);
  }

  Future<void> insertRun(int score, int durationSeconds) async {
    final db = await instance.database;
    await db.insert('runs', {
      'score': score,
      'duration_seconds': durationSeconds,
    });
  }

  Future<void> deleteMyDatabase() async {
    final dbPath = await getDatabasesPath();
    final path = join(dbPath, 'game_scores.db');
    await deleteDatabase(path);
  }
  Future<Map<String, int>> getBestStats() async {
    final db = await instance.database;
    final scoreResult = await db.rawQuery('SELECT MAX(score) as max_score FROM runs');
    final timeResult = await db.rawQuery('SELECT MAX(duration_seconds) as max_time FROM runs');
    
    return {
      'highest_score': (scoreResult.first as int?) ?? 0,
      'longest_time': (timeResult.first as int?) ?? 0,
    };
  }
}
