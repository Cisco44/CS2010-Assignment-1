#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

#define ROW 50 		// Number of words.
#define COLUMN 21 	// Number of characters.
#define MAXWORD	50	// Number of maximum length of words.

using namespace std;

/*
	Author: Da Costa, Francisco
	Student ID: 5026516
	Purpose:
		The following program will read string inputs, documents the input
		words in 2D arrays, and outputs all the used words in the file and the number
		of occurances. 

*/

static char dict [ROW][COLUMN];
static char buffer [MAXWORD];
static char ch = '\0';

static int freq [ROW];
static int leng = 0;
static int numWords = 0;

void DumpDictionary();
void SearchDictionary(char []);

void SearchDictionary(char buff []){
	
	leng = strlen(buff);

	// Test to verify that the buffered word doesn't exceed the maximum char length.
	if(leng < 20){

			int i = 0;
			// Check to see if the word exists in dictionary.
			while(i < numWords){
				if(strcmp (buff, dict[i]) == 0){
				   freq[i]++; 
                                   break;
                                }
				i++;					
			} 
			// Addition of new words to the dictionary.
			if(numWords == i){ 
					strcpy(dict[i], buff);
                        		freq[numWords] = 1;
					numWords++;
			}
	}
	// Output if word exceeds maximum char length.	
	else{ 
		cout << "\nThe word <" << buff << "> is too big for dictionary." << endl;
		cout << "<"<< buff << "> will be excluded from dictionary."<< endl;
		
	}

leng = 0;
	
}

void DumpDictionary(){

	cout << "\nDICTIONARY DUMP" << endl << "Number of words = " << numWords << endl << endl;
	cout << "Word		Frequency" << endl;
	cout << "-------------------------" << endl;
	
	// Writing the words and their frequencies to the console.
	for(int i = 0; i < numWords; i++){		
		cout << dict[i];
		for(int j = 0; j < 24 - strlen(dict[i]); j++) cout << ' ';
		cout << freq [i] << endl;	
	}
}

int main() {

	// Flag to test if a word is in the buffer.
	int buffOcc = 0; 

	// Checks to see if there are characters to read.
	while( cin.good()) { 		
		
		if(numWords == ROW){
			cout << "\nMaximum number words reached." << endl;
			cout << "Dumping dictionary." << endl;
			break;
		}

		// Retreives a character input. Also changes the char to lowercase.
		ch = tolower(cin.get()); 
	
		// Tests the input to verify if it is "a" to "z" or "A" to "Z". Then adds char to the buffer.
		if ( isalpha(ch) ) {  		 
			buffer[leng++] = ch;
			buffOcc = 1;
		}

		// Adds null char to the end of the buffer. Sets the buffer occupied to false.
 		else if(buffOcc){
			buffer[leng] = '\0';
			buffOcc = 0;
			SearchDictionary(buffer);
		}
	}

	DumpDictionary();
}
