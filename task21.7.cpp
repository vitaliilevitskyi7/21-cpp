#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word = "abc";
    
    // Для повної генерації рядок має бути відсортований
    std::sort(word.begin(), word.end());

    std::cout << "Анаграми слова " << word << ":\n";
    do {
        std::cout << word << "\n";
    } while (std::next_permutation(word.begin(), word.end()));

    return 0;
}
