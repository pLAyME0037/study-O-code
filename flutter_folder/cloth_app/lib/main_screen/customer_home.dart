import 'package:flutter/material.dart';

  class CustomerHomeScreen extends StatelessWidget {
      const MyApp ({super.key});

      @override
      State<CustomerHomeScreen> createState() => _CustomerHomeScreenState();
  }

class _CustomerHomeScreenState extends State<CustomerHomeScreen> {
  @override
  Widget build(BuildContext context) {
    return Scaffold (
        bottomNavigationBar: BottomNavigationBar(items: [
            BottomNavigationBar(icon: Icon(Icons.home), label: "home");
            BottomNavigationBar(icon: Icon(Icons.search), label: "Categlory");
            BottomNavigationBar(icon: Icon(Icons.shop), label: "Story");
            BottomNavigationBar(icon: Icon(Icons.shopping_cart), label: "Cart");
            BottomNavigationBar(icon: Icon(Icons.home), label: "home");
        ],
        selectedItemColor: Colors.black));
  }
}
