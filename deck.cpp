#include "deck.h"

deck::deck(void)
{
}


deck::~deck(void)
{
}

void deck::getSong(song song_, string path)
{
	mySong = song_;
	mySong.loadSong(path);
}

int deck::getBPM(){return bpm_pl;}

void deck::setMaster(bool mast){master = mast;}

void deck::setBPM(int bpm)
{
	bpm_pl = bpm;
	mySong.changeSpeed(bpm);
}

bool deck::isMaster(){return master;}

void deck::setDeck(song song_, string path, bool mast)
{
	getSong(song_, path);
	setMaster(mast);
	bpm_pl = mySong.getBPM();
}

void deck::releaseDeck()
{
	mySong.unloadSong();
	setMaster(false);
}

