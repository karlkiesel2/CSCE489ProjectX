#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> lines;
    std::string input;

    std::cout << "Enter lines of text. Type 'print' to display all entries.\n";

    while (true) {
        std::getline(std::cin, input);

        if (input == "print") {
            std::cout << "Stored lines:\n";
            for (const auto& line : lines) {
                std::cout << line << std::endl;
            }
            break;
        }

        lines.push_back(input);
    }

    return 0;
}
