#include <iostream>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
void    to_upper(char *str)
{
    int i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }

}
int main(int ac, char **av)
{
    int i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (i < ac)
         {
            to_upper(av[i]);
            std::cout << av[i];
            i++; 
         }
    }
    std::cout << std::endl;
    return (0);
}