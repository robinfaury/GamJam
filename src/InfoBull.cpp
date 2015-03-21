/**
 * Project Untitled
 */


#include "InfoBull.h"


/**
 * InfoBull implementation
 */ 

InfoBull::InfoBull(std::string s)
{
	sf::Text text;
	sf::Font font;

	int a = s.size();

	font.loadFromFile("../GamJam/res/arial.ttf");

	// choix de la police � utiliser
	text.setFont(font); // font est un sf::Font

	// choix de la cha�ne de caract�res � afficher
	text.setString(s);
	
	std::cout << a;
	// choix de la taille des caract�res
	text.setCharacterSize(40); // exprim�e en pixels, pas en points !

	// choix de la couleur du texte
	text.setColor(sf::Color::Blue);

	// choix du style du texte
	text.setStyle(sf::Text::Bold );
	


	std::cout << "truc"<<std::endl;
	sf::Texture Image;
	sf::Sprite Sprite;


	if (!Image.loadFromFile("../GamJam/res/bulle.png"))
	{
		// Erreur...
	}
	Image.setSmooth(true);
	Sprite.setTexture(Image);
	// cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(900, 600), "My window");
	window.setSize(sf::Vector2u(a*26+100, a*22));
	text.move( 6*a+75, 150);
	// on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
	while (window.isOpen())
	{
		// on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fen�tre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacement de la fen�tre en noir
		window.clear(sf::Color::White);

		// c'est ici qu'on dessine tout
		window.draw(Sprite);
		window.draw(text);

		// fin de la frame courante, affichage de tout ce qu'on a dessin�
		window.display();
	}

}

InfoBull::~InfoBull(void){
	
}