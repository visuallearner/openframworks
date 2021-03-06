#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	ofSoundPlayer soundPlayer;
public:
	void setup();
	void update();
	void draw();
	
        void face();
        void happy();
        void sad();
        void surprise();
        void angry();
        void move1();
        void move2();
    void move3();
    void move4();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

	void circleResolutionChanged(int & circleResolution);
	void ringButtonPressed();

	bool bHide;

	ofxFloatSlider soundvolume;
	ofxColorSlider color;
    ofxColorSlider facecolor;
	ofxVec2Slider centerface;
    ofxFloatSlider scalesize;
	ofxIntSlider leftbrow;
    ofxIntSlider rightbrow;
	ofxToggle filled;
	ofxButton emotions;
//	ofxButton ringButton;
	ofxLabel screenSize;
//
	ofxPanel gui;
    
    
    ofTrueTypeFont    verdana14;
//
//	ofSoundPlayer ring;
};

