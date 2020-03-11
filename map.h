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


template <class K, class V>
class map
{
private:
	BST<pair<K, V>>* bst;

public:
	//DEFAULT CONSTRUCTOR
	map()
	{
		bst = NULL;
	}

	//COPY CONSTRUCTOR
	map(const map <K, V>& rhs) { bst = rhs.bst; };

	//DESTRUCTOR
	~map()
	{
		clear();
	}

	//ASSIGNMENT OPERATOR
	map& operator = (const map <K, V>& rhs);

	//STANDARD CONTAINER INTERFACES
	int size() { return bst.size(); }
	bool empty() { return bst.empty(); }
	void clear() { bst.clear(); }

	//SPECIFIC CONTAINER INTERFACES
	void insert(const pair <K, V>& input);
	void insert(const K& k, const V& v);
	map& operator [] (const K& k);
	map &operator [] (const K& k) const;

	//ITERATOR CLASS FOR MAP
	class iterator;
	iterator find(K k);
	iterator begin();
	iterator end();


};

/*************************************************************************
* INSERT
**************************************************************************/
template<class K, class V>
void insert(const pair<K, V>& input)
{
	map<K, V>::iterator it = bst.find(input);

	if (it != NULL)
	{
		*it = input;
	}
	else
	{
		bst.insert(input);
	}
} // namespace custom




#endif //MAP_H