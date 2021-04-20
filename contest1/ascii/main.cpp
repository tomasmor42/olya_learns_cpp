#include <iostream>

int main() {
    for(int i = 33; i <= 126; i++)
    {
        char c = (char)i;
        std::cout << c << " " << i << std::endl;
    }
    return 0;
}
