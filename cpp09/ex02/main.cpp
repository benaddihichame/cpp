#include "PmergeMe.hpp"
#include <cstdlib>
#include <sstream>
#include <climits>
bool isInteger(const std::string &str)
{
    if (str.empty())
        return false;

    size_t start = 0;
    if (str[0] == '+')
        start = 1;

    for (size_t i = start; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }

    if (str.length() - start > 10)
        return false;
    
    if (str.length() - start == 10) {
        if (str.compare(start, std::string::npos, "2147483647") > 0)
            return false;
    }

    return true;
}


int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: No numbers provided." << std::endl;
        return 1;
    }
    
    std::vector<int> numbers;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (!isInteger(arg)) {
            std::cerr << "Error: Invalid input '" << arg << "'. Only integers are allowed." << std::endl;
            return 1;
        }
        
        int num;
        std::istringstream iss(arg);
        iss >> num;
        
        if (num < 0) {
            std::cerr << "Error: Negative number '" << num << "' detected. Only positive integers are allowed." << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }
    
    PmergeMe sorter(numbers);
    
    std::cout << "Before: ";
    sorter.display(sorter.getVector());
    
    sorter.sortVector();
    sorter.sortDeque();
    
    std::cout << "After: ";
    sorter.display(sorter.getVector());
    
    sorter.displayTime();
    
    return 0;
}
