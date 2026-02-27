import 'package:flutter/material.dart';

class NestedScrollDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'NestedScrollView Demo',
      theme: ThemeData(primarySwatch: Colors.deepPurple),
      home: NestedScrollPage(),
    );
  }
}

// Main Page with NestedScrollView
class NestedScrollPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: NestedScrollView(
        headerSliverBuilder: (context, innerBoxIsScrolled) {
          return [
            SliverAppBar(
              expandedHeight: 200.0, // បន្ដទំហំ AppBar
              floating: false,
              pinned: true, // AppBar ខាងលើនៅតែជាប់
              flexibleSpace: FlexibleSpaceBar(
                title: Text("Nested Scroll View"),
                background: Image.network(
                  "https://storage.googleapis.com/cms-storage-bucket/stable-and-reliable.3461c6a5b33c339001c5.jpg",
                  fit: BoxFit.cover,
                ),
              ),
            )
          ];
        },
        body: ListView.builder(
          itemCount: 30, // ចំនួន Item
          itemBuilder: (context, index) => ListTile(
            title: Text('Item ${index + 1}'),
            leading: Icon(Icons.check_circle_outline),
          ),
        ),
      ),
    );
  }
}
