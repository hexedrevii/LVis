#include <iostream>
#include <format>

#include <CLI/CLI.hpp>

int main(int argc, char** argv)
{
	CLI::App app("Visualise level XP");

	double gap = 2;
	CLI::Option* gap_opt = app.add_option("-g,--gap,/gap", gap, "Level Gap")->capture_default_str();

	double increase = 0.15;
	CLI::Option* increase_opt = app.add_option("-i,--increase,/increase", increase, "Level Increase")->capture_default_str();

	unsigned int levels = 0;
	CLI::Option* levels_opt = app.add_option("-l,--levels,/levels", levels, "Amount of levels to show.")->capture_default_str();

	unsigned int level = 0;
	CLI::Option* level_opt = app.add_option("-s,--level,/level", level, "Show a specific level.")->capture_default_str();

	CLI11_PARSE(app, argc, argv);
 
	if (levels <= 0 && level <= 0)
	{
		std::cerr << "Could not show: No level or levels specified." << std::endl;
		std::cerr << "Run with --help for more information." << std::endl;

		return 1;
	}

	if (level > 0)
	{
		int xp = (int)std::floor(std::pow((level / increase), gap));
		std::cout << "level " << level << ": " << xp << " XP" << std::endl;

		if (levels != 0)
		{
			std::cout << std::endl;
		}
	}

	if (levels > 0)
	{
		for (int i = 1; i <= levels; i++)
		{
			int xp = (int)std::floor(std::pow((i / increase), gap));
			std::cout << "level " << i << ": " << xp << " XP" << std::endl;
		}
	}
}
