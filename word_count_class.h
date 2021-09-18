#pragma once
#include <string>
#include <map>
#include <malloc.h>
#include <fstream>
using namespace std;

class word_count
{
public:
	word_count()
	{
		numberofwords = 0;
		numberofunicwords = 0;
	}

	void ReadFromFile(string filename);

	void DeployToFile(string filename);
	
private:
	map <string, int> words;
	int numberofunicwords = 0;
	int numberofwords = 0;

	void AddWord(string word);

	int GetNumberOfWord(string word);

	void Swap(string* wordsbyrarity, int index1, int index2);

	string* SortByRarity();

};
