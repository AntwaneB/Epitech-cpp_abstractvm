#include <iostream>
#include "App.hpp"
#include "Exception.hpp"

int	main(int ac, char **av)
{
	App	app(ac, av);

	try
	{
		app.run();
	} catch (ExitException const & e)
	{
		return (0);
	}
	catch (Exception const & e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	return (0);
}
