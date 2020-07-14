#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "cPFile.cpp"

using std::cout;
using std::endl;

//prototypes
void getFiles_recursive(const std::filesystem::path& path);
void getCodeFile(std::string path);

//globals
std::vector<std::string> files;
std::vector<std::string> codeFiles;

//main***********************************************************************************//
int main(int argc, char *argv[]) 
{
    // //TODO: make a command interputer
    getFiles_recursive(argv[1]);
    for(auto & i : files)
    {
        getCodeFile(i);
    }

    for(auto & f : codeFiles)
    {
        std::cout << f << std::endl;
    } 

    return 0;
}
//end main******************************************************************************//

//getFiles_recursive gets all files from directory passed as argv[1] and adds paths to
//global vector files
void getFiles_recursive(const std::filesystem::path& path)
{
    for(const auto& p: std::filesystem::recursive_directory_iterator(path))
    {
        if (!std::filesystem::is_directory(p))
        {
            files.push_back(p.path());
            
            
        }
    }
}

//getCodeFile gets all the src files from the files vector and adds paths to the codeFile vector
void getCodeFile(std::string path)
{
    if(path.substr(path.find_last_of(".") + 1) == "java")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "cc")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "c")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "cpp")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "h")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "CC")
    {
        codeFiles.push_back(path);

    }
    
    if(path.substr(path.find_last_of(".") + 1) == "C")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "CPP")
    {
        codeFiles.push_back(path);

    }

    if(path.substr(path.find_last_of(".") + 1) == "H")
    {
        codeFiles.push_back(path);

    }


}



