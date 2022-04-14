#include "FileProcessor.h"

int main(int argc, char **argv)
{
  // checks for correct amount of command line arguments
  if(argc != 4)
  {
    cout << "Please provide the input and output files as well as E2T or T2E" << endl;
    return 1;
  }
  // puts input and output file names into string variables and gets E2T/T2E
  string input = argv[1];
  string output = argv[2];
  string choice = argv[3];
  FileProcessor process;

  // if E2T run processFile which processes english to tut
  if (choice == "E2T")
  {
    process.processFile(input, output);
  }
  // if T2E run processTut file which processes tut to english
  else if (choice == "T2E")
  {
    process.processTutFile(input, output);
  }
  // else the user inputted something wrong, tell user, exit
  else
  {
    cout << "Please provide the input and output files as well as E2T or T2E" << endl;
    return 1;
  }
  return 0;
}
