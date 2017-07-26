#ifndef HandEquity_H
#define HandEquity_H

#include <iostream> 
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <string>
#include <ctime>

inline int DealCard(bool DealtCards[]);
inline int GetCardRank(int card);
inline int GetCardSuit(int card);
int CardToInteger(std::string card);
double CalculateExpectedValue(std::string C1, std::string C2, std::string B1, std::string B2, std::string B3, std::string B4, std::string B5, int P, int N);


#endif