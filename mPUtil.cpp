#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include "cPFile.cpp"

using std::cout;
using std::endl;
using std::vector;

vector<cpFile> cPFiles(std::vector<std::string> files)
{
    vector<cpFile> Pfiles;

    for(auto & f : files)
    {
        cpFile cpf;
        cpf.filePath = f;

        int numLines = 0;
        std::ifstream in("file.txt");
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