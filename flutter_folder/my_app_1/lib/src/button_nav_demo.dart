import 'package:flutter/material.dart';

class BottomNavDemo extends StatefulWidget {
  const BottomNavDemo({super.key});

  @override
  State<BottomNavDemo> createState() => _BottomNavDemoState();
}

class _BottomNavDemoState extends State<BottomNavDemo> {
  int _index = 0;

  final _pages = const [
    Center(child: Text("Home Page")),
    Center(child: Text("Search Page")),
    Center(child: Text("Profile Page")),
    Center(child: Text("User Page")),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text("BottomNavigationBar"),
          centerTitle: true,
        ),
        body: _pages[_index],
        bottomNavigationBar: BottomNavigationBar(
          type: BottomNavigationBarType.fixed,
          selectedItemColor: Colors.blue,
          unselectedItemColor: Colors.grey,
          currentIndex: _index,
          onTap: (i) => setState(() => _index = i),
          items: const [
            BottomNavigationBarItem(icon: Icon(Icons.home), label: "Home"),
            BottomNavigationBarItem(icon: Icon(Icons.search), label: "Search"),
            BottomNavigationBarItem(icon: Icon(Icons.person), label: "Profile"),
            BottomNavigationBarItem(icon: Icon(Icons.person), label: "User"),
          ],
        ),
        floatingActionButton: FloatingActionButton(
            backgroundColor: Colors.redAccent,
            onPressed: () => Navigator.of(context, rootNavigator: true).pop(),
            child: const Icon(Icons.home))
    );
  }
}

