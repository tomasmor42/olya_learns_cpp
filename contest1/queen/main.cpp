#include <iostream>

int main() {
    int a;
    int b;
    int c;
    int d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    if (a == c || b == d || a-c == b-d || c-a == d-b || -(a-c) == b-d || -(c-a) == d-b){
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }


    return 0;
}
