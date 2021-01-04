/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Implements functions useful for counting the number
** of letters in an ifstream and outputting them to an ofstream
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>

/*********************************************************************
** Description: count_letters() takes an ifstream and a pointer to an
** int array and counts the number of each letter on a per paragraph
** basis, recording them into the array
*********************************************************************/
void count_letters(std::ifstream &inFile, int* numChar){
	std::string currentPara;

	getline(inFile, currentPara);
	numChar[0]++;
	for (int i = 0; i < currentPara.length(); i++) {
		if ((currentPara[i] >= 97 && currentPara[i] <= 122) || (currentPara[i] >= 65 && currentPara[i] <= 90)) {
			currentPara[i] = tolower(currentPara[i]);
			numChar[currentPara[i] - 96]++;
		}
	}
}

/*********************************************************************
** Description: output_letters() takes an ofstream and a pointer to an
** int array and prints the number of each character recorded in the
** array
*********************************************************************/
void output_letters(std::ofstream &outFile, int* numChar){
	for (int i = 0; i < 27; i++) {
		if (i == 0) {
			outFile << "Paragraph " << numChar[0] << " has: " << std::endl;
		}
		else if (i > 0) {
			outFile << (char)(i + 96) << ": " << numChar[i] << std::endl;
		}
		else {
			std::cout << "trying to go outside numChar[]" << std::endl;
		}
	}
	outFile.close();

	for (int i = 1; i < 27; i++) {
		numChar[i] = 0;
	}
}


