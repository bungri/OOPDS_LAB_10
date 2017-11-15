/** Task.h */
#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
using namespace std;
class Task
{
	friend ostream& operator<<(ostream&, const Task&);
public:
	Task() {}; // constructor
	Task(string tName, int pri, int dur) { taskName = tName; priority = pri; duration = dur; };
	string getTaskName() { return taskName; }
	int getPriority() { return priority; }
	int getDuration() { return duration; }
	void setTaskName(string n) { taskName = n; }
	void setPriority(int pri) { priority = pri; };
	void setDuration(int dur) { duration = dur; };
	bool operator>(Task& t) { return (priority > t.priority); }
	bool operator<(Task& t) { return (priority < t.priority); }
private:
	string taskName; // name of task
	int priority; // priority of task in scheduling: 0 ~ 49
	int duration; // duration of processing time, [ms]
};

#endif