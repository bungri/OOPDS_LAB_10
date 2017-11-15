/** Exceptions.h */
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <iostream>
using namespace std;
class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	}
	string getMessage() const {
		return errorMsg;
	}
};
class NonexistentElement : public RuntimeException {
public:
	NonexistentElement(const string& err) : RuntimeException(err) {}
};
#endif