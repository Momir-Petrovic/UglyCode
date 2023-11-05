#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std;

void PrintCircle(int i, int j, int currentLetter, int size, int reverse, int numberOfRing){
	vector<char> word = {'I', ' ', 'c', 'h', 'a', 'n', 'g', 'e', 'd', ' ', 't', 'h', 'e', ' ', 'w', 'o', 'r', 'l', 'd', ' '}; 
	bool inARing = false;
	int denominator = (2*numberOfRing-1)*(2*numberOfRing-1);
	for(int k = 0; k < numberOfRing; k++){
		if(i * i + j * j >= (2 * k) * (2 * k) * (size * size)/denominator && 
		   i * i + j * j <= ((2*k)+1) * ((2*k)+1) * (size * size)/denominator)
			inARing = true;
	}
	if(inARing){
		if(i == reverse || j == reverse || i == -reverse || j == -reverse){
			if(i*j > 0)
				cout << word[word.size()-1-((i + j)%word.size())] << ' ';
			else
				cout << word[word.size()-1-currentLetter] << ' ';
			currentLetter ++;
			if(currentLetter >= word.size())
				currentLetter = 0;
		}
		else{
			if(i*j > 0)
				cout << word[(i + j)%word.size()] << ' ';
			else
				cout << word[currentLetter] << ' ';
			currentLetter ++;
			if(currentLetter >= word.size())
				currentLetter = 0;
		}
	}
	else{
		if(i == reverse || i == -reverse)
		{
			cout << "| ";
		}
		else if(j == reverse || j == -reverse){
			cout << "= ";
		}
		else{
			cout << "  ";
		}
	}
	if(i < size){
		PrintCircle(i+1, j, currentLetter, size, reverse, numberOfRing);
	}
	else if(j < size){
		cout << endl;
		PrintCircle(-size, j+1, currentLetter, size, reverse, numberOfRing);
	}
}

int main(int argc, char* argv[]){
	int size = atoi(argv[1]);
	//int reverse = rand()%(2*size);
	int reverse = atoi(argv[2]);
	int numberOfRing = atoi(argv[3]);
	PrintCircle(-size, -size, 0, size, reverse, numberOfRing);
	cout << endl;
}
