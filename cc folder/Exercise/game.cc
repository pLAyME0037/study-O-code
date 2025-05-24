#include <iostream>
#include <string>
#include <vector>

struct Room {
    std::string name;
    std::string description;
    std::vector<std::string> items;
    std::vector<std::pair<std::string, int>> exits; // Direction, Room index
};

struct Player {
    int currentRoom;
    std::vector<std::string> inventory;
};

void displayRoom(const Room& room) {
    std::cout << "\n--- " << room.name << " ---\n";
    std::cout << room.description << "\n";

    if (!room.items.empty()) {
        std::cout << "Items here: ";
        for (const auto& item : room.items) {
            std::cout << item << ", ";
        }
        std::cout << "\n";
    }

    std::cout << "Exits: ";
    for (const auto& exit : room.exits) {
        std::cout << exit.first << ", ";
    }
    std::cout << "\n";
}

int main() {
    // Game Setup
    std::vector<Room> rooms = {
        {"Starting Room", "A dimly lit room with a door to the north.", {"key"}, {{"north", 1}}},
        {"Second Room", "A larger room with a chest. A door to the south.", {"chest"}, {{"south", 0}}}
    };

    Player player = {0, {}}; // Start in the first room

    // Game Loop
    while (true) {
        displayRoom(rooms[player.currentRoom]);

        std::cout << "What do you want to do? (e.g., go north, take key, quit): ";
        std::string command;
        std::getline(std::cin, command);

        // Process Command (Very basic example)
        if (command == "go north") {
            for(const auto& exit : rooms[player.currentRoom].exits){
                if(exit.first == "north"){
                    player.currentRoom = exit.second;
                    break;
                }
            }
        } else if (command == "go south") {
            for(const auto& exit : rooms[player.currentRoom].exits){
                if(exit.first == "south"){
                    player.currentRoom = exit.second;
                    break;
                }
            }
        } else if (command == "take key") {
            if (player.currentRoom == 0) {
                player.inventory.push_back("key");
                rooms[0].items.clear(); // Remove the key from the room
                std::cout << "You took the key.\n";
            }
        } else if (command == "quit") {
            break;
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}