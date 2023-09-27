#include <stdio.h>
#include <stdint.h>

const int32_t SPADE   = 1;
const int32_t HEART   = 2;
const int32_t DIAMOND = 3;
const int32_t CLUB    = 4;

// Check card validity
int32_t isValidCard(int32_t card)
{
	if (card < 1 || card > 52)
	{
		printf("Wrong input, your input must between 1 ~ 52\n");
		return 0;
	}
	
	return 1;
}

// Card point
int32_t highCardPoint(int32_t card)
{
	if (card == 1 || card == 14 || card == 27 || card == 40)
	{
		return 4;
	}
	else if (card == 13 || card == 26 || card == 39 || card == 52)
	{
		return 3;
	}
	else if (card == 12 || card == 25 || card == 38 || card == 51)
	{
		return 2;
	}
	else if (card == 11 || card == 24 || card == 37 || card == 50)
	{
		return 1;
	}

	return 0;
}

// Check card suit
int32_t checkCardSuit(int32_t card)
{
	if (card >= 1 && card <= 13)
	{
		return SPADE;
	}
	else if (card >= 14 && card <= 26)
	{
		return HEART;
	}
	else if (card >= 27 && card <= 39)
	{
		return DIAMOND;
	}
	else if (card >= 40 && card <= 52)
	{
		return CLUB;
	}
}

// Check balance suit
int32_t isBalanceSuit(int32_t suit1, int32_t suit2, int32_t suit3, int32_t suit4)
{
	if ((suit1 == 3 && suit2 == 3 && suit3 == 3 && suit4 == 4) ||
		(suit1 == 3 && suit2 == 3 && suit3 == 4 && suit4 == 3) ||
		(suit1 == 3 && suit2 == 4 && suit3 == 3 && suit4 == 3) ||
		(suit1 == 4 && suit2 == 3 && suit3 == 3 && suit4 == 3))
	{
		return 1;
	}

	return 0;
}

/*
 * Bidding System for Contract Bridge
 * 
 * Poker Card Encoding Rule:
 *  1-13: Spade   A, 2, 3, ..., 10, J, Q, K
 * 14-26: Heart   A, 2, 3, ..., 10, J, Q, K
 * 27-39: Diamond A, 2, 3, ..., 10, J, Q, K
 * 40-52: Club    A, 2, 3, ..., 10, J, Q, K
 */
int main()
{
	// Input Cards 
	int32_t card1  = 0, card2  = 0, card3  = 0, card4  = 0, card5  = 0;
	int32_t card6  = 0, card7  = 0, card8  = 0, card9  = 0, card10 = 0;
	int32_t card11 = 0, card12 = 0, card13 = 0;

	// High Card Points
	int32_t high_card_points = 0;

	// Spade AKQ and Heart AKQ Check
	int32_t spade_AKQ = 0, heart_AKQ = 0;

	// Card suit count
	int32_t spade_count = 0, heart_count = 0, diamond_count = 0, club_count = 0;

	/*
	 * Card Data 
	 */
	// Scan and check the cards, then add high card points and add suits to count
	// 1st card
	printf("1st  card: ");
	scanf("%d", &card1);
	
	if (isValidCard(card1) == 0)
	{	
		return 1;
	}

	if (card1 == 1 || card1 == 12 || card1 == 13)
	{
		spade_AKQ++;
	}

	if (card1 == 14 || card1 == 25 || card1 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card1);

	if (checkCardSuit(card1) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card1) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card1) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card1) == CLUB)
	{
		club_count++;
	}

	// 2nd card
	printf("2nd  card: ");
	scanf("%d", &card2);
	if (isValidCard(card2) == 0)
	{	
		return 1;
	}
	
	if (card2 == 1 || card2 == 12 || card2 == 13)
	{
		spade_AKQ++;
	}

	if (card2 == 14 || card2 == 25 || card2 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card2);

	if (checkCardSuit(card2) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card2) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card2) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card2) == CLUB)
	{
		club_count++;
	}

	// 3rd card
	printf("3rd  card: ");
	scanf("%d", &card3);
	if (isValidCard(card3) == 0)
	{	
		return 1;
	}
	
	if (card3 == 1 || card3 == 12 || card3 == 13)
	{
		spade_AKQ++;
	}

	if (card3 == 14 || card3 == 25 || card3 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card3);

	if (checkCardSuit(card3) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card3) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card3) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card3) == CLUB)
	{
		club_count++;
	}

	// 4th card
	printf("4th  card: ");
	scanf("%d", &card4);
	if (isValidCard(card4) == 0)
	{	
		return 1;
	}
	
	if (card4 == 1 || card4 == 12 || card4 == 13)
	{
		spade_AKQ++;
	}

	if (card4 == 14 || card4 == 25 || card4 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card4);

	if (checkCardSuit(card4) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card4) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card4) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card4) == CLUB)
	{
		club_count++;
	}

	// 5th card
	printf("5th  card: ");
	scanf("%d", &card5);
	if (isValidCard(card5) == 0)
	{	
		return 1;
	}
	
	if (card5 == 1 || card5 == 12 || card5 == 13)
	{
		spade_AKQ++;
	}

	if (card5 == 14 || card5 == 25 || card5 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card5);

	if (checkCardSuit(card5) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card5) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card5) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card5) == CLUB)
	{
		club_count++;
	}

	// 6th card
	printf("6th  card: ");
	scanf("%d", &card6);
	if (isValidCard(card6) == 0)
	{	
		return 1;
	}
	
	if (card6 == 1 || card6 == 12 || card6 == 13)
	{
		spade_AKQ++;
	}

	if (card6 == 14 || card6 == 25 || card6 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card6);

	if (checkCardSuit(card6) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card6) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card6) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card6) == CLUB)
	{
		club_count++;
	}

	// 7th card
	printf("7th  card: ");
	scanf("%d", &card7);
	if (isValidCard(card7) == 0)
	{	
		return 1;
	}
	
	if (card7 == 1 || card7 == 12 || card7 == 13)
	{
		spade_AKQ++;
	}

	if (card7 == 14 || card7 == 25 || card7 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card7);

	if (checkCardSuit(card7) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card7) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card7) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card7) == CLUB)
	{
		club_count++;
	}

	// 8th card
	printf("8th  card: ");
	scanf("%d", &card8);
	if (isValidCard(card8) == 0)
	{	
		return 1;
	}
	
	if (card8 == 1 || card8 == 12 || card8 == 13)
	{
		spade_AKQ++;
	}

	if (card8 == 14 || card8 == 25 || card8 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card8);

	if (checkCardSuit(card8) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card8) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card8) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card8) == CLUB)
	{
		club_count++;
	}

	// 9th card
	printf("9th  card: ");
	scanf("%d", &card9);
	if (isValidCard(card9) == 0)
	{	
		return 1;
	}
	
	if (card9 == 1 || card9 == 12 || card9 == 13)
	{
		spade_AKQ++;
	}

	if (card9 == 14 || card9 == 25 || card9 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card9);

	if (checkCardSuit(card9) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card9) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card9) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card9) == CLUB)
	{
		club_count++;
	}

	// 10th card
	printf("10th card: ");
	scanf("%d", &card10);
	if (isValidCard(card10) == 0)
	{	
		return 1;
	}
	
	if (card10 == 1 || card10 == 12 || card10 == 13)
	{
		spade_AKQ++;
	}

	if (card10 == 14 || card10 == 25 || card10 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card10);

	if (checkCardSuit(card10) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card10) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card10) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card10) == CLUB)
	{
		club_count++;
	}

	// 11th card
	printf("11th card: ");
	scanf("%d", &card11);
	if (isValidCard(card11) == 0)
	{	
		return 1;
	}
	
	if (card11 == 1 || card11 == 12 || card11 == 13)
	{
		spade_AKQ++;
	}

	if (card11 == 14 || card11 == 25 || card11 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card11);

	if (checkCardSuit(card11) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card11) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card11) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card11) == CLUB)
	{
		club_count++;
	}

	// 12th card
	printf("12th card: ");
	scanf("%d", &card12);
	if (isValidCard(card12) == 0)
	{	
		return 1;
	}
	
	if (card12 == 1 || card12 == 12 || card12 == 13)
	{
		spade_AKQ++;
	}

	if (card12 == 14 || card12 == 25 || card12 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card12);

	if (checkCardSuit(card12) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card12) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card12) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card12) == CLUB)
	{
		club_count++;
	}

	// 13th card
	printf("13th card: ");
	scanf("%d", &card13);
	if (isValidCard(card13) == 0)
	{	
		return 1;
	}
	
	if (card13 == 1 || card13 == 12 || card13 == 13)
	{
		spade_AKQ++;
	}

	if (card13 == 14 || card13 == 25 || card13 == 26)
	{
		heart_AKQ++;
	}
	
	high_card_points += highCardPoint(card13);

	if (checkCardSuit(card13) == SPADE)
	{
		spade_count++;
	}
	else if (checkCardSuit(card13) == HEART)
	{
		heart_count++;
	}	
	else if (checkCardSuit(card13) == DIAMOND)
	{
		diamond_count++;
	}
	else if (checkCardSuit(card13) == CLUB)
	{
		club_count++;
	}

	// Print the high card points
	printf("HCP: %d pts\n", high_card_points);
	
	// Print the suits count
	printf("Suit: %d-%d-%d-%d\n", spade_count, heart_count, diamond_count, club_count);

	/*
	 * Bidding choice
	 */
	printf("The bidding choice: ");

	// Find the bidding choice
	// 22 <= HCP <= 24 && balance suit
	if (high_card_points >= 22 && high_card_points <= 24 && 
		isBalanceSuit(spade_count, heart_count, diamond_count, club_count))
	{
		printf("2NT");
	}
	// HCP >= 16
	else if (high_card_points >= 16)
	{
		printf("1C");
	}
	// 13 <= HCP <= 15 && balance suit
	else if (high_card_points >= 13 && high_card_points <= 15 && 
		isBalanceSuit(spade_count, heart_count, diamond_count, club_count))
	{
		printf("1NT");
	}
	// 11 <= HCP <= 15
	else if (high_card_points >= 11 && high_card_points <= 15)
	{	
		if (spade_count >= 5 || heart_count >= 5)
		{
			if (spade_count >= heart_count)
			{
				printf("1S");
			}
			else
			{
				printf("1H");
			}
		}
		else if (diamond_count >= 4)
		{
			printf("1D");
		}
		else if (club_count >= 6)
		{
			printf("2C");
		}
		else if (club_count >= 5 && diamond_count == 0)
		{
			printf("2D");
		}
		else
		{
			printf("Pass");
		}
	}
	// 8 <= HCP <= 11
	else if (high_card_points >= 8 && high_card_points <= 11)
	{
		if (spade_count == 6)
		{
			printf("2S");
		}
		else if (heart_count == 6)
		{
			printf("2H");
		}
		else if (spade_count >= 7)
		{
			printf("3S");
		}
		else if (heart_count >= 7)
		{
			printf("3H");
		}
		else if (diamond_count >= 7)
		{
			printf("3D");
		}
		else if (club_count >= 7)
		{
			printf("3C");
		}
		else
		{
			printf("Pass");
		}
	}
	// HCP < 8
	else
	{
		if ((spade_count == 7 || heart_count == 7) && 
			(spade_AKQ == 3 || heart_AKQ == 3))
		{
			printf("3NT");
		}
		else
		{
			printf("Pass");
		}
	}
	
	printf("\n");
	return 0;
}

