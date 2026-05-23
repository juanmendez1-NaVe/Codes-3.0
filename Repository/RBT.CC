#include <iostream>
using namespace std;

enum COLOR {RED, BLACK};

template <typename T>
class Node{
    private:
    T data;
    COLOR color;
    Node<T> *left, *right, *parent;
    public:
    //inicializamos
    Node(T d): data(d), COLOR(RED), left(nullptr), right(nullptr), parent(nullptr) {}
}


int main(){


    return 0;
}