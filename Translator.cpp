#include "Translator.h"

Translator::Translator(){}
Translator::~Translator(){}

/*
  takes a single string representing a single English word as
  input and returns a string representing the Tutnese translation.
*/
string Translator::translateEnglishWord(string word)
{
  Model model;
  char current;
  string translate;
  // iterate over word size
  for (int i = 0, n = word.size(); i < n; ++i)
  {
    current = word.at(i);

    // If not in the alphabet, add char
    if (!isalpha(current))
    {
      translate += current;
    }
    /*
      i+1 != n to avoid non-existing index,
      and check if the current char is the same as the next (aka double char)
    */
    else if (i + 1 != n && tolower(current) == tolower(word.at(i+1)))
    {
      // translate current char, double char
      translate += model.translateDoubleCharacter(current);
      ++i;
    }
    else
    {
      // if current char is a single char, translate
      translate += model.translateSingleCharacter(current);
    }
  }
  return translate;
}

/*
  takes a single string representing a single English
  sentence as input and returns a string representing the Tutnese translation. Make
  sure to account for punctuation.
*/
string Translator::translateEnglishSentence(string sentence)
{
  string translate;
  string word = "";
  char currentChar;
  int counter = 0;
  // iterate over sentence size
  for (int i = 0, n = sentence.size(); i < n; ++i)
  {
    currentChar = sentence.at(i);
    /*
        check for a space to indicate the end of a word,
        and check if at the end of the sentence
    */
    if (!isspace(currentChar) && i != n-1)
    {
      word += currentChar;
    }
    else
    {
      // if at the end of the sentence, add char
      if (i == n-1)
      {
        word += currentChar;
      }
      // translate word and add space at the end
      translate += translateEnglishWord(word + " ");
      word = "";
    }
  }
  return translate;
}

string Translator::translateTutWord(string tutWord)
{
  string translate = "";
  char temp;
  char initial;
  char twice;
  bool upper = false;
  int counter = 0;
  int wordSize = tutWord.size();
  // while not at end of word
  while (counter != wordSize)
  {
    // get current char
    initial = tutWord.at(counter);
    // if the char is in the alphabet, check if it's uppercase
    if (isalpha(initial))
    {
      upper = isupper(initial);
      temp = tolower(initial);
    }
    else
    {
      // else add char to translate string
      translate.push_back(initial);
      counter++;
      continue;
    }
    // switch case statement for different chars
    switch (temp)
    {
      case 's':
        // squatut case
        if (counter + 7 < wordSize && (tutWord.substr(counter, 7) == "squatut" || tutWord.substr(counter, 7) == "Squatut"))
        {
          if (upper)
          {
            translate.append("Tt");
          }
          else
          {
            translate.append("tt");
          }
          counter += 7;
        }
        // if there is squat, check letter after, add to string twice
        else if (counter + 5 < wordSize && (tutWord.substr(counter, 5) == "squat" || tutWord.substr(counter, 5) == "Squat"))
        {
          twice = tutWord.at(counter + 5);
          if (upper)
          {
            translate.push_back(toupper(twice));
            translate.push_back(twice);
          }
          else
          {
            translate.push_back(twice);
            translate.push_back(twice);
          }
          counter += 6;
        }
        // if there is squa, check letter after, add to string twice, skip remaining letters of
        else if (counter + 4 < wordSize && (tutWord.substr(counter, 4) == "squa" || tutWord.substr(counter, 4) == "Squa"))
        {
          twice = tutWord.at(counter + 4);
          if (counter + 5 < wordSize && twice == 'e' && tutWord.at(counter + 5) != 'x')
          {
            counter += 5;
          }
          else if (twice == 'b' || twice == 'd' || twice == 'f' || twice == 'g' ||
          twice == 'j' || twice == 'l' || twice == 'm' || twice == 'n' ||
          twice == 'p' || twice == 'r' || twice == 's' || twice == 'v' ||
          twice == 'y' || twice == 'z')
          {
            counter += 7;
          }
          else if (twice == 'c' || twice == 'h' || twice == 'k' || twice == 'w')
          {
            counter += 8;
          }
          else if (twice == 'q')
          {
            counter += 9;
          }
          // if squaex, apend xx or Xx depending on capitalization
          if (counter + 5 < wordSize && twice == 'e' && tutWord.at(counter + 5) == 'x')
          {
            if (upper)
            {
              translate.append("Xx");
            }
            else
            {
              translate.append("xx");
            }
            counter += 6;
          }
          else
          {
            if (upper)
            {
              translate.push_back(toupper(twice));
              translate.push_back(twice);
            }
            else
            {
              translate.push_back(twice);
              translate.push_back(twice);
            }
          }
        }
        // if the char is just s and not squat or squa, add char
        else
        {
          if (upper)
          {
            translate.push_back(initial);
          }
          else
          {
            translate.push_back(temp);
          }
          counter += 3;
        }
        break;
      // special case for e since it could be ex which is x
      case 'e':
        if (counter + 1 < wordSize && tutWord.at(counter + 1) == 'x')
        {
          if (upper)
          {
            translate.push_back('X');
          }
          else
          {
            translate.push_back('x');
          }
          counter += 2;
        }
        else
        {
          if (upper)
          {
            translate.push_back(initial);
          }
          else
          {
            translate.push_back(temp);
          }
          counter++;
        }
        break;
      // add vowels
      case 'a':
      case 'i':
      case 'o':
      case 'u':
        if (upper)
        {
          translate.push_back(initial);
        }
        else
        {
          translate.push_back(temp);
        }
        counter++;
        break;
      // add consonants, increment counter the same as they are all same length
      case 'b':
      case 'd':
      case 'f':
      case 'g':
      case 'j':
      case 'l':
      case 'm':
      case 'n':
      case 'p':
      case 'r':
      case 't':
      case 'v':
      case 'y':
      case 'z':
        if (upper)
        {
          translate.push_back(initial);
        }
        else
        {
          translate.push_back(temp);
        }
        counter += 3;
        break;
      // add char, increment counter the same since they are of same length
      case 'c':
      case 'h':
      case 'k':
      case 'w':
        if (upper)
        {
          translate.push_back(initial);
        }
        else
        {
          translate.push_back(temp);
        }
        counter += 4;
        break;
      case 'x':
        if (upper)
        {
          translate.push_back(initial);
        }
        else
        {
          translate.push_back(temp);
        }
        counter++;
        break;
      case 'q':
        if (upper)
        {
          translate.push_back(initial);
        }
        else
        {
          translate.push_back(temp);
        }
        counter += 5;
        break;
      default:
        translate.push_back(initial);
        counter++;
        break;
    }
  }
  return translate;
}

string Translator::translateTutSentence(string tutSentence)
{
  string temp = "";
  char current;
  string translation = "";
  // iterate through sentence
  for (int i = 0, n = tutSentence.size(); i < n; ++i)
  {
    // get current char, add to temp string
    current = tutSentence.at(i);
    temp.push_back(current);
    // if at end of sentence or there is a space, add to translation string and translate word
    if (i == n-1 || isspace(current))
    {
      translation.append(translateTutWord(temp));
      temp = "";
    }
  }
  return translation;
}
