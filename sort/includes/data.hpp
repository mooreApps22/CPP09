#pragma once

typedef std::list<int>				List;	
typedef std::list<int>::iterator	ListIt;	
typedef std::deque<int>				Deque;
typedef std::deque<int>::iterator	DequeIt;

std::ostream&	operator<<(std::ostream& cout, List numbers);
std::ostream&	operator<<(std::ostream& cout, Deque numbers);
List			fillList(char **argv);
double			getTimeMicroseconds();
void			printTime(const std::string& name, double usec, size_t size);
