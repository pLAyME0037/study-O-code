
import 'package:flutter/material.dart';
// នាំចូល Flutter material package ដែលផ្តល់ UI Widgets ដូចជា MaterialApp, Scaffold, AppBar

class FlutterScaffoldStructure extends StatelessWidget {
  const FlutterScaffoldStructure({super.key});
  // Constructor (មាន super.key សម្រាប់ប្រើក្នុង widget tree)

  @override
  Widget build(BuildContext context) {
    // build() => function សម្រាប់សង់ UI

    return MaterialApp(
      debugShowCheckedModeBanner: false,

      // ដកស្លាក "debug" នៅខាងស្តាំលើ
      title: 'MaterialApp Demo',

      // ចំណងជើង app (ប្រើនៅពេល Android/iOS បង្ហាញ recent apps)
      theme: ThemeData(
        primarySwatch: Colors.blue,
        // កំណត់ theme ពណ៌សម្រាប់ app
      ),

      home: const HomePage(),
      // home = widget ដំបូង (root page) → ទៅកាន់ HomePage()
    );
  }
}

/// ---------------------------
/// Home Page
/// ---------------------------
class HomePage extends StatelessWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // Scaffold = ផ្តល់ផ្នែក UI ដូចជា AppBar, Body, Drawer, FloatingActionButton
      appBar: AppBar(
        title: const Text("Hello Flutter"),

        // AppBar មាន Title
        //centerTitle: true,

        // ដាក់ចំកណ្តាល
        //leading: const Icon(Icons.menu),
        //backgroundColor: Colors.blue, // ពណ៌ផ្ទៃខាងក្រោយ
        //elevation: 4, // Shadow

        // flexibleSpace: Container(
        //   // ផ្ទៃក្រោយមាន Gradient
        //   decoration: const BoxDecoration(
        //     gradient: LinearGradient(
        //       colors: [Colors.blue, Colors.purple],
        //       begin: Alignment.topLeft,
        //       end: Alignment.bottomRight,
        //     ),
        //   ),
        // ),
      ),

      body: const Center(
        // Body = ខ្លឹមសារ UI កណ្តាលអេក្រង់
        child: Text(
          "Welcome to Flutter",
          style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
        ),
      ),
    );
  }
}
