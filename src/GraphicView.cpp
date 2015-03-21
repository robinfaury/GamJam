/**
 * Project Untitled
 */


#include "GraphicView.h"

/**
 * GraphicView implementation
 */

GraphicView::GraphicView(World* world)
{
	this->world = world;
}

void GraphicView::Init(int height, int width)
{
	this->window = new sf::RenderWindow(sf::VideoMode(height, width), "boobs");
	this->window->setVerticalSyncEnabled(true);

	for (int i=1; i<=5; ++i)
	{
		std::string filename("../GamJam/res/textures/blocs/bloc");
		if (i<10)
			filename += "0";
		else
			filename += "";
		filename += std::to_string(i) + ".png";

		this->blocTextures.push_back(sf::Texture());
		if (!this->blocTextures[this->blocTextures.size()-1].loadFromFile(filename))
			std::cout<<"ERROR : "<<filename<<std::to_string(i)<<".png isn't loaded"<<std::endl;
		std::cout<<filename<<std::to_string(i)<<".png is loaded"<<std::endl;
	}

	Map* map = this->world->getMap();
	for (int x=0; x<map->getwidth(); ++x)
	{
		for (int y=0; y<map->getheight(); ++y)
			std::cout<<map->getgrid()[x][y];
		std::cout<<std::endl;
	}
	for (int x=0; x<map->getwidth(); ++x)
	{
		for (int y=0; y<map->getheight(); ++y)
		{
			this->sprites.push_back(sf::Sprite());
			if (map->getgrid()[x][y] != 0)
				this->sprites[this->sprites.size()-1].setTexture(this->blocTextures[map->getgrid()[x][y]-1]);
			this->sprites[this->sprites.size()-1].setPosition(y*30, x*30);
		}
	}
	this->sprites.push_back(sf::Sprite());
	this->sprites[this->sprites.size()-1].setTexture(this->blocTextures[4]);
	this->sprites[this->sprites.size()-1].setPosition(50, 50);
}


void GraphicView::Draw()
{
	window->clear(sf::Color::Black);

	for (std::vector<sf::Sprite>::iterator currentSprite = this->sprites.begin(); currentSprite	!= this->sprites.end(); ++currentSprite)
	{
		window->draw(*currentSprite);
	}

	window->display();
}

GraphicView::~GraphicView()
{

}