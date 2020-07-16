#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//cPFiles gets a vector of CPFile by using paths from getFiles_recursive
vector<cPFile> cPFiles(std::vector<std::string> files)
{
    vector<cPFile> Pfiles;

    for(auto & f : files)
    {
        cPFile cpf;
        cpf.filePath = f;

        int numLines = 0;
        std::ifstream in(f);
        std::string unused;
        while ( std::getline(in, unused) )
        {
            ++numLines;
        }
        cpf.lineCount = numLines;
        Pfiles.push_back(cpf);
           


    }

    return Pfiles;
}

//getFiles_recursive gets all files from directory passed as argv[1] and adds paths to
//global vector files
vector<string> getFiles_recursive(const std::filesystem::path& path)
{
    std::vector<std::string> files;
    for(const auto& p: std::filesystem::recursive_directory_iterator(path))
    {
        if (!std::filesystem::is_directory(p))
        {
            files.push_back(p.path());
            
            
        }
    }
    return files;
}

//getCodeFile gets all the src files from the files vector and adds paths to the codeFile vector
vector<string> getCodeFiles(vector<string> paths)
{
    vector<string> codeFiles;

    for(auto & p : paths)
    {
        if(p.substr(p.find_last_of(".") + 1) == "java")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "cc")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "c")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "cpp")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "h")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "CC")
        {
            codeFiles.push_back(p);

        }
        
        if(p.substr(p.find_last_of(".") + 1) == "C")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "CPP")
        {
            codeFiles.push_back(p);

        }

        if(p.substr(p.find_last_of(".") + 1) == "H")
        {
            codeFiles.push_back(p);

        }

    }//end for


    return codeFiles;
}