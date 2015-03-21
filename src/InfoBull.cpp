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

	// choix de la police à utiliser
	text.setFont(font); // font est un sf::Font

	// choix de la chaîne de caractères à afficher
	text.setString(s);
	
	std::cout << a;
	// choix de la taille des caractères
	text.setCharacterSize(40); // exprimée en pixels, pas en points !

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
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(900, 600), "My window");
	window.setSize(sf::Vector2u(a*26+100, a*22));
	text.move( 6*a+75, 150);
	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacement de la fenêtre en noir
		window.clear(sf::Color::White);

		// c'est ici qu'on dessine tout
		window.draw(Sprite);
		window.draw(text);

		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

}

InfoBull::~InfoBull(void){
	
}