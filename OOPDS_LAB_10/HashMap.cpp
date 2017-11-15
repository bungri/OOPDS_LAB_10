/** HashMap.cpp (1) */
#include <iostream>

#include "HashMap.hpp"
#include "Entry.hpp"

using namespace std;

template <typename K, typename V, typename H> // constructor
HashMap<K, V, H>::HashMap(int capacity) : n(0), B(capacity) { }

template <typename K, typename V, typename H> // number of entries
int HashMap<K, V, H>::size() const { return n; }

template <typename K, typename V, typename H> // is the map empty?
bool HashMap<K, V, H>::empty() const { return size() == 0; }

template <typename K, typename V, typename H> // iterator to front
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::begin() {
	if (empty()) return end(); // emtpty - return end
	BItor bkt = B.begin(); // else search for an entry
	while (bkt->empty()) ++bkt; // find nonempty bucket
	return Iterator(B, bkt, bkt->begin()); // return first of bucket
}

template <typename K, typename V, typename H> // iterator to end
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::end() {
	return Iterator(B, B.end());
}

template <typename K, typename V, typename H> // get entry
typename HashMap<K, V, H>::Entry& HashMap<K, V, H>::Iterator::operator*() {
	return *ent;
}

template <typename K, typename V, typename H> // are iterators equal?
bool HashMap<K, V, H>::Iterator::operator==(const Iterator& p) const {
	if (ba != p.ba || bkt != p.bkt) return false; // ba or bkt differ?
	else if (bkt == ba->end()) return true; // both at the end?
	else return (ent == p.ent); // else use entry to decide
}

template <typename K, typename V, typename H> // are iterators equal?
bool HashMap<K, V, H>::Iterator::operator!=(const Iterator& p) const
{
	if (ba != p.ba || bkt != p.bkt) return true; // ba or bkt differ?
	else if (bkt == ba->end()) return false; // both at the end?
	else return (ent != p.ent); // else use entry to decide
}

template <typename K, typename V, typename H> // advance to next entry
typename HashMap<K, V, H>::Iterator& HashMap<K, V, H>::Iterator::operator++()
{
	++ent; // next entry in bucket
	if (endOfBkt(*this)) { // at end of bucket?
		++bkt; // go to next bucket
		while (bkt != ba->end() && bkt->empty()) // find nonempty bucket
			++bkt;
		if (bkt == ba->end()) return *this; // end of bucket array?
		ent = bkt->begin(); // first nonempty entry
	}
	return *this; // return self
}

template <typename K, typename V, typename H> // find utility
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::finder(const K& k)
{
	int i = hash(k) % B.size(); // get hash index i, using CyclicShiftHashCode
#ifdef HASH_TEST
	cout << i;
#endif
	BItor bkt = B.begin() + i; // the i-th bucket
	Iterator p(B, bkt, bkt->begin()); // start of i-th bucket
	while (!endOfBkt(p) && (*p).key() != k) // linear search for k in the bucket
		nextEntry(p);
	return p; // return final position
}

template <typename K, typename V, typename H> // find key
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::find(const K& k)
{
	Iterator p = finder(k); // look for k
	if (endOfBkt(p)) // didn't find it?
		return end(); // return end iterator
	else
		return p; // return its position
}

template <typename K, typename V, typename H> // insert utility
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::inserter(const Iterator& p, const Entry& e) {
	EItor ins = p.bkt->insert(p.ent, e); // insert before p using insert() of list<Entry>
	n++; // one more entry
	return Iterator(B, p.bkt, ins); // return this position
}

template <typename K, typename V, typename H> // insert/replace (v,k)
typename HashMap<K, V, H>::Iterator HashMap<K, V, H>::put(const K& k, const V& v) {
	Iterator p = finder(k); // search for k
	if (endOfBkt(p)) { // k not found?
		return inserter(p, Entry(k, v)); // insert at end of bucket
	}
	else { // found it?
		p.ent->setValue(v); // replace value with v
		return p; // return this position
	}
}

template <typename K, typename V, typename H> // remove utility
void HashMap<K, V, H>::eraser(const Iterator& p) {
	p.bkt->erase(p.ent); // remove entry from bucket
	n--; // one fewer entry
}

template <typename K, typename V, typename H> // remove entry at p
void HashMap<K, V, H>::erase(const Iterator& p)
{
	eraser(p);
}

template <typename K, typename V, typename H> // remove entry with key k
void HashMap<K, V, H>::erase(const K& k) {
	Iterator p = finder(k); // find k
	if (endOfBkt(p)) // not found?
		throw NonexistentElement("Erase of nonexistent"); // ...error
	eraser(p); // remove it
}