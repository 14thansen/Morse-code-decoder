#include <iostream>
#include <string>
#include <fstream>

//function prototypes
void englishToMorse(int toGo);
void morseToEnglish(int toGo);
void convoMode();
void recentWords();
void recentCodes();

using namespace std;
int main(int argc, char *argv[]) 
{
	//declare variables
	int menuOption = 0;
	
	//give menu options
	cout << "Morse code rules:" << endl;
	cout << "The length of a dot is one unit." << endl;
	cout << "A dash is three units." << endl;
	cout << "The space between parts of the same letter is one unit." << endl;
	cout << "The space between words is seven units (Represented by a forward slash in this program)." << endl;
	while (menuOption != 7)
	{
		cout << endl;
		cout << "1  English to Morse code" << endl;
		cout << "2  Morse code to English" << endl;
		cout << "3  Conversation mode" << endl;
		cout << "4  Recently encoded words" << endl;
		cout << "5  Recently decoded words" << endl;
		cout << "6  Clear memory" << endl;
		cout << "7  Exit program" << endl;
		cout << "Enter menu option: ";
		cin >> menuOption;
		cout << endl;
		//use correct function
		if (menuOption == 1)
			englishToMorse(0);
		else 
			if (menuOption == 2)
				morseToEnglish(0);
			else 
				if (menuOption == 3)
					convoMode();
				else 
					if (menuOption == 4)
						recentWords();
					else 
						if (menuOption == 5)
							recentCodes();
						else
							if (menuOption == 6)
							{
								ofstream outFileA;
								ofstream outFileB;
								outFileA.open("words.txt", ios::out | ios::trunc);
								outFileB.open("code.txt", ios::out | ios:: trunc);
								outFileA.close();
								outFileB.close();
								cout << "Memory cleared." << endl << endl;
							}
							else 
								menuOption = 7;
							//end if
						//end if
					//end if
				//end if
			//end if
		//end if
	}//end while
}//end of main function

//*****function definitions*****
void englishToMorse(int toGo)
{
	//declare constants and variables
	const string ENGLISH[45] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
								"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
								"U", "V", "W", "X", "Y", "Z", " ", "1", "2", "3",
								"4", "5", "6", "7", "8", "9", "0", ".", ",", "?",
								"!", ":", "\"", "'", "="};
	const string MORSE[45] =   {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
								"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
								"..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", 
								"...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
								".-.-.-", "--..--", "..--..", "..--.", "---...", ".-..-.", ".----.", "-...-"};
	string origPhrase = "";
	string newPhrase = "";
	string phrase = "";
	int word = 0;
	int kill = 0;
	
	//open file
	ofstream outFile;
	outFile.open("words.txt", ios:: app);
	
	cout << "Enter a word or a phrase (press [enter] to exit): ";
	if (toGo == 0)
		cin.ignore(100, '\n');
	getline(cin, origPhrase);
	transform(origPhrase.begin(), origPhrase.end(), origPhrase.begin(), ::toupper);
	
	if (outFile.is_open())
	{
		for (int word = 0; word < origPhrase.length(); word += 1)
		{
			for (int sub = 0; sub <= 45; sub += 1)
			{
				if (origPhrase.substr(word, 1) == ENGLISH[sub])
				{
					phrase = MORSE[sub];
					kill = 1;
				}//end if
				if (sub == 45 && kill == 0)
					phrase = origPhrase.substr(word, 1);
				//end if
			}//end for
			newPhrase += phrase;
			newPhrase += " ";
			kill = 0;
		}
		cout << "--> " << newPhrase << endl << endl;
		outFile << origPhrase << '#' << newPhrase << endl;
	}
	else 
		cout << "File could not be opened." << endl;
	//end if
	outFile.close();
}//end of englishToMorse function

void morseToEnglish(int toGo)
{
	//declare constants and variables
	const string ENGLISH[45] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", 
								"k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
								"u", "v", "w", "x", "y", "z", " ", "1", "2", "3",
								"4", "5", "6", "7", "8", "9", "0", ".", ",", "?",
								"!", ":", "\"", "'", "="};
	const string MORSE[45] =   {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
								"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
								"..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", 
								"...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
								".-.-.-", "--..--", "..--..", "..--.", "---...", ".-..-.", ".----.", "-...-"};
	string origPhrase = "";
	string newPhrase = "";
	string phrase = "";
	string temp = "";
	int space = 0;
	int run = 0;
	int location = 0;
	int kill = 0;
	
	//open file
	ofstream outFile;
	outFile.open("code.txt", ios :: app);
	
	cout << "Enter a word or a phrase in morse code, seperate each word by a space," << endl;
	cout << "a forward slash and another space ' / '. Seperate each letter by a single" << endl;
	cout << "space (press [enter] to exit): ";
	if (toGo == 0)
		cin.ignore(100,'\n');
	getline(cin, origPhrase);
	temp = origPhrase + " ";
	space = 0;
	
	if (outFile.is_open())
	{
		for (int x = 0; x < temp.length(); x += 1)
		{
			if (temp.substr(x, 1) == " ")
				space += 1;
		}
		//end for
		do
		{
			location = temp.find(" ", 0);
			for (int sub = 0; sub < 45; sub += 1)
			{
				if (temp.substr(0, location) == MORSE[sub])
				{
					phrase = ENGLISH[sub];
					newPhrase += phrase;
					temp.erase(0, location + 1);
					kill = 1;
					break;
				}
				//end if
				if (sub == 45 && kill == 1)
				{
					phrase = temp.substr(0, location);
					newPhrase += phrase;
					temp.erase(0, location + 1);
				}
				//end if
			}//end for
			location = 0;
			space -= 1;
		} while (space > 0);
		//end repeat
		cout << "--> " << newPhrase << endl << endl;
		outFile << origPhrase << '#' << newPhrase << endl;
	}
	else 
		cout << "File could not be opened." << endl;
	//end if
	outFile.close();
}//end of morseToEnglish function

void convoMode()
{
	string enter = "";
	
	cout << "Converstation mode allows you to encode and decode" << endl;
	cout << "sentances repeatedly, starting with encoding." << endl;
	cout << "When prompted by \"Continue...\" press [enter] to continue" << endl;
	cout << "the converstation or press [space] [enter] to leave converstation mode" << endl << endl;
	cout << "Continue..." << endl;
	cin.ignore(100, '\n');
	getline(cin, enter);
	while (enter.length() == 0)
	{
		englishToMorse(1);
		morseToEnglish(1);
		cout << "Continue..." << endl;
		getline(cin, enter);
	}
}// end of convoMode function

void recentWords()
{
	//open file
	ifstream inFile;
	inFile.open("words.txt");
	
	//declare variables
	string code = "";
	string word = "";
	
	//display file
	if (inFile.is_open())
	{
		getline(inFile, word, '#');
		getline(inFile, code);
		
		while (!inFile.eof())
		{
			//display words
			if (word.length() > 0)
				cout << word << " --> " << code << endl;
			getline(inFile, word, '#');
			getline(inFile, code);
		}//end while
	}
	else 
		cout << "File could not be opened." << endl;
	//end if
}//end recentWords function

void recentCodes()
{
	//open file
	ifstream inFile;
	inFile.open("code.txt");
	
	//declare variables
	string code = "";
	string word = "";
	
	//display file 
	if (inFile.is_open())
	{
		getline(inFile, code, '#');
		getline(inFile, word);
		
		while (!inFile.eof())
		{
			//display words
			if (code.length() > 0)
				cout << code << " --> " << word << endl;
			getline(inFile, code, '#');
			getline(inFile, word);
		}//end while
	}
	else 
		cout << "File could not be opened." << endl;
	//end if
}//end of recentCodes function