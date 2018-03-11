#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void Reverse(char *begin, char *end);

void reverseWords(char *s)
{
	char *word_begin = s;
	char *temp = s; /* temp is for word boundry */

					/*STEP 1 of the above algorithm */
	while (*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			Reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ')
		{
			Reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	} /* End of while */

	  /*STEP 2 of the above algorithm */
	Reverse(s, temp - 1);
}

//
//
//int CharCount(const char* input) {
//	int messageLength = 0;
//	bool messageEnded = false;
//
//	while (!messageEnded) {
//		if (input[messageLength] == '\0') {
//			messageEnded = true;
//		}
//
//		messageLength++;
//	}
//
//	messageLength -= 1;
//	return messageLength;
//}
//
//int CountWords(const char* input) {
//	int length = CharCount(input);
//	int wordCount = 0;
//	for (int i = 0; i < length; ++i) {
//		if (input[i] == ' ') {
//			wordCount++;
//		}
//	}
//	return wordCount;
//}
//
void Reverse(char *begin, char *end)
{
	char temp;
	while (begin < end) 
	{
		temp = *begin; //temp is set to first character in range
		*begin++ = *end;/* the value in the begin position is changed to the value from the end position
						, then the begin position is incrimented down*/
		*end-- = temp; //vice-versa
	}
}

string WordReverse(const char* input) {
	char * word_begin = (char*)input; // keeps track of the beginning of the word you are currently reversing
	char * temp = (char*)input; // keeps track of the end of the word

	while (*temp) { //loop will finish once the value at temp is null, once it is pushed to the end sequeance character '\0'
		temp++; //pushes temp's address to the next char in the sequence
			if (*temp == '\0') { // if we have reached the end of the sequence, reverse everything from the beginning of this word to the last character before '\0'
				Reverse(word_begin, temp -1);
				//if this happens, (bool)*temp will resolve to false
			}
			else if (*temp == ' ') { //if we hit a space
				Reverse(word_begin, temp - 1);//reverse everything from word beginning (or beginning of series on fist loop) to temp
				word_begin = temp + 1;// move word_begin to the position after the space you just found
			}
			
	}

	return input;
}
//


//void DemonstrateCharCounter() {
//	cout << "This is a character counter. Please enter some text." << endl;
//	string input;
//	getline(cin, input);
//
//	char * message = input.c_str;
//
//	cout << "This entry has " << CharCount(message) << " characters." << endl;
//	//cout << "It has " << CountWords(message) << " words." << endl;
//
//	std::system("pause");
//
//}



void DemonstrateWordReverse() {
	cout << "This will reverse the words' spelling while keeping them in order. Please enter some text." << endl;
	string input;
	getline(cin, input);
	
	string output = WordReverse(input.c_str());
	cout << output << endl;
}


int main() {

	//DemonstrateCharCounter();
	DemonstrateWordReverse();
	std::system("pause");
	return 0;
}
