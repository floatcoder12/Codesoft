#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
 {
   int secretNumber, guess;

   srand(time(0));

   // Generate a random number between 1 and 50
   secretNumber = rand() % 50 + 1;

   cout << "Welcome to the Number Guessing Game!\n";
   cout << "Let's begin!\n";
   cout << "I'm thinking of a number between 1 and 50. Can you guess it?\n";

   while (true)
    {
       cout << "Enter your guess: ";
       cin >> guess;

       if (guess < 1 || guess > 50) 
       {
           cout << "Invalid guess. Please enter a number between 1 and 50.\n";
           continue;
       }

       if (guess == secretNumber) 
       {
           cout << "Applause! You guessed the number!\n";
           break;
       } 
       else if (guess < secretNumber)
        {
           cout << "Too low! Try a higher number.\n";
        }
        else 
        {
           cout << "Too high! Try a lower number.\n";
        }
   }
   
   return 0;

}



   

