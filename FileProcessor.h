#include "Translator.h"
#include <fstream>
using namespace std;

class FileProcessor
{
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string input, string output);
    void processTutFile(string fileInput, string fileOutput);
  private:
};
