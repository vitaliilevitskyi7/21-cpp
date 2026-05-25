#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> L = {10, 5, 3, 8, 15, 2, 12};
    int x = 7;

    std::cout << "Початковий список: ";
    for (int val : L) std::cout << val << " ";
    std::cout << "\n";

    // Розділення: спочатку ті, що не перевищують x
    std::stable_partition(L.begin(), L.end(), [x](int val) {
        return val <= x;
    });

    std::cout << "Після перестановки (X=" << x << "): ";
    for (int val : L) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
