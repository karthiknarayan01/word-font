/*

File name - WordFontInterface.h
Name - Karthik Narayan
Course Number - CPS 400

	This header file contains details of the public methods that can be invoked by client programs. WordFont class contain following private members
1) word - The input string entered by the user
2) isBold - If user enters 0 then it will hold False else True
3) fontSize - The 2d dimension which user wishes to have the letters drawn in
4) pixelChar.
	CAI class contains following methods
	1) 15 methods one written for each character in a e i o u c b d f p x j z l t
	   these methods will return a 2d matrix with the pixel characters filled in. If	   the returned matrix is printed out then it will draw out the character on 		   screen

	2) getInput - It gets fontSize, word, isBold, pixelChar from user.

	3) printOutput - It iterates through each of the char in the input word, gets the 	2d representation of each of the character and adds of those chars in a bigger 		matrix which will be used to draw out the pixel representation of the word in 		screen.

	4)addCharToWord - It takes in 2 parameters, one which is a 2d vector that is supposed to hold the entire word and another 2d vector which represents a single char.

*/

#pragma once

#include<string>
#include<vector>
#include<iostream>
using namespace std;
class WordFont {

public:
	void getInput();
	void printOutput();

private:
	string word;
	bool isBold;
	int fontSize;
	char pixelChar;
	void addCharToWord(vector<vector<char> >* word, vector<vector<char> > c, int current);
	vector<vector<char> > aChar();
	vector<vector<char> > eChar();
	vector<vector<char> > iChar();
	vector<vector<char> > oChar();
	vector<vector<char> > uChar();
	vector<vector<char> > cChar();
	vector<vector<char> > bChar();
	vector<vector<char> > dChar();
	vector<vector<char> > fChar();
	vector<vector<char> > pChar();
	vector<vector<char> > xChar();
	vector<vector<char> > jChar();
	vector<vector<char> > zChar();
	vector<vector<char> > lChar();
	vector<vector<char> > tChar();

};