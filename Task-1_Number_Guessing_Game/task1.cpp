#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
  
void guessNum();
string name;

int main()
{
  int limit = 100, choice, guess;

  cout<<"\n***********Welcome to Number Guessing Game**************\n"<<endl;
  cout<<"Please enter your name:   ";
  getline(cin,name);

  do{
    cout<<"\n1: Start the Game"<<endl;
    cout<<"0: Exit the Game"<<endl;
    cout<<"\n===>Enter your choice: ";
    cin>>choice;

    if (choice==1)
    {
      guessNum();
      cout<<"\nWant to play again? (1 : Yes and 0 : No): ";
      cin>>choice;
    }

  }while (choice==1);

   cout<<"\nExiting Game....Come back again";
  
  return 0;
}

void guessNum()
{
  int randNum, guess;
  srand(time(0));
  randNum = rand() % 100;  //generating a random number
  cout<<"\nEnter any number in between range 1 to 100 : ";
  
  do
  {
    cin>>guess;
    if(guess==randNum)
    {
      cout<<"\nCongratulations "<<name<<"! You guessed the correct number...."<<endl;
    }
    else if (guess<randNum)
    {
      cout<<"\nYour guess is too low....Please try again"<<endl;
      cout<<"\nEnter another number : ";
    }
    else if (guess>randNum)
    {
      cout<<"\nYour guess is too high....Please try again"<<endl;
      cout<<"\nEnter another number : ";
    }
    
  } while (guess!=randNum);
  
  cout<<"Game End...\n";
  
}