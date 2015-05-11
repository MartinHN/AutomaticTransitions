#pragma once

#include "ofMain.h"

#if ID3_SUPPORT
// taglib stuff
#include "tag.h"
#include "fileref.h"
#endif
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
#if ID3_SUPPORT
	void getSongByID3Tags(string path); //WIP
#endif
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
    
    
    
    // example tonal element structure
    // can be also in a separate file if song class grows too much
    // see begining of song.cpp for static initialisations
    typedef struct tone {
        static string KeyFinderNames[];
        //        static string readableNames[] = {"C","C#",....
        int value = -1;
        
        tone(const string & name){
            int i =0;
            while(KeyFinderNames[i]!="FF"){
                if(name == KeyFinderNames[i]){break;}
                i++;
            }
            value = i;
        }
        
        const string & getReadableName(){
            // readableName[value]
        }
        // comparator can compare "value"  attribute without iterating each time
        
        
        
    }tone;
};

