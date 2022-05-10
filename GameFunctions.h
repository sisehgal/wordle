// The header file that contains the functions used in the wordle game
// tested using Windows Dev C++ & Visual Studio Code 

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;


	// Name of the class that will contain the functions employed within the main .cpp file
class GameFunctions{

public:

// The first function we have created has been called 'PickFromFile' to select a random 
// word from our text file holding a total of 10 words. The list is treated as a 2D array
// of 10 rows and 5 columns (10 words by 5 letters each)\

	char* PickFromFile(char * word1){  
	char words[10][5];
	char randomWord[5];

// An input stream is used to open the text file containing the words
// A if check makes sure that there is no error when we open the text file 
// and if there is any error, the entire method is exited 

	ifstream File;
	File.open("words.txt"); // This file contains 10 words, making testing simple 
	if(!File){              // the user can easily add more words, adjusting the parameters in line 22 and 58
		word1[0]='1';       // even import a larger text file with dictionairy contents 
		cout<<"\n\t\tError in opening Words file.";
		return word1;
	}

// This loop allows the entire text file to be read from beginning to end 
// The loop repeats itself (i is incremented) until there are no more words left 
// The words are extracted from the file using >> operator and stored in a 
// array labelled as 'word'

	int i=0;
	while(!File.eof()){
		char word[5];
		File>>word;
		for(int j=0;j<5;j++){
			words[i][j]=word[j];
		}
		i++;
	}

// Using the time as a seed - srand(time(0))
// at the beginning of the program to initialize the random seed
// time(0) returns the integer number of seconds from the system clock.
// if not used, same index number can be generated over and over again, using srand() generates a different random number every time 

	srand(time(0));
	int randomIndex=rand()%10;         // between 0 and 9 a random number will be generated, referring to word in the list 
	for(int i=0;i<5;i++){
		word1[i]=words[randomIndex][i];
	}
	return word1;
}

// Now two functions are defined when inputted letters are in the wrong or right places
// referencing the inputted word 'ch' and the real word (realWord).
// This should return True if the letter is at the correct index, else it returns false.
// Similarly, a wrong place check is implemented in the exact same way, true if letter is 
// in the wrong place, false if it is in the right place
// This serves as the suitable test method for the game

bool CorrectPlace(char ch,int index,char *realWord){
		if(ch==realWord[index]){
			return true;
	}
	else{
		return false;
	}
}

bool WrongPlace(char ch,char *realWord){
		for(int i=0;i<5;i++){  
	   	if(ch==realWord[i]  ){
	   		return true;
		   }
        }
	   return false;

}

};