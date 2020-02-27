#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *__cdecl check2(char *input)
{
  char b[50]; // [esp+18h] [ebp-50h]
  char a[6]; // [esp+4Ah] [ebp-1Eh]
  int num3; // [esp+50h] [ebp-18h]
  int j; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  int pos; // [esp+5Ch] [ebp-Ch]

  strcpy(a, "flag{");
  memset(b, 0, 0x30u);
  b[48] = 0;
  pos = 5;
  for ( i = 0; ; ++i )
  {
    num3 = strlen(input);
    if ( num3 - 1 <= pos )
      break;
    if ( input[pos] == 45 )
      --i;
    else
      b[i] = input[pos];
    ++pos;
  }
  for ( j = 0; j <= 4; ++j )
  {
    if ( input[j] != a[j] )
    {
      printf("0");
      exit(0);
    }
  }
  if ( input[13] != input[28] )
  {
    printf("0");
    exit(0);
  }
  if ( input[13] != input[18] )
  {
    printf("0");
    exit(0);
  }
  if ( input[13] != input[23] )
  {
    printf("0");
    exit(0);
  }
  if ( input[13] != 45 )
  {
    printf("0");
    exit(0);
  }
  if ( input[41] != 125 )
  {
    printf("0");
    exit(0);
  }
  return strcpy(input, b);
}
