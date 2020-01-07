/*

File name - WordFontImpl.cpp
Name - Karthik Narayan
Course Number - CPS 400

	This file contains implementation details of the public & private methods.
	Description of what each method does is given in WordFontInterface.h file

*/

// b, o

#include "WordFontInterface.h"

/*

For drawing characters, each of the 15 methods uses the fact that it needs to place the pixel characters in a 2d vector whose dimensions are fontSize * fontSize. So top leftmost point in 2d vector has dimension of (0,0), top rightmost (0,fontSize-1), bottom leftmost (fontSize-1,0) and bottom rightmost (fontSize-1,fontSize-1). Now each character is just a bunch of lines in the 2d vector and a line is connection of points represented as (x,y). All that is left is to find the equation of these lines for each character and we find the points that satisfies those equations and place the pixel characters on those points.

*/

/*

Equation of the lines when character A is not bold:

1) xdimension or rows = 0 -> All points (0,0), (0,1) .. will meet this equation
2) ydimension or cols = 0 -> Points (0,0), (1,0) .. will meet this equation
3) ydimension or cols = fontSize - 1
4) xdimension or rows = fontSize/2

Equation of the lines when character A is bold:

1) xdimension or rows = 0
2) xdimension or rows = 1
3) ydimension or cols = 0
4) ydimension or cols = 1
5) ydimension or cols = fontSize - 2
6) ydimension or cols = fontSize - 1
7) xdimension or rows = fontSize/2
8) xdimension or rows = fontSize/2-1

*/
vector<vector<char> > WordFont::aChar() {

	vector<vector<char> > aCharacter(fontSize, vector<char>(fontSize, ' '));

	/* Written a for loop that retrieves all the points in a 2d vector and for each point it checks if it meets the condition of the line equation in the if statements*/

	if (!isBold)
	{
		for (int rows = 0; rows < aCharacter.size(); rows++) {
			for (int cols = 0; cols < aCharacter.at(0).size(); cols++) {
				if (rows == 0 || cols == 0 || cols == fontSize - 1 || rows == fontSize / 2)
					aCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < aCharacter.size(); rows++) {
			for (int cols = 0; cols < aCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || cols == 0 || cols == 1 || cols == fontSize - 2 || cols == fontSize - 1 || rows == fontSize / 2 || rows == fontSize / 2 - 1)
					aCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return aCharacter;

}

/*

Equation of the lines when character E is not bold:

1) xdimension or rows = 0 -> All points (0,0), (0,1) .. will meet this equation
2) ydimension or cols = 0 -> Points (0,0), (1,0) .. will meet this equation
3) xdimension or rows = fontSize - 1
4) xdimension or rows = fontSize/2

Equation of the lines when character E is bold:

1) xdimension or rows = 0
2) xdimension or rows = 1
3) ydimension or cols = 0
4) ydimension or cols = 1
5) ydimension or rows = fontSize - 2
6) ydimension or rows = fontSize - 1
7) xdimension or rows = fontSize/2
8) xdimension or rows = fontSize/2-1

*/

vector<vector<char> > WordFont::eChar() {

	vector<vector<char> > eCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < eCharacter.size(); rows++) {
			for (int cols = 0; cols < eCharacter.at(0).size(); cols++) {
				if (rows == 0 || cols == 0 || rows == fontSize / 2 || rows == fontSize - 1)
					eCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < eCharacter.size(); rows++) {
			for (int cols = 0; cols < eCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || cols == 0 || cols == 1 || rows == fontSize / 2 || rows == fontSize / 2 - 1 || rows == fontSize - 1 || rows == fontSize - 2)
					eCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return eCharacter;

}

/*

Equation of the lines when character I is not bold:

1) xdimension or rows = 0 -> All points (0,0), (0,1) .. will meet this equation
2) xdimension or rows = fontSize - 1
3) ydimension or cols = fontSize/2

Equation of the lines when character I is bold:

1) xdimension or rows = 0
2) xdimension or rows = 1
3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) ydimension or cols = fontSize/2
6) ydimension or cols = fontSize/2-1

*/

vector<vector<char> > WordFont::iChar() {

	vector<vector<char> > iCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < iCharacter.size(); rows++) {
			for (int cols = 0; cols < iCharacter.at(0).size(); cols++) {
				if (rows == 0 || cols == fontSize / 2 || rows == fontSize - 1)
					iCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < iCharacter.size(); rows++) {
			for (int cols = 0; cols < iCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || cols == fontSize / 2 || cols == fontSize / 2 - 1 || rows == fontSize - 1 || rows == fontSize - 2)
					iCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return iCharacter;

}

/*

Equation of the lines when character O is not bold:

1) xdimension or rows = 0 -> All points (0,0), (0,1) .. will meet this equation
2) xdimension or rows = fontSize - 1
3) ydimension or cols = 0
4) ydimension or cols = fontSize - 1

Equation of the lines when character O is bold:

1) xdimension or rows = 0
2) xdimension or rows = 1
3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) ydimension or cols = 0
6) ydimension or cols = 1
7) ydimension or cols = fontSize - 1
8) ydimension or cols = fontSize - 2

additionally do not populate the corner pixels

*/

vector<vector<char> > WordFont::oChar() {

	vector<vector<char> > oCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < oCharacter.size(); rows++) {
			for (int cols = 0; cols < oCharacter.at(0).size(); cols++) {
				if ((rows == 0 || cols == 0 || rows == fontSize - 1 || cols == fontSize - 1) && !((rows == 0 && cols == 0) || (rows == 0 && cols == fontSize - 1) || (rows == fontSize - 1 && cols == 0) || (rows == fontSize - 1 && cols == fontSize - 1)))
					oCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < oCharacter.size(); rows++) {
			for (int cols = 0; cols < oCharacter.at(0).size(); cols++) {
				if ((rows == 0 || rows == 1 || cols == 0 || cols == 1 || rows == fontSize - 1 || rows == fontSize - 2 || cols == fontSize - 1 || cols == fontSize - 2) && !(((rows == 0 || rows == 1) && (cols == fontSize - 1 || cols == fontSize - 2 || cols == 0 || cols == 1)) || ((rows == fontSize - 1 || rows == fontSize - 2) && (cols == fontSize - 1 || cols == fontSize - 2 || cols == 0 || cols == 1)) ))
					oCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return oCharacter;

}

/*

Equation of the lines when character U is not bold:

2) xdimension or rows = fontSize - 1
3) ydimension or cols = 0
4) ydimension or cols = fontSize - 1

Equation of the lines when character U is bold:

3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) ydimension or cols = 0
6) ydimension or cols = 1
7) ydimension or cols = fontSize - 1
8) ydimension or cols = fontSize - 2

*/

vector<vector<char> > WordFont::uChar() {

	vector<vector<char> > uCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < uCharacter.size(); rows++) {
			for (int cols = 0; cols < uCharacter.at(0).size(); cols++) {
				if (cols == 0 || rows == fontSize - 1 || cols == fontSize - 1)
					uCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < uCharacter.size(); rows++) {
			for (int cols = 0; cols < uCharacter.at(0).size(); cols++) {
				if (cols == 0 || cols == 1 || rows == fontSize - 1 || rows == fontSize - 2 || cols == fontSize - 1 || cols == fontSize - 2)
					uCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return uCharacter;

}

/*

Equation of the lines when character C is not bold:

1) xdimension or rows = 0
2) xdimension or rows = fontSize - 1
3) ydimension or cols = 0

Equation of the lines when character C is bold:

3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) xdimension or rows = 0
6) xdimension or rows = 1
7) ydimension or cols = 0
8) ydimension or cols = 1

*/

vector<vector<char> > WordFont::cChar() {

	vector<vector<char> > cCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < cCharacter.size(); rows++) {
			for (int cols = 0; cols < cCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == fontSize - 1 || cols == 0)
					cCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < cCharacter.size(); rows++) {
			for (int cols = 0; cols < cCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || rows == fontSize - 1 || rows == fontSize - 2 || cols == 0 || cols == 1)
					cCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return cCharacter;

}

/*

Equation of the lines when character B is not bold:

1) xdimension or rows = 0
2) xdimension or rows = fontSize - 1
2) xdimension or rows = fontSize / 2
3) ydimension or cols = 0
3) ydimension or cols = fontSize - 1

Equation of the lines when character B is bold:

3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) xdimension or rows = 0
6) xdimension or rows = 1
5) xdimension or rows = fontSize/2
6) xdimension or rows = fontSize/2 - 1
7) ydimension or cols = 0
8) ydimension or cols = 1
7) ydimension or cols = fontSize - 1
8) ydimension or cols = fontSize - 2

additionally do not populate the right corner pixels
*/

vector<vector<char> > WordFont::bChar() {

	vector<vector<char> > bCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < bCharacter.size(); rows++) {
			for (int cols = 0; cols < bCharacter.at(0).size(); cols++) {
				if ((rows == 0 || rows == fontSize - 1 || rows == fontSize / 2 || cols == 0 || cols == fontSize - 1) && !((rows == 0 && cols == fontSize - 1) || (rows == fontSize - 1 && cols == fontSize - 1)))
					bCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < bCharacter.size(); rows++) {
			for (int cols = 0; cols < bCharacter.at(0).size(); cols++) {
				if ((rows == 0 || rows == 1 || rows == fontSize - 1 || rows == fontSize - 2 || rows == fontSize / 2 || rows == fontSize / 2 - 1 || cols == 0 || cols == 1 || cols == fontSize - 1 || cols == fontSize - 2) && !(((rows == 0 || rows == 1) && (cols == fontSize - 1 || cols == fontSize - 2)) || ((rows == fontSize - 1 || rows == fontSize - 2) && (cols == fontSize - 1 || cols == fontSize - 2)) ))
					bCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return bCharacter;

}

/*

Equation of the lines when character D is not bold:

1) xdimension or rows = 0
2) xdimension or rows = fontSize - 1
3) ydimension or cols = 0
3) ydimension or cols = fontSize - 1

Equation of the lines when character D is bold:

3) xdimension or rows = fontSize - 2
4) xdimension or rows = fontSize - 1
5) xdimension or rows = 0
6) xdimension or rows = 1
7) ydimension or cols = 0
8) ydimension or cols = 1
7) ydimension or cols = fontSize - 1
8) ydimension or cols = fontSize - 2

Additionally dont populate pixels in (0,fontSize-1) (fontSize-1, fontSize -1)  -> this is to give a curved look which the D character has

*/

vector<vector<char> > WordFont::dChar() {

	vector<vector<char> > dCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < dCharacter.size(); rows++) {
			for (int cols = 0; cols < dCharacter.at(0).size(); cols++) {
				if ((rows == 0 || rows == fontSize - 1 || cols == 0 || cols == fontSize - 1) && !((rows == 0 && cols == fontSize - 1) || (rows == fontSize - 1 && cols == fontSize - 1)))
					dCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < dCharacter.size(); rows++) {
			for (int cols = 0; cols < dCharacter.at(0).size(); cols++) {
				if ((rows == 0 || rows == 1 || rows == fontSize - 1 || rows == fontSize - 2 || cols == 0 || cols == 1 || cols == fontSize - 1 || cols == fontSize - 2) && !(((rows == 0 || rows == 1 || rows == fontSize - 1 || rows == fontSize - 2) && (cols == fontSize - 1 || cols == fontSize - 2))))
					dCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return dCharacter;

}

/*

Equation of the lines when character F is not bold:

1) xdimension or rows = 0
2) xdimension or rows = fontSize/2
3) ydimension or cols = 0

Equation of the lines when character F is bold:

3) xdimension or rows = fontSize / 2
4) xdimension or rows = fontSize / 2 - 1
5) xdimension or rows = 0
6) xdimension or rows = 1
7) ydimension or cols = 0
8) ydimension or cols = 1

*/

vector<vector<char> > WordFont::fChar() {

	vector<vector<char> > fCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < fCharacter.size(); rows++) {
			for (int cols = 0; cols < fCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == fontSize / 2 || cols == 0)
					fCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < fCharacter.size(); rows++) {
			for (int cols = 0; cols < fCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || rows == fontSize / 2 || rows == fontSize / 2 - 1 || cols == 0 || cols == 1)
					fCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return fCharacter;

}

/*

Equation of the lines when character P is not bold:

1) xdimension or rows = 0
2) xdimension or rows = 2
3) ydimension or cols = 0

Equation of the lines when character F is bold:

3) xdimension or rows = 2
4) xdimension or rows = 3
5) xdimension or rows = 0
6) xdimension or rows = 1
7) ydimension or cols = 0
8) ydimension or cols = 1

Additionally add pixels at (1,fontSize-1)

*/

vector<vector<char> > WordFont::pChar() {

	vector<vector<char> > pCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < pCharacter.size(); rows++) {
			for (int cols = 0; cols < pCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 2 || cols == 0 || (rows == 1 && cols == fontSize - 1))
					pCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < pCharacter.size(); rows++) {
			for (int cols = 0; cols < pCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || rows == 3 || rows == 4 || cols == 0 || cols == 1 || (rows == 1 && cols == fontSize - 1) || (rows == 2 && (cols == fontSize - 2 || cols == fontSize - 1)))
					pCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return pCharacter;

}

/*

X is just two diagonals. so
Equation of the lines when character X is not bold:

1) rows = cols
2) rows+cols = fontSize - 1

Equation of the lines when character X is bold:

1) rows - cols = 1
2) cols - rows = 1
3) rows + cols = fontsize - 2
4) rows + cols = fontsize


*/

vector<vector<char> > WordFont::xChar() {

	vector<vector<char> > xCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < xCharacter.size(); rows++) {
			for (int cols = 0; cols < xCharacter.at(0).size(); cols++) {
				if (rows == cols || rows + cols == fontSize - 1)
					xCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < xCharacter.size(); rows++) {
			for (int cols = 0; cols < xCharacter.at(0).size(); cols++) {
				if (rows - cols == 1 || cols - rows == 1 || rows + cols == fontSize - 2 || rows + cols == fontSize)
					xCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return xCharacter;

}

/*

Equation of the lines when character J is not bold:

1) rows = 0
2) cols = fontsize / 2
2) rows = fontsize - 1 and cols <= fontsize / 2

Equation of the lines when character J is bold:

1) rows = 0
1) rows = 1
2) cols = fontsize / 2
2) cols = fontSize / 2 - 1
2) rows = fontsize - 1 and cols <= fontsize / 2
3) rows = fontSize - 2 and cols <= fontsize/2 - 1


*/

vector<vector<char> > WordFont::jChar() {

	vector<vector<char> > jCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < jCharacter.size(); rows++) {
			for (int cols = 0; cols < jCharacter.at(0).size(); cols++) {
				if (rows == 0 || (rows == fontSize - 1 && cols <= fontSize / 2) || cols == fontSize / 2)
					jCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < jCharacter.size(); rows++) {
			for (int cols = 0; cols < jCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || (rows == fontSize - 1 && cols <= fontSize / 2) || (rows == fontSize - 2 && cols <= fontSize / 2 - 1) || cols == fontSize / 2 || cols == fontSize / 2 - 1)
					jCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return jCharacter;

}

/*

Equation of the lines when character z is not bold:

1) rows = 0
2) rows = fontsize - 1
2) rows + cols = fontsize - 1

Equation of the lines when character z is bold:

1) rows = 0
1) rows = 1
2) rows = fontsize - 1
2) cols = fontSize - 2
2) rows + cols = fontsize - 2
3) rows + cols = fontsize


*/

vector<vector<char> > WordFont::zChar() {

	vector<vector<char> > zCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < zCharacter.size(); rows++) {
			for (int cols = 0; cols < zCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == fontSize - 1 || rows + cols == fontSize - 1)
					zCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < zCharacter.size(); rows++) {
			for (int cols = 0; cols < zCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || rows == fontSize - 1 || rows == fontSize - 2 || rows + cols == fontSize - 2 || rows + cols == fontSize)
					zCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return zCharacter;

}

/*

Equation of the lines when character z is not bold:

1) rows = fontsize - 1
2) cols = 0

Equation of the lines when character z is bold:

1) cols = 0
1) cols = 1
2) rows = fontsize - 1
2) rows = fontSize - 2

*/

vector<vector<char> > WordFont::lChar() {

	vector<vector<char> > lCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < lCharacter.size(); rows++) {
			for (int cols = 0; cols < lCharacter.at(0).size(); cols++) {
				if (rows == fontSize - 1 || cols == 0)
					lCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < lCharacter.size(); rows++) {
			for (int cols = 0; cols < lCharacter.at(0).size(); cols++) {
				if (rows == fontSize - 1 || rows == fontSize - 2 || cols == 1 || cols == 0)
					lCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return lCharacter;

}

/*

Equation of the lines when character t is not bold:

1) rows = 0
2) cols = fontsize / 2

Equation of the lines when character t is bold:

1) rows = 0
1) rows = 1
2) cols = fontsize / 2
3) cols = fontsize / 2 - 1

*/

vector<vector<char> > WordFont::tChar() {

	vector<vector<char> > tCharacter(fontSize, vector<char>(fontSize, ' '));

	if (!isBold)
	{
		for (int rows = 0; rows < tCharacter.size(); rows++) {
			for (int cols = 0; cols < tCharacter.at(0).size(); cols++) {
				if (rows == 0 || cols == fontSize / 2)
					tCharacter[rows][cols] = pixelChar;
			}
		}
	}
	else {
		for (int rows = 0; rows < tCharacter.size(); rows++) {
			for (int cols = 0; cols < tCharacter.at(0).size(); cols++) {
				if (rows == 0 || rows == 1 || cols == fontSize / 2 || cols == fontSize / 2 - 1)
					tCharacter[rows][cols] = pixelChar;
			}
		}
	}

	return tCharacter;

}

/*getInput() function has a bunch of cout statements asking the user for following info - Word, FontSize, Pixel Character and whether the user wants the word drawn bold or not*/

void WordFont::getInput() {

	int temp;
	cout << "Enter a word. Characters must be in (a, e, i, o, u, x, j, z, l, t, c, b, d, f, p): ";
	cin >> word;
	cout << "Enter the pixel character which you want to use : ";
	cin >> pixelChar;
	cout << "Enter the font size (8-12) : ";
	cin >> fontSize;
	cout << "Bold? (0=No, 1=Yes) : ";
	cin >> temp;
	isBold = (temp != 0);

}

void WordFont::printOutput() {

	// the variable resultingMatrixDimensionX will have the horizantal pixels required for the entired word. Now each of the letter takes up fontSize pixels and we will insert 2 spaces between each letter 
	// therefore we use this formula resultingMatrixDimensionX = fontSize * word.length() + 2 * (word.length() - 1)

	int resultingMatrixDimensionX = fontSize * word.length() + 2 * (word.length() - 1), resultingMatrixDimensionY = fontSize * word.length();

	vector<vector<char> > resultingMatrix(fontSize, vector<char>(resultingMatrixDimensionX, ' '));

	// temp variable is used to hold each character in the word when we iterate through it
	char temp;

	// current variable is used to hold the position where each of these characters need to be drawn out. since each char will take up fontsize pixels we will iterate this variable fontSize + 2. added 2 
	// to consider the 2 extra spaces we are using to seperate the chars
	int current = 0;

	for (int i = 0; i < word.length(); i++) {
		temp = toupper(word[i]);
		switch (temp - 'A') {
		case 0:
			addCharToWord(&resultingMatrix, aChar(), current);
			break;
		case 4:
			addCharToWord(&resultingMatrix, eChar(), current);
			break;
		case 8:
			addCharToWord(&resultingMatrix, iChar(), current);
			break;
		case 14:
			addCharToWord(&resultingMatrix, oChar(), current);
			break;
		case 20:
			addCharToWord(&resultingMatrix, uChar(), current);
			break;
		case 2:
			addCharToWord(&resultingMatrix, cChar(), current);
			break;
		case 1:
			addCharToWord(&resultingMatrix, bChar(), current);
			break;
		case 3:
			addCharToWord(&resultingMatrix, dChar(), current);
			break;
		case 5:
			addCharToWord(&resultingMatrix, fChar(), current);
			break;
		case 15:
			addCharToWord(&resultingMatrix, pChar(), current);
			break;
		case 23:
			addCharToWord(&resultingMatrix, xChar(), current);
			break;
		case 9:
			addCharToWord(&resultingMatrix, jChar(), current);
			break;
		case 25:
			addCharToWord(&resultingMatrix, zChar(), current);
			break;
		case 11:
			addCharToWord(&resultingMatrix, lChar(), current);
			break;
		case 19:
			addCharToWord(&resultingMatrix, tChar(), current);
			break;
		}
		current += fontSize + 2;
	}

	for (int i = 0; i < resultingMatrix.size(); i++) {
		for (int j = 0; j < resultingMatrix[0].size(); j++) {
			cout << resultingMatrix[i][j];
		}
		cout << "\n";
	}

}

void WordFont::addCharToWord(vector<vector<char> >* word, vector<vector<char> > c, int current) {
	// this function will just copy the pixels in variable c to matrix word starting from position current
	for (int i = 0; i < (*word).size(); i++) {
		for (int j = 0, p = current; j < fontSize; j++, p++)
			(*word)[i][p] = c[i][j];
	}
}