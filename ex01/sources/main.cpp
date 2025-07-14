#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include "data.hpp"

typedef std::stack<int, std::vector<int> >	Stack;
typedef std::string::iterator				It;

bool	isValidPush(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isValidSymbol(const std::string& c)
{
	return (c == "+" || c == "-" || c == "*" || c == "/");
}

int	calculate(int x, int y, const std::string& symbol)
{
	if (symbol == "+")
		return x + y;
	if (symbol == "-")
		return x - y;
	if (symbol == "*")
		return x * y;
	if (symbol == "/")
	{
		if (y == 0)
			throw std::runtime_error("Can't divide by 0");
		return x / y;
	}
	throw std::runtime_error("Unknown symbol");
}

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}

	std::istringstream		stream(argv[1]);
	std::string				token;
	Stack					numbers;

	try
	{
		while (stream >> token)
		{
			if (token.size() == 1 && std::isdigit(token[0]))
				numbers.push(token[0] - '0');
			else if (isValidSymbol(token))
			{
				if (numbers.size() < 2)
					throw std::runtime_error("not enough numbers");
				int x = numbers.top();
				numbers.pop();
				int y = numbers.top();
				numbers.pop();
				int result = calculate(x, y, token);
				numbers.push(result);
			}
		}

		std::cout << numbers.top() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (2);
	}
	return (0);
}
