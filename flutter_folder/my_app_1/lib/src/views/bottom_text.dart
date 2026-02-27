import 'package:flutter/material.dart';

class BottomText extends StatelessWidget {
  const BottomText({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'BottomSheet Demo', // ចំណងជើង
      theme: ThemeData(primarySwatch: Colors.blue), // Theme
      home: BottomSheetDemoPage(), // ទៅកាន់ទំព័រដែលបង្ហាញ BottomSheet
    );
  }
}

// UI Page មាន Button ក៏បង្ហាញ BottomSheet
class BottomSheetDemoPage extends StatelessWidget {
  const BottomSheetDemoPage({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('BottomSheet Demo'), // Title នៅ AppBar
        centerTitle: true,
      ),
      body: Center(
        child: ElevatedButton(
          child: Text('បង្ហាញ Bottom Sheet'),
          onPressed: () {
            // បង្ហាញ BottomSheet ពេលចុច
            showModalBottomSheet(
              context: context,
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.vertical(top: Radius.circular(20)), // បន្ថែម Corners
              ),
              builder: (context) {
                return Container(
                  padding: EdgeInsets.all(20), // Padding ខាងក្នុង
                  height: 250, // កំណត់កម្ពស់
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'ជម្រើស',
                        style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                      ),
                      Divider(),
                      ListTile(
                        leading: Icon(Icons.photo),
                        title: Text('ជ្រើសរូបភាពពី Gallery'),
                        onTap: () {
                          Navigator.pop(context); // បិទ BottomSheet
                        },
                      ),
                      ListTile(
                        leading: Icon(Icons.camera_alt),
                        title: Text('ថតរូបដោយ Camera'),
                        onTap: () {
                          Navigator.pop(context);
                        },
                      ),
                    ],
                  ),
                );
              },
            );
          },
        ),
      ),
    );
  }
}
class MyApp2 extends StatelessWidget {
  const MyApp2({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'BottomSheet Demo', // ចំណងជើង
      theme: ThemeData(primarySwatch: Colors.blue), // Theme
      home: BottomSheetDemoPage(), // ទៅកាន់ទំព័រដែលបង្ហាញ BottomSheet
    );
  }
}

// UI Page មាន Button ក៏បង្ហាញ BottomSheet
class BottomSheetDemoPage2 extends StatelessWidget {
  const BottomSheetDemoPage2({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('BottomSheet Demo'), // Title នៅ AppBar
        centerTitle: true,
      ),
      body: Center(
        child: ElevatedButton(
          child: Text('បង្ហាញ Bottom Sheet'),
          onPressed: () {
            // បង្ហាញ BottomSheet ពេលចុច
            showModalBottomSheet(
              context: context,
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.vertical(top: Radius.circular(20)), // បន្ថែម Corners
              ),
              builder: (context) {
                return Container(
                  padding: EdgeInsets.all(20), // Padding ខាងក្នុង
                  height: 250, // កំណត់កម្ពស់
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'ជម្រើស',
                        style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                      ),
                      Divider(),
                      ListTile(
                        leading: Icon(Icons.photo),
                        title: Text('ជ្រើសរូបភាពពី Gallery'),
                        onTap: () {
                          Navigator.pop(context); // បិទ BottomSheet
                        },
                      ),
                      ListTile(
                        leading: Icon(Icons.camera_alt),
                        title: Text('ថតរូបដោយ Camera'),
                        onTap: () {
                          Navigator.pop(context);
                        },
                      ),
                    ],
                  ),
                );
              },
            );
          },
        ),
      ),
    );
  }
}
