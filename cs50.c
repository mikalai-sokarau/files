#include <cs50.h>
#include <stdio.h>

bool check_card_number(int length, int first_sign)
{
  bool is_american_express = length == 15 && (first_sign == 34 || first_sign == 37);
  bool is_visa = (length == 13 || length == 16) && first_sign == 4;
  bool is_master_card = length == 16 && (first_sign >= 51 && first_sign <= 55);

  printf("is_a_e: %d\n, is_v: %d\n, is_m_c: %d\n", is_american_express, is_visa, is_master_card);
  return is_american_express || is_visa || is_master_card;
}

int main(void)
{
  long long card_number;
  int length;
  int first_sign;

  do
  {
    length = 0;
    long long user_input = get_long_long("Enter card number: ");
    card_number = user_input;

    while (user_input)
    {
      first_sign = user_input;
      user_input /= 10;
      length++;
    }
  } while (check_card_number(length, first_sign));

  printf("%lld\n", card_number);

  return 0;
}

confirmation modal сделать

