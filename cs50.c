#include <cs50.h>
#include <stdio.h>
#include <string.h>

void check_card_number(int length, int first_signs);
char card_name[] = "INVALID";

int main(void)
{
  long long card_number;
  int first_signs;
  int length;
  int result = 0;
  long long user_input;

  do
  {
    user_input = get_long_long("Enter card number: ");
    card_number = user_input;
    length = 0;

    while (user_input)
    {
      if (user_input <= 99 && user_input >= 10)
      {
        first_signs = user_input;
      }
      user_input /= 10;
      length++;
    }
  } while (user_input < 0);

  check_card_number(length, first_signs);

      for (int i = 0; i < length; i++)
  {
    int last_number = card_number % 10;

    if (i % 2 == 0)
    {
      result += last_number;
    }
    else
    {
      int multiplied_number = last_number * 2;
      result += multiplied_number > 9 ? (multiplied_number % 10) + 1 : multiplied_number;
    }
    card_number /= 10;
  }

  if (result % 10)
  {
    printf("%s\n", "INVALID");
  }
  else
  {
    printf("%s\n", card_name);
  }

  return 0;
}

void check_card_number(int length, int first_signs)
{
  bool is_american_express = length == 15 && (first_signs == 34 || first_signs == 37);
  bool is_visa = (length == 13 || length == 16) && (first_signs >= 40 && first_signs <= 49);
  bool is_master_card = length == 16 && (first_signs >= 51 && first_signs <= 55);

  if (is_american_express)
  {
    strcpy(card_name, "AMEX");
  }
  else if (is_visa)
  {
    strcpy(card_name, "VISA");
  }
  else if (is_master_card)
  {
    strcpy(card_name, "MASTERCARD");
  }
}
