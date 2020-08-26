#pragma once
#include<string>
#include"Point.h"
#include"Snapshot.h"
#include"LinkedList.h"
#include "ArrayStack.h"
#include"BinarySearchTree.h"

using namespace std;
class Editor
{
private:
	LinkedList<string> lines;
	Point <int> position;
	int MAX;
	ArrayStack <Snapshot> UndoStack;
	BinarySearchTree <string>* keywordsBST;
public:
	bool readFile(string);
	void run();
	void display();
	bool readKeyword(string);
	Editor();

};