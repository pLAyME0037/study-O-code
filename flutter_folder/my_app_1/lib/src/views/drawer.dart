import 'package:flutter/material.dart';

class DrawerDemo extends StatelessWidget {
  const DrawerDemo({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(title: const Text("Drawer Demo"), centerTitle: true),
        // Drawer ខាងឆ្វេង (hamburger icon បង្ហាញស្វ័យប្រវត្តិ)
        drawer: Drawer(
          child: ListView(
            padding: EdgeInsets.zero,
            children: [
              const DrawerHeader(
                decoration: BoxDecoration(color: Colors.blue),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: Text("Main Menu", style: TextStyle(color: Colors.white, fontSize: 22)),
                ),
              ),
              ListTile(leading: const Icon(Icons.home), title: const Text("Home"), onTap: () {}),
              ListTile(leading: const Icon(Icons.person), title: const Text("Profile"), onTap: () {}),
              ListTile(leading: const Icon(Icons.settings), title: const Text("Settings"), onTap: () {}),
            ],
          ),
        ),
        body: const Center(child: Text("Slide from left to open Drawer")),
      ),
    );
  }
}
