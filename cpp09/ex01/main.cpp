#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "You need only 2 args" << std::endl;
        return 1;
    }

    RPN calculator;
    std::string expression = argv[1];
    
    try {
        int result = calculator.doMath(expression);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}