#include "threading.h"

#include <iostream>

using namespace moderncpp;
using namespace threading;

int main()
{
	asyncExample(5, 2);
	std::cin.get();
	return 0;
}