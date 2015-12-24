Presenting Music Manager for you and your SFML projects! Its easy to use and sets up in minutes!

How to use:
1.Place all the files in your Project folder.
2.Import the MusicManager.cpp and MusicManager.h in your Project.
3.Create an object of the claas MusicManager and pass your renderwindow as an argument to the constructor.
MusicManager,by default will look for music files in Music/ folder of your project. However, you can change this by passing a second argument
to the constructor, a string with the location of music files.
4.use the function obj.Handler() in your main game loop and obj.DisplayPlayer() to draw the player.
5. You are done!!



The MusicManager also looks for a text file in the directory of music files that may contain artist info, name etc. 
The music files must be named as follows:
1.Track 1.ogg
2. any name will do.ogg
3.wow.wav

The name does not matter but the Serial number does.
The contents of text file containing artist info must be as follows:

Rodeo by human
the last of tracks
Mymusic records limited
#
jigglipuff
the last of tracks
Mymusic records limited
#
free me from this
the last of tracks
#

each track must end with a hashtag. 


