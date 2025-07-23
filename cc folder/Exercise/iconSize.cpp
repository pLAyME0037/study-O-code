#include <windows.h>
#include <iostream>
#include <string>
#include <winreg.h> // For registry functions
#include <shlobj.h> // For SHChangeNotify

// Function to set the desktop icon size
bool SetDesktopIconSize(DWORD newSize) {
    HKEY hKey;
    LONG result;
    bool success = false;

    // The registry path for desktop view settings can vary.
    // This is a common path, but you might need to find the correct "Bag" ID for some systems.
    const WCHAR* subKey = L"SOFTWARE\\Microsoft\\Windows\\Shell\\Bags\\1\\Desktop";
    const WCHAR* valueName = L"IconSize";

    // Open the registry key
    result = RegOpenKeyExW(HKEY_CURRENT_USER, subKey, 0, KEY_SET_VALUE, &hKey);

    if (result == ERROR_SUCCESS) {
        // Set the new IconSize value
        result = RegSetValueExW(hKey, valueName, 0, REG_DWORD, (const BYTE*)&newSize, sizeof(newSize));

        if (result == ERROR_SUCCESS) {
            std::wcout << L"Successfully set IconSize to " << newSize << L" in " << subKey << std::endl;
            success = true;
        } else {
            std::wcerr << L"Failed to set IconSize. RegSetValueExW Error: " << result << std::endl;
        }
        RegCloseKey(hKey);
    } else {
        std::wcerr << L"Failed to open registry key. RegOpenKeyExW Error: " << result << std::endl;
        // If Bag 1 doesn't exist, you might need to try Bag 0 or enumerate bags.
        // For simplicity, we'll just report failure here.
    }

    // Notify the shell about the change
    if (success) {
        // SHCNE_ASSOCCHANGED tells the shell to re-read settings related to file associations and shell views.
        // SHCNF_IDLIST | SHCNF_FLUSH ensures the change is applied immediately and propagated.
        SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST | SHCNF_FLUSH, NULL, NULL);
        std::cout << "Desktop refresh notification sent. Icons should update shortly." << std::endl;
    }

    return success;
}
int main() {
    ICONMETRICS iconMetrics = {0};
    iconMetrics.cbSize = sizeof(ICONMETRICS);

    // Get current icon metrics
    if (!SystemParametersInfo(SPI_GETICONMETRICS, sizeof(ICONMETRICS), &iconMetrics, 0)) {
        std::cerr << "Failed to get current icon metrics. Error: " << GetLastError() << std::endl;
        return 1;
    }

    std::cout << "Current icon label font height: " << iconMetrics.lfFont.lfHeight << std::endl;
    std::wcout << L"Current icon label font face: " << iconMetrics.lfFont.lfFaceName << std::endl;


    // --- Set desired icon label font size and other spacing settings ---
    // Change font height to a specific value (e.g., -15 for about 11pt, negative for character height)
    // Positive for cell height
    iconMetrics.lfFont.lfHeight = -13;
    
    // Optionally change font family or weight
    // wcscpy_s(iconMetrics.lfFont.lfFaceName, L"Segoe UI"); // Or your preferred font
    // iconMetrics.lfFont.lfWeight = FW_BOLD; // Make it bold

    // Set desired icon spacing (pixels)
    iconMetrics.iHorzSpacing = 16; // More horizontal space
    iconMetrics.iVertSpacing = 16; // More vertical space
    iconMetrics.iTitleWrap = 1;    // Enable title wrap (already common)

    // Change the actual icon size (system-wide)
    // 32 is default, 48 is large, 16 is small
    int newIconSize = 16; // Set your desired icon size here

    // Set large icon size
    if (!SystemParametersInfo(SPI_ICONHORIZONTALSPACING, 0, (PVOID)(intptr_t)newIconSize, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
        std::cerr << "Failed to set icon horizontal spacing. Error: " << GetLastError() << std::endl;
    }
    if (!SystemParametersInfo(SPI_ICONVERTICALSPACING, 0, (PVOID)(intptr_t)newIconSize, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
        std::cerr << "Failed to set icon vertical spacing. Error: " << GetLastError() << std::endl;
    }
    // Apply new icon metrics
    if (SystemParametersInfo(SPI_SETICONMETRICS, sizeof(ICONMETRICS), &iconMetrics, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
        std::cout << "Desktop icon spacing and label font updated. You may need to refresh the desktop (F5)." << std::endl;
    } else {
        std::cerr << "Failed to update icon metrics. Error: " << GetLastError() << std::endl;
    }

    // Example: Set desktop icons to 48x48 pixels (Large Icons equivalent)
    DWORD desiredIconSize = 16;

    if (SetDesktopIconSize(desiredIconSize)) {
        std::cout << "Desktop icon size change initiated." << std::endl;
    } else {
        std::cout << "Failed to change desktop icon size." << std::endl;
    }

    // You can also try other sizes:
    // SetDesktopIconSize(16); // Small
    // SetDesktopIconSize(32); // Medium
    // SetDesktopIconSize(256); // Extra Large (might scale down visually)
    return 0;
}
// for compiler
// g++ copilot.cpp -o copilot.exe -luser32 -lshlwapi -ladvapi32