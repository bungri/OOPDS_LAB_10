/** MyVoca.h */
#ifndef MY_VOCA_HPP
#define MY_VOCA_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum Word_Type { NOUN, VERB, ADJ, ADV, PREPOS }; // noun, verb, adjective, adverbs, preposition
string wd_ty[] = { "n", "v", "adj", "adv", "prepos" };

typedef list<string> List_Str;
typedef list<string>::iterator Lst_Str_Itr;

typedef struct Struct_Voca
{
	string w;
	Word_Type type;
	List_Str thes;
	List_Str usg;
} Struct_Voca;

class MyVoca {
	friend ostream& operator<<(ostream& fout, MyVoca& mv);
public:
	MyVoca(string entry, Word_Type wt, List_Str thes, List_Str ex_usg)
		:word(entry), type(wt), thesaurus(thes), usages(ex_usg) {}
	MyVoca(Struct_Voca sv)
		:word(sv.w), type(sv.type), thesaurus(sv.thes), usages(sv.usg) {}
	MyVoca() {} // default constructor
private:
	string word; // entry word (also key)
	Word_Type type;
	List_Str thesaurus; // thesarus of the entry word in the type
	List_Str usages;
};

ostream& operator<<(ostream& fout, MyVoca& mv)
{
	list<string>::iterator itr;
	fout << mv.word << "(" << wd_ty[mv.type] << "): \n";
	fout << " - thesaurus(";
	for (itr = mv.thesaurus.begin(); itr != mv.thesaurus.end(); ++itr)
	{
		fout << *itr << ", ";
	} fout << ")" << endl;
	fout << " - example usage(";
	for (itr = mv.usages.begin(); itr != mv.usages.end(); ++itr)
	{
		fout << *itr << " ";
	} fout << ")" << endl << endl;
	return fout;
}

#endif