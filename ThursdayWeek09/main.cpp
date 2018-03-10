#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int CharCount(const char* input) {
	int messageLength = 0;
	bool messageEnded = false;

	while (!messageEnded) {
		if (input[messageLength] == '\0') {
			messageEnded = true;
		}

		messageLength++;
	}

	messageLength -= 1;
	return messageLength;
}

int CountWords(const char* input) {
	int length = CharCount(input);
	int wordCount = 0;
	for (int i = 0; i < length; ++i) {
		if (input[i] == ' ') {
			wordCount++;
		}
	}
	return wordCount;
}

const char* WordReverse(const char* input) {
	int wordCount = CountWords(input);
	char * word_begin = (char*)input; // keeps track of the beginning of the word you are currently reversing
	char * temp = (char*)input; // keeps track of the end of the word

	while (*temp) { //loop will finish once the value at temp is null, once it is pushed to the end sequeance character '\0'
		temp++; //pushes temp's address to the next char in the sequence
			if (*temp == '\0') { // if we have reached the end of the sequence, reverse everything from the beginning of this word to the last character before '\0'
				Reverse(word_begin, temp -1);
				//if this happens, (bool)*temp will resolve to false
			}
			else if (*temp == ' ') { //if we hit a space
				reverse(word_begin, temp - 1);//reverse everything from word beginning (or beginning of series on fist loop) to temp
				word_begin = temp + 1;// move word_begin to the position after the space you just found
			}
			
	}

	return input;
}


void Reverse(char *begin, char *end)
{
	char temp;
	while (begin < end) 
	{
		temp = *begin;
		*begin++ = *end;// ask question about this
		*end-- = temp;
	}
}

void DemonstrateCharCounter() {
	cout << "This is a character counter. Please enter some text." << endl;
	string input;
	cin >> input;

	const char* message = input.c_str;

	cout << "This entry has " << CharCount(message) << " characters." << endl;
	//cout << "It has " << CountWords(message) << " words." << endl;

	std::system("pause");

}


void DemonstrateWordReverse() {
	cout << "This will reverse words. Please enter some text." << endl;
	string input;
	cin >> input;

	const char* message = input.c_str();

	cout << CharCount(message) << endl;


	std::system("pause");

}


int main() {
	DemonstrateCharCounter();
	DemonstrateWordReverse();
	return 0;
}
