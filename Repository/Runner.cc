#include <iostream>
#include "VectorImplementation.hpp" 

int main(){
     Vector<int> v(4532);
    for(int i = 0; i < 11; i++){
        v.push_back(i*10);
    }
    v.print();
    //v.rangeErase(1, 4);
    //v.print();
    //v.Clear();
    //v.Contains(20);
    //v.Find(110);
    //v.replace(20, 99);
    //v.print();
    //v.push_back(20);
    //v.print();
    //v.remove_all(20);
    //v.replace_all(20,55);
    //v.print();
    //v.count(99);
    //v.indices_of(20);
    //v.swap(1,8);
    //v.print();
    //v.reverse();
    //v.print();
   // v.Simplerotate_left(2);
    //v.print();
    //v.rotate_left(2);
    //v.print();
    //v.rotate_right(2);
    //v.print();
    /*v.push_back(5); 
    v.push_back(1); 
    v.push_back(4); 
    v.push_back(2); 
    v.push_back(3);
    v.print();
    v.sort();
    v.print();*/
    


    
    return 0;
}