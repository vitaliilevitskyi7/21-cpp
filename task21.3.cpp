#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// а) Сума k найбільших чисел
double sum_k_largest(std::vector<double> vec, size_t k) {
    if (k > vec.size()) return 0.0;
    std::nth_element(vec.begin(), vec.begin() + k, vec.end(), std::greater<double>());
    return std::accumulate(vec.begin(), vec.begin() + k, 0.0);
}

// б) Масив k найменших чисел
std::vector<double> get_k_smallest(std::vector<double> vec, size_t k) {
    if (k > vec.size()) return std::vector<double>(); // Порожній масив
    std::nth_element(vec.begin(), vec.begin() + k, vec.end());
    return std::vector<double>(vec.begin(), vec.begin() + k);
}

int main() {
    std::vector<double> data = {4.5, 1.2, 8.9, 3.3, 5.5};
    std::cout << "Сума 2 найбільших: " << sum_k_largest(data, 2) << "\n";

    auto smallest = get_k_smallest(data, 2);
    std::cout << "2 найменших: ";
    for (double v : smallest) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
