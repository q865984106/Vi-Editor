#include<iostream>
#include<string>
#include"Editor.h"
#include "windows.h"
#include "LinkedList.h"
#include<conio.h>
#include <cstring>
#include<fstream>
#include"BinarySearchTree.h"
using namespace std;
#define ESC 27 
void placeCursorAt(Point <int> coordinate)
{
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void colorText(int value) 
{

	COORD coord;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	FlushConsoleInputBuffer(hConsole);

	SetConsoleTextAttribute(hConsole, value);

}

Editor::Editor():MAX(0)
{
	keywordsBST = new BinarySearchTree<string>();
}

bool Editor::readFile(string  name)
{
	ifstream inFile;
	inFile.open(name);
	if (!inFile)
	{
		return false;

	}
	int count = 1;
	string data;
	while (!inFile.eof())
	{

		getline(inFile, data);
		lines.insert(count, data);
		MAX++;
		count++;
	}
	return true;
}


bool Editor::readKeyword(string name)
{
	ifstream inFile;
	inFile.open(name);
	if (!inFile)
	{
		cout << "Error" << endl;
		return false;
	}
	string data;
	while (!inFile.eof())
	{
		inFile >> data;
		keywordsBST->add(data);
	}
	return true;
}

void Editor::run()
{
	int size;
	Snapshot snapshot;
	string change;
	string length;
	char command;
	bool x = true;
	string line;
	Snapshot oldData;
	char ch;
	string addchars;
	while (x)
	{
		command = _getch();
		switch (command)
		{
		case 'h': 

			position.setX(position.getX() - 1);
			placeCursorAt(position);
			break;
		case 'j':
			position.setY(position.getY() + 1);
			if (position.getY() > MAX-1)
			{
				position.setY(MAX-1);
			}
			placeCursorAt(position);
			break;
		case 'k':
			position.setY(position.getY() - 1);
			if (position.getY() < 0)
			{
				position.setY(0);
			}
			placeCursorAt(position);
			break;
		case 'l':
			length = lines.getEntry(position.getY() + 1);
			size = length.length();
			position.setX(position.getX() + 1);
			if (position.getX() > size - 1)
			{
				position.setX(size-1);
			}
			placeCursorAt(position);
			break;

		case 'd':
			command = _getwch();
			if (command == 'd') 
			{

				snapshot.setvalue(lines.getEntry(position.getY() + 1));//get the data
				snapshot.setCommand('d');//get the command
				snapshot.setpostion(position);// get the position 
				UndoStack.push(snapshot);// send the data into undo stack
				lines.remove(position.getY() + 1);// remove the line
				placeCursorAt(position);
				MAX--;
				system("cls");
				display();
			}
			break;

		case'x':
			change = lines.getEntry(position.getY() + 1);
			change.erase(position.getX(),1);
			snapshot.setCommand('x');
			snapshot.setvalue(lines.getEntry(position.getY() + 1));
			snapshot.setpostion(position);
			UndoStack.push(snapshot);
			lines.replace(position.getY()+1, change);
			system("cls");
			display();
			break;


		case 'u':
			if (!UndoStack.isEmpty())
			{
				oldData = UndoStack.peek(); // get the data from the Snapshot in the stack
				position = oldData.getpostion();// get the position for the line that need to undo
				if (oldData.getCommand() == 'x')
				{
					lines.replace(position.getY() + 1, oldData.getvalue());// replace the data
					UndoStack.pop();

				}
				else
				{
					lines.insert(position.getY() + 1, oldData.getvalue());// replace the data
					MAX++;
					UndoStack.pop();
					
				}
			
				system("cls");
				display();
			}
			system("cls");
			display();
			break;

		case'I':
			line = lines.getEntry(position.getY()+1);
			position.setX(0);
			placeCursorAt(position);
		while( (ch=_getwche()) !=ESC)
		{
			 
			addchars += ch;
			line = ch + line;
			lines.replace(position.getY() + 1, line);

			system("cls");
			display();

		}

			system("cls");
			display();
		    break;

		}//end switch
	}
}//end run


 
void Editor::display()
{
	bool isKeyword;
	fstream inFile;
	string line;
	bool stop = true;


	int j = 0;
	for (int k = 1; k < MAX + 1; k++)
	{
		line = lines.getEntry(k);
		for (int i = 0; i < line.size(); i++)
		{
			if (tolower(line[i]) >= 'a' && tolower(line[i]) <= 'z') 
			{
				string currentWord;
				for (j = i; (tolower(line[j]) >= 'a' && tolower(line[j]) <= 'z'); j++)
				{
					currentWord += line[j];
				}
				isKeyword = !keywordsBST->contains(currentWord);
				if (isKeyword)
					colorText(FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0X80);  //blue
				else
					colorText(0XF0);
				cout << currentWord;
				if (j != 0)
					i = j - 1;
			}
			else
			{
				cout << line[i];

			}
			//cout << endl;
		}
		cout << endl;
		
	}
	placeCursorAt(position);
	//goToXY(_currentPos,currentLine-1);

 }
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
// void Editor::display()
//{
//	int count = 1;
//	string line;
//	bool stop = true;
//	int i = 0;
//	while (i < MAX)
//	{
//		line = lines.getEntry(count);
//		cout << line <<endl;
//		count++;
//		if (lines.isEmpty())
//		{
//			stop = false;
//		}
//		i++;
//	}
//	placeCursorAt(position);
//
//}
//