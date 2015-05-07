#include "song.h"


song::song(void)
{
}


song::~song(void)
{
}

string song::parse(string path)
{
	bool stop = false;
	int old, n;
	string name;
	
	old = path.find('\\', 0);
	while (!stop) {
		n = path.find('\\', old+1);
			if (n != -1){
				old = n;
			} else stop = true;
	}

	
	return path.erase(0, old+1);
}

void song::getSongByFilename(string path)
{
	song Song;
	//audio.loadSound(path);
	string filename = parse(path);
	string bpm_;
	
	int pos = filename.find('-',0);
	key = filename;
	key = key.erase(pos-1, filename.size());
	filename = filename.erase(0, pos+2);
	pos = filename.find('-',0);
	bpm_ = filename;
	bpm_ = bpm_.erase(pos-1, filename.size());
	filename = filename.erase(0,pos+2);
	pos = filename.find('-',0);
	artist = filename;
	artist = artist.erase(pos-1, filename.size());
	title = filename.erase(0, pos+2);
	title = title.erase(title.size()-4, title.size());

	std::string::size_type sz;
	bpm = stoi(bpm_, &sz);
	
}

void song::getSongByID3Tags(string path)
{
	song Song;
	audio.loadSound(path);
}

string song::getTitle(){return title;}

string song::getArtist(){return artist;}

string song::getKey(){return key;}

int song::getBPM(){return bpm;}

string song::getPath(){return aud_path;}

void song::setPath(string path){aud_path = path;}

void song::loadSong(string path)
{
	audio.loadSound(path);
}

void song::unloadSong()
{
	audio.unloadSound();
}

void song::play()
{
	audio.play();
}

void song::stop()
{
	audio.stop();
}

bool song::isPlaying()
{
	return audio.getIsPlaying();
}

void song::showSong()
{
	cout << getKey() << " - " << getBPM() << " - " << getArtist() << " - " << getTitle() << endl; 
}

void song::showShortSong()
{
	cout << getArtist() << " - " << getTitle() << endl;
}

void song::changeSpeed(int nbpm)
{
	audio.setSpeed(float(nbpm)/float(getBPM()));
}