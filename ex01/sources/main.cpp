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

bool	isArithmeticOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	runCalculation(int result, int num, char symbol)
{
	switch (symbol)
	{
		case '+':
			return result + num;
		case '-':
			return result - num;
		case '*':
			return result * num;
		case '/':
		{
			if (num == 0)
			{
				std::cerr << "Error " <<  symbol << std::endl;
				return (0);
			}
			return result / num;
		}
		default:
		{
			std::cerr << "Error " <<  symbol << std::endl;
			return (0);
		}
	}
}

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return (1);
	}

	std::string		input(argv[1]);
	Stack			numbers;
	int				result = 0;

	for (It it = input.begin(); it != input.end(); ++it)
	{
		if (isValidPush(*it))
		{
			int num = *it - '0';
			numbers.push(num);
		// 	std::cout << "Load: " << *it << std::endl;
		}
		else if (isArithmeticOperator(*it))
		{
			while (!numbers.empty())
			{	
				int num = numbers.top();

			//	std::cout << "Fire: " << num << std::endl;
				result = runCalculation(result, num, *it);
				numbers.pop();
			}
		}
		else if ( *it == ' ')
			continue ;
		else
		{
			std::cerr << "Error" << std::endl;
			break ;
		}			
	}

	std::cout << result << std::endl;

	return (0);
}
