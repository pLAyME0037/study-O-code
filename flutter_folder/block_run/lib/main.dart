import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';
import 'dart:io';
import 'database/database_helper.dart';
import 'package:go_router/go_router.dart';
import 'views/main_menu.dart';
import 'views/game_screen.dart';

void main() async {
    WidgetsFlutterBinding.ensureInitialized();

    if (Platform.isWindows || Platform.isLinux) {
        sqfliteFfiInit();
        databaseFactory = databaseFactoryFfi;
    }
    await DatabaseHelper.instance.database;
    runApp(const MyApp());
}

// Router Configuration
final GoRouter _router = GoRouter(
  initialLocation: '/',
  routes: [
    GoRoute(
      path: '/',
      builder: (context, state) => const MainMenu(),
    ),
    GoRoute(
      path: '/game',
      builder: (context, state) => const GameScreen(),
    ),
  ],
);

class MyApp extends StatelessWidget {
    const MyApp({super.key});

    // This widget is the root of your application.
    @override
    Widget build(BuildContext context) {
        String title = "Color Block Runner";
        String data = "Get Started";
        return MaterialApp.router(
            title: title,
            theme: ThemeData(brightness: Brightness.dark,
                             primarySwatch: Colors.blue),
            // theme: ThemeData(colorScheme: .fromSeed(seedColor: Colors.green),),
            // home: Scaffold(body: Center(child: Text(data),),),
            routerConfig: _router,);
    }
}

class MyHomePage extends StatefulWidget {
    const MyHomePage({super.key, required this.title});

    final String title;

    @override
    State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
    int _counter = 0;

    void _incrementCounter() {
        setState(() {
            _counter++;
        });
    }

    @override
    Widget build(BuildContext context) {
        return Scaffold(
            appBar: 
            AppBar(backgroundColor: Theme.of(context).colorScheme.inversePrimary,
                   title: Text(widget.title),),
            body: 
            Center(child: Column(mainAxisAlignment: .center,
                                 children: [
                                     const Text('You have pushed the button this many times:'),
                                     Text('$_counter',
                                          style: Theme.of(context).textTheme.headlineMedium,),
                                 ],),),
            floatingActionButton: 
            FloatingActionButton(onPressed: _incrementCounter,
                                 tooltip: 'Increment',
                                 child: const Icon(Icons.add),),);
    }
}
