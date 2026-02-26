import 'package:flutter/material.dart';

class AppScreen extends StatelessWidget {
  const AppScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false, // remove "debug" banner
      title: 'Home Screen',
      home: const HomeScreen(),
    );
  }
}

/// ---------------------------
/// Home Screen
/// ---------------------------
class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Home Screen - Choose a Page')),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const Screen1()),
                );
              },
              child: const Text('Go to Screen 1'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const Screen2()),
                );
              },
              child: const Text('Go to Screen 2'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const Screen3()),
                );
              },
              child: const Text('Go to Screen 3'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const Screen4()),
                );
              },
              child: const Text('Go to Screen 4'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const Screen5()),
                );
              },
              child: const Text('Go to Screen 5'),
            ),
          ],
        ),
      ),
    );
  }
}

/// ---------------------------
/// Screen 1
/// ---------------------------
class Screen1 extends StatelessWidget {
  const Screen1({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Screen 1')),
      body: const Center(
        child: Text('Welcome to Screen 1', style: TextStyle(fontSize: 20)),
      ),
    );
  }
}

/// ---------------------------
/// Screen 2
/// ---------------------------
class Screen2 extends StatelessWidget {
  const Screen2({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Screen 2')),
      body: const Center(
        child: Text('Welcome to Screen 2', style: TextStyle(fontSize: 20)),
      ),
    );
  }
}

/// ---------------------------
/// Screen 3
/// ---------------------------
class Screen3 extends StatelessWidget {
  const Screen3({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Screen 3')),
      body: const Center(
        child: Text('Welcome to Screen 3', style: TextStyle(fontSize: 20)),
      ),
    );
  }
}

/// ---------------------------
/// Screen 4
/// ---------------------------
class Screen4 extends StatelessWidget {
  const Screen4({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Screen 4')),
      body: const Center(
        child: Text('Welcome to Screen 4', style: TextStyle(fontSize: 20)),
      ),
    );
  }
}

/// ---------------------------
/// Screen 5
/// ---------------------------
class Screen5 extends StatelessWidget {
  const Screen5({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Screen 5')),
      body: const Center(
        child: Text('Welcome to Screen 5', style: TextStyle(fontSize: 20)),
      ),
        floatingActionButton: FloatingActionButton(
            backgroundColor: Colors.redAccent,
            onPressed: () => Navigator.of(context, rootNavigator: true).pop(),
            child: const Icon(Icons.home))
    );
  }
}

