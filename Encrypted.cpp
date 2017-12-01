#include <iostream>
#include <iomanip> 
using namespace std;

int originalNumber, key, n1, n2, n3, en1, en2, en3, s1, s3, encryptedNumber; //declare global variables

void isolateDigits();
void encryptedDigits();
void swapDigit1WithDigit3();
void recomposeNumber();

int main()
{
	cout << "Enter the original three-digit number: "; //prompt user to enter three-digit number
	cin >> originalNumber; //input three-digit number
	cout << "Enter the key: "; //prompt user to enter a key
	cin >> key; //input the key

	isolateDigits(); 
	encryptedDigits();
	swapDigit1WithDigit3();
	recomposeNumber();

	cout << setfill('0'); // fill space with 0
	cout << "The encrypted number for " << originalNumber << " is: " << setw(3) << encryptedNumber << "." << endl; //set the encrypted number to three-digits. output encrypted number.

	system("pause");
	return (0);
}

void isolateDigits()
{
	int mod; //declare local variables
	n1 = originalNumber / 100; //isolate first digit

	mod = originalNumber % 100; 
	n2 = mod / 10; //isolate second digit

	n3 = mod % 10; //isolate third digit
} //end of isolateDigits


void encryptedDigits()
{
	const short t(10); //declare 10 as a constant, referred to as t
	en1 = n1 + key % t; //add key to first digit
	if (en1 > t)
	{
		en1 = en1 - t; //if first digit is greater than 10, minus 10
	}
	if (en1 == t)
	{
		en1 = 0; //if first digit is equal to 10, make digit equal to zero
	}

	en2 = n2 + key % t; //add key to second digit
	if (en2 > t)
	{
		en2 = en2 - t; // if second digit if greater than 10, minus 10
	}
	if (en2 == t)
	{
		en2 = 0; // if second digit equal to 10, make digit equal to zero
	}


	en3 = n3 + key % t; //add key to third digit
	if (en3 > t)
	{
		en3 = en3 - t; // if third number is greater than 10, minus 10
	}
	if (en3 == t)
	{
		en3 = 0; // if third number is equal to zero, make digit equal to zero
	}
} // end of encryptDigits

void swapDigit1WithDigit3()
{
	s1 = en3; //swap first digit for the last digit
	s3 = en1; //swap last digit with first digit
} // end of swapDigit1WithDigit3

void recomposeNumber()
{
	encryptedNumber = (s1 * 100) + (en2 * 10) + s3; //join the three digits back together to form an integer again
} // end of recomposeNumber
