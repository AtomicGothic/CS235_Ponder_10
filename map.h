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
using namespace std;
using namespace custom;

namespace custom
{
	template <class K, class V>
	class map
	{
	public:
		// Iterator
		class iterator
		{

		private:

			// Need to put typename so the compiler knows that this is a type and not a static member of BST
			typename BST < pair <K, V> > ::iterator it;

		public:

			//Constructors
			iterator() : it() {}
			iterator(const typename BST < pair <K, V> >::iterator & rhs)
			{
				it = rhs;
			}
			iterator(const iterator & rhs)
			{
				it = rhs.it;
			}

			//Assignment operator
			iterator & operator = (const iterator & rhs)
			{
				it = rhs.it;
				return *this;
			}

			// Comparison Operators
			bool operator == (const iterator & rhs) { return (it == rhs.it); }
			bool operator != (const iterator & rhs) { return (it != rhs.it); }

			// Dereference operator
			pair<K, V> & operator * ()
			{
				return *it;
			}

			// prefix increment
			iterator & operator ++ ()
			{
				++it;
				return *this;
			}

			// postfix increment
			iterator operator ++ (int postfix)
			{
				iterator tmp(*this);
				it++;
				return tmp;

			}

			//prefix decrement
			iterator & operator -- ()
			{
				--it;
				return *this;
			}

			// postfix decrement
			iterator operator -- (int postfix)
			{
				iterator tmp(*this);
				it--;
				return tmp;
			}
		};

		// default and copy constructors
		map() : bst() {}
		map(const map<K, V> & rhs) throw (const char *)
		{
			bst = rhs.bst;
		}

		// assignment operator
		map <K, V> & operator = (const map <K, V> & rhs)
		{
			bst = rhs.bst;
			return *this;
		}

		// access operator
		V & operator [] (K key) throw (const char *)
		{
			iterator temp(find(key));

			//If the specified key is not there, then add it
			if (temp == end())
			{
				pair<K, V> tempPair(key, V());
				insert(tempPair);
				temp = find(key);
			}
			return (*temp).second;
		}

		// access operator for const values
		const V & operator [] (K key) const throw (const char *)
		{
			iterator temp(find(key));

			//If the specified key is not there, then return default value for V
			if (temp == end())
			{
				return V();
			}

			return (*temp).second;
		}

		bool empty() { return bst.empty(); }
		int size() { return bst.size(); }
		void clear() { bst.clear(); }
		void insert(K key, V value)
		{
			pair<K, V> pair(key, value);
			bst.insert(pair);
		}
		void insert(pair<K, V> pair) { bst.insert(pair); }

		iterator find(K key)
		{
			pair<K, V> tempPair(key, V());
			iterator it(bst.find(tempPair));
			iterator temp(it);
			return temp;
		}
		iterator begin()
		{
			return bst.begin();
		}
		iterator end()
		{
			iterator temp(nullptr);
			return temp;
		}

	private:

		//BST of type pair<K, V>
		BST < pair <K, V> > bst;
	};

} 

#endif //MAP_H