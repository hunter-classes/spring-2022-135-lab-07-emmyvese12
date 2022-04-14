#include <iostream>
// capital alphabet ascii range is [65,90] and lower alphabet ascii range is [97,122]
bool isAlpha(char c)
{
return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
char shiftChar(char c, int rShift)
{
if (!isAlpha) // if not alphabetical character
{
return c;
}
// take care of bounds
int newAscii = c + rShift;
if (newAscii > 90 && (c >= 65 && c <= 90)) // capital overflow
{
int overflow = newAscii - 90 - 1;
return (char)(65 + overflow);
}
if (newAscii > 122 && (c >= 97 && c <= 122)) // lowercase overflow
{
// std::cout << "lowercase overflow!\n";
int overflow = newAscii - 122 - 1;
return (char)(97 + overflow);
}
return (char)(newAscii);
}
std::string encryptCaesar(std::string plainTxt, int rShift)
{
std::string result = plainTxt;
for (int i = 0; i < plainTxt.length(); i++)
{
char currChar = plainTxt[i];
char shiftedChar = shiftChar(currChar, rShift);
result[i] = shiftedChar;
}
return result;
}
