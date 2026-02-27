import 'package:flutter/material.dart';


class NestedScreen extends StatelessWidget {
  const NestedScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Sequential Screens Demo',
      home: const HomeScreen(),
    );
  }
}

/// ---------------------------
/// Home
/// ---------------------------
class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Home')),
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (_) => const Screen1()),
            );
          },
          child: const Text('Start → Go to Screen 1'),
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
    return _ScaffoldStep(
      title: 'Screen 1',
      content: 'You are on Screen 1',
      nextLabel: 'Next → Screen 2',
      onNext: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (_) => const Screen2()),
        );
      },
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
    return _ScaffoldStep(
      title: 'Screen 2',
      content: 'You are on Screen 2',
      nextLabel: 'Next → Screen 3',
      onNext: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (_) => const Screen3()),
        );
      },
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
    return _ScaffoldStep(
      title: 'Screen 3',
      content: 'You are on Screen 3',
      nextLabel: 'Next → Screen 4',
      onNext: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (_) => const Screen4()),
        );
      },
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
    return _ScaffoldStep(
      title: 'Screen 4',
      content: 'You are on Screen 4',
      nextLabel: 'Next → Screen 5',
      onNext: () {
        Navigator.push(
          context,
          MaterialPageRoute(builder: (_) => const Screen5()),
        );
      },
    );
  }
}

/// ---------------------------
/// Screen 5 (Finish)
/// ---------------------------
class Screen5 extends StatelessWidget {
  const Screen5({super.key});

  @override
  Widget build(BuildContext context) {
    return _ScaffoldStep(
      title: 'Screen 5',
      content: 'You are on Screen 5',
      nextLabel: 'Finish → Back to Home',
      onNext: () {
        // ត្រឡប់ទៅ Home ដោយលុប Stack ទាំងអស់ក្រៅពី Home
        Navigator.popUntil(context, (route) => route.isFirst);
      },
    );
  }
}

/// ---------------------------
/// Reusable UI Scaffold for steps
/// ---------------------------
class _ScaffoldStep extends StatelessWidget {
  final String title;
  final String content;
  final String nextLabel;
  final VoidCallback onNext;

  const _ScaffoldStep({
    required this.title,
    required this.content,
    required this.nextLabel,
    required this.onNext,
  });

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
        // មាន Back default (arrow) ដើម្បីត្រឡប់ទៅមុន
      ),
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            Text(content, style: const TextStyle(fontSize: 20)),
            const SizedBox(height: 24),
            ElevatedButton(onPressed: onNext, child: Text(nextLabel)),
          ],
        ),
      ),
    );
  }
}
