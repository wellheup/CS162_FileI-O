/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/14/19
** Description: Prototypes functions useful for counting the number
** of letters in an ifstream and outputting them to an ofstream
*********************************************************************/
#ifndef LETTERCOUNTER_HPP
#define LETTERCOUNTER_HPP

/*********************************************************************
** Description: count_letters() takes an ifstream and a pointer to an
** int array and counts the number of each letter on a per paragraph
** basis, recording them into the array
*********************************************************************/
void count_letters(std::ifstream &inFile, int*);


/*********************************************************************
** Description: output_letters() takes an ofstream and a pointer to an
** int array and prints the number of each character recorded in the 
** array
*********************************************************************/
void output_letters(std::ofstream &outFile, int*);

#endif
