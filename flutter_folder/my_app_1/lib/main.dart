import 'package:flutter/material.dart';
import 'package:my_app_1/src/button_nav_demo.dart';
import 'package:my_app_1/src/counter_app.dart';
import 'package:my_app_1/src/event_app.dart';
import 'package:my_app_1/src/multi_screen_app.dart';

void main() {
    runApp(const MaterialApp(home: MainLauncher(),));
}

class MainLauncher extends StatelessWidget {
                const MainLauncher({super.key});

    @override
    Widget build(BuildContext context) {
        return Scaffold(appBar: AppBar(title: const Text('Main Launcher')),
        body: ListView(padding: const EdgeInsets.all(16),
        children: [
            _buildLauncherButton(context, 'Counter App', const MyApp()),
            _buildLauncherButton(context, 'Button Nav Demo', const BottomNavDemo()),
            _buildLauncherButton(context, 'Event App 1', const EventApp1()),
            _buildLauncherButton(context, 'Multi Screen App', const AppScreen()),
        ],),);
    }

    Widget _buildLauncherButton(BuildContext context, String title, Widget target) {
        return Card(child: ListTile(title: Text(title),
        trailing: const Icon(Icons.arrow_forward_ios),
        onTap: () {
            Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => target),
            );
        }),);
    }
}

