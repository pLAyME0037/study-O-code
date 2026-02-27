import 'package:flutter/material.dart';

class CardApp extends StatelessWidget {
    const CardApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Card Widget Demo', // App Title
      theme: ThemeData(primarySwatch: Colors.teal), // Theme color
      home: CardDemoPage(), // ទៅកាន់ទំព័រដំបូង
    );
  }
}

// UI Page មាន Card
class CardDemoPage extends StatelessWidget {
    const CardDemoPage({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Card Widget Demo'), // Title នៅលើ AppBar
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0), // Padding ជុំវិញ
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [

            Text('Card with text only'),
            SizedBox(height: 10),
            Card( // Card មួយ
              elevation: 4, // Shadow depth
              child: Padding(
                padding: EdgeInsets.all(16),
                child: Text(
                  'This is a simple card with only text.',
                  style: TextStyle(fontSize: 16),
                ),
              ),
            ),

            SizedBox(height: 20),

            Text('Card with ListTile'),
            SizedBox(height: 10),
            Card(
              elevation: 4,
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(12), // រាងជុំមូល
              ),
              child: ListTile( // ListTile សម្រាប់ ListItem-style
                leading: Icon(Icons.account_circle, size: 40, color: Colors.teal),
                title: Text('Keo Tongheng'),
                subtitle: Text('Flutter Developer'),
                trailing: Icon(Icons.arrow_forward_ios),
                onTap: () {
                  // ការប្រតិបត្តិពេលចុច
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(content: Text('Clicked on card')),
                  );
                },
              ),
            ),

            SizedBox(height: 20),

            Text('Card with image and content'),
            SizedBox(height: 10),
            Card(
              elevation: 4,
              child: Column(
                children: [
                  Image.network(
                    'https://mir-s3-cdn-cf.behance.net/projects/404/59053c183008103.Y3JvcCwyNTU2LDIwMDAsMjIxLDA.jpg',
                    height: 150,
                    fit: BoxFit.cover,
                  ),
                  Padding(
                    padding: EdgeInsets.all(12),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text('Flutter Layouts',
                            style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                        SizedBox(height: 6),
                        Text('This card has image, title and description.'),
                      ],
                    ),
                  )
                ],
              ),
            ),

          ],
        ),
      ),
    );
  }
}
