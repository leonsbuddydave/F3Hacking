#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Needs dictionary." << endl;
		return 1;
	}
	
	map<int, vector<string> > Dictionary;
		
	ifstream InputFile;
	string Line;
	string PreviousLine;
	
	int WordsProcessed = 0;
	
	InputFile.open(argv[1]);
	
	while (1)
	{
		getline(InputFile, Line);
		if (Line != PreviousLine)
		{
			PreviousLine = Line;
			
			if ( Dictionary.find( Line.length() ) == Dictionary.end() )
				Dictionary[ Line.length() ] = vector<string>();
				
			Dictionary[ Line.length() ].push_back( Line );
			
			WordsProcessed++;
			if (WordsProcessed % 1000)
				cout << WordsProcessed << " words processed." << endl;
		}
		else
		{
			break;
		}
	}
	InputFile.close();
	
	map<int, vector<string> >::iterator mapIter;
	
	for ( mapIter = Dictionary.begin(); mapIter != Dictionary.end(); ++mapIter )
	{
		ofstream OutputFile;
		
		stringstream out;
		out << "words/" << (mapIter->first - 1) << ".txt";
		
		string Filename = out.str();
		
		OutputFile.open(Filename.c_str());
		
		vector<string>::iterator vectorIter;
		
		vector<string> temp = (*mapIter).second;
		
		for (vectorIter = temp.begin(); vectorIter != temp.end(); ++vectorIter)
		{
			OutputFile << *vectorIter << endl;
		}
		
		OutputFile.close();
		
	}
	
	return 0;
}

