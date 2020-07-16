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
    cout << "main" << endl;


    return 0;
}
//end main******************************************************************************//
