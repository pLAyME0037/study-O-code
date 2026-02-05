#include <windows.h>
#include <iostream>
#include <string>
#include <winreg.h> // For registry functions
#include <shlobj.h> // For SHChangeNotify
#include <cstdio>   // For swprintf

// Function to set the desktop icon size by modifying the registry
bool SetDesktopIconSize(DWORD newSize) {
    HKEY hKey;
    LONG result;
    bool success = false;
    wchar_t subKey[256];
    const WCHAR* valueName = L"IconSize";

    // The desktop view settings are stored in a numbered "Bag" key that can change.
    // We will loop through a few common bag numbers to find the right one.
    for (int i = 0; i < 10; ++i) {
        swprintf(subKey, 256, L"SOFTWARE\\Microsoft\\Windows\\Shell\\Bags\\%d\\Desktop", i);

        // Try to open the key
        result = RegOpenKeyExW(HKEY_CURRENT_USER, subKey, 0, KEY_SET_VALUE, &hKey);

        if (result == ERROR_SUCCESS) {
            // Key found, now set the IconSize value
            result = RegSetValueExW(hKey, valueName, 0, REG_DWORD, (const BYTE*)&newSize, sizeof(newSize));

            if (result == ERROR_SUCCESS) {
                std::wcout << L"Successfully set IconSize to " << newSize << L" in registry key: " << subKey << std::endl;
                success = true;
            } else {
                std::wcerr << L"Found key, but failed to set IconSize value. RegSetValueExW Error: " << result << std::endl;
            }
            RegCloseKey(hKey);
            
            // If we successfully set the value, we can exit the loop.
            if (success) {
                break; 
            }
        }
    }

    if (!success) {
        std::wcerr << L"Could not find the desktop settings registry key. This method may not work on your version of Windows." << std::endl;
    }

    // Notify the shell that settings have changed to refresh the desktop
    if (success) {
        SHChangeNotify(SHCNE_ALLEVENTS, SHCNF_FLUSH, NULL, NULL);
        std::cout << "Desktop refresh notification sent. If icons do not update, try pressing F5 on the desktop or restarting explorer.exe." << std::endl;
    }

    return success;
}

void ShowMenu() {
    std::cout << "\n--- Desktop Icon Size Changer ---" << std::endl;
    std::cout << "1. Set a custom icon size" << std::endl;
    std::cout << "2. Restore default icon size (32)" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    DWORD desiredIconSize;

    while (true) {
        ShowMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\nEnter desired icon size (typically between 16 and 256): ";
                std::cin >> desiredIconSize;
                if (std::cin.fail() || desiredIconSize < 16 || desiredIconSize > 256) {
                    std::cerr << "Invalid size. Please enter a number between 16 and 256." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                } else {
                    if (SetDesktopIconSize(desiredIconSize)) {
                        std::cout << "Desktop icon size change initiated successfully." << std::endl;
                    } else {
                        std::cerr << "Failed to change desktop icon size. Your system may not be supported." << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "\nRestoring default icon size (32)..." << std::endl;
                if (SetDesktopIconSize(32)) {
                    std::cout << "Default icon size restored successfully." << std::endl;
                } else {
                    std::cerr << "Failed to restore default icon size." << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cerr << "Invalid choice. Please select 1, 2, or 3." << std::endl;
                break;
        }
    }

    return 0;
}

// for compiler
// g++ iconSize.cpp -o iconSize -luser32 -lshlwapi -ladvapi32; .\iconSize
