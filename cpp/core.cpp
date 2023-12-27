#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

void trim(std::string& str) {
    // Trim leading whitespaces
    size_t start = str.find_first_not_of(" \t");
    if (start != std::string::npos) {
        // Trim trailing whitespaces
        size_t end = str.find_last_not_of(" \t");
        str = str.substr(start, end - start + 1);
    } else {
        // String is all whitespaces
        str.clear();
    }
}

int main() {
    std::ifstream inputFile("config_file.txt");
    std::unordered_map<std::string, std::variant<int, bool, std::string, std::unordered_map<std::string, std::string>>> configMap;
    std::string line;
    std::string currentSegment;

    while (std::getline(inputFile, line)) {
        trim(line);

        // Check if the line is not empty
        if (!line.empty()) {
            // Check if the line contains '='
            if (line.find('=') != std::string::npos) {
                std::istringstream iss(line);
                std::string key, rawValue;
                std::getline(iss, key, '=');
                std::getline(iss, rawValue);

                trim(key);
                trim(rawValue);

                // Convert raw value to appropriate type
                std::variant<int, bool, std::string> value;
                if (rawValue.front() == '"' && rawValue.back() == '"') {
                    value = rawValue.substr(1, rawValue.size() - 2);
                } else if (rawValue == "true" || rawValue == "false") {
                    value = rawValue == "true";
                } else if (std::all_of(rawValue.begin(), rawValue.end(), ::isdigit)) {
                    value = std::stoi(rawValue);
                } else {
                    value = rawValue;
                }

                if (!currentSegment.empty()) {
                    configMap[currentSegment][key] = value;
                } else {
                    configMap[key] = value;
                }
            } else {
                currentSegment = line;
                configMap[currentSegment] = {};
            }
        }
    }

    // Print the resulting configuration
    for (const auto& [key, value] : configMap) {
        if (std::holds_alternative<std::unordered_map<std::string, std::string>>(value)) {
            std::cout << key << ":\n";
            for (const auto& [subkey, subvalue] : std::get<std::unordered_map<std::string, std::string>>(value)) {
                std::cout << "  " << subkey << ": " << subvalue << "\n";
            }
        } else {
            std::cout << key << ": " << std::visit([](const auto& v) { return v; }, value) << "\n";
        }
    }

    return 0;
}

