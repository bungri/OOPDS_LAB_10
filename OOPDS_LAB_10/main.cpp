/** main.cpp */
#include <iostream>
#include <string>
#include "HashMap.hpp"
#include "HashMap.cpp"
#include "LessThan.hpp"
#include "CyclicShiftHashCode.hpp"
#include "Entry.hpp"
//#include "Task.hpp"
#include "HashDictionary.hpp"
#include "MyVoca_TOEIC.h"
#define NUM_TASKS 20
//#define TEST_HASH_MAP 1
#define TEST_HASH_DICTIONARY 1
void main()
{
	cout << "Testing Hash Dictionary" << endl;
	Struct_Voca *pSV;
	string word;
	Word_Type type;
	List_Str thesaurus;
	List_Str usages;
	Lst_SV_Itr sv_itr;
	int word_count;
	MyVoca mv;
	//Entry<string, MyVoca> ent;
	HashDict<string, MyVoca, CyclicShiftHashCode> myVocaDict;
	HashMap<string, MyVoca, CyclicShiftHashCode>::Iterator itr;
	HashDict<string, MyVoca, CyclicShiftHashCode>::Range range;
	cout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	for (pSV = &myToeicVocaList[word_count]; pSV->w != "-1";
		pSV = &myToeicVocaList[word_count++])
	{
		pSV = &myToeicVocaList[word_count];
		word = pSV->w;
		if (word == "-1")
			break;
		myVocaDict.insert(word, *pSV);
	}
	//cout << endl;
	cout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;
	// check all vocabularies in the hash_dictionary
	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)
	{
		mv = itr.getValue();
		cout << mv;
	}
	cout << endl;
	string testWord = "mean";
	range = myVocaDict.findAll(testWord);
	cout << "Thesaurus of [" << testWord << "]: \n";
	for (itr = range.begin(); itr != range.end(); ++itr)
	{
		mv = itr.getValue();
		cout << mv;
	}
	cout << endl;
}