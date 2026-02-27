import 'package:flutter/material.dart';

class BannerApp extends StatelessWidget {
  const BannerApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Banner Example',
      home: Scaffold(
        appBar: AppBar(title: const Text('4) Banner Message')),
        body: Builder(
          builder: (context) => Center(
            child: ElevatedButton(
              onPressed: () {
                ScaffoldMessenger.of(context).showMaterialBanner(
                  MaterialBanner(
                    content: const Text("This is a MaterialBanner"),
                    actions: [
                      TextButton(
                        onPressed: () {
                          ScaffoldMessenger.of(
                            context,
                          ).hideCurrentMaterialBanner();
                        },
                        child: const Text("DISMISS"),
                      ),
                    ],
                  ),
                );
              },
              child: const Text("Show Banner"),
            ),
          ),
        ),
      ),
    );
  }
}
