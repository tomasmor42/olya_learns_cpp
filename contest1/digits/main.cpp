#include <iostream>

int main() {
    int n;
    int sum = 0;
    int digit;
    std::cin >> n;
    while (n != 0){
        digit = n % 10;
        n = n / 10;
        sum += digit;
    }
    std::cout << sum << std::endl;
    return 0;
}
