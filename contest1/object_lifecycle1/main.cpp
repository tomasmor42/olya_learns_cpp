#include <iostream>
#include <list>
#include "c.h"
int main() {
    int n;
    std::cin >> n;
    std::list<C*> listOfClasses;

    for (int i=0; i < n; i++){
        C* c = new C;
        listOfClasses.push_back(c);

    }
    for(const auto& cl : listOfClasses)
    {
        delete cl;
    }

    return 0;
}
