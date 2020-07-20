// #include <iostream>
// #include <filesystem>
// #include <vector>
// #include <string>

#include <fstream>

using namespace std;


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
// getConfigs ingests a file in key:value\n format and parses out value by removing key and delimeter from the line
vector<string> getConfigs(string configPath, string key, string delimeter)
{
  // local vars
  string line;
  vector<string> v;
  ifstream infile;

  // open a file in read mode.
  infile.open(configPath);

  // read the data from the file
  while(getline(infile, line))
  {
    // parse key line
    if(line.find(key) != std::string::npos)
    {
      size_t pos = 0;
      string token;
      //find position of delimeter to remove key and delimeter from line
      while((pos = line.find(delimeter) != string::npos))
      {
        token = line.substr(0, pos);
        // remove key and delimeter
        line.erase(0, pos + delimeter.length());
      }//end while pos

      // add value to vector
      v.push_back(line);
    }//end if found key

  }//end while getline

  return v;
}
// setv_AllFiles reads the configs.dat  to get all files from scan directories and add the paths to v_allFiles vector
void setv_AllFiles(string configsDat, string key, string delimeter, vector<string> &v)
{
  //cout << configsDat << " " << key << " " << delimeter << endl;
  // read configs dat for scan directories and add file paths to allFiles std::vector<string> v;
  for(auto & dir : getConfigs(configsDat, key, delimeter))
  {
    for(auto & f : getFiles_recursive(dir))
    {
            v.push_back(f);
    }
  }//end get all files
}
//setv_codeExt reads the configs.dat to get all code file extenstions and adds them to the v_codeExt vector
void setv_codeExt(string configsDat, string key, string delimeter, vector<string> &v)
{
  //cout << configsDat << " " << key << " " << delimeter << endl;
  // read configs dat for scan directories and add file paths to allFiles std::vector<string> v;
  for(auto & ext : getConfigs(configsDat, key, delimeter))
  {
    v.push_back(ext);    
  }//end get all files
  
}
//setv_filesToScan searches the v_allFiles vector using the file extensions in the v_codeExt vector to find and add code file paths to the v_filesToScanVector
void setv_filesToScan(vector<string> &v_aF, vector<string> &v_cFE, vector<string> &v_fTS)
{
  for(auto & f : v_aF)
  {
    for(auto & ext : v_cFE)
    {
      if(f.substr(f.find_last_of(".") + 1) == ext)
      {
        v_fTS.push_back(f);

      }
    }//end for ext
  }
    
}

int getSLOC(string filepath)
{
  // local vars
  int i = 1;
  string line;
  ifstream infile;

  // open a file in read mode.
  infile.open(filepath);
  // read the data from the file
  while(getline(infile, line))
  {
    i++;
  }
  
  return i;
}

int getTotalSLOC(vector<string> filepaths)
{
  int i = 0;
  for(auto & f : filepaths)
  {
    i+= getSLOC(f);
  }
  return i;
}

void getIndicators(string key, string filepath, vector<cPIndicator> &v_cpis)
{
  // string filepath = configsDat;
  string line;
  ifstream infile;
  int linecount = 1;
  //////cPIndicator cpi;

  // // open a file in read mode.
  infile.open(filepath);
  // // read the data from the file
  while(getline(infile, line))
  {
       
    // parse key line
    if(line.find(key) != std::string::npos)
    {
        
      cPIndicator cpi;
      cpi.filePath = filepath;
      cpi.indicator = key;
      cpi.linenumber = linecount;
      cpi.linetext = line;
      v_cpis.push_back(cpi);
    }
    linecount++;
        
  }//end while
  return;
}