#include "Game.h"
#include"Parser.h"

int main(int argc, char* argv[])
{
	Parser p = Parser();
	p.loadLevel("../GamJam/res/sauvegarde.txt");
	std::cin.get();
	return 0;
}