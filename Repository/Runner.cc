#include <iostream>
#include "VectorImplementation.hpp" 

int main() {
     Vector<int> v(4532);
    for(int i = 0; i < 11; i++){
        v.push_back(i*10);
    }
    v.print();
    v.rangeErase(1, 4);
    v.print();
    return 0;
}