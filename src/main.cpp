#include "UniquePtr.h"
#include <utility>
#include <iostream>

int main() {
    UniquePtr<int> ptr(new int(5));
    // they test all methods here...
    //UniquePtr<float> ptr2(std::move(ptr));
    //std::cout << ptr.operator bool() << std::endl;
    UniquePtr<int> uniquePtr1 = makeUnique<int>(5);
    auto uniquePtr2 = makeUnique<int>(5);
    return 0;
}
