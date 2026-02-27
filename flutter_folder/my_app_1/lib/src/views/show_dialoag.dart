//   flutter_localizations:
//     sdk: flutter

// flutter clean
// flutter pub get

import 'package:flutter/material.dart';
import 'package:flutter_localizations/flutter_localizations.dart';

class DialogApp extends StatelessWidget {
  const DialogApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Dialog Example',

      localizationsDelegates: GlobalMaterialLocalizations.delegates,
      supportedLocales: const [Locale('en'), Locale('km')],


      home: Scaffold(
        appBar: AppBar(title: const Text('3) Dialog Message')),
        body: Builder(
          builder: (ctx) => Center(
            child: ElevatedButton(
              onPressed: () {
                showDialog(
                  context: ctx,
                  builder: (_) => AlertDialog(
                    title: const Text("Dialog Title"),
                    content: const Text("This is a dialog message"),
                    actions: [
                      TextButton(
                        onPressed: () => Navigator.of(ctx).pop(),
                        child: const Text("OK"),
                      ),
                    ],
                  ),
                );
              },
              child: const Text("Show Dialog"),
            ),
          ),
        ),
      ),
    );
  }
}
