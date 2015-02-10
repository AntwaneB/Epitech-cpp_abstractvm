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
#include "Parser.hpp"

App::App(int ac, char** av)
	: _ac(ac), _av(av)
{

}

App::~App()
{
}

int	App::run() const
{
	std::ifstream					ofs;
	std::vector<std::string> 	vector;
	std::string 					save;
	int								i;
	Parser							parser;

	i = 1;
	if (_ac < 2)
	{
		while (save != ";;" && (i == 1 || (save.size() && save.c_str()[0] != '\0')))
		{
			char tmp[500];
			std::cin.getline(tmp, 500, '\n');
			save = std::string(tmp);
			vector.push_back(save);
			i++;
		}
		if (save == ";;")
			parser.parse(vector);
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
				parser.parse(vector);
				ofs.close();
				}
			i++;
		}
	}
	return (0);
}
