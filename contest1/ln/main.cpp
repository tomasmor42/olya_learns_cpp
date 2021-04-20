#include <iostream>

int main() {
    long int n;
    float res;
    res = 0;
    std::cin >> n;
    int _sing = 1;
    for (long int i=1; i <= n; i++){
        if (i % 2){
            _sing = 1;
        }
        else {
            _sing = -1;
        };
        res += _sing*(1./i);
    };
    std::cout << res << std::endl;
    return 0;
}
