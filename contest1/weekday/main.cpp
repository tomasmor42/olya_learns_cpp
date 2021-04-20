#include <iostream>

int main() {
    int n;
    std::cin >> n;
    switch(n){
        case 1:
            std::cout << "mon" << std::endl;
            break;
        case 2:
            std::cout << "tue" << std::endl;
            break;
        case 3:
            std::cout << "wed" << std::endl;
            break;
        case 4:
            std::cout << "thu" << std::endl;
            break;
        case 5:
            std::cout << "fri" << std::endl;
            break;
        case 6:
            std::cout << "sat" << std::endl;
            break;
        case 7:
            std::cout << "sun" << std::endl;
    };
    return 0;
}
