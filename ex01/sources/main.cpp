#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include "data.hpp"

typedef std::stack<char>		Stack;
typedef std::string::iterator	It;

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}

	std::string		input(argv[1]);
	Stack			stack;

	for (It it = input.begin(); it != input.end(); ++it) {
		char	ch = *it;
		stack.push(ch);
		std::cout << "Load: " << ch << std::endl;
	}

	while (!stack.empty())
	{
		char	ch = stack.top();
		stack.pop();
		std::cout << "Fire: " << ch << std::endl;
	}
	return (0);
}
