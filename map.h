/***********************************************************************
* Component:
*    Assignment 10, Word Count
*    Brother JonesL, CS 235
* Author:
*    Adam Goff, Aaron Rook, Martin Melerio, Tanner Stratford, Allan Marina
* Summary:
*    Our Map Class
************************************************************************/

#ifndef MAP_H
#define MAP_H
#include "bst.h"
#include "pair.h"

namespace custom
{
template <class K, class V>
class map 
{
private:
	BST bst;

public:
	map()
	{
		bst = NULL;
	}

	~map()
	{
		clear();
	}

	int size() { return bst.size(); }
	bool empty() { return bst.empty(); }
	void clear() { bst.clear(); }


};

} // namespace custom




#endif //MAP_H