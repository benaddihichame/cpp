#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <limits>


class PmergeMe
{
    private:
        std::vector<int> veve;
        std::deque<int> dede;
        double vecTime;
        double deqTime;

        template<typename Container>
        void sort(Container &box, double &time);

        template<typename Container>
        void FordJohnsonSort(Container &box);

    public:
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &cpy);
        PmergeMe(const PmergeMe &cpy);
        PmergeMe();
        PmergeMe(std::vector<int> &num);

        const std::vector<int> &getVector()const;
        const std::deque<int> &getDeque()const;

        void sortVector();
        void sortDeque();

        template<typename Container>
        void display(const Container &box)const;
        void displayTime()const;

};

template <typename Container>
void PmergeMe::display(const Container &box)const
{
    for(size_t i = 0; i < box.size(); i++)
    {
        std::cout << box[i];
        if (i != box.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}


#endif