#include "Model.h"

Model::Model(){}
Model::~Model(){}

/*
  takes a single character as input and returns a string
  representing its encoding in Tutnese. Capitalization should be preserved.
*/
string Model::translateSingleCharacter(char single)
{
  char temp = tolower(single);
  string translate;
  // if the char is not a vowel
  if (temp != 'a' || temp != 'e' || temp != 'i' || temp != 'o'|| temp != 'u')
  {
    translate = single;
    // append proper replacement for given char, w/ preserved capitalizaiton
    if (temp == 'b' || temp == 'y' || temp == 'z' || temp == 'p')
    {
      translate.append("ub");
    }
    else if (temp == 'c' || temp == 'h')
    {
      translate.append("ash");
    }
    else if (temp == 'd')
    {
      translate.append("ud");
    }
    else if (temp == 'f')
    {
      translate.append("uf");
    }
    else if (temp == 'g')
    {
      translate.append("ug");
    }
    else if (temp == 'j')
    {
      translate.append("ay");
    }
    else if (temp == 'k')
    {
      translate.append("uck");
    }
    else if (temp == 'l')
    {
      translate.append("ul");
    }
    else if (temp == 'm')
    {
      translate.append("um");
    }
    else if (temp == 'n')
    {
      translate.append("un");
    }
    else if (temp == 'q')
    {
      translate.append("uack");
    }
    else if (temp == 'r')
    {
      translate.append("ug");
    }
    else if (temp == 's')
    {
      translate.append("us");
    }
    else if (temp == 't')
    {
      translate.append("ut");
    }
    else if (temp == 'v')
    {
      translate.append("uv");
    }
    else if (temp == 'w')
    {
      translate.append("ack");
    }
    else if (temp == 'x')
    {
      if (isupper(single))
      {
        translate = "Ex";
      }
      else
      {
        translate = "ex";
      }
    }
  }
  else
  {
    // keep vowels
    translate = single;
  }
  return translate;
}

/*
  takes a single character as input that appears twice in
  a row and returns a string representing its encoding in Tutnese. Capitalization
  should be preserved.
*/
string Model::translateDoubleCharacter(char doubleChar)
{
  char temp = tolower(doubleChar);
  string translate;
  // if the char is a vowel, give proper replacement, append char
  if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
  {
    if (isupper(doubleChar))
    {
      translate = "Squat";
    }
    else
    {
      translate = "squat";
    }
    translate.push_back(temp);
  }
  else
  {
    // if not a vowel, give proper replacement, append char
    if (isupper(doubleChar))
    {
      translate = "Squa";
    }
    else
    {
      translate = "squa";
    }
    translate.append(translateSingleCharacter(temp));
  }
  return translate;
}
