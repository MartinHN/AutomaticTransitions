#pragma once

#include "ofMain.h"


class song
{
private:
	
	string aud_path, title, artist, key;
	int bpm;

public:
	song(void);
	~song(void);

	ofSoundPlayer audio;

	string parse(string path); // gets song's filename
	void getSongByFilename(string path); // gets song's data
	void getSongByID3Tags(string path); //WIP
	
	// GETTERS
	string getTitle();
	string getArtist();
	string getKey();
	int getBPM();
	string getPath();
	void setPath(string path);
	void loadSong(string path);
	void unloadSong();

	void play();
	void stop();
	bool isPlaying();
	void showSong(); // displays song's data
	void showShortSong();
	void changeSpeed(int bpm);
};

