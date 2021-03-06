/** HashDictionary.h */
#ifndef HASH_DICTIONARY_HPP
#define HASH_DICTIONARY_HPP

#include "HashMap.hpp"
template <typename K, typename V, typename H>
class HashDict : public HashMap<K, V, H> {
public: // public functions
	typedef typename HashMap<K, V, H>::Iterator Iterator;
	typedef typename HashMap<K, V, H>::Entry Entry;
	// Range class declaration
	class Range { // an iterator range
	private:
		Iterator _begin; // front of range
		Iterator _end; // end of range
	public:
		Range() {} // default constructor
		Range(const Iterator& b, const Iterator& e) // constructor
			: _begin(b), _end(e) { }
		Iterator& begin() { return _begin; } // get beginning
		Iterator& end() { return _end; } // get end
	};
public: // public functions
	HashDict(int capacity = 100); // constructor
	Range findAll(const K& k); // find all entries with k
	Iterator insert(const K& k, const V& v); // insert pair (k,v)
};

template <typename K, typename V, typename H> // constructor
HashDict<K, V, H>::HashDict(int capacity) : HashMap<K, V, H>(capacity) { }

template <typename K, typename V, typename H> // find all entries with k
typename HashDict<K, V, H>::Range HashDict<K, V, H>::findAll(const K& k)
{
	Iterator b = finder(k); // look up k
	Iterator p = b;
	while (!endOfBkt(p) && (*p).key() == (*b).key())
	{ // find next unequal key
		++p;
	}
	return Range(b, p); // return range of positions
}

template <typename K, typename V, typename H> // insert pair (k,v)
typename HashDict<K, V, H>::Iterator HashDict<K, V, H>::insert(const K& k, const V& v)
{
	Iterator p = finder(k); // find key
	Iterator q = inserter(p, Entry(k, v)); // insert it here
	return q; // return its position
}

#endif