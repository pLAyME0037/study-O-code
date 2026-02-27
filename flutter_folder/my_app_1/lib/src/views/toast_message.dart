// dependencies:
//   fluttertoast: ^8.2.4
// flutter pub get

import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';

class ToastApp extends StatelessWidget {
  const ToastApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Toast Example',
      home: Scaffold(
        appBar: AppBar(title: const Text('2) Toast Message')),
        body: Center(
          child: ElevatedButton(
            onPressed: () {
              Fluttertoast.showToast(
                msg: "This is a Toast message",
                toastLength: Toast.LENGTH_SHORT,
                gravity: ToastGravity.BOTTOM);
            },
            child: const Text("Show Toast")))));
  }
}
