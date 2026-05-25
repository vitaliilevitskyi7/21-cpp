#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string sentence = "я люблю програмувати";
    std::stringstream ss(sentence);
    std::string word;
    std::vector<std::string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end());

    std::cout << "Перестановки слів у реченні:\n";
    do {
        for (const auto& w : words) std::cout << w << " ";
        std::cout << "\n";
    } while (std::next_permutation(words.begin(), words.end()));

    return 0;
}
