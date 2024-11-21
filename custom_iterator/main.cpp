#include <iostream>
#include <algorithm>

#include "Arr_Iterator.hpp"

int main() {

    Arr <int> arr1({1, 3, 6, 100, -1123});
    std::cout << "arr1:" << std::endl;
    arr1.print();
    
    Arr <int> arr2(7);
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = i;
    }

    std::cout << "arr2:" << std::endl;
    arr2.print();

    Arr <int> arr3(arr1);
    std::cout << "arr3:" << std::endl;
    arr3.print();

    std::cout << "arr1:" << std::endl;
    arr1.print();

    arr1 = arr2;
    arr2 = arr3;

    std::cout << "arr1:" << std::endl;
    arr1.print();

    std::cout << "arr2:" << std::endl;
    arr2.print();

    arr1.swap(arr2);

    std::cout << "arr1:" << std::endl;
    arr1.print();
    
    std::cout << "arr2:" << std::endl;
    arr2.print();

    return 0;
}
