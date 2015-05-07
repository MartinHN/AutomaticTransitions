#include "dj.h"


dj::dj(void)
{
}


dj::~dj(void)
{
}

void dj::mix(deck DeckA, deck DeckB, playlist myPlaylist)
{
	int pos = 2;
	DeckA.mySong.play();
	sync(DeckA, DeckB);

	while(pos < myPlaylist.getLength())
	{
		if(DeckA.mySong.audio.getPosition() == 1)
		{
			DeckB.mySong.play();
			//DeckB.setMaster(true);
			DeckA.releaseDeck();
			DeckA.setDeck(myPlaylist.list[pos], myPlaylist.list[pos].getPath(), false);
			DeckA.mySong.loadSong(myPlaylist.list[pos].getPath());
			sync(DeckB, DeckA);
			pos++;
		}

		if(DeckB.mySong.audio.getPosition() == 1)
		{
			DeckA.mySong.play();
			DeckB.releaseDeck();
			DeckB.setDeck(myPlaylist.list[pos], myPlaylist.list[pos].getPath(), false);
			DeckB.mySong.loadSong(myPlaylist.list[pos].getPath());
			sync(DeckA, DeckB);
			pos++;		
		}
	}	
}

void dj::sync(deck &Master, deck &Slave)
{
	int bpm_M = Master.getBPM();

	Slave.mySong.changeSpeed(bpm_M);
	Slave.setBPM(bpm_M);
}