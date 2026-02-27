import 'package:flutter/material.dart';
import 'package:my_app_1/src/button_nav_demo.dart';
import 'package:my_app_1/src/counter_app.dart';
import 'package:my_app_1/src/event_app.dart';
import 'package:my_app_1/src/multi_screen_app.dart';
import 'package:my_app_1/src/views/alert_dialog.dart';
import 'package:my_app_1/src/views/bottom_text.dart';
import 'package:my_app_1/src/views/card_demo.dart';
import 'package:my_app_1/src/views/drawer.dart';
import 'package:my_app_1/src/views/list_title_demo.dart';
import 'package:my_app_1/src/views/nested_screen.dart';
import 'package:my_app_1/src/views/nested_scroll.dart';
import 'package:my_app_1/src/views/show_dialoag.dart';
import 'package:my_app_1/src/views/show_material_banner.dart';
import 'package:my_app_1/src/views/show_model_bottom_sheet.dart';
import 'package:my_app_1/src/views/snack_bar_demo.dart';
import 'package:my_app_1/src/views/structure_flutter_for_scaffold.dart';
import 'package:my_app_1/src/views/toast_message.dart';

void main() {
    runApp(const MaterialApp(home: MainLauncher()));
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
            _buildLauncherButton(context, 'Nested Screen App', const NestedScreen()),
            _buildLauncherButton(context, 'Bottom Text', const BottomText()),
            _buildLauncherButton(context, 'Card Demo', const CardApp()),
            _buildLauncherButton(context, 'Alert Dialog Demo', AlertDialogDemo()),
            _buildLauncherButton(context, 'Snack Bar Demo', SnackBarDemo()),
            _buildLauncherButton(context, 'List Tile Demo', ListTitleDemo()),
            _buildLauncherButton(context, 'Nested Scroll', NestedScrollDemo()),
            _buildLauncherButton(context, 'Toast App', ToastApp()),
            _buildLauncherButton(context, 'Dialog App', DialogApp()),
            _buildLauncherButton(context, 'Banner App', BannerApp()),
            _buildLauncherButton(context, 'Banner Bottom Sheet', BottomSheetApp()),
            _buildLauncherButton(context, 'Flutter Scaffold Structure', FlutterScaffoldStructure()),
            _buildLauncherButton(context, 'Drawer Demo', DrawerDemo()),
        ]));
    }

    Widget _buildLauncherButton(BuildContext context, String title, Widget target) {
        return Card(child: ListTile(title: Text(title),
        trailing: const Icon(Icons.arrow_forward_ios),
        onTap: () {
            Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => target),
            );
        }));
    }
}

