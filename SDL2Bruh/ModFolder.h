#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

#define PATH std::filesystem::current_path()


//directory paths for mods
static std::vector<std::string> gathered_dirs;
static std::vector<std::string> gathered_dirs_filenames;


namespace ModFolder
{
	//get all directories with MOD_ in their name and add them to gathered dirs
	void GatherModDirectories();
	void CoutDirectories();
}