/**
 * Project Untitled
 */


#include "GraphicView.h"
#include "InfoBull.h"

/**
 * GraphicView implementation
 */

GraphicView::GraphicView(World* world)
{	
	this->sortir = 0;
	this->world = world;
	this->currentIDTexture = 0;
	this->editor = false;
	this->play = false;
	this->time = 0;
}

void GraphicView::Init(int height, int width)
{
	this->window = new sf::RenderWindow(sf::VideoMode(1630, 1080), "boobs");
	this->window->setVerticalSyncEnabled(true);
	this->event = Event(this->window);

	
	for (int i=0; i<this->world->getMap()->getMaxIDTexture(); ++i)
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
	}

	if (!textureBackground.loadFromFile("../GamJam/res/textures/body/fond.png"))
		std::cout<<"ERROR : "<<"../GamJam/res/textures/body/fond.png isn't loaded"<<std::endl;
	this->background.setTexture(textureBackground);
	this->background.setPosition(0, 120);

	if (!lateralTexture.loadFromFile("../GamJam/res/textures/body/lateral.png"))
		std::cout<<"ERROR : "<<"../GamJam/res/textures/body/fond.png isn't loaded"<<std::endl;
	this->lateral.setTexture(lateralTexture);
	this->lateral.setPosition(46*29+15, 0);

	if (!hautTexture.loadFromFile("../GamJam/res/textures/body/haut.png"))
		std::cout<<"ERROR : "<<"../GamJam/res/textures/body/fond.png isn't loaded"<<std::endl;
	this->haut.setTexture(hautTexture);
	this->haut.setPosition(0, 0);

	this->buttons.push_back(Button(1400, 700, 50, 65, 1));
	this->buttons.push_back(Button(500,53, 370, 65, 1));
	this->buttons.push_back(Button(1000, 53, 370, 65, 1));
	this->buttons.push_back(Button(1400, 800,204,65,1));
	this->buttons.push_back(Button(50, 53, 370, 65, 2));
	this->buttons[this->buttons.size() - 5].setImage("../GamJam/res/textures/body/refresh.png");
	this->buttons[this->buttons.size() - 4].setImage("../GamJam/res/textures/body/btm2.png");
	this->buttons[this->buttons.size() - 3].setImage("../GamJam/res/textures/body/btm.png"); //jouer
	this->buttons[this->buttons.size()-2].setImage("../GamJam/res/textures/body/btv.png"); //quitter
	this->buttons[this->buttons.size()-1].setImage("../GamJam/res/textures/body/btm3.png"); //editer
	
}

int GraphicView::computeEvent()
{
	int eventID = this->event.CheckEvent();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		/*if (this->play == true)
		{ 
			this->play = false;
		}
		else
		{*/
			this->play = true;
		//}
		this->world->getPlayer()->stop();
	}

	if (0 <= eventID && eventID <= this->blocTextures.size()-1)
	{
		this->currentSprite.setTexture(this->blocTextures[eventID]);
		this->currentIDTexture = eventID;
	}
	if (this->editor)
	{
		float x = sf::Mouse::getPosition(*this->window).x, y = sf::Mouse::getPosition(*this->window).y;
		if (!(x < 0 || y < 120 || x > 46*30 || y > this->window->getSize().y))
		{
			this->currentSprite.setPosition(x-30, y-30);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				int i = x/30, j = (y-120)/30;
				this->world->getMap()->getgrid()[j][i] = this->currentIDTexture;
				this->world->getWorldObjects()->at(this->world->getMap()->getheight()*j+i).setType(this->currentIDTexture);
				this->world->getWorldObjects()->at(this->world->getMap()->getheight()*j+i).init(this->world->getNbFrame(this->currentIDTexture));
			}
		}
	}

	float x = sf::Mouse::getPosition(*this->window).x, y = sf::Mouse::getPosition(*this->window).y;

	if (this->buttons[this->buttons.size() - 5].verif(x, y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttons[this->buttons.size() - 5].setImage("../GamJam/res/textures/body/refresh_c.png");
			this->world->getPlayer()->setGender(!this->world->getPlayer()->getGender());

		}
		else{
			this->buttons[this->buttons.size() - 5].setImage("../GamJam/res/textures/body/refresh.png");
		}
		
	}

	if (this->buttons[this->buttons.size() - 4].verif(x, y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttons[this->buttons.size() - 4].setImage("../GamJam/res/textures/body/btm2_c.png");
			this->world->SaveLevel();
			this->editor = false;

		}else{

			this->buttons[this->buttons.size() - 4].setImage("../GamJam/res/textures/body/btm2.png");
			
		}
	}

	if (this->buttons[this->buttons.size() - 3].verif(x, y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttons[this->buttons.size() - 3].setImage("../GamJam/res/textures/body/btm_c.png");
			this->editor = false;

			
			closer2();

			this->sortir = 1;
			

			

		}
	}

	if (this->buttons[this->buttons.size() - 2].verif(x,y))
	{	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttons[this->buttons.size() - 2].setImage("../GamJam/res/textures/body/btv_c.png");
			closer();
			
		}
	}
	if (this->buttons[this->buttons.size() - 1].verif(x, y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttons[this->buttons.size() - 1].setImage("../GamJam/res/textures/body/btm3_c.png");


		}
		else{
			
			this->buttons[this->buttons.size() - 1].setImage("../GamJam/res/textures/body/btm3.png");
			this->editor = true;
		}
	}


	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		
	}*/

	return eventID;
}


void GraphicView::Draw()
{
	window->clear(sf::Color::Black);

	window->draw(this->background);
	
	for (int i=0; i<this->world->getWorldObjects()->size(); ++i)
	{
		this->world->getWorldObjects()->at(i).draw(time);
		window->draw(*this->world->getWorldObjects()->at(i).getSprite());
	}
	if (this->editor)
		window->draw(this->currentSprite);
	window->draw(*this->world->getPlayer()->getPlayerSprite());

	window->draw(this->lateral);
	window->draw(this->haut);

	for (std::vector<Button>::iterator it = this->buttons.begin(); it != this->buttons.end(); ++it)
		window->draw(*(*it).getSprite());

	window->display();

	if (this->world->getPlayer()->getDead() == true)
	{
		this->play = false;
		InfoBull bulle("Game over!");
	}

	if (this->world->getPlayer())

	if (this->play)
		this->world->getPlayer()->run(this->time);

	++this->time;
}
void GraphicView::closer(){
window->close();
exit(0);
}
void GraphicView::closer2(){
	window->close();
	
}
GraphicView::~GraphicView()
{

}
int GraphicView::getsortir(){
	return sortir;
}