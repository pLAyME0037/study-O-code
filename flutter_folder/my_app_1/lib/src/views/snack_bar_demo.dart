import 'package:flutter/material.dart';

class SnackBarDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'SnackBar Demo',
      home: SnackBarPage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class SnackBarPage extends StatelessWidget {
  void _showSnackBar(BuildContext context) {
    // Method បង្ហាញ SnackBar
    final snackBar = SnackBar(
      content: Text('This is a SnackBar!'), // Text message
      backgroundColor: Colors.teal, // ប្ដូរពណ៌ផ្ទៃក្រោយ
      duration: Duration(seconds: 3), // រយៈពេលបង្ហាញ
      action: SnackBarAction(
        label: 'UNDO', // Button UNDO
        textColor: Colors.white,
        onPressed: () {
          // Action បន្ទាប់ (អាច Undo ឬ Log)
          ScaffoldMessenger.of(context).showSnackBar(
            SnackBar(content: Text('Undo clicked!')),
          );
        },
      ),
    );

    // បង្ហាញ SnackBar
    ScaffoldMessenger.of(context).showSnackBar(snackBar);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('SnackBar Demo'),
        backgroundColor: Colors.teal,
      ),
      body: Center(
        child: ElevatedButton(
          child: Text('Show SnackBar'),
          onPressed: () => _showSnackBar(context), // ហៅ method បង្ហាញ
        ),
      ),
    );
  }
}
