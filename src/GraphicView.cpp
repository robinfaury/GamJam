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
	this->event = Event(this->window);

	Map* map = this->world->getMap();
	for (int i=1; i<=map->getMaxIDTexture(); ++i)
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

int GraphicView::computeEvent()
{
	int eventID = this->event.CheckEvent();
	std::cout<<eventID;
	if (eventID == 2)
	{
		this->editor = true;
	}
	if (eventID == 3)
	{
		this->currentSprite.setTexture(this->blocTextures[0]);
	}
	if (this->editor)
	{
		this->currentSprite.setPosition(sf::Mouse::getPosition(*this->window).x-15, sf::Mouse::getPosition(*this->window).y-15);
	}

	return eventID;
}


void GraphicView::Draw()
{
	window->clear(sf::Color::Black);

	for (std::vector<sf::Sprite>::iterator it = this->sprites.begin(); it	!= this->sprites.end(); ++it)
	{
		window->draw(*it);
	}
	if (this->editor)
	{
		if (this->editor)
			window->draw(this->currentSprite);
	}

	window->display();
}

GraphicView::~GraphicView()
{

}