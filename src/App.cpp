/*
 ** App.cpp
 **
 ** Made by Antoine Buchser
 ** Login   <buchse_a@epitech.eu>
 **
 ** Started on February 6, 2015, 10:53 AM Antoine Buchser
 ** Updated on February 6, 2015, 10:53 AM Antoine Buchser
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "App.hpp"

App::App(int ac, char** av)
	: _ac(ac), _av(av)
{

}

App::~App()
{
}

int	App::run()
{
std::ifstream					ofs;
std::vector<std::string> 		vector;
std::string 					save;
int								i;

i = 1;
if (_ac < 2)
{
	while (save != ";;")
	{
		std::cin >> save;
		vector.push_back(save);
	}
	if (save == ";;")
		Parser(vector);
}
else
{
	while (i < _ac)
		{
		ofs.open(_av[i]);
		if (ofs.is_open())
			{
			for(std::string line; getline(ofs, line);)
				vector.push_back(line);
			Parser(vector);
			ofs.close();
			}
		i++;
		}
}
return (0);
}
