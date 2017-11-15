/** Entry.h */

#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <iostream>
#include <iomanip>
using namespace std;
template <typename K, typename V>
class Entry { // a (key, value) pair
	friend ostream& operator<<(ostream& fout, Entry& ent);
public: // public functions
	Entry(const K& k = K(), const V& v = V()) // constructor
		: _key(k), _value(v) { }
	const K& key() const { return _key; } // get key
	const V& value() const { return _value; } // get value
	void setKey(const K& k) { _key = k; } // set key
	void setValue(const V& v) { _value = v; } // set value
private: // private data
	K _key; // key
	V _value; // value
};
template <typename K, typename V>
ostream& operator<<(ostream& fout, Entry<K, V>& ent)
{
	//. . . .
	return fout;
}

#endif