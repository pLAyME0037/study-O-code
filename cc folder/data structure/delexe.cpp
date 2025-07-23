#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  try {
    fs::path current_dir = fs::current_path();
    int deleted_count = 0;

    // Get the path of the running executable
    fs::path exe_path = fs::absolute(fs::path(argv[0]));

    for (const auto& entry : fs::directory_iterator(current_dir)) {
      if (entry.is_regular_file() && entry.path().extension() == ".exe") {
        // Skip deleting the running executable itself
        if (fs::equivalent(entry.path(), exe_path)) {
          continue;
        }
        std::cout << "Deleting: " << entry.path().filename() << std::endl;
        fs::remove(entry.path());
        ++deleted_count;
      }
    }

    std::cout << "Deleted " << deleted_count << " .exe files." << std::endl;
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}