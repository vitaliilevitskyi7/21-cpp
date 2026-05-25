#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Person {
    std::string surname;
    int age;
};

int main() {
    // Згенеруємо довільну кількість тестових людей за умовою
    std::vector<Person> army_list = {
        {"Іванов", 42},
        {"Петров", 20},
        {"Сидоров", 35},
        {"Васильєв", 19},
        {"Павлов", 28},
        {"Антонов", 45},
        {"Борисов", 28},
        {"Федоров", 31}
    };

    std::cout << "--- Початковий виборчий список служб ---\n";
    for (const auto& p : army_list) {
        std::cout << p.surname << " (" << p.age << " років)\n";
    }

    // 1. Розділяємо вектор на дві частини: ті, кому менше 35 років, йдуть на початок
    // Використовуємо stable_partition для збереження відносного початкового порядку
    auto partition_boundary = std::stable_partition(army_list.begin(), army_list.end(), [](const Person& p) {
        return p.age < 35;
    });

    // 2. Сортуємо першу частину (менше 35 років) від наймолодшого до найстаршого (за зростанням віку)
    std::sort(army_list.begin(), partition_boundary, [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    // 3. Сортуємо решту списку (35 років і більше) за прізвищем (в алфавітному порядку)
    std::sort(partition_boundary, army_list.end(), [](const Person& a, const Person& b) {
        return a.surname < b.surname;
    });

    // Виведення фінального результату
    std::cout << "\n--- Модифікований та впорядкований список ---\n";
    std::cout << "[ПРИЗОВНИКИ: Менше 35 років (від наймолодшого)]:\n";
    for (auto it = army_list.begin(); it != army_list.end(); ++it) {
        if (it == partition_boundary) {
            std::cout << "\n[РЕШТА СПИСКУ: 35 років і більше (за алфавітом)]:\n";
        }
        std::cout << " * " << it->surname << " - " << it->age << " років\n";
    }

    return 0;
}
