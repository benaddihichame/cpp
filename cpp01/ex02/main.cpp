#include <iostream>

int main()
{
    std::string hi = "HI THIS IS BRAIN";
    std::string *stringPTR = &hi;
    std::string& stringREF = hi;

    std::cout << "Adresse de hi  =  "<< &hi << std::endl;
    std::cout << "Adresse de  stringPTR  =  " << &stringPTR << std::endl;
    std::cout << "Adresse de stringREF  =  " << &stringREF << std::endl;

    std::cout << "Valeur de hi  =  " << hi << std::endl;
    std::cout << "Valeur de stringPTR  =  "<< *stringPTR << std::endl;
    std::cout << "Valeur de stringREF  =  " << stringREF << std::endl;
}