#include <iostream>

int main()
{
    std::string hi = "HI THIS IS BRAIN";
    std::string *stringPTR = &hi;
    std::string& stringREF = hi;

    std::cout << "Adresse de hi  =  "<< &hi << std::endl;
    std::cout << "Adresse de  stringPTR  =  " << stringPTR << std::endl;
    std::cout << "Adresse de stringREF  =  " << &stringREF << std::endl;

    std::cout << "Valeur de hi  =  " << hi << std::endl;
    std::cout << "Valeur de stringPTR  =  "<< *stringPTR << std::endl;
    std::cout << "Valeur de stringREF  =  " << stringREF << std::endl;
}

/* 
 * The differences between pointers and refs :
 *
 *
 * 	Pointers:
 * 	1. pointers are nullable and reassignable.
 * 	2. Pointers can have arithmetic operations.
 * 	
 *
 * 	Refs: 
 * 	1. Are not nullable, they must always be init to refer to a valid object.
 * 	2. Are not reassignable, once a ref is init to an object, it cannot be changed to 		refer to another object.
 * 	3. Accessing the value referred to by a reference doesn't require any operator
 * 		like pointers we need to use * op.	
 * 	4. No arithmetic ops for refs.
 * 	
 *
 * 	*/