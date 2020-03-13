/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    Adam Goff, Aaron Rook, Martin Melerio, Tanner Stratford, Allan Marina
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include "map.h"
#include "pair.h"

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/

void wordCount();
bool readFile(map <string, int> & counts, const string & fileName);

#endif // WORD_COUNT_H

