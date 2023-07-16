#include <iostream>
#include "IntArray.h"
#include "MyException.h"
#include <limits.h>

int main()
{    
    const int size_1 = 100'000'000'000;
    const int size_2 = 10;
    const int size_3 = 5;

    IntArray array(size_1);                       //cheking Exception
    IntArray arr(10);                              
    IntArray array_1(size_2);   

    array_1.fill();

    arr.erase();
    arr.fill();                                    //cheking Exception
   
    IntArray array_2(array_1);
    
    array_1.resize(8);
    array_2.resize(-1);                            //cheking Exception
    
    array_1.insert(20, 5);
    array_2.insert(20, -1);                        //cheking Exception
    
    array_1.remove(3); 
    array_2.remove(-1);                            //cheking Exception
    
    array_1.insertAtEnd(30);
    array_1.insertAtBeginning(40);

    array_2.deleteAtBegin();   
    array_2.deleteAtEnd();   

    IntArray array_3(5);
    array_3 = array_1;
    
    std::cout << "\nArray 1: ";
    array_1.find(4);
    std::cout << "\nArray 1: ";
    array_1.find(20);

    std::cout << "\nArray 1: ";
    array_1.print();
    std::cout << "\nArray 2: ";
    array_2.print();
    std::cout << "\nArray 3: ";
    array_3.print();
    std::cout << '\n';

    return 0;
}