#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "cPFile.cpp"
#include "mPUtil.cpp"

//prototypes
int testCPFile();
void testCFiles();

using std::cout;
using std::endl;

//main***********************************************************************************//
int main() 
{
    testCPFile();
    testCPFiles();  
    return 0;
}

int testCPFile()
{
    cPFile myObj;  // Create an object of MyClass

    // Access attributes and set values
    myObj.lineCount = 15; 
    myObj.filePath = "Some path";

    // Print attribute values
    cout << myObj.lineCount << endl;
    cout << myObj.filePath << endl;
    return 0;
   
}

void testCPFiles()
{
    std::vector<std::string> files;
    files.push_back("/home/geo/source/parascan/main.cpp");
    files.push_back("/home/geo/source/parascan/test.cpp");

    std::vector<cPFile> cpfs = cPFiles(files);

    for(auto & cf : cpfs)
    {
        cout << cf.filePath << endl;
        cout << "line count: " << cf.lineCount << endl;
    }
    return;


}