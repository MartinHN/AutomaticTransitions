#include "song.h"

// static declaration shared by all tone structures
// in cpp to be executed only once the cpp is compiled ( not each time header is called)
string song::tone::KeyFinderNames [] =  {"1A", "1B", "2B", "2A", "3A", "3B", "4B", "4A","5A", "5B", "6B", "6A", "7A", "7B", "8B","8A","9A", "9B", "10B", "10A", "11A", "11B", "12B", "12A", "FF"};

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
    
    //	string filename = parse(path);
    string filename =     ofFile(path).getBaseName();
	string bpm_;
	
    
    
    
    vector<string> fields = ofSplitString(filename, "-");
    
    if(fields.size()>3){
        artist = fields[0];
        title = fields[1];
        key = fields[2];
        bpm = ofToInt(fields[3]);
    }
    else{
        ofLogError("song") << "invalid song name" << filename;
    }
    
    
    // NOTE: hard to understand logic.. replaced by previous
    //	int pos = filename.find('-',0);
    //	key = filename;
    //	key = key.erase(pos-1, filename.size());
    //	filename = filename.erase(0, pos+2);
    //	pos = filename.find('-',0);
    //	bpm_ = filename;
    //	bpm_ = bpm_.erase(pos-1, filename.size());
    //	filename = filename.erase(0,pos+2);
    //	pos = filename.find('-',0);
    //	artist = filename;
    //	artist = artist.erase(pos-1, filename.size());
    //	title = filename.erase(0, pos+2);
    //	title = title.erase(title.size()-4, title.size());
    
    //	std::string::size_type sz;
    //	bpm = stio(bpm_,sz);
	
}

#if ID3_SUPPORT
void song::getSongByID3Tags(string path)
{
	song Song;
	audio.loadSound(path);
    
    TagLib::FileRef f(path.c_str());
    artist =f.tag()->artist().toCString();
    //    album = ofToString(f.tag()->album());
    title = f.tag()->title().toCString();
    
    vector<string> fields = ofSplitString(ofFile(path).getBaseName(), "-");
    
    if(fields.size()>3){
        key = fields[2];
        bpm = ofToInt(fields[3]);
    }
}
#endif
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