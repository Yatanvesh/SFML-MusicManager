#pragma once

#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include <Windows.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class MusicManager
{
private:

	sf::Sprite MusicImage;
	sf::Texture MusicImageTexture;
	int Alpha = 254;
	sf::Font MusicFont;
	sf::Text MusicText;
	sf::Clock NextPlayTimer;
	sf::Clock NextDisplayTimer;
	sf::RenderWindow &GameWindow;
	sf::Vector2f Screendimentions;
	string SubDirectory;
	//FileGetters
	string wchar_t2string(const wchar_t *wchar);
	wchar_t *string2wchar_t(const string &str);
	vector<string> listFilesInDirectory(string directoryName);

	bool MusicInfoFound = false;
	void NameGetter();
public:
	sf::Music GameMusic;
 vector<string> FileList;
 vector< pair<string, string>> MusicList;
	MusicManager(sf::RenderWindow &GameWindow,string _SubDirectory="Music/");

	void NextTrack();
	void StopPlaying();
	void StartPlaying();
	void TogglePlaying();

	void Handler();
	void DisplayPlayer();
	void SetTextSize(int size);
	void SetTextPosition(sf::Vector2f pos);
	void SetPlayerSize(float Size);
	~MusicManager();
	

		
	

};
