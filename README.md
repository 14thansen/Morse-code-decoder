# Morse-code-decoder
Program allows you decode and encode morse code messages.

# example code
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
This portion of the code searches for spaces in the morse code, marking individual letters, and converts them into germanic letters. I had a hard time working this portion out but I think it turned out nicely.

# Motivation
I created this project primarily for a school project. I chose to create a Morse code decoder because I knew it would be a challenge for me and would help me expand my knowledge with strings, arrays, and sequential text files.

# Installation
Download project with the link 'C++ final project.cpp', all additional files are created in the script.

# Tests
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
When testing the program you will be given these options, as you select an option futher instructions will be given.

