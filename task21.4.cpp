#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>

// Генератор поточного значення clock()
struct ClockGenerator {
    std::clock_t operator()() {
        return std::clock();
    }
};

int main() {
    std::list<std::clock_t> times(10);
    
    // Заповнення генератором
    std::generate_n(times.begin(), 10, ClockGenerator());

    // Видалення дублікатів через сортування
    times.sort();
    times.unique();

    std::cout << "Елементи списку (унікальні, відсортовані):\n";
    for (auto t : times) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    return 0;
}
