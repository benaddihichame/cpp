#include "PmergeMe.hpp"

PmergeMe::PmergeMe():vecTime(0), deqTime(0){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &cpy): veve(cpy.veve), dede(cpy.dede), vecTime(cpy.vecTime), deqTime(cpy.deqTime)
{}
PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    if (this != &cpy)
    {
        veve = cpy.veve;
        dede = cpy.dede;
        vecTime = cpy.vecTime;
        deqTime = cpy.deqTime;
    }
    return *this;
}

PmergeMe::PmergeMe(std::vector<int> &num)
{
    for (size_t i = 0; i < num.size(); i++)
    {
        dede.push_back(num[i]);
        veve.push_back(num[i]);
    }
}
//     GETTER 
const std::vector<int> &PmergeMe::getVector()const
{
    return this->veve;
}

const std::deque<int> &PmergeMe::getDeque()const
{
    return this->dede;
}

void PmergeMe::displayTime()const
{
    std::cout << GREEN <<  "Time to process a range of " << veve.size() << " elements with std::vector is " << vecTime  << " us" << RESET << std::endl;
    std::cout << RED << "Time to process a range of " << dede.size() << " elements with std::deque is " << deqTime << " us" << RESET << std::endl;
}

void PmergeMe::sortVector()
{
    sort(veve, vecTime);
}
void PmergeMe::sortDeque()
{
    sort(dede, deqTime);
}

template<typename Container>
void PmergeMe::sort(Container &box, double &time)
{
    clock_t start = clock();
    FordJohnsonSort(box);
    clock_t end = clock();
    time = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}


template<typename Container>
void PmergeMe::FordJohnsonSort(Container &box)
{
    if (box.size() <= 1)
        return;
    

    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = box.size() % 2 != 0;
    int oddElement = 0;
    

    for (size_t i = 0; i < box.size() - (hasOdd ? 1 : 0); i += 2) {
        int a = box[i];
        int b = box[i + 1];
        
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    

    if (hasOdd)
        oddElement = box.back();
    

    Container largeElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largeElements.push_back(pairs[i].first);
    }

    FordJohnsonSort(largeElements);
    
    Container result;
    

    result.push_back(largeElements[0]);
    

    if (pairs[0].second < largeElements[0])
        result.insert(result.begin(), pairs[0].second);
    else
        result.push_back(pairs[0].second);
    

    for (size_t i = 1; i < largeElements.size(); i++) {

        size_t pos = 0;
        while (pos < result.size() && result[pos] < largeElements[i]) {
            pos++;
        }
        

        result.insert(result.begin() + pos, largeElements[i]);
    }
    

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1); 
    
    size_t prev = 1;
    size_t curr = 3;
    
    jacobsthal.push_back(curr);
    
    while (curr < pairs.size()) {
        size_t next = curr + 2 * prev;
        jacobsthal.push_back(next);
        prev = curr;
        curr = next;
    }
    

    std::vector<size_t> insertionOrder;
    

    for (size_t i = 0; i < jacobsthal.size(); i++) 
    {
        size_t jIdx = jacobsthal[i];
        
        for (size_t k = (i == 0 ? 1 : jacobsthal[i-1] + 1); k <= jIdx && k < pairs.size(); k++) {
            insertionOrder.push_back(k);
        }
    }
    
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t idx = insertionOrder[i];
        if (idx >= pairs.size())
            continue;
        
        int element = pairs[idx].second;
        
        size_t left = 0;
        size_t right = result.size();
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < element)
                left = mid + 1;
            else
                right = mid;
        }
        
        result.insert(result.begin() + left, element);
    }
    
   
    if (hasOdd) {
        size_t left = 0;
        size_t right = result.size();
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < oddElement)
                left = mid + 1;
            else
                right = mid;
        }
        
        result.insert(result.begin() + left, oddElement);
    }
    box = result;
}