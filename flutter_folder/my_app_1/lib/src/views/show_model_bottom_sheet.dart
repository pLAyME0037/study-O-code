//   flutter_localizations:
//     sdk: flutter

// flutter clean
// flutter pub get

import 'package:flutter/material.dart';
import 'package:flutter_localizations/flutter_localizations.dart';

class BottomSheetApp extends StatelessWidget {
  const BottomSheetApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'BottomSheet Example',

      localizationsDelegates: GlobalMaterialLocalizations.delegates,
      supportedLocales: const [
        Locale('en'), // English
        Locale('km'), // Khmer (strings fallback to en where missing)
      ],

      home: Scaffold(
        appBar: AppBar(title: const Text('5) BottomSheet Message')),
        body: Builder(

          builder: (ctx) => Center(
            child: ElevatedButton(
              onPressed: () {
                showModalBottomSheet(
                  context: ctx, // use ctx from Builder
                  builder: (context) => const Padding(
                    padding: EdgeInsets.all(16.0),
                    child: Text("This is a BottomSheet message"),
                  ),
                );
              },
              child: const Text("Show BottomSheet"),
            ),
          ),
        ),
      ),
    );
  }
}
