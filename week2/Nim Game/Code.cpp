#include <iostream>
#include <math.h>
using namespace std;

#define PLAYER1 1
#define PLAYER2 2

struct move
{
	int pile_index;
	int stones_removed;
};

void showPiles (int piles[], int n)
{
	int i;
	cout <<"Current Game Status -> ";
	for (i=0; i<n; i++)
		cout << " " << piles[i];
	cout <<"\n";
	return;
}

bool gameOver(int piles[], int n)
{
	int i;
	for (i=0; i<n; i++)
		if (piles[i]!=0)
			return (false);

	return (true);
}

void declareWinner(int whoseTurn)
{
	if (whoseTurn == PLAYER1)
		cout <<"\nPLAYER2 won\n\n";
	else
		cout <<"\nPLAYER1 won\n\n";
	return;
}

int calculateNimSum(int piles[], int n)
{
	int i, nimsum = piles[0];
	for (i=1; i<n; i++)
		nimsum = nimsum ^ piles[i];
	return(nimsum);
}

void makeMove(int piles[], int n, struct move * moves)
{
	int i, nim_sum = calculateNimSum(piles, n);

	if (nim_sum != 0)
	{
		for (i=0; i<n; i++)
		{
			if ((piles[i] ^ nim_sum) < piles[i])
			{
				(*moves).pile_index = i;
				(*moves).stones_removed =
								piles[i]-(piles[i]^nim_sum);
				piles[i] = (piles[i] ^ nim_sum);
				break;
			}
		}
	}

	else
	{
		int non_zero_indices[n], count;

		for (i=0, count=0; i<n; i++)
			if (piles[i] > 0)
				non_zero_indices [count++] = i;

		(*moves).pile_index = (rand() % (count));
		(*moves).stones_removed =
				1 + (rand() % (piles[(*moves).pile_index]));
		piles[(*moves).pile_index] =
		piles[(*moves).pile_index] - (*moves).stones_removed;

		if (piles[(*moves).pile_index] < 0)
			piles[(*moves).pile_index]=0;
	}
	return;
}

void playGame(int piles[], int n, int whoseTurn)
{
	cout <<"\nGAME STARTS\n\n";
	struct move moves;

	while (gameOver (piles, n) == false)
	{
		showPiles(piles, n);

		makeMove(piles, n, &moves);

		if (whoseTurn == PLAYER1)
		{
			cout <<"COMPUTER removes" << moves.stones_removed << "stones from pile at index "
			<< moves.pile_index << endl;
			whoseTurn = PLAYER2;
		}
		else
		{
			cout <<"PLAYER2 removes"<< moves.stones_removed << "stones from pile at index "
			<< moves.pile_index << endl;
			whoseTurn = PLAYER1;
		}
	}

	showPiles(piles, n);
	declareWinner(whoseTurn);
	return;
}

void knowWinnerBeforePlaying(int piles[], int n,
							int whoseTurn)
{
	cout <<"Prediction before playing the game -> ";

	if (calculateNimSum(piles, n) !=0)
	{
		if (whoseTurn == PLAYER1)
			cout <<"PLAYER1 will win\n";
		else
			cout <<"PLAYER2 will win\n";
	}
	else
	{
		if (whoseTurn == PLAYER1)
			cout <<"PLAYER2 will win\n";
		else
			cout <<"PLAYER1 will win\n";
	}

	return;
}

int main()
{
	int piles[] = {3, 4, 5};
	int n = sizeof(piles)/sizeof(piles[0]);

	// PLAYER1 starts first
	knowWinnerBeforePlaying(piles, n, PLAYER1);

	playGame(piles, n, PLAYER1);

	return(0);
}

