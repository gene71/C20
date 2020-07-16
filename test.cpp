#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "cPFile.cpp"
#include "mPUtil.cpp"

//prototypes
int testCPFile();
void testCPFiles();
void testGetRecurseFile();
void testGetCodeFiles();

using std::cout;
using std::endl;
using std::vector;
using std::string;

//main***********************************************************************************//
int main() 
{
    //testCPFile();
    //testCPFiles();
    //testGetRecurseFile();
    testGetCodeFiles();  
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

//this test also tests getFiles_recursive
void testCPFiles()
{
    vector<cPFile> cpfs = cPFiles(getFiles_recursive("/home/geo/source/parascan"));

    for(auto & cf : cpfs)
    {
        cout << cf.filePath << endl;
        cout << "line count: " << cf.lineCount << endl;
    }
    return;


}
//tested by testCPFiles()
void testGetRecurseFile()
{
    for(auto & f : getFiles_recursive("/home/geo/source/parascan"))
    {
        cout << f << endl;
    }

    return;
}

void testGetCodeFiles()
{
    vector<string> codeFiles = getCodeFiles(getFiles_recursive("/home/geo/source/parascan"));

    for(auto & cf : codeFiles)
    {
        cout << cf << endl;
    }

    
}