#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string s = "Hello, World!";
    
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::toupper(c);
    });

    std::cout << "Великі літери: " << s << "\n";
    return 0;
}
