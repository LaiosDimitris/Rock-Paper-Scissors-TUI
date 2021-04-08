#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

class Game
{
public:

	Game();

	void get_user_choice();
	void get_machine_choice();

	bool check_winner();
	void print_score();

	void start_game();

private:

	int rounds;

	int user_score;
	int machine_score;

	std::string user_choice;
	std::string machine_choice;
};

Game::Game()
{
	this->rounds = 7;
	this->user_score = 0;
	this->machine_score = 0;
}

void Game::get_user_choice()
{
	char input;

	do
	{
		std::cout << "--> Enter your choice(R, P or S): ";
		std::cin >> input;

		input = toupper(input);

		if (input != 'R' && input != 'P' && input != 'S')
			std::cout << "You need to enter R, P or S!" << std::endl;

	} while (input != 'R' && input != 'P' && input != 'S');

	switch (input)
	{
	case 'R':
		this->user_choice = "Rock";
		break;
	case 'P':
		this->user_choice = "Paper";
		break;
	case 'S':
		this->user_choice = "Scissors";
		break;
	}
}

void Game::get_machine_choice()
{
	srand(time(NULL));

	std::string options[] = { "Rock", "Paper", "Scissors" };

	this->machine_choice = options[rand() % 3];
}

bool Game::check_winner()
{
	std::string winner;
	std::string compare_choice;

	// User wins
	if (this->user_choice == "Rock" && this->machine_choice == "Scissors")
	{
		winner = "User";
		compare_choice = "Rock > Scissors";
		this->user_score++;
	}
	else if (this->user_choice == "Paper" && this->machine_choice == "Rock")
	{
		winner = "User";
		compare_choice = "Paper > Rock";
		this->user_score++;
	}
	else if (this->user_choice == "Scissors" && this->machine_choice == "Paper")
	{
		winner = "User";
		compare_choice = "Scissors > Paper";
		this->user_score++;
	}
	// Machine wins
	else if (this->machine_choice == "Rock" && this->user_choice == "Scissors")
	{
		winner = "Machine";
		compare_choice = "Rock > Scissors";
		this->machine_score++;
	}
	else if (this->machine_choice == "Paper" && this->user_choice == "Rock")
	{
		winner = "Machine";
		compare_choice = "Paper > Rock";
		this->machine_score++;
	}
	else if (this->machine_choice == "Scissors" && this->user_choice == "Paper")
	{
		winner = "Machine";
		compare_choice = "Scissors > Paper";
		this->machine_score++;
	}

	// Print the winner
	std::cout << compare_choice << ", " << winner << " wins!" << std::endl;

	// Check for 4 point difference early win
	if (this->user_score - this->machine_score == 4 || this->machine_score - this->user_score == 4)
	{
		return false;
	}

	return true;
}

void Game::print_score()
{
	std::cout << "User Score: " << this->user_score << std::endl;
	std::cout << "Machine Score: " << this->machine_score << std::endl;
}

void Game::start_game()
{
	int game_round = 1;

	// Main loop
	while (game_round <= this->rounds)
	{
		std::cout << "ROUND: " << game_round << std::endl;

		do
		{
			this->get_user_choice();
			this->get_machine_choice();

			std::cout << "User entered " << this->user_choice << ", while machine entered " << this->machine_choice << "---> ";

			if (this->user_choice == this->machine_choice)
				std::cout << "Draw" << std::endl;

		} while (this->user_choice == this->machine_choice);

		if (check_winner() == false)
		{
			this->print_score();
			break;
		}
		
		this->print_score();
		std::cout << "##########################################\n";

		game_round++;
	}

	// End of game
	if (this->user_score > this->machine_score)
		std::cout << "Final winner: User" << std::endl;
	else
		std::cout << "Final winner: Machine" << std::endl;
}

int main()
{
	Game game;

	game.start_game();

	return 0;
}