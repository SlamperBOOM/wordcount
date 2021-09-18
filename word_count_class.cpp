#include "word_count_class.h"
#include <string>
#include <map>
#include <malloc.h>
#include <fstream>

void word_count::ReadFromFile(string filename)
{
    ifstream input;
    input.open(filename);
    while (!input.eof())
    {
        string text = "";
        getline(input, text);
        int length = text.size();
        if (length == 0)
        {
            break;
        }
        string word = "";
        for (int i = 0; i < length; i++)
        {
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= '0' && text[i] <= '9'))
            {
                word += text[i];
            }
            else  if (word != "")
            {
                AddWord(word);
                word = "";
            }
        }
        if (word != "")
        {
            AddWord(word);
        }
    }
}

void word_count::DeployToFile(string filename)
{
	string * sortedwords = SortByRarity();
	ofstream output;
	output.open(filename);
	for (int i = 0; i < numberofunicwords; i++)
	{
		int count = GetNumberOfWord(sortedwords[i]);
		double percentage = (double)count / numberofwords * 100;
		output << sortedwords[i] << ';' << count << ';' << (int)(percentage / 1e-2) * 1e-2 << '%' << endl;
	}
	output.close();
}

void word_count::AddWord(string word)
{
	map <string, int> ::iterator it;
	it = words.find(word);
	if (it == words.end())
	{
		words[word] = 1;
		numberofunicwords++;
	}
	else
	{
		words[word]++;
	}
	numberofwords++;
}

string* word_count::SortByRarity()
{
	string* wordsbyrarity = new string[numberofunicwords];
	map <string, int> ::iterator it = words.begin();
	for (int i = 0; i < numberofunicwords; i++)
	{
		wordsbyrarity[i] = it->first;
		it++;
	}
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < numberofunicwords - 1; i++)
		{
			if (words[wordsbyrarity[i]] < words[wordsbyrarity[i + 1]])
			{
				sorted = false;
				Swap(wordsbyrarity, i, i + 1);
			}
		}
	}
	return wordsbyrarity;
}

int word_count::GetNumberOfWord(string word)
{
	map <string, int> ::iterator it = words.find(word);
	if (it != words.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

void word_count::Swap(string* wordsbyrarity, int index1, int index2)
{
	string a = wordsbyrarity[index1];
	wordsbyrarity[index1] = wordsbyrarity[index2];
	wordsbyrarity[index2] = a;
}