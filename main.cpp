#include<iostream>
#include<string>
#include"LinkedList.h"
#include"Editor.h"
using namespace std;

int main()
{

	string data;
	Editor inEditor;

	data = "sample.txt";
	inEditor.readFile(data);
	string data2 = "Keyword.txt";
	inEditor.readKeyword(data2);
	inEditor.display();
	inEditor.run();
	system("pause");
	return 0;
}