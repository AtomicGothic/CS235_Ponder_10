/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Goff, Aaron Rook, Martin Melerio, Tanner Stratford, Allan Marina
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <fstream>
#include <string>
#include <iostream>

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/

void wordCount()
{
    map<string, int> mappedWords;

    //Prompt for file
    std::string fileName;
    std::cout << "What is the filename to be counted? ";
    
    //get file
    std::cin >> fileName;
    
    //Did we get and read the file?
    bool fileRead = readFile(mappedWords, fileName);

    if (fileRead)
    {
        std::cout << "What word whose frequency is to be found. Type ! when done\n";
        std::string userResponse;

        while (userResponse != "!")
        {
            std::cout << "> ";
            std::cin >> userResponse;

            if (userResponse != "!")
            {
                std::cout << "\t" << userResponse << " : " << mappedWords[userResponse] << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Error: Unable to open" << fileName << std::endl;
    }

}
   
bool readFile(map <string, int> & mappedWords, const std::string & fileName)
{
    ifstream fin;
    fin.open(fileName);
    if (fin.fail())
    {
        std::cout << "Error: Unable to open " << fileName << std::endl;
        fin.close();
        return false;
    }

    std::string word;
    while (!fin.eof() && fin >> word)
    {
        mappedWords[word]++;
    }

    fin.close();
    return true;
}


