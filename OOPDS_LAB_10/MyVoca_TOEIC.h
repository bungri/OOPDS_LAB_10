/** MyVoca_TOEIC.h */

#ifndef MY_VOCA_TOEIC_H
#define MY_VOCA_TOEIC_H

#include <string>
#include <list>
#include "MyVoca.hpp"
using namespace std;
typedef list<Struct_Voca> List_SV;
typedef list<Struct_Voca>::iterator Lst_SV_Itr;
Struct_Voca myToeicVocaList[] =
{
	{ "offer", NOUN,{ "proposal" },{ "He accepted out offer to write the business plan." } },
	{ "offer", VERB,{ "to propose" }, { "She must offer her banker new statistics in order to satisfy the bank's requirement for the loan." } },
	{ "compromise", NOUN,{ "give-and-take", "bargaining", "acomodation" },	{ "The couple made a compromise and ordered food to take out." } },
	{ "compromise", VERB,{ "settle", "conciliate", "find a middle ground" }, { "He does not like sweet dishes so I compromised by adding just a small amount of sugar." } },
	{ "delegate", NOUN,{ "representative", "agent", "substitute" },{ "" } },
	{ "delegate", VERB,{ "authorize", "appoint", "designate" },{ "" } },
	{ "foster", VERB,{ "nurture", "raise", "promote", "advance" },{ "" } },
	{ "foster", ADJ,{ "substitute", "adoptive", "stand-in" },{ "" } },
	{ "imperative", ADJ,{ "authoritative", "vital" },{ "" } },
	{ "imperative", NOUN,{ "necessity", "essential", "requirement" },{ "" } },
	{ "mean", ADJ,{ "nasty", "poor", "middle", "miserly", "paltry" },{ "A man of mean intelligence, a mean appearance" } },
	{ "mean", NOUN,{ "average", "norm", "median", "middle", "midpoint", "(antonym)extremity" },{ "The mean error, the golden mean, the arithmetical mean, the geometric	mean" } },
	{ "mean", VERB,{ "require", "denote", "intend" },{ "What do you mean by ¡°perfect¡± ?" } },
	{ "-1", NOUN,{ "" },{ "" } }, // end sentinel
};

#endif