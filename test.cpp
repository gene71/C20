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
void testSaveScanConfig();
void testGetTestDir();
void testInit();
void init();
void testGetConfigs();
void testSetV();

using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<string> v_allFiles;
vector<string> v_codeFileExt;
vector<string> v_filesToScan;
vector<string> config;

string configsDat = "/home/geo/source/parascan/dat/configs.dat";
string delimeter = ":";

//main***********************************************************************************//
int main()
{
   init();
   testInit();
  //testSetV();
  //testGetConfigs();
    //testCPFile();
    //testCPFiles();
    //testGetRecurseFile();
    //testGetCodeFiles();
    //testSaveScanConfig();
    //testGetTestDir();

    return 0;
}

void init()
{

  // read configs dat for scan directories and add file paths to allFiles std::vector<string> v;
  setv_AllFiles(configsDat, "scanDir", delimeter, v_allFiles);
  
  // get code file extensions from configs dat and add them to
  setv_codeExt(configsDat, "codeExt", delimeter, v_codeFileExt);
  
  // get code file paths from all files and add to files filesToScan std::vector<string> v;
  setv_filesToScan(v_allFiles, v_codeFileExt, v_filesToScan);
  

  return;


}//end init()

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

// void testGetCodeFiles()
// {
//     vector<string> codeFiles = getCodeFiles(getFiles_recursive("/home/geo/source/parascan"));

//     for(auto & cf : codeFiles)
//     {
//         cout << cf << endl;
//     }


// }

void testSaveScanConfig()
{
  string name = "testFile";
  string config = "LKJLKJLKJLKJLKJLKJJ<<<<<>>>>>>>";
  //saveScanConfig(config, name);

}

// void testGetTestDir()
// {
//   std::vector<string> v = getConfig("/home/geo/source/parascan/dat/config.dat");
//   for(auto & configs : v)
//   {
//     std::cout << configs << endl;
//   }

// }

void testInit()
{

  for(auto & dir : v_allFiles)
  {
    cout << "directories: " << dir << endl;
  }

  for(auto & ext : v_codeFileExt)
  {
    cout << "extensions to scan: " << ext << endl;
  }

  for(auto & f : v_filesToScan)
  {
    cout << "file to scan: " << f << endl;
  }

}

void testGetConfigs()
{
  string configPath = "/home/geo/source/parascan/dat/configs.dat";
  string key = "codeExt";
  string delimeter = ":";
  vector<string> v = getConfigs(configPath, key, delimeter);
  for(auto & c : v)
  {
    cout << c << endl;
  }
  return;
}

void testSetV()
{
  setv_AllFiles(configsDat, "scanDir", delimeter, v_allFiles);
  //setV(configsDat, "codeExt", delimeter, v_codeFileExt);
  for(auto & f : v_allFiles)
  {
    cout << f << endl;
  }

  // for(auto & ext : v_codeFileExt)
  // {
  //   cout << ext << endl;
  // }

}
