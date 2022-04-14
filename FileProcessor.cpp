#include "FileProcessor.h"

FileProcessor::FileProcessor(){}
FileProcessor::~FileProcessor(){}

/*
  takes a string representing the input file (English) and a string
  representing the output file (where the Tutnese translation will be written). This
  method has a void return type.
*/
void FileProcessor::processFile(string input, string output)
{
  ifstream fsInput;
  ofstream fsOutput;
  string data;
  Translator translator;

  // open files
  fsInput.open(input);
  fsOutput.open(output);

  // check if able to open files
  if(!fsInput.is_open())
  {
    cout << "Can't open file" << endl;
    return;
  }

  if (!fsOutput.is_open())
  {
    cout << "Can't open file" << endl;
    return;
  }

  // read from fsInput into data, line by line
  getline(fsInput, data);

  // Read until failure
  while(!fsInput.fail())
  {
    // translate sentences from the input file, and output to output file
    fsOutput << translator.translateEnglishSentence(data) << endl;
    getline(fsInput, data);
  }

  // premature exit of file, error
  if (!fsInput.eof())
  {
    cout << "Input failure, did not reach the end of file" << endl;
    return;
  }

  // close files
  fsInput.close();
  fsOutput.close();
}

void FileProcessor::processTutFile(string fileInput, string fileOutput)
{
  ifstream fsInput;
  ofstream fsOutput;
  string data;
  Translator translator;

  // open files
  fsInput.open(fileInput);
  fsOutput.open(fileOutput);

  // check if able to open files
  if(!fsInput.is_open())
  {
    cout << "Can't open file" << endl;
    return;
  }

  if (!fsOutput.is_open())
  {
    cout << "Can't open file" << endl;
    return;
  }

  // read from fsInput into data, line by line
  getline(fsInput, data);

  // Read until failure
  while(!fsInput.fail())
  {
    // translate tut sentences from the input file, translate to english, and output to output file
    fsOutput << translator.translateTutSentence(data) << endl;
    getline(fsInput, data);
  }

  // premature exit of file, error
  if (!fsInput.eof())
  {
    cout << "Input failure, did not reach the end of file" << endl;
    return;
  }

  // close files
  fsInput.close();
  fsOutput.close();
}
