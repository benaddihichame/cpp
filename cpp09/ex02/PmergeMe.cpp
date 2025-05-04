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
const std::vector<int> &PmergeMe::getVector()const{return this->veve;}
const std::deque<int> &PmergeMe::getDeque()const{return this->dede;}


void PmergeMe::displayTime()const
{
    std::cout << "Time to process a range of " << veve.size() << " elements with std::vector is " << vecTime  << "us" << std::endl;
    std::cout << "Time to process a range of " << dede.size() << " elements with std::deque is " << deqTime << "us" << std::endl;
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
    
    std::vector<std::pair<int, int> >pairs;
    bool hasOdd = box.size() % 2 != 0; 
    int oddElements = 0;
        
    for (size_t i = 0; i < box.size() - (hasOdd ? 1 : 0); i += 2)
    {
        int a = box[i];
        int b = box[i + 1];

        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (hasOdd)
        oddElements = box[box.size() - 1];
    
    Container sorted;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        sorted.push_back(pairs[i].first);
    }

    FordJohnsonSort(sorted);

    Container result;
    result.push_back(sorted[0]);

    if (pairs[0].second < sorted[0])
        result.insert(result.begin(), pairs[0].second);
    else
        result.push_back(pairs[0].second);

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);

    size_t i = 2;
    while (jacobsthal.back() < pairs.size())
    {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
        i++;
    }

    std::vector<size_t> insertionOrder;

    for (size_t j = 0; j < jacobsthal.size() - 1 ; j++)
    {
        for(size_t k = jacobsthal[j]; k < jacobsthal[j + 1] && k < pairs.size(); k++)
        {
            insertionOrder.push_back(k);
        }
    }

    for (size_t j = 0; j < insertionOrder.size(); j++)
    {
        size_t idx = insertionOrder[j];
        if (idx >= pairs.size())
            continue;

        int elem = pairs[idx].second;

        size_t left = 0;
        size_t right = result.size();

        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < elem)
                left = mid + 1;
            else
                right = mid;
        }

        result.insert(result.begin() + left, elem);
    }

    if (hasOdd)
    {
        size_t left = 0;
        size_t right = result.size();

        while(left < right)
        {
            size_t mid = left + (right - left) / 2;
            if(result[mid] < oddElements)
                left = mid + 1;
            else
                right = mid;
        }

        result.insert(result.begin() + left , oddElements);
    }

    box = result;
}