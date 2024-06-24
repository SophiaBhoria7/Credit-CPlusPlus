#include <iostream>
using namespace std;

//declaration of all the functions used 
int Luhn_sum(long int credit);
int Luhn_multiply(int last_dig);
int dig_length(long int credit);
bool is_AMEX(long int credit, int digit_length);
bool is_MASCAR(long int credit, int digit_length);
bool is_VISA(long int credit, int digit_length);
bool is_DIS(long int credit, int digit_length);  

int main()
{
  //declaration of varibales being used 
  long int credit;
  int digit_length = 0;
  bool AMEX;
  bool MASCAR;
  bool VISA;
  bool DISC;
  int total_sum;

  //input taken from the user
  cout << "Please enter a number: " << endl;
  cin >> credit;

  // processing to find the length of the credit card number and the type.... 
  digit_length = dig_length(credit);
  AMEX = is_AMEX(credit, digit_length);
  MASCAR = is_MASCAR(credit, digit_length);
  VISA = is_VISA(credit, digit_length);
  DISC = is_DIS(credit, digit_length);
  
  total_sum = Luhn_sum(credit);
  //outputs with checks
  if (total_sum % 10 != 0)
  {
    cout << "INVALID CARD" << endl;
  }
  else if (AMEX == true)
  {
    cout << "This is an AMEX card" << endl;
  }
  else if (MASCAR == true)
  {
    cout << "This is a MasterCard" << endl;
  }
  else if (VISA == true)
  {
    cout << "This is a VISA card" << endl;
  }
  else if (DISC == true)
  {
    cout << "This is a Discover card" << endl;
  }
  else
  {
    cout << "This IS a Valid Card, however, our system doesn't know the type yet." << endl;
  }
  return 0;
}

//number of digits in the provided number
int dig_length(long int credit)
{
  // counter
  int count = 0;

  while (credit > 0)
    {
      credit = credit / 10;
      count = count + 1;
    }
  return count;
}

//is this a AMEX card?
bool is_AMEX(long int credit, int digit_length)
{
  int first_digits = credit / (1e13);

  if (digit_length == 15 && (first_digits == 34 || first_digits == 37))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//is this a MasterCard?
bool is_MASCAR(long int credit, int digit_length)
{
  int first_digits = credit / (1e14);

  if (digit_length == 16 && (first_digits == 51 || first_digits == 52 || first_digits == 53 || first_digits == 54 || first_digits == 55))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//is this a Visa card?
bool is_VISA(long int credit, int digit_length)
{
  int first_digits = 0;
  //accounting for both lenghts that VISA card's have
  if (digit_length == 13)
  {
    first_digits = credit / (1e12);
  }
  else if (digit_length == 16)
  {
    first_digits = credit / (1e15);
  }
  else
  {
    return false;
  }

  //looking at how the card starts
  if (first_digits == 4)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//is this a Discover card?
bool is_DIS(long int credit, int digit_length)
{
  int first_digits = credit / (1e15);

  if (digit_length == 16 && (first_digits == 6))
  {
    return true;
  }
  else
  {
    return false;
  }
}


//sum according to Luhn's algorithm
int Luhn_sum(long int credit)
{
  int total_sum = 0;
  int last_dig = 0;
  bool second_last = false;

  while (credit > 0)
    {
      if (second_last == true)
      {
        last_dig = credit % 10;
        total_sum = total_sum + Luhn_multiply(last_dig);
      }
      else
      {
        last_dig = credit % 10;
        total_sum = total_sum + last_dig;
      }
      second_last = !second_last;
      credit = credit / 10;
    }
  return total_sum;
}

//the multiplication step of Luhn's algorithm (this function is used in the Luhn_sum function)
int Luhn_multiply(int last_dig)
{
  int multi_sum = 0;
  int lst_dig = 0;
  int multi_num = last_dig * 2;

  while (multi_num > 0)
    {
      lst_dig = multi_num % 10;
      multi_sum = multi_sum + lst_dig;
      multi_num = multi_num / 10;
    }
  return multi_sum;
}
