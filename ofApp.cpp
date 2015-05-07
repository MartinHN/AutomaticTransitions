#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	myPlaylist.getPlaylist("songs");
	mixStyle = NoMix;
}

//--------------------------------------------------------------
void ofApp::update(){

	if(mixStyle == NoMix)
	{
		if(DeckA.mySong.audio.getPosition() >= 0.9999 && pos < myPlaylist.getLength())
		{
			DeckB.mySong.play();
			DeckA.releaseDeck();
			DeckA.setDeck(myPlaylist.list[pos], myPlaylist.list[pos].getPath(), false);
			DeckA.mySong.loadSong(myPlaylist.list[pos].getPath());
			DJ.sync(DeckB, DeckA);
			pos++;
		}

		if(DeckB.mySong.audio.getPosition() >= 0.9999 && pos < myPlaylist.getLength())
		{
			DeckA.mySong.play();
			DeckB.releaseDeck();
			DeckB.setDeck(myPlaylist.list[pos], myPlaylist.list[pos].getPath(), false);
			DeckB.mySong.loadSong(myPlaylist.list[pos].getPath());
			DJ.sync(DeckA, DeckB);
			pos++;		
		}	
	}
	else if (mixStyle == SoftMix)
	{
		//WIP
	}
	else if (mixStyle == HardMix)
	{
		//WIP
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// F1 Shows the Playlist
	if (key == 257) { // 257 = F1
		system("cls");
		myPlaylist.showPlaylist();
	}
	
	// F2 Starts the music from the beginning of the Playlist	
	if (key == 258) { // 258 = F2
		DeckA.releaseDeck();
		DeckB.releaseDeck();
		DeckA.setDeck(myPlaylist.list[0], myPlaylist.list[0].getPath(), true);
		DeckB.setDeck(myPlaylist.list[1], myPlaylist.list[1].getPath(), false);
		pos = 2;
		DeckA.setBPM(250);
		DeckA.mySong.play();	
	}
	
	// F3 Stops all the music
	if (key == 259) { // 258 = F3
		ofSoundStopAll();
		DeckA.releaseDeck();
		DeckB.releaseDeck();
		system("cls");
	}

	if(key-'a' == 0) mixStyle = NoMix;   // Sets NoMix style
	if(key-'b' == 0) mixStyle = SoftMix; // Sets SoftMix style
	if(key-'c' == 0) mixStyle = HardMix; // Sets HardMix style

	/* Test Purposes
	if (key-'a' >= 0 && key-'a' < myPlaylist.getLength() && PlayMode == true) {
		if (!myPlaylist.list[key-'a'].isPlaying()) myPlaylist.list[key-'a'].play();
		else myPlaylist.list[key-'a'].stop();
	}
	
	if (key-'a') DeckA.mySong.play();

	if (key-'b') DeckB.mySong.play();
	*/
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
