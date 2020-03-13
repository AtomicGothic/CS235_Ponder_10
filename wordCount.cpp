/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
//void readFile(map <string, Count> & counts, const string & fileName,);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/

void wordCount()
{
 
    //Declare an input variable
    string fileName;

    //Prompt for file
    cout << "What is the filename to be counted? ";
    //get file
    cin >> fileName;

    //declare input file stream variable
    ifstream fin;
    fin.open("fileName");
    //Check if file was able to open
    if (fin.fail())
    {
        //In case file does NOT open:
        cout << "Unable to open file " << fileName << endl;
    }

    map<string, int> count;
    int num;
    string key;
    while (fin >> key >> num)
    {
        count[key] = num;
    }


    //Close file
    fin.close();



    cout << "What word whose frquency is to be found. Type ! when done\n";
    //Note from Linux lab testBed:
    /*  There are 1345 words in this file, most of which have duplicates.
        This means there should be a few hundred nodes. The depth of the tree
        should be about 8. This means searching for a word should take, on average
        7 or 8 compares. That should be very fast. */
    map<string, int>::iterator it;
    for (it = count.begin(); it != count.end(); it++)
    {
        
    }







 /*   string filename = promptFile();
    cout >> "What word whose frequency is to be found. Type ! when done" << endl;
    map<string,int> counts;
    while (cin != "!") {
        string word;
        cin >> word;
        readFile(counts,filename,word);
    }
*/
}
/*
void readFile(map <string, Count> & counts, const string & filename, string word) {
    ifstream filestream;
    filestream.open(filename);
    // while we have input, either add the 
    string fileInput;
    while (filestream >> fileInput) {
        if (fileInput == word) {
            if (counts.find(word != NULL)) {
                counts.find(word).data++;
            }
            else {
                pair<string,int> initialCount = {word,1};
                counts.insert(intialCount);
            }
        }
    }

}
*/

/*string promptFile() {
    cout << "What is the filename to be counted? ";
    string filename;
    cin >> filename;

    return filename;
}
*/
