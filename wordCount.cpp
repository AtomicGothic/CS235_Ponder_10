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
using namespace std;
//void readFile(map <string, Count> & counts, const string & fileName,);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
    string filename = promptFile();
    cout >> "What word whose frequency is to be found. Type ! when done" << endl;
    map<string,int> counts;
    while (cin != "!") {
        string word;
        cin >> word;
        readFile(counts,filename,word);
    }

}

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

string promptFile() {
    cout << "What is the filename to be counted? ";
    string filename;
    cin >> filename;

    return filename;
}
