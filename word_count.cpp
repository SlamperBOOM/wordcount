#include "word_count_class.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Type names of input and output files";
        return 0;
    }
    string inputname = (string)argv[1];
    string outputname = (string)argv[2];

    word_count words;
    words.ReadFromFile(inputname);
    words.DeployToFile(outputname);
}

