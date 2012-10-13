#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

double Confidence = 40.0;

int Similar(string, string);

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "Arguments: wordlength wordcount confidence" << endl;
		return 1;
	}
	
	Confidence = (double)atoi(argv[3]);
	
	ifstream InputFile;
	
	stringstream ss;
	ss << "words/" << argv[1] << ".txt";
	
	InputFile.open(ss.str().c_str());
	
	string Line;
	string PreviousLine = "";
	
	vector<string> Words;
	
	while (1)
	{
		getline(InputFile, Line);
		
		if (Line != PreviousLine)
		{
			PreviousLine = Line;
			Words.push_back(Line.substr(0, atoi(argv[1])));
		}
		else
		{
			break;
		}
	}
	
	// Starting word
	srand( time(NULL) );
	int randIndex = rand() % Words.size();
	string StartWord = Words[randIndex];
	Words.erase(Words.begin() + randIndex);
	
	// Get a collection of all similar words
	vector<string> SimilarWords;
	SimilarWords.push_back( StartWord );
	
	for (int i = 0; i < Words.size(); i++)
	{
		int Similarity = Similar( StartWord, Words[i] );
		double Accuracy = (double)Similarity / (double)atoi(argv[1]) * 100.0;
		
		if (Accuracy >= Confidence)
		{
			SimilarWords.push_back(Words[i]);
		}
	}
	
	random_shuffle(SimilarWords.begin(), SimilarWords.end());
	
	printf("%s", "{\"words\":[");
	for (int i = 0; i < atoi(argv[2]); ++i)
	{
		
			
		printf("\"%s\"", SimilarWords[i].c_str());
		if (i < atoi(argv[2]) - 1 )
		{
			if (i + 1 == SimilarWords.size())
				break;
			printf("%s", ",");
		}
	}
	printf("%s", "]}");
}

int Similar(string One, string Two)
{
	int similar = 0;
	for (int i = 0; i < One.length(); i++)
	{
		if (One[i] == Two[i])
		{
			similar++;
		}
	}
	return similar;
}


