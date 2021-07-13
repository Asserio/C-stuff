#include <iostream>

//This function deals with the bet ammoun and the total credit on the accout. Receives credit ammout from main.cpp
int banca(int quantia_no_banco)
{

	int aposta{};
	//Outputs to the player how much he wants to bet and show total credit
	std::cout << "How much you want to bet? " << '\n';
	std::cout << "Your credit: " << quantia_no_banco << " euros. Bet: ";
	std::cin >> aposta;
	//If the player bets more then he can then tell him he doesn't have that many, and repeats the process of asking how much to bet
	while (aposta > quantia_no_banco)
	{
		system("cls");
		std::cout << "Your total credit is to low for that size, please insert a bet size lower then" << quantia_no_banco << '\n';
		std::cout << "Bet: ";
		std::cin >> aposta;
	}

	return aposta;
}

//This functions shows info about the two fighters and lets the player pick one
int escolha_lutador()
{
	//This will be used to get input from who to bet of the user
	int resposta{};

	//Info about the fighthers and how to bet in one
	system("cls");
	std::cout << "And we have as fighter, the big and the tiny elMininoooooo! " << '\n';
	std::cout << "And as the other figther we have the fishman and its zeBacalhauuuuu!" << '\n';
	std::cout << "Pick one of the figthers that you wish to bet." << '\n';
	std::cout << "elMinino = 2 " << '\n';
	std::cout << "zeBacalhau = 1" << '\n';

	//Gets the input from the user about who to bet
	std::cout << "Fighter: ";
	std::cin >> resposta;

	//In case the user inserts a invalid number, warn him and re-do the process again
	while (resposta != 1 and resposta != 2)
	{
			system("cls");
			std::cout << "Fighter invalid, please choose between 1 or 2." << '\n';
			std::cout << "elMinino = 2 " << '\n';
			std::cout << "zeBacalhau = 1" << '\n';

			//Get user input
			std::cout << "Fighter: ";
			std::cin >> resposta;
	}
	return resposta;
}
