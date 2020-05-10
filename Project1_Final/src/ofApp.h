#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
        void open();
        void eyewake();
        void eyemovearound();
        void eyeclosed();
        void ballcomein();
        void ballspeak();
        void ballspeak2();
        void ballspeak3();
        void eyespeak();
        void eyespeak2();
        void eyespeak3();
        void eyespeak4();
        void eyespeak5();
        void eyechase();
        void eyechase2();
        void tears();
        void end();
    
    
    
    ofxBox2d box2d;
     
     ofxBox2dCircle circle;
     
     vector <shared_ptr<ofxBox2dCircle>> circles;
     
     vector <shared_ptr<ofxBox2dRect>> rectangles;
     
     vector <shared_ptr<ofxBox2dPolygon>> polygons;
     
     ofPolyline polygonShape;
    
};
