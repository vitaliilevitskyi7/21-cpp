#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

template <typename T>
struct Sum {
    T total = T();
    void operator()(const T& val) {
        total += val;
    }
};

int main() {
    std::vector<double> vec = {1.5, 2.5, 3.5};
    
    Sum<double> s = std::for_each(vec.begin(), vec.end(), Sum<double>());
    
    std::cout << "Сума елементів: " << s.total << "\n";
    return 0;
}
