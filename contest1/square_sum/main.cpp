#include <iostream>

int main() {
    unsigned long n;
    unsigned long sum = 0;
    std::cin >> n;
    for (unsigned long i = 1; i <= n; i++) {
        sum += (i * i);
    }
    std::cout << sum << std::endl;
    return 0;
}
