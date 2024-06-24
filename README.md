# Credit C++
This is the Credit Problem Set that is given in the CS50: Intro to CS Problem Sets but in the language of C++ with a few modifications from my side included as well { allows me to not only practice some coding but also place authenticity with a new lanugage and expands my exposure}

/*
Directions from CS50 Course plus extra bits from my side: 

Using the Luhn's Algorithm (which is stated below), validate a credit card number.
  If the credit card number isn't valid, print out that the input is an INVALID card number. 
  If the credit card is valid, print out if it's a VISA, MasterCard, American Express, or Discover card. 
  If the credit card is valid, however, the type isn't found in the system, let the user know that this is a valid card, however, our system can't detect which type of card it is. 

  ***** ALL OF THIS IS ASSUMING THAT THE USER INPUTS THE CARD NUMBER WITHOUT HYPHENS OR OTHER SPECIAL CHARACTERS (INCLUDING LETTERS)... IF THE USER INPUTS THE CARD NUMBER WITH HYPHENS OR OTHER SPECIAL CHARACTERS, THEN THE SYSTEM WON'T WORK PROPERLY *****

  Luhn's Algorithm that was used:
  1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.

  2. Add the sum to the sum of the digits that weren’t multiplied by 2.

  3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

*/
