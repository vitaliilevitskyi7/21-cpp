#include <iostream>
#include <vector>
#include <algorithm>

class BoolVector {
private:
    std::vector<bool> vec;

public:
    BoolVector(const std::vector<bool>& v) : vec(v) {}

    // Порозрядна кон'юнкція
    BoolVector operator&(const BoolVector& other) const {
        std::vector<bool> res(std::min(vec.size(), other.vec.size()));
        for (size_t i = 0; i < res.size(); ++i) {
            res[i] = vec[i] & other.vec[i];
        }
        return BoolVector(res);
    }

    // Порозрядна диз'юнкція
    BoolVector operator|(const BoolVector& other) const {
        std::vector<bool> res(std::min(vec.size(), other.vec.size()));
        for (size_t i = 0; i < res.size(); ++i) {
            res[i] = vec[i] | other.vec[i];
        }
        return BoolVector(res);
    }

    // Заперечення
    BoolVector operator~() const {
        std::vector<bool> res(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            res[i] = !vec[i];
        }
        return BoolVector(res);
    }

    void print_counts() const {
        long ones = std::count(vec.begin(), vec.end(), true);
        long zeros = vec.size() - ones;
        std::cout << "Одиниць: " << ones << ", Нулів: " << zeros << "\n";
    }
};

int main() {
    BoolVector bv1({{true, false, true, true}});
    BoolVector bv2({{false, true, true, false}});

    std::cout << "bv1 -> "; bv1.print_counts();
    std::cout << "bv1 & bv2 -> "; (bv1 & bv2).print_counts();
    std::cout << "~bv1 -> "; (~bv1).print_counts();

    return 0;
}
