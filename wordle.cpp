// This is the main .cpp file for the wordle game
// performed, typed and tested on Windows 10 as my Mac OSX system was just not cooperating. 
// tested using Windows Dev C++ & Visual Studio Code 

#include <iostream>
#include "GameFunctions.h" // header file with our functions to run game
#include<stdlib.h>
#include<windows.h> 

using namespace std;


// METHOD for color coding of the letters in the wrong and right places
// Using a method found on the internet, each possible color is assigned a numeric value
// the SetColor function takes one argument, an integer between 1 and 16. 
// Tried using the ANSI code method on mac but for some reason this method on my windows laptop 
// worked more smoothly, found more help on this method via stack exhange. 

void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}


// Now entering the main part of the program 
// define our variables, note how our functions headerfile is listed as an obj
// so that we can interface with it here and call on the functions previously 
// written and made public.

int main(){

    char choice;         		  // choice to play the game again or not       
	GameFunctions obj;    		 // our header file containing functions now an object to interact with
	char *word;           		 // public variable to hold the random word from the text file
	word=new char[5];     		 // This is a pointer to an array of chars. Array is allocated from the heap
	int result[5]={-1,-1,-1,-1,-1}; // -1 is simply a place holder array is empty 

	do{
	system("CLS");                // clear screen , when user reaches choice at bottom and selects 'y', screen clears and game restarts with new word
	SetColor(7);                  // Setting a color scheme (7 = light grey)
	word=obj.PickFromFile(word);  // calling on the PickFromFile function to randomly select a word from the text file 
	if(word[0]=='1'){            // the selected word assigned to variable 'word'
		return 0;
	}

// We now take a five letter input from the user, defined as a 5 index array called 'userword'
// we also take into account that each letter can either be in the wrong place or just wrong (not present at all)
// and define variables for those possibilities as well, operate on them when checking the letters at each index 
// using cin and cout operators, user inputs the first attempt
// the checking process of right place, wrong letter, wrong place is looped over all the indexes of the 5 letter inpu

	for(int i=0;i<6;i++){     // i represents the attempt number, 1, 2, 3, 4, 5 and 6. All subsequent loops are performed 6 times
	int correct[5]={-1,-1,-1,-1,-1},wrongplace[5]={-1,-1,-1,-1,-1},wrong[5]={-1,-1,-1,-1,-1};
	char userWord[5]={'*','*','*','*','*'};     // asterix as place holder, user input will be stored in this array 
	SetColor(7);
	cout<<"\n\n\t======LETS PLAY WORDLE!======\n\n";
	cout<<"\n\t\t Attempt Number: "<<i+1<<"\n"<<endl;
	cout<<"\t\t Enter 5 letters (in lowercase):";
    cin>>userWord;

// VALIDATING THE INPUT 
// setting limits on each character, making sure each index exists within and including a to z

	while(!((userWord[0]>='a' && userWord[0]<='z') && (userWord[1]>='a' && userWord[1]<='z') && (userWord[2]>='a' && userWord[2]<='z')
	&& (userWord[3]>='a' && userWord[3]<='z') && (userWord[4]>='a' && userWord[4]<='z'))){  //this loop will keep executing until valid input is given 
	
		cout<<"\t\t Please enter 5 letters (lowercase):";
		cin>>userWord;
	}

// Calling on our CorrectPlace and WrongPlace functions from the header file
// This checks if any letter for each index is in the right place or wrong place 
// if the letter of the jth index of the user input matches that for the stored word ('word') that 
// we are trying to guess, returns true. else returns false and process iterates over the 5 indexes 
// CorrectPlace( char ch, int index, char* realword) inital definition of its arguments, now using user input and comparing 
// indexes with actual stored word 

    cout<<"\n\t\t";
	for(int j=0;j<5;j++){                           // checking if any letter is at correct place
	    if(obj.CorrectPlace(userWord[j],j,word)){   // appending index of userword to empty array 'correct'
	    	correct[j]=j;                           // j is current index we are looping 0,1,2,3,4, we are storing the index of the user input 
	    											// only correct indexes stored, remaining will be -1 (simply empty)
			}

		else if(obj.WrongPlace(userWord[j],word)){  // checking if any letter is at wrong place
			wrongplace[j]=j;                        // appends j index to empty array 'wrongplace'
			}
	
		else{ 										//if the letter itself is wrong
			wrong[j]=j;                             // appends j index to empty array 'wrong'
			}
		}


// we now have 3 arrays filled 	
// Printing output of each guess attempt, with the corresponding color schemes for each situation
// SetColor(6) == Yellow color (right letter wrong place)
// SetColor(2) == Green color (right letter right place)
// SetColor(8) == Grey color (wrong letter)
// SetColor(7) == White color (standard)

	for(int j=0;j<5;j++){
		if(correct[j]==j){          			// for correct letter and correct place, hence we use the correct[5] array stored with the right letters in order
			SetColor(2);            			// setting green color
			cout<<userWord[j]<<" "; 			// displaying the contents of the user input, in green color
			result[j]=1;						// if the 5 elements contain 1, user entered all the correct letters and array is now filled, hence now 1 not -1
		}                                       // -1 changing to 1 within result indicates correct letter at correct index is stored. 

		else if(wrongplace[j]==j){				// for correct letter and wrong place, we use the wrongplace[5] array stored with right letters in wrong order
			int word_duplicates=0;				// this loop is to handle if one letter is repeated multiple times within the guess, duplicates in stored word
			int userword_duplicates=0;          // how many duplicate letters exist in the user input 
			for(int k=0;k<5;k++){               // j is fixed for every 5 interation of this loop as k is incremented, j = 0, k = 0 1 2 3 4, j = 1, k = 0 1 ...
				if(word[k]==userWord[j])
				word_duplicates++;              // counter for how many duplicates of a letter we have. 
			}
			for(int k=0;k<5;k++){
				if(userWord[k]==userWord[j]){  // giving an instance, if stored word is apple and user inputs aaple, we want to make sure that second 'a' is grey
					userword_duplicates++;      // and not yellow. We track the repeated letters and any excess duplicates of a letter that is correct or correct 
				}                               // in the wrong position, must be grey and not colored. 
			}
			int gap=word_duplicates-userword_duplicates;
			if(gap==0){                         // another example, if the stored word is apple and the user inputs 'aaale', gap = 3 - 1 = 2 not equal to 0 
				SetColor(6);         			// hence the 2nd and 3rd a's are grey, not yellow or green 
				cout<<userWord[j]<<" ";	        // another example, set word is apple and the user inputs ''appel', 4th and 5th letters will be yellow. 
			}
			else{
				SetColor(8);        			//setting grey color also if character repeated
				cout<<userWord[j]<<" ";
			}
		}
		else{
			SetColor(8);            			//setting grey color
			cout<<userWord[j]<<" ";
		}
	}



		SetColor(7);               			   // setting color as white 
		int count=0;               		       // counting how many times result element contains 1
        for(int k=0;k<5;k++)				   // defining count variable to keep track of the number of guesses user has made, limit at 5, like actual game
          if(result[k]==1){
          	count++;
		  }

		// For count equalling to 5, this means that all the 5 letters were at correct place
		// we should see a winner banner

		if(count==5){
		  	cout<<"\n\n\t======Winner!======";
		  	break;
		  }

		// if the count<5 and i=5 which means till the last attempt there is no correct word entered, all 5 correct letters have not been inputted  

		if(count<5 && i==5){                   // double AND meaning that both conditions must be TRUE for this if condition to execute 
		    cout<<"\n\n\t=====You Used All Your attempts Sorry!======";
		    cout<<"\n\n\t=====The correct word was: "<< word <<"========"; // user can see at the end of 6 attempts what the actual stored word was 
			}		
	   }
	
    cout<<"\n\n\t\tDo you play again? (y or n): ";
    cin>>choice;

    }while(choice=='y'||choice=='Y');       // OR Statement (small or capital y input is same result) while loop with yes or no statements implemented 
    										// here so that user can restart game with a new random word selected, go back to do{} line 37 and screen clears fresh 
}                                           