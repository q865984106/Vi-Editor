#include "Snapshot.h"


void Snapshot::setCommand(char command)
{
	storedCommand = command;
}

void Snapshot::setpostion(Point<int> oldPostion)
{

	Lastpostion = oldPostion;

}

Point<int> Snapshot::getpostion()
{
	return Lastpostion;


}
char Snapshot::getCommand()
{
	return storedCommand;
}
string Snapshot::getvalue()
{
	return savedvalue;
}

void Snapshot::setvalue(string value)
{
	savedvalue = value;
}

