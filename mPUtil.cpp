#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
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

//getCodeFile gets all the src files from the files vector and adds paths to the codeFile vector
// vector<string> getCodeFiles(vector<string> paths)
// {
//     vector<string> codeFiles;

//     for(auto & p : paths)
//     {
//         if(p.substr(p.find_last_of(".") + 1) == "java")
//         {
//           codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "cc")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "c")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "cpp")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "h")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "CC")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "C")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "CPP")
//         {
//             codeFiles.push_back(p);

//         }

//         if(p.substr(p.find_last_of(".") + 1) == "H")
//         {
//             codeFiles.push_back(p);

//         }

//     }//end for


//     return codeFiles;
// }

// void saveScanConfig(string config, string name)
// {
//   // open a file in write mode.
//    ofstream outfile;
//    outfile.open(name + ".dat");
//    // write inputted data into the file.
//    outfile << config << endl;
//
// }

// vector<string> getConfig(string configPath)
// {
//   string line;
//   vector<string> v;
//   // open a file in read mode.
//   ifstream infile;
//   infile.open(configPath);

//   // again read the data from the file and display it.
//   while(getline(infile, line))
//   { //read data from file object and put it into string.
//     v.push_back(line);
//   }

//   return v;

// }

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
