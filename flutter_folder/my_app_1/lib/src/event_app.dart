import 'package:flutter/material.dart';

class EventApp1 extends StatelessWidget {
    const EventApp1({super.key});
  
    @override
    Widget build(BuildContext context) {
        return Scaffold(
            appBar: AppBar(title: const Text('1) ElevatedButton onPressed')),
            body: Center(
              child: Builder(
                builder: (ctx) => ElevatedButton(
                  onPressed: () {
                    // show message on screen
                    ScaffoldMessenger.of(ctx).showSnackBar(
                      const SnackBar(content: Text('✅ Button Pressed!')));
                  },
                  child: const Text('Click Me')))),
            floatingActionButton: FloatingActionButton(
                onPressed: () => Navigator.of(context, rootNavigator: true).pop(),
                child: const Icon(Icons.home)));
    }
}
