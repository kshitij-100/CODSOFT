#include<iostream>

using namespace std;


int main()
{
  float num1,num2;
  char operation;

  cout<<"\nEnter first number: ";
  cin>>num1;
  cout<<"Enter second number: ";
  cin>>num2;

  cout<<"\nEnter operation (+,-,*,/) to perform: ";
  cin>>operation;


    switch (operation)
    {
    case '+':
        cout<<"\nAddition of "<<num1<<" and "<<num2<<" is "<<num1+num2;
      break;

    case '-':
        cout<<"\nSubstraction of "<<num1<<" and "<<num2<<" is "<<num1-num2<<endl;
      break;

    case '*':
        cout<<"\nMultiplication of "<<num1<<" and "<<num2<<" is "<<num1*num2<<endl;
      break;

    case '/':
        if(num2 != 0)
        {
          cout<<"\nDivision of "<<num1<<" and "<<num2<<" is "<<num1/num2<<endl;
        }
        else{
          cout<<"\nError. Divisor can't be zero.";
        }
      break;
    
    default:
      cout<<"\nInvalid choice! Please try again...";
    break;
    }

  return 0;
}

