/**
 * Project Untitled
 */


#include "GraphicView.h"

/**
 * GraphicView implementation
 */

GraphicView::GraphicView()
{

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

	for (int x=0; x<30; ++x)
	{
		for (int y=0; y<30; ++y)
		{
			this->sprites.push_back(sf::Sprite());
			this->sprites[this->sprites.size()-1].setTexture(this->blocTextures[0]);
			this->sprites[this->sprites.size()-1].setPosition(x*30, y*30);
		}
	}
	this->sprites.push_back(sf::Sprite());
	this->sprites[this->sprites.size()-1].setTexture(this->blocTextures[4]);
	this->sprites[this->sprites.size()-1].setPosition(50, 50);
}

int GraphicView::CheckEvent()
{
	sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
		{
            this->window->close();
			return 1;
		}
    }
	return 0;
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

void GraphicView::SetWorld(World* world)
{
	this->world = world;
}

GraphicView::~GraphicView()
{

}