//User-defined libraries
#include "Money.h"
#include "Info.h"
//Standart c++ libraries
#include <iostream>
#include <stdlib.h> 
#include <time.h>  
#include <Windows.h>


//Player 2 Class 
class elMinino
{
public:
	//Just a const char for testing purposes on std::cout
	const char* name = "elMinino";
	//Life 
	int vida = 100;
	//Generates a random number between 0 and 10 to add onto computer clock so players have different damage seeds Using rand() from stdlib.h
	int gerarRandom = rand() % 10;

	//Function for oponent damage
	int dano_oponente()
	{
		//Uses computer clock + random number from above to generate a random seed. time.h library
		srand(time(NULL) + gerarRandom);
		//damage variable that uses the above seed and generates then a number between 0 and 30
		int dano = rand() % 30;
		return dano;
	}
};

//Player 1 Class
class zeBacalhau
{
public:
	const char* name = "zeBacalhau";
	int vida = 100;
	int gerarRandom = rand() % 10;

	int dano_oponente()
	{
		srand(time(NULL) + gerarRandom);
		int dano = rand() % 30;
		return dano;
	}
};

int main()
{
	//Initialize variable that holds the total credit on our account. This variable will be used to pass it to money.cpp
	int dinheiro_no_banco = 1000;

	//Give both our classes an instance so we can use them 
	zeBacalhau jogador_um;
	elMinino jogador_dois;

	//This is from info.cpp, will input a short introduction to the game
	info();

	//Infine loop so the user keeps the fights going till he wants to stop using END on keyboard
	while (!GetAsyncKeyState(VK_END))
	{
		/*Initializing two variables that receives returns from two functions on Money.cpp! The first allows us to pick a figther to bet and returns it, the other returns an ammount to bet depending on our credit*/
		int queLutador = escolha_lutador();
		int aposta = banca(dinheiro_no_banco);

		//Subtracting the bet ammount from the total credit
		dinheiro_no_banco -= aposta;

		//Initialize the variables that are responsible for the damage of both fighters
		int bacalhau_damage{};
		int minino_damage{};

		//Press any key to start the battle
		std::cout << "Press any key to start the battle" << '\n';
		std::cin.get();

		//A while loop that keeps the fight going till one of the players lose
		while (jogador_um.vida > 0 and jogador_dois.vida > 0)
		{
			//Cleans the console output
			system("cls");

			//Outputs to the console both players HP
			std::cout << "zeBacalhau HP: " << jogador_um.vida << '\n';
			std::cout << "elMinino HP: " << jogador_dois.vida << '\n';

			//Variables that hold the random damage that each player will receive from one another
			bacalhau_damage = jogador_um.dano_oponente();
			minino_damage = jogador_dois.dano_oponente();

			//Show damage dealt to the players on console
			std::cout << jogador_um.name << " gave " << bacalhau_damage << " to elMinino!";
			std::cin.get();
			std::cout << jogador_dois.name << " deu " << minino_damage << " to zeBacalhau!";
			std::cin.get();

			//Update HP of both players
			jogador_um.vida -= minino_damage;
			jogador_dois.vida -= bacalhau_damage;
		}

		//After one lost the battle update one last time the HP so its the correct value that's being showed
		system("cls");
		std::cout << "zeBacalhau HP: " << jogador_um.vida << '\n';
		std::cout << "elMinino HP: " << jogador_dois.vida << '\n';

		//Two checks to see wich of our fighters won, if it was p1 = jogador_um or p2 = jogador_dois
		if (jogador_um.vida > 0)
		{
			//Outputting text to who the winner was
			std::cout << "And the winner was! " << jogador_um.name << '\n';
			//An if check to see if you bet on the winner, if yes, tells the user and rewards them with x2 bet value.
			if (queLutador == 1)
			{
				int dobragem_aposta = aposta * 2;
				std::cout << "Congratulations, you won your bet! " << '\n';
				std::cout << "You won " << dobragem_aposta << " euros!" << '\n';
				std::cout << "Your total credit: " << dinheiro_no_banco + dobragem_aposta << '\n';
				
				//Update the credit on the account in case the user won the bet
				dinheiro_no_banco += dobragem_aposta;
			}
			//If he failed the bet, then say that he lost, how much and how much left he has on credit
			else
			{
				std::cout << "You failed your bet!" << '\n';
				std::cout << "You lost " << aposta << " euros, and have " << dinheiro_no_banco << " of credit!" << '\n';
				std::cout << "We wish you best luck next time!";
			}
		}
		//If P2 won
		else if (jogador_dois.vida > 0)
		{
			std::cout << "And the winner was! " << jogador_dois.name << '\n';
			if (queLutador == 2)
			{
				int dobragem_aposta = aposta * 2;
				std::cout << "Congratulations, you won your bet! " << '\n';
				std::cout << "You won " << dobragem_aposta << " euros!" << '\n';
				std::cout << "Your total credit: " << dinheiro_no_banco + dobragem_aposta << '\n';

				//Update the credit on the account in case the user won the bet
				dinheiro_no_banco += dobragem_aposta;
			}
			else
			{
				std::cout << "You failed your bet!" << '\n';
				std::cout << "You lost " << aposta << " euros, and have " << dinheiro_no_banco << " of credit!" << '\n';
				std::cout << "We wish you best luck next time!";
			}
		}

		//Restore both figthers HP back to 100
		jogador_um.vida = 100;
		jogador_dois.vida = 100;

		//Tell the user that if he wants to leave the game he can click END and ENTER now! If not, just press any key to proceed
		std::cout << "To leave the game press END and then ENTER, if you wish to continue click any key...";
		std::cin.get();

	}
	//Close the program
	std::cin.get();
	return 0;
}