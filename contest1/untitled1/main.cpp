#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::string str, out, reverse;
    std::vector<char> vec;
    std::getline(std::cin, out);
    str = "";
    for (long unsigned int i=0; i < out.length(); i++){
        if (out[i] != ' '){
            str += out[i];
        }
    }
    reverse = str;
    std::reverse(str.begin(), str.end());
    if (reverse == str){
    std::cout << "yes" << std::endl;
    }else{std::cout << "no" << std::endl;}

    return 0;
}
