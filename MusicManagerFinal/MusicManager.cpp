#include "MusicManager.h"





MusicManager::MusicManager(sf::RenderWindow &_GameWindow, string _SubDirectory) :GameWindow(_GameWindow)
{

	SubDirectory = _SubDirectory;
	srand(time(0));
	NameGetter();
	
	random_shuffle(MusicList.begin(), MusicList.end());
	

	random_shuffle(MusicManager::FileList.begin(), MusicManager::FileList.end());
	
	Screendimentions = sf::Vector2f(GameWindow.getSize());

	string direc = SubDirectory + MusicList.front().first;
	
	MusicFont.loadFromFile("MusicPlayerResources/Font.ttf");
	MusicText.setFont(MusicFont); MusicText.setCharacterSize(20); MusicText.setString(MusicList.front().second);
	MusicText.setPosition(Screendimentions.x*0.2, Screendimentions.y*0.85);
	MusicText.setOrigin(MusicText.getLocalBounds().width / 2, MusicText.getLocalBounds().height / 2 );

	MusicImageTexture.loadFromFile("MusicPlayerResources/Player.png"); MusicImage.setTexture(MusicImageTexture);

	MusicImage.setOrigin(MusicImage.getLocalBounds().width / 2, MusicImage.getLocalBounds().height / 4);
	MusicImage.setPosition(MusicText.getPosition().x, MusicText.getPosition().y);

	GameMusic.openFromFile(direc);
	GameMusic.play();
}


MusicManager::~MusicManager()
{
}



string MusicManager::wchar_t2string(const wchar_t *wchar)
{
	string str = "";
	int index = 0;
	while (wchar[index] != 0)
	{
		str += (char)wchar[index];
		++index;
	}
	return str;
}

wchar_t *MusicManager::string2wchar_t(const string &str)
{
	wchar_t wchar[260];
	int index = 0;
	while (index < str.size())
	{
		wchar[index] = (wchar_t)str[index];
		++index;
	}
	wchar[index] = 0;
	return wchar;
}

vector<string> MusicManager::listFilesInDirectory(string directoryName)
{
	WIN32_FIND_DATA FindFileData;
	wchar_t * FileName = string2wchar_t(directoryName);
	HANDLE hFind = FindFirstFile(FileName, &FindFileData);

	vector<string> listFileNames;
	listFileNames.push_back(wchar_t2string(FindFileData.cFileName));

	while (FindNextFile(hFind, &FindFileData))
		listFileNames.push_back(wchar_t2string(FindFileData.cFileName));

	return listFileNames;
}

void MusicManager::NameGetter()
{
	ifstream MusicInfoGetter;
	
	vector<string> listFiles;
	listFiles = listFilesInDirectory("./Music/*.*");
	for each (string str in listFiles)
	{
		if (str.find("txt") != std::string::npos)
		{
			
			MusicInfoGetter.open(SubDirectory+ str); MusicInfoFound = true; 
			
		}

	}
	
	char tmp[200]; string tmp1;

	
	int counter = 0;
	for each (string str in listFiles)
	{
		if (counter > 1)
		{
			if (str.find("txt") == std::string::npos)
			{
				MusicInfoGetter.getline(tmp, 200,'#');
				MusicList.push_back(std::make_pair(str, string(tmp)));
			}
			
			
		}

		counter++;
	}

	
}


void MusicManager::Handler()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::End))
	{
		NextPlayTimer.restart().asSeconds();
		GameMusic.pause();
		NextDisplayTimer.restart().asSeconds();
		Alpha = 255;
	}
	
	
	if (GameMusic.getStatus() == sf::Sound::Stopped)
	{
		NextPlayTimer.restart().asSeconds();
		NextDisplayTimer.restart().asSeconds();
		Alpha = 255;
	}
	if (NextPlayTimer.getElapsedTime().asSeconds() > 1 &&GameMusic.getStatus()!=sf::Music::Playing)
	{
		random_shuffle(MusicList.begin(), MusicList.end());

		string direc = SubDirectory + MusicList.front().first;
		
		GameMusic.openFromFile(direc);
		GameMusic.play();
		MusicText.setString(MusicList.front().second);
		MusicText.setOrigin(MusicText.getLocalBounds().width / 2, MusicText.getLocalBounds().height / 2);

	}
}

void MusicManager::DisplayPlayer()
{
	if (NextDisplayTimer.getElapsedTime().asSeconds()>4)
	Alpha = (5 - NextDisplayTimer.getElapsedTime().asSeconds())*100*2.55;
	MusicImage.setColor(sf::Color(255, 255, 255, Alpha));
	MusicText.setColor(sf::Color(255, 255, 255, Alpha));
	if (NextDisplayTimer.getElapsedTime().asSeconds() <5)
	{
		GameWindow.draw(MusicImage);
		GameWindow.draw(MusicText);
	}
}

void MusicManager::SetTextSize(int size)
{
	MusicText.setCharacterSize(size);
}
void MusicManager::SetTextPosition(sf::Vector2f pos)
{
	MusicText.setPosition(pos);
	
}
void MusicManager::SetPlayerSize(float size)
{
	MusicText.scale(size, size);
	MusicImage.scale(size, size);
}