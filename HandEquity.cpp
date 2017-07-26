#ifndef HandEquity_CPP
#define HandEquity_CPP

#include "HandEquity.h"


inline int DealCard(bool DealtCards[]){
	while(true){
		int card = (rand() % 52) + 1;
		if(DealtCards[card] == false){
			DealtCards[card] = true;
			return card;
		}
	}	
}

inline int GetCardRank(int card){
	int k = ((card - 1) % 13) + 1;
	if(k == 1){
		return 14;
	}
	return k;
}

inline int GetCardSuit(int card){
	return ((card - 1) / 13) + 1;
}


int CardToInteger(std::string card){
	if (card == "AH") return 1;
	if (card == "2H") return 2;
	if (card == "3H") return 3;
	if (card == "4H") return 4;
	if (card == "5H") return 5;
	if (card == "6H") return 6;
	if (card == "7H") return 7;
	if (card == "8H") return 8;
	if (card == "9H") return 9;
	if (card == "TH") return 10;
	if (card == "JH") return 11;
	if (card == "QH") return 12;
	if (card == "KH") return 13;
	if (card == "AS") return 14;
	if (card == "2S") return 15;
	if (card == "3S") return 16;
	if (card == "4S") return 17;
	if (card == "5S") return 18;
	if (card == "6S") return 19;
	if (card == "7S") return 20;
	if (card == "8S") return 21;
	if (card == "9S") return 22;
	if (card == "TS") return 23;
	if (card == "JS") return 24;
	if (card == "QS") return 25;
	if (card == "KS") return 26;
	if (card == "AD") return 27;
	if (card == "2D") return 28;
	if (card == "3D") return 29;
	if (card == "4D") return 30;
	if (card == "5D") return 31;
	if (card == "6D") return 32;
	if (card == "7D") return 33;
	if (card == "8D") return 34;
	if (card == "9D") return 35;
	if (card == "TD") return 36;
	if (card == "JD") return 37;
	if (card == "QD") return 38;
	if (card == "KD") return 39;
	if (card == "AC") return 40;
	if (card == "2C") return 41;
	if (card == "3C") return 42;
	if (card == "4C") return 43;
	if (card == "5C") return 44;
	if (card == "6C") return 45;
	if (card == "7C") return 46;
	if (card == "8C") return 47;
	if (card == "9C") return 48;
	if (card == "TC") return 49;
	if (card == "JC") return 50;
	if (card == "QC") return 51;
	if (card == "KC") return 52;
	return 0;
}


double CalculateHandEquity(std::string C1, std::string C2, std::string B1, std::string B2, std::string B3, std::string B4, std::string B5, int P, int N){

bool DealtCards[53];

double FinalResult = 0;
int TotalWin   = 0;
int TieCount;

int k1 = CardToInteger(C1);
int k2 = CardToInteger(C2);
int k3 = CardToInteger(B1);
int k4 = CardToInteger(B2);
int k5 = CardToInteger(B3);
int k6 = CardToInteger(B4);
int k7 = CardToInteger(B5);

if(P < 2 || N < 1){
	return 0;
}

if(k1 == 0 || k2 == 0){
	return 0;
}

int cards_to_deal = 5;
if(k3 == 0 && k4 == 0 && k5 == 0 && k6 == 0 && k7 == 0){
	cards_to_deal = 5;	
}
else if(k3 != 0 && k4 != 0 && k5 != 0 && k6 == 0 && k7 == 0){
	cards_to_deal = 2;		
}
else if(k3 != 0 && k4 != 0 && k5 != 0 && k6 != 0 && k7 == 0){
	cards_to_deal = 1;		
}
else if(k3 != 0 && k4 != 0 && k5 != 0 && k6 != 0 && k7 != 0){
	cards_to_deal = 0;		
}
else{
	return 0;
}


int flush_suit;
int straight_top;
int board_cards[7];
int board_suits[7];
int board_ranks[7];
int rank_count[15];
int flush_count[5];
bool flush_hit[15];

int pair4;
int pair3[2];
int pair2[3];

int result1[6];
int result2[6];
int next_result;
int next_result2;
int next_result3;
int next_result4;


for(int iteration = 1; iteration <= N; iteration++){

	DealtCards[0]  = false;
	DealtCards[1]  = false;
	DealtCards[2]  = false;
	DealtCards[3]  = false;
	DealtCards[4]  = false;
	DealtCards[5]  = false;
	DealtCards[6]  = false;
	DealtCards[7]  = false;
	DealtCards[8]  = false;
	DealtCards[9]  = false;
	DealtCards[10] = false;
	DealtCards[11] = false;
	DealtCards[12] = false;
	DealtCards[13] = false;
	DealtCards[14] = false;
	DealtCards[15] = false;
	DealtCards[16] = false;
	DealtCards[17] = false;
	DealtCards[18] = false;
	DealtCards[19] = false;
	DealtCards[20] = false;
	DealtCards[21] = false;
	DealtCards[22] = false;
	DealtCards[23] = false;
	DealtCards[24] = false;
	DealtCards[25] = false;
	DealtCards[26] = false;
	DealtCards[27] = false;
	DealtCards[28] = false;
	DealtCards[29] = false;
	DealtCards[30] = false;
	DealtCards[31] = false;
	DealtCards[32] = false;
	DealtCards[33] = false;
	DealtCards[34] = false;
	DealtCards[35] = false;
	DealtCards[36] = false;
	DealtCards[37] = false;
	DealtCards[38] = false;
	DealtCards[39] = false;
	DealtCards[40] = false;
	DealtCards[41] = false;
	DealtCards[42] = false;
	DealtCards[43] = false;
	DealtCards[44] = false;
	DealtCards[45] = false;
	DealtCards[46] = false;
	DealtCards[47] = false;
	DealtCards[48] = false;
	DealtCards[49] = false;
	DealtCards[50] = false;
	DealtCards[51] = false;
	DealtCards[52] = false;

	DealtCards[k1] = true;
	DealtCards[k2] = true;
	DealtCards[k3] = true;
	DealtCards[k4] = true;
	DealtCards[k5] = true;
	DealtCards[k6] = true;
	DealtCards[k7] = true;

	switch(cards_to_deal){
		case 5:
			board_cards[2] = DealCard(DealtCards);
			board_cards[3] = DealCard(DealtCards);
			board_cards[4] = DealCard(DealtCards);
			board_cards[5] = DealCard(DealtCards);
			board_cards[6] = DealCard(DealtCards);
			break;
		case 2:
			board_cards[2] = k3;
			board_cards[3] = k4;
			board_cards[4] = k5;
			board_cards[5] = DealCard(DealtCards);
			board_cards[6] = DealCard(DealtCards);
			break;
		case 1:
			board_cards[2] = k3;
			board_cards[3] = k4;
			board_cards[4] = k5;
			board_cards[5] = k6;
			board_cards[6] = DealCard(DealtCards);
			break;
		case 0:
			board_cards[2] = k3;
			board_cards[3] = k4;
			board_cards[4] = k5;
			board_cards[5] = k6;
			board_cards[6] = k7;
			break;	
	}

	TieCount = 0;
	result1[0] = 0;
	result1[1] = 0;
	result1[2] = 0;
	result1[3] = 0;
	result1[4] = 0;
	result1[5] = 0;

	for(int current_player = 1; current_player <= P; current_player++){

		result2[0] = 0;
		result2[1] = 0;
		result2[2] = 0;
		result2[3] = 0;
		result2[4] = 0;
		result2[5] = 0;

		if(current_player == 1){
			board_cards[0] = k1;
			board_cards[1] = k2;
		}else{
			board_cards[0] = DealCard(DealtCards);
			board_cards[1] = DealCard(DealtCards);
		}


	board_suits[0] = GetCardSuit(board_cards[0]);
	board_suits[1] = GetCardSuit(board_cards[1]);
	board_suits[2] = GetCardSuit(board_cards[2]);
	board_suits[3] = GetCardSuit(board_cards[3]);
	board_suits[4] = GetCardSuit(board_cards[4]);
	board_suits[5] = GetCardSuit(board_cards[5]);
	board_suits[6] = GetCardSuit(board_cards[6]);

	board_ranks[0] = GetCardRank(board_cards[0]);
	board_ranks[1] = GetCardRank(board_cards[1]);
	board_ranks[2] = GetCardRank(board_cards[2]);
	board_ranks[3] = GetCardRank(board_cards[3]);
	board_ranks[4] = GetCardRank(board_cards[4]);
	board_ranks[5] = GetCardRank(board_cards[5]);
	board_ranks[6] = GetCardRank(board_cards[6]);

	flush_count[1] = 0;
	flush_count[2] = 0;
	flush_count[3] = 0;
	flush_count[4] = 0;

	flush_count[board_suits[0]] += 1;
	flush_count[board_suits[1]] += 1;
	flush_count[board_suits[2]] += 1;
	flush_count[board_suits[3]] += 1;
	flush_count[board_suits[4]] += 1;
	flush_count[board_suits[5]] += 1;
	flush_count[board_suits[6]] += 1;

	flush_suit = 0;
	if(flush_count[1] >= 5){flush_suit = 1;} 
	if(flush_count[2] >= 5){flush_suit = 2;} 
	if(flush_count[3] >= 5){flush_suit = 3;} 
	if(flush_count[4] >= 5){flush_suit = 4;} 

	
		flush_hit[1]  = false;
		flush_hit[2]  = false;
		flush_hit[3]  = false;
		flush_hit[4]  = false;
		flush_hit[5]  = false;
		flush_hit[6]  = false;
		flush_hit[7]  = false;
		flush_hit[8]  = false;
		flush_hit[9]  = false;
		flush_hit[10] = false;
		flush_hit[11] = false;
		flush_hit[12] = false;
		flush_hit[13] = false;
		flush_hit[14] = false;

	if(flush_suit != 0){
		if(board_suits[0] == flush_suit){flush_hit[board_ranks[0]] = true;}
		if(board_suits[1] == flush_suit){flush_hit[board_ranks[1]] = true;}
		if(board_suits[2] == flush_suit){flush_hit[board_ranks[2]] = true;}
		if(board_suits[3] == flush_suit){flush_hit[board_ranks[3]] = true;}
		if(board_suits[4] == flush_suit){flush_hit[board_ranks[4]] = true;}
		if(board_suits[5] == flush_suit){flush_hit[board_ranks[5]] = true;}
		if(board_suits[6] == flush_suit){flush_hit[board_ranks[6]] = true;}
		flush_hit[1] = flush_hit[14];
	}

	rank_count[2]  = 0;
	rank_count[3]  = 0;
	rank_count[4]  = 0;
	rank_count[5]  = 0;
	rank_count[6]  = 0;
	rank_count[7]  = 0;
	rank_count[8]  = 0;
	rank_count[9]  = 0;
	rank_count[10] = 0;
	rank_count[11] = 0;
	rank_count[12] = 0;
	rank_count[13] = 0;
	rank_count[14] = 0;

	rank_count[board_ranks[0]] += 1;
	rank_count[board_ranks[1]] += 1;
	rank_count[board_ranks[2]] += 1;
	rank_count[board_ranks[3]] += 1;
	rank_count[board_ranks[4]] += 1;
	rank_count[board_ranks[5]] += 1;
	rank_count[board_ranks[6]] += 1;

	straight_top = 0;
	pair4 = 0;
	pair3[0] = 0;
	pair3[1] = 0;
	pair2[0] = 0;
	pair2[1] = 0;
	pair2[2] = 0;

	int straight_count = 0;
	int next3 = 0;
	int next2 = 0;
	for(int x = 14; x >= 2; x--){
		switch(rank_count[x]){
			case 0:
				straight_count = 0;
				break;
			case 1:
				straight_count += 1;
				break;
			case 2:
				pair2[next2] = x;
				next2 += 1;
				straight_count += 1;
				break;
			case 3:
				pair3[next3] = x;
				next3 += 1;
				straight_count += 1;
				break;
			case 4:
				pair4 = x;
				break;
		}
		
		switch(straight_count){
			case 5:
				straight_top = x + 4;
				break;
			case 4:
				if(x == 2 && rank_count[14] != 0){
					straight_top = 5;
				}
				break;
		}

	} 


	//Straight Flush
	if(straight_top != 0 && flush_suit != 0){
		if(flush_hit[straight_top] == true && 
		flush_hit[straight_top - 1]== true && 
		flush_hit[straight_top - 2]== true &&
		flush_hit[straight_top - 3]== true &&
		flush_hit[straight_top - 4]== true)
		{
			result2[0] = 9;
			result2[1] = straight_top;
			goto CompareResults;
		}
	}

	//Four Of A Kind
	if(pair4 != 0){
		result2[0] = 8;
		result2[1] = pair4;
		for(int x = 14; x >= 2; x--){
			if(x != pair4 && rank_count[x] != 0){
				result2[2] = x;
				goto CompareResults;
			}
		}
	}

	//Full House
	if(pair3[0] != 0 && pair2[0] != 0){
		result2[0] = 7;
		result2[1] = pair3[0];
		result2[2] = pair2[0];
		goto CompareResults;
	}

	//Flush
	if(flush_suit != 0){
		result2[0] = 6;
		next_result = 1;
		for(int x = 14; x >= 2; x--){
			if(flush_hit[x] == true){
				result2[next_result] = x;
				next_result += 1;
			}
			if(next_result == 6){
				goto CompareResults;
			}
		}
	}

	//Straight
	if(straight_top != 0){
		result2[0] = 5;
		result2[1] = straight_top;
		goto CompareResults;
	}

	//Three Of A Kind
	if(pair3[0] != 0){
		result2[0] = 4;
		result2[1] = pair3[0];
		next_result2 = 2;
		for(int x = 14; x >= 2; x--){
			if(x != pair3[0] && rank_count[x] != 0){
				result2[next_result2] = x;
				next_result2 += 1;
			}
			if(next_result2 == 4){
				goto CompareResults;
			}
		}
	}

	//Two Pair
	if(pair2[0] != 0 && pair2[1] != 0){
		result2[0] = 3;
		result2[1] = pair2[0];
		result2[2] = pair2[1];
		for(int x = 14; x >= 2; x--){
			if(x != pair2[0] && x != pair2[1] && rank_count[x] != 0){
				result2[3] = x;
				goto CompareResults;
			}
		}
	}

	//One Pair
	if(pair2[0] != 0){
		result2[0] = 2;
		result2[1] = pair2[0];
		next_result3 = 2;
		for(int x = 14; x >= 2; x--){
			if(x != pair2[0] && rank_count[x] != 0){
				result2[next_result3] = x;
				next_result3 += 1;
			}
			if(next_result3 == 5){
				goto CompareResults;
			}
		}
	}

	//High Card
	result2[0] = 1;
	next_result4 = 1;
	for(int x = 14; x >= 2; x--){
		if(rank_count[x] != 0){
			result2[next_result4] = x;
			next_result4 += 1;
		}
		if(next_result4 == 6){
			goto CompareResults;
		}
	}


	CompareResults:

	if(current_player == 1){
		result1[0] = result2[0];
		result1[1] = result2[1];
		result1[2] = result2[2];
		result1[3] = result2[3];
		result1[4] = result2[4];
		result1[5] = result2[5];
	}else{
		for(int x = 0; x < 6; x++){
			if(result2[x] > result1[x]){
				goto EndIteration;
			}else if(result2[x] < result1[x]){
				goto NextPlayer;
			}
		}
		TieCount += 1;
	}

	NextPlayer:;

	}//player for


	TieCount += 1;
	if(TieCount == 1){
		FinalResult += 1;
	}else{
		FinalResult += 1.0/TieCount;
	}



	EndIteration:;

}//iteration for



//return TotalWin / N;
return FinalResult / N;

}//function




#endif