#include <iostream>
#include "VectorImplementation.hpp" 
#include <string>

int main(){
     Vector<int> v(4532);
    for(int i = 0; i < 11; i++){
        v.push_back(i*10);
    }
    //v.print();
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
    
    /*Vector<int> v2;
    v2.push_back(200); "concatenar"
    v2.push_back(300);
    v2.print();
    v.append(v2); 
    v.print();*/ 
    /*Vector<int> tajada = v.slice(1, 4);  crear vector subconjunto
    tajada.print();*/ 
    
    /*Vector<int> copia;
    copia = v;
    copia.print();  "copia uno en otro nuevo"
    copia[0] = 999; //prueba de funcionamiento
    copia.print();
    v.print();*/
    
    /*bool any = v.any([](const int& x) { return x % 2 == 0; });
    cout<<any<<endl;*/

    /*bool minors = v.all([](const int& x) { return x < 101; });
    cout << minors << endl;*/

    /*bool negative = v.none([](const int& x) { return x < 0; });
    cout << negative << endl;*/

    /*Vector<int> mayores = v.filter([](const int& x) { 
        return x >40; 
    });
    mayores.print();*/
    
/*Vector<int> duplicados = v.map([](int x) { 
    return x * 2; 
}); 
duplicados.print(); */


/*Vector<std::string> etiquetas = v.map([](int x) {
    return (x % 2 == 0) ? std::string("par") : std::string("impar");
});
etiquetas.print(); NO FUNCIONAL*/

/*v.for_each([](int& x) { 
    x = x + 5; 
});

v.print();*/

for (int x : v) { 
    cout << x << " ";
}




    return 0;
}
