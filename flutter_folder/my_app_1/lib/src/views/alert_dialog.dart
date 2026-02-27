import 'package:flutter/material.dart';

class AlertDialogDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false, // hide debug banner
      title: 'AlertDialog Demo',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: HomePage(),
    );
  }
}

// Home Page
class HomePage extends StatelessWidget {
  // Function to show AlertDialog
  void _showMyDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: Text("Confirmation"),
          content: Text("Are you sure you want to continue?"),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop(); // close dialog
              },
              child: Text("Cancel"),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.of(context).pop(); // close dialog
                ScaffoldMessenger.of(context).showSnackBar(
                  SnackBar(content: Text("You clicked OK")),
                );
              },
              child: Text("OK"),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("AlertDialog Example"),
      ),
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            _showMyDialog(context); // show dialog
          },
          child: Text("Show AlertDialog"),
        ),
      ),
    );
  }
}
