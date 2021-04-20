#include <iostream>

int hasCapitalLetters(std::string pwd){
    if (true)
    {
        int count = 0;
        for(int i = 65; i <= 90; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return 0;
        else {return 1;}

    }
}
int hasSmallLetters(std::string pwd){
    if (true)
    {
        int count = 0;
        for(int i = 97; i <= 122; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return 0;
        else {return 1;}

    }

}
int hasDigits(std::string pwd){
    if (true)
    {
        int count = 0;
        for(int i = 48; i <= 57; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return 0;
        else {return 1;}

    }
}
int hasOther(std::string pwd){
    if (true)
    {
        int count = 0;
        for(int i = 33; i <= 47; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        for(int i = 58; i <= 63; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        for(int i = 91; i <= 96; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;
        }
        for(int i = 123; i <= 126; i++)
        {
            char c = (char)i;
            std::string str1(1, c);

            if (pwd.find(str1) !=
                std::string::npos)
                count = 1;

        }

        if (count == 0)
            return 0;
        else {return 1;}

    }
}

int main() {
    std::string pwd;
    std::cin >> pwd;
    if (pwd.length() < 8 or pwd.length() > 13){
        std::cout << "NO" << std::endl;
        return 0;
    }
    for (long unsigned int i = 0; i < pwd.size(); i++)
    {
        if ((int)pwd[i] < 33 or (int)pwd[i] > 126){
            std::cout << "NO" << std::endl;
            return 0;
        }

    }
    if (hasCapitalLetters(pwd) + hasSmallLetters(pwd) + hasOther(pwd) + hasDigits(pwd) >= 3){
        std::cout << "YES" << std::endl;
        return 0;

    }
    std::cout << "NO" << std::endl;
    return 0;
}
