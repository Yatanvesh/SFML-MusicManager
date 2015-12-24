
#include <windows.h>
#include <iostream>
#include <string>
#include "MusicManager.h"
#include <vector>
using namespace std;


void main()
{
	
	sf::RenderWindow GameWindow(sf::VideoMode(1024,768),"Music",sf::Style::Default);
	MusicManager a(GameWindow);
	
	while (1)
	{
		
		a.Handler();
		GameWindow.clear();
		a.DisplayPlayer();
		GameWindow.display();
	}

	
}