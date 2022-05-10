#include<iostream>
#include<assert.h>
#include "GameFunctions.h"
using namespace std;
int main(){
    GameFunctions obj;

    //Testing Correct Place Checker Method
    char word[5]={'m','a','n','g','o'};
    char correct[5]={'m','a','n','g','o'};
    int count=0;
    for(int i=0;i<5;i++){
        bool res=obj.CorrectPlace(word[i],i,correct);
        if(res)
        count++;
    }
    assert(count==5);
    cout<<"Passed: Correct Place Checker Passed.";

     //Testing WrongPlace Checker Method
    char word2[5]={'o','g','m','a','n'};
    char correct2[5]={'m','a','n','g','o'};
    int count2=0;
    for(int i=0;i<5;i++){
        bool res=obj.WrongPlace(word2[i],correct2);
        if(res){
        count2++;
        }
    }
    assert(count2==5);
    cout<<"\nPassed: WrongPlace Checker Passed.";


}
