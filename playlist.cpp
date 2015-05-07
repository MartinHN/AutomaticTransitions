#include "playlist.h"
//#include <tag.h>


playlist::playlist(void)
{
}


playlist::~playlist(void)
{
}

bool keyOrder(song s1, song s2) 
{
	string keysOrder[] = {"1A", "1B", "2B", "2A", "3A", "3B", "4B", "4A", 
						  "5A", "5B", "6B", "6A", "7A", "7B", "8B", "8A", 
						  "9A", "9B", "10B", "10A", "11A", "11B", "12B", "12A", "FF"};

	int n1 = 0, n2 = 0;

	while(keysOrder[n1] != s1.getKey()) {n1++;}
	while(keysOrder[n2] != s2.getKey()) {n2++;}

	return n1<n2;
}

int playlist::getLength()
{
	return length;
}

void playlist::getPlaylist(string path)
{
	cout << "Loading... This may take some time";
	ofDirectory dir(path);
	dir.allowExt("mp3");
	dir.listDir();

	length = dir.numFiles();

	for(int i = 0; i < dir.numFiles(); i++){
		string song_path = dir.getPath(i);
		song Song;
		Song.setPath(song_path);
		Song.getSongByFilename(song_path);
		list.push_back(Song);
	}
	
	// order by key
	sort(list.begin(), list.end(), keyOrder);
	
	system("cls"); cout << "Ready!";
}

void playlist::showPlaylist()
{
	for(int i = 0; i < getLength(); i++)
	{
		list[i].showSong();
	}
}

void playlist::showPLShort()
{
	for(int i = 0; i < getLength(); i++)
	{
		cout << char(i+65) << ")  ";
		list[i].showShortSong();
	}
}