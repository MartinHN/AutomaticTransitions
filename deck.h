#pragma once

#include "song.h"

class deck
{
private:
	bool master;
	int bpm_pl;
public:
	song mySong;
	
	deck(void);
	~deck(void);

	void getSong(song, string path);
	int getBPM();
	void setMaster(bool);
	void setBPM(int);
	bool isMaster();

	void setDeck(song, string path, bool);
	void releaseDeck();
};

