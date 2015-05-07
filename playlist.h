#pragma once

#include "song.h"
#include <vector>
#include <iostream>
#include <string>

class playlist
{
private:
	int length;

public:
	playlist(void);
	~playlist(void);

	vector<song> list;

	int getLength(); // returns number of songs
	void getPlaylist(string path); // gets playlist ordered
	void showPlaylist(); // displays all song's data by order
	void showPLShort(); // display for PlayMode
};

