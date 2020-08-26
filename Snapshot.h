#pragma once
#include <string>
#include "Point.h"
using namespace std;

class Snapshot {
public:
	void setCommand(char);
	char getCommand();
	void setvalue(string);
	string getvalue();
	void setpostion(Point<int>);
	Point<int> getpostion();
	
private:
	Point<int> Lastpostion;
	char storedCommand;
	string savedvalue;
};
