
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Prompts the user to start the letter counting program
** class then runs it if the user wishes to. Requires a valid .txt
** file for input provided by the user as well as user provided
** .txt filenames for files it can record the letter counts for each
** letter from the input for each paragraph in the input
*********************************************************************/
#include<string>
#include<iostream>
#include<fstream>

#include "menuShell.hpp"
#include "isValidInput.hpp"
#include "letterCounter.hpp"

int main(){
	std::string //strings for menu
		greeting = "\nWelcome to Phillip Wellheuser's Lab 2 program. What would you like to do?",
		startupText = "1. Start Lab 2 Letter counting program.";

	while (initMenuSOrQ(greeting, startupText) == 1) {
    std::ifstream inFile;
    std::ofstream outFile;
    std::string inFileName, outFileName = "";
    int numChar[27] = { 0 }; //paragraph number is stored in numChar[0]
    bool validInFile = false;

		std::cout << "\nPlease enter the file directory of the \".txt\" file you'd like to analyze." << std::endl;
		
		while (validInFile==false) {//warn user if their file doesn't end in .txt
			std::cin >> inFileName;
			if (isTxtFile(inFileName) == false) {
				std::cout << inFileName << " doesn't appear to be a valid \".txt\" file name." << std::endl;
				
			}
			else if(isTxtFile(inFileName) == true){
				inFile.open(inFileName, std::ios::in);
				if (!inFile) {
					std::cout << inFileName << " couldn't be opened, please enter a valid \".txt\" file name." << std::endl;
				}
				else if (inFile){
					validInFile = true;
				}
				else {
					std::cout << "error detecting actual inFile" << std::endl;
				}
			}
			else {
				std::cout << "error detecting .txt" << std::endl;
			}
		}

    int numPara = 1;
    while (inFile.good()) {
			count_letters(inFile, numChar);
      if(outFileName == ""){
        std::cout << "\nPlease provide a non- \".txt\" name for the letter count files of each paragraph:" << std::endl;
        std::cin >> outFileName;
      }
			while (outFileName == "") {
				std::cout << outFileName << " doesn't appear to be a valid \".txt\" file name." << std::endl;
				std::cin >> outFileName;
			}
			
			outFile.open("./output/" + outFileName + std::to_string(numPara) + ".txt", std::ios::out);
			output_letters(outFile, numChar);
      numPara++;
		}
		inFile.close();
    std::cout << "Counting complete."<< std::endl;
	}
	return 0;
}
