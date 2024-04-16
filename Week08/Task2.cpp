#include<iostream>
#include "Cake.h"

int main()
{
    Cake firstCake(300, 200, 100);
    firstCake /= 16;
    std::cout << firstCake.getMaxSlices() << std::endl;;
    firstCake -= 3;
    std::cout << firstCake.getCurrentSlices()<<std::endl;
    firstCake +=2;
    std::cout << firstCake.getCurrentSlices()<<std::endl;
    firstCake /= 32;
    std::cout << firstCake.getCurrentSlices() << std::endl;

}