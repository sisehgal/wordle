READ ME FILE FOR THE WORDLE C++ GAME. 

Welcome to Wordle, a daily online word guessing extravaganza that has surged its way into our brains, since its creation in 2013
by Josh Wardle. 

Most of you might have probably googled the daily Wordle puzzle every morning with your coffee in hand....

... pondered hours and hours over those five harmless yet mysterious and teasing little boxes....
... experienced godly levels of adrenaline and dopamine when one or even perhaps two of those boxes light up yellow, or better yet, green. 
... your minds racing to put together the right five letter combination that, when entered, will light up your iphone screen like a christmas bulb! 

For those who have not dared to play, Wordle is a game where the user is given six chances to guess a random 5 letter word.

- Correct letter in the right place == Green Box 
- Correct letter in the wrong place == Yellow Box
- Wrong Letter == Grey Box

This effective yet succinct C++ program, to simulate Wordle in the command line, has been written, compiled and run on
Windows 10, through Dev C++ and Visual Studio Code. (I attempted to compile and run on Mac OSX but could not solve the color scheme 
issue with the letters, even using ANSI codes for some reason i could not resolve. I found an interesting way using <windows.h> on stackexchange
that provided a SetColor(int value) function that worked seamlessly on Windows. I also used an extension on VS code titled C/C++ Makefile to make
my makefile as i had again had some trouble achieving this on the terminal in Mac OSX.) 

The code selects a random word from a text file of 10. The user then has to input up to 6 attempts to guess the word. 
The functions that read & select a word at random as well as check each index element of the user input with the stored word, these are all defined
in a header file that I have called GameFunctions.h that is imported. 

I have extensively commented on every block of code within the .cpp file and header file as best as I can, to give the user a clearer understanding
of how the file functions when it is compiled and run. The text file contains a selection of 10 tricky words but this can easily be expanded by the user, with appropriate adjustment mentioned in the comments within the code. For simple testing purposes when running the program, 10 words was enough although even with just 10, guessing one was hard enough sometimes!!

A test file was designed to check that the functions for comparing each index element of the user input with that of the 
Stored word seemed elegant enough to ensure the games functionality. 

As a student at the end of this course, I felt that this project really tested my knowledge of writing loops, if/else statements as well as appending data to empty lists and manipulating them. 

Wordle is a super fun game that my mother and I literally team up to do every day, despite being on two different sides of the planet. 

May you have fun with this!