#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string alert1 = "info";
	std::string alert2 = "debug";
	std::string alert3 = "warning";
	std::string alert4 = "error";

	harl.complain(alert1);
	harl.complain(alert2);
	harl.complain(alert3);
	harl.complain(alert4);
}