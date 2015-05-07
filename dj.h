#pragma once

#include "playlist.h"
#include "deck.h"

class dj
{
public:

	void mix(deck, deck, playlist);
	void sync(deck&, deck&);

	dj(void);
	~dj(void);
};

