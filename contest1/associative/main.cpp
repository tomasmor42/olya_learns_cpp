#include <iostream>


int main() {
    int n;
    std::cin >> n;
    int matrix[n][n];
    std::string in;

    for(int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            std::cin >> matrix[j][i];
        }
    }
    for (int x=0; x < n; x++){
        for (int y=0; y < n; y++){
            for (int z=0; z < n; z++){

                if (matrix[matrix[x][y]][z] != matrix[x][matrix[y][z]]){
                    std::cout << "NO" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}
