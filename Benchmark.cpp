#include "HandEquity.cpp"

int main(){

srand (time(NULL));


std::clock_t start = std::clock();
std::cout << CalculateHandEquity("AH", "AS", "2H", "3H", "7H", "JS", "KC", 10, 1000000) << std::endl;
std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;


int throw_away;
std::cin >> throw_away;

}