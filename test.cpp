//parascan
#include "globals.cpp"


//prototypes
void init();
int testCPFile();
void testCPFiles();
void testGetRecurseFile();
void testGetCodeFiles();
void testSaveScanConfig();
void testGetTestDir();
void testInit();
void testGetConfigs();
void testSetV();
void testGetSLOC();
void testStToChar();
void testGetCPIs();
// void testScan();


//main***********************************************************************************//
int main()
{
  
   //init();
   //testInit();
  //testSetV();
  //testGetConfigs();
    //testCPFile();
    //testCPFiles();
    //testGetRecurseFile();
    //testGetCodeFiles();
    //testSaveScanConfig();
    //testGetTestDir();
    //testGetSLOC();
    //testStToChar();
    testGetCPIs();
    //testScan();

    return 0;
}

void init()
{

  // read configs dat for scan directories and add file paths to allFiles std::vector<string> v;
  setv_AllFiles(configsDat, "scanDir", delimeter, v_allFiles);
  
  // get code file extensions from configs dat and add them to
  setv_codeExt(configsDat, "codeExt", delimeter, v_codeFileExt);

  // get scan from configs dat and add them to v_scanconfigs.  use the same method for code extenstions since only variables changes for this call
  setv_codeExt(configsDat, "scanConfig", delimeter, v_scanconfigs);

  
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

void testSaveScanConfig()
{
  string name = "testFile";
  string config = "LKJLKJLKJLKJLKJLKJJ<<<<<>>>>>>>";
  //saveScanConfig(config, name);

}

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
  
  for(auto & f : v_allFiles)
  {
    cout << f << endl;
  }

  
}

void testGetSLOC()
{
  init();
  cout << "Total Files: " << v_filesToScan.size() << endl;
  cout << "Total SLOC: " << getTotalSLOC(v_filesToScan) << endl;
}

void testStToChar()
{
  // string str = "a string";
  // for(int i = 0; i < str.size(); i++)
  // {
  //   cout<< str[i] << endl;
  // }
  // local vars
  string filepath = configsDat;
  int i = 1;
  string line;
  ifstream infile;

  // open a file in read mode.
  infile.open(filepath);
  // read the data from the file
  while(getline(infile, line))
  {
    for(int i = 0; i < line.size(); i++)
    {
      if(line[i] == 'c')
      {
        cout << "found " << line[i] <<  " found delim " << line[i+7] << endl; 
      }
    }
    
  }




   
}

void testGetCPIs()
{
  init();
  for(auto & f : v_filesToScan)
  {
    getIndicators("memcpy", f, v_cpis);
  }

  for(auto & cpi : v_cpis)
  {
    //cout << cpi.linetext << "found in: " << cpi.filePath << " at line: " << cpi.linenumber << endl;
    cout << cpi.linetext << endl;
    cout << "found at line: " << cpi.linenumber << " in file: " << cpi.filePath << endl;;
  }

  
}

