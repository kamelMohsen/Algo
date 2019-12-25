#include <fstream>
#include <vector> 
#include <chrono>
#include <iostream>
using namespace std;


void Probe(string * H,int Size, string Element, int Location);
int Hash(string Word);
int Search(string* H, int Size, string Element);

int main()
{
    //Opening the file and reading to a vector
	ifstream inFile;
	inFile.open("C:\\Users\\Kamel\\Desktop\\Fall 2019\\Algo\\Labs\\Lab3\\\Lab Material\\words20K.txt");
	if (!inFile)
	{
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}
	string x = "";
	vector<string> List;
	while (inFile >> x)
	{
		List.push_back(x);
	}
    //Inserting the vector elements to an array
	string* A = new string[List.size()];
	for (int i = 0; i < List.size(); i++)
			A[i] = List.at(i);
	//Creating and intializing the hash array
	int HSize = 24000;
	string * H = new string[HSize];
	for (int i = 0; i < HSize; i++)
			H[i] = "";
	int HN = 0;
//Inserting the elements to hash array and measuring time for every 500 entery
		auto start = chrono::steady_clock::now();
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		float Time = 0;
		vector<float> times;
		int FiveHundred = 0;
		for (int i = 0; i < List.size(); i++)
		{
			if(FiveHundred == 0)
				start = chrono::steady_clock::now();
			if (FiveHundred != 500)
			{
				HN = Hash(A[i]);
				Probe(H, HSize, A[i], HN);
				FiveHundred++;
			}
			if (FiveHundred == 500)
			{
				end = chrono::steady_clock::now();
				diff = end - start;
				times.push_back(chrono::duration <double, milli>(diff).count()/500);
				FiveHundred = 0;
			}
		}
		//Printing the avg time for every 500 entery to a file  
		ofstream SelectionFile;
		SelectionFile.open("C:\\Users\\Kamel\\Desktop\\Fall 2019\\Algo\\Labs\\Lab3\\Result Timings\\result.txt");
		for (int i = 0; i < times.size(); i++)
		{
			SelectionFile << times.at(i) << " ms \n";
		}
		//Deleting elements from 14000 to 15000 and getting probe info.
		int probes = 0, min = INT16_MAX, sum = 0 , max = INT16_MIN;
		for (int i = 14000; i < 15000; i++)
		{
			probes = Search(H, HSize, A[i]);
			sum += probes;
			if (probes > max)
				max = probes;
			if (probes < min)
				min = probes;
		}
		cout << "Max " << max<<endl;
		cout << "Min " << min << endl;
		cout << "Avg " << sum/1000 << endl;
	return 0;
}



















void Probe(string* H,int Size,string Element, int Location)
{
	int c = 0;
	while (c != Size)
	{
		
		if (Location == Size )
			Location = 0;
		if (H[Location] == "")
		{
			H[Location] = Element;
			break;
		}
		c++;
		Location++;
	}

}

int Hash(string Word)
{
	int HN = 0;

	if (Word.size() == 1) 
		HN = 39 * int(Word[0]);
	else if (Word.size() == 2)
		HN = 39 * int(Word[0]) + 392 * int(Word[1]);
	else if (Word.size() == 3)
		HN = 39 * int(Word[0]) + 392 * int(Word[1]) + 393 * int(Word[2]);
	else 
		HN = 39 * int(Word[0]) + 392 * int(Word[1]) + 393 * int(Word[2]) + 394 * int(Word[3]);
	HN = HN % 24000;
	return HN;
}

int Search(string* H, int Size, string Element)
{
	int c = 0;
	int probes = 0;
	int Location = Hash(Element);

	while (c != Size)
	{


		if (Location == Size)
			Location = 0;

	    if (H[Location] == Element)
		{
			H[Location] = "d";
			break;
		}
		else if (H[Location] == "")
		{

			break;
		}
		c++;
		Location++;
		probes++;
	}

	return probes;
}
