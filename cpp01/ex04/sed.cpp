#include "sed.hpp"

void	ft_replace(std::string &str, std::string const &src, std::string const &dst)
{
	if (src.empty())
		return ;
	
	std::string newString;
	size_t pos = 0;
	size_t srcLength = src.length();

	while ((pos = str.find(src, pos)) != std::string::npos)
	{
		newString.append(str, 0, pos);
		newString.append(dst);
		pos += srcLength;
		str.erase(0, pos);
		pos = 0;  
	}
	newString.append(str);
	str.swap(newString);
}
void	sed(char **av)
{
	std::string	line;
	std::ifstream infile(av[1]);
	std::ofstream outfile("output.txt");

	if (!infile)
	{
		std::cout << "Error to open the file\n";
		return ;
	}
	if (!outfile)
	{
		std::cout << "Error to put the output in the file\n";
		return ;
	}

	while (std::getline(infile, line))
	{
		ft_replace(line, av[2], av[3]);
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}