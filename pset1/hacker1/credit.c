// Amex uses 15 digit numbers, all cards star with 34 or 37
// Visa uses 13 and 16 digit numbers, all cards start with 51, 52, 53, 54, or 55
// Mastercard uses 16 digit numbers, all cards start with 4

/*
Hahns Peter Luhn Algorithm

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.

2. Add the sum to the sum of the digits that weren’t multiplied by 2.

3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// calculate number of digits
// known bug, if the number starts with a zero, no error is thrown
int numberofdigits(long long num)
{
    int digits = 0;
    for (long long int temporary = num; 
        temporary > 0; temporary /= 10, digits++); 
    return digits;
}

// based on Luhn's checksum algorithm 
const char* validate(long long cardnumber)
{
  int even_sum = 0, odd_sum = 0, total = 0;
  int digits = numberofdigits(cardnumber);
  
  for (int i = 0; i < digits; i++,cardnumber /= 10) 
  {
    // get last digit of card number
    int thisdigit = cardnumber % 10; 
    
    if (i % 2 == 1)
    {
      int prod_dig_sum = 0;
      
      thisdigit *= 2;
      prod_dig_sum += (thisdigit % 10) + (thisdigit / 10);
      even_sum += prod_dig_sum;
    }
    
    else 
    {
      odd_sum += thisdigit;
    }
  }
  
  total = odd_sum + even_sum;
  
  if (total % 10 == 0)
  {
    return "VALID";
  }
  
  else 
  {
    return "INVALID";
  }
  
  return "INVALID";
}

// determine whether Amex, Visa, or Mastercard
const char* cardtype(long long cardnumber)
{
  int digits = numberofdigits(cardnumber);
  int check = (cardnumber / (long long int ) pow(10, digits - 1));
  int check2 = (cardnumber / (long long int ) pow(10, digits - 2));
  const char* valid_card = validate(cardnumber);
  
  if (strcmp(valid_card, "VALID") == 0)
  {
    
    // Visa verification
    if (check == 4 && (digits == 16 || digits == 13))
    {
      return "VISA";
    }
    
    // American Express verification
    else if (check == 3 && digits == 15)
    {
      if ((check2 == 37) || (check2 == 34))
      {
       return "AMEX"; 
      }
      else 
      {
        return "INVALID";
      }
    
    }
    
    // Mastercard verification
    else if (check == 5 && digits == 16)
    {
      if ((check2 == 51) || (check2 == 52) || (check2 == 53) || (check2 == 54) || (check2 == 55))
      {
       return "MASTERCARD"; 
      }
      else 
      {
        return "INVALID";
      }
    }
    else 
    {
     return "INVALID"; 
    }
  }
  return "INVALID";
}


int main(void)
{
    long long card;
    
    do
    {
        printf("Number: ");
        scanf("%llu", &card);;
    }
    
    while (card < 0);
    
    printf("%s\n", cardtype(card));

}