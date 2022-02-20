#include "ModFolder.h"
#include <iostream>
#include <string>

//gets all the MOD_ DIRECTORIES and stores them into path
void ModFolder::GatherModDirectories()
{
	gathered_dirs.clear();
	for (auto file : std::filesystem::directory_iterator(PATH))
	{
		std::string filepath_str = file.path().filename().string();
		if (std::filesystem::is_directory(file.path()))
		{
			if (filepath_str.find("MOD_") != std::string::npos)
			{
				gathered_dirs.push_back(file.path().string());
				gathered_dirs_filenames.push_back(filepath_str);
			}
		}
	}
}

//simply prints out all the strings to console
void ModFolder::CoutDirectories()
{
	for (int i = 0; i < gathered_dirs.size(); i++)
	{
		std::cout << gathered_dirs[i] << std::endl;
	}
	for (int i = 0; i < gathered_dirs_filenames.size(); i++)
	{
		std::cout << gathered_dirs_filenames[i] << std::endl;
	}

}