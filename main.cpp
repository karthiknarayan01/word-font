/*

File name - main.cpp
Name - Karthik Narayan
Course Number - CPS 400

	Main.cpp creates an object of type WordFont and invokes its public method getInput() to get input from user and printOutput() to draw the word on the screen.

*/

#include "WordFontInterface.h"

int main() {
	WordFont wordFontObj;
	wordFontObj.getInput();
	wordFontObj.printOutput();
	return 0;
}