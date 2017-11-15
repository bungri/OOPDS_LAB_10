/** LessThan.h */
#ifndef LESSTHAN_H
#define LESSTHAN_H

using namespace std;
template<class T>
class LessThan
{
public:
	bool operator()(T& p, T& q) const
	{
		return p < q;
	}
};

#endif