#include<iostream>

std::string findSum(std::string str2){
    std::string str1 = "1";
    std::string str = "";

    int n1 = 1, n2 = str2.length();

    std::reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    std::reverse(str.begin(), str.end());

    return str;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << findSum(str);
    return 0;
}