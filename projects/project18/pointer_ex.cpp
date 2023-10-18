#include <iostream>

int main() {

    // pointers = variable that stores a memory address of another variable
    //                    sometimes it's easier to work with an address         

    // & address-of operator
    // * dereference operator

    std::string name = "Bro";
    int age = 21;
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    
    std::string *pName = &name;
    int *pAge = &age;
    std::string *pFreePizzas = freePizzas;

    std::cout << *pName << '\n';
    std::cout << *pAge << '\n';

    std::string *pPizza = pFreePizzas; 

    while (pPizza < (pFreePizzas + 5)) {  // Loop while the pointer is within the bounds of the array
        std::cout << *pPizza << '\n';
        pPizza++;  // Move the pointer to the next element
    }
    

    return 0;
}