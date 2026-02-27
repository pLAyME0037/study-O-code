import 'package:flutter/material.dart';

class ListTitleDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'ListTile Demo',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: ListTileDemoPage(),
    );
  }
}

// Main Page
class ListTileDemoPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('ListTile Demo'),
        centerTitle: true,
      ),
      body: ListView(
        children: [
          ListTile(
            leading: Icon(Icons.account_circle, color: Colors.blue),
            title: Text('John Doe'), // Title
            subtitle: Text('Software Developer'), // Subtitle
            trailing: Icon(Icons.phone), // Icon on right
            onTap: () {
              print("Tapped John Doe");
            },
          ),
          Divider(),

          ListTile(
            leading: CircleAvatar(
              backgroundColor: Colors.green,
              child: Text('A'),
            ),
            title: Text('Alice'),
            subtitle: Text('UI/UX Designer'),
            trailing: Icon(Icons.email),
            onTap: () {
              print("Tapped Alice");
            },
          ),
          Divider(),

          ListTile(
            leading: Icon(Icons.settings, color: Colors.grey),
            title: Text('Settings'),
            onTap: () {
              print("Tapped Settings");
            },
          ),
        ],
      ),
    );
  }
}

