#include "ofApp.h"
ofVec2f centerface,lefteyebrow, righteyebrow, lefteyecenter, righteyecenter, mouthcenter, offset;
bool start;
float x = 0;
float y = 0;
float z = 0;
ofColor gee;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    //ofTrueTypeFont::setGlobalDpi(72);

     verdana14.load("verdana.ttf", 70, true, true);

     ofSetFrameRate(60);
     ofBackground(255,255,255);
     lefteyecenter.set(centerface + ofVec2f(-65,-20));
     righteyecenter.set(centerface + ofVec2f(65,-20));
     lefteyebrow.set(centerface + ofVec2f(-65,-70));
     righteyebrow.set(centerface + ofVec2f(65,-70));
     mouthcenter.set(centerface + ofVec2f(0,70));
     offset.set(0,17);
     start = false;
     soundPlayer.load("music.mp3");
     soundPlayer.setMultiPlay(true);
    
    bHide = false;
    
    gui.setup();
    gui.add(soundvolume.setup("Soundvolume", 0, 0, 1));
    gui.add(color.setup("Background Color", ofColor(0, 255, 255), ofColor(9,233, 0), ofColor(255, 255,255)));
    gui.add(facecolor.setup("Hat color", ofColor(0, 221, 75), ofColor(9,233, 0), ofColor(255, 255)));
    gui.add(centerface.setup("Face Position", {ofGetWidth()*.5, ofGetHeight()*.5}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    gui.add(leftbrow.setup("Lefteyebrow", 0, 3, 360));
    gui.add(rightbrow.setup("Righteyebrow", 0, 3, 360));
    gui.add(emotions.setup("Surprise"));
    gui.add(scalesize.setup("Change Emotion", 1, 0.9963, 1.088));
   soundPlayer.play();
}

//--------------------------------------------------------------


//--------------------------------------------------------------


//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::update(){
	//ofSetCircleResolution(circleResolution);

}

//--------------------------------------------------------------
void ofApp::draw(){
 
    ofSoundSetVolume(soundvolume);
//    if ((ofGetFrameNum())%120 == 0) {
//
//    }
    ofBackground(color);
    ofSetColor(255);
     verdana14.drawString("Minion with a hat", 100,400);
    
    if (emotions) {
        sad();
    }
    else{
    happy();
    }
    
    if(!bHide){
        gui.draw();
    }
}


    void ofApp::happy(){
        ofPath path;
         
        
        //drawface
        ofSetColor(246, 198, 22);
        ofDrawRectRounded(centerface, 250,300, 50);
         ofSetColor(0);
        ofNoFill();
        ofSetLineWidth(5);
         ofDrawRectRounded(centerface, 250,300, 50);
        ofSetColor(214, 214, 214);
        ofSetLineWidth(10);
        ofDrawEllipse(centerface + ofVec2f(-65,-20),110,110);
        ofDrawEllipse(centerface + ofVec2f(65,-20),110, 110);
        ofDrawRectangle(centerface+ ofVec2f(0,-20), 30, 2);
        
        //eyes,eyeballs
        ofPushMatrix();
        ofFill();
        ofSetColor(0);
        ofScale(1,scalesize,1);
        ofDrawEllipse(centerface + ofVec2f(-65,-20), 50, 30);
        ofSetColor(0);
        ofDrawEllipse(centerface + ofVec2f(65,-20), 50, 30);
        ofSetColor(0);
        ofDrawEllipse(centerface + ofVec2f(0,70), 60, 60);
        ofSetColor(255);
        ofDrawEllipse(centerface + ofVec2f(-65,-15), 10, 15);
        ofSetColor(255);
        ofDrawEllipse(centerface + ofVec2f(65,-15), 10, 15);
        ofPopMatrix();
        
        

        
        
        //body
        ofNoFill();
        ofSetColor(0);
        ofSetLineWidth(10);
        ofDrawRectRounded(centerface+ ofVec2f(0,180), 250, 50, 10);
        ofFill();
        ofSetColor(12, 69, 122);
        ofDrawRectRounded(centerface+ ofVec2f(0,180), 250, 50, 10);
        
        // HAT
        
        path.moveTo(centerface + ofVec2f(0,-310));
        path.lineTo(centerface + ofVec2f(-140,-100));
        path.lineTo(centerface + ofVec2f(140,-100));
        path.close();
        gee = facecolor;
        path.setFillColor(gee);
        path.setFilled(true);
        path.draw();
        
        
        //ofScale(scalesize);
        // lefteyebrow
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(centerface + ofVec2f(-65,-70));
        ofRotateZDeg(leftbrow);
        ofDrawRectangle(0, 0, 50, 10);
        ofPopMatrix();
        //righteyebrow
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(centerface + ofVec2f(65,-70));
        ofRotateZDeg(rightbrow);
        ofDrawRectangle(0, 0, 50, 10);
        ofPopMatrix();
        //Mouthcover
        ofSetColor(246, 198, 22);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle((centerface + ofVec2f(0,53)), 57, 30);
    }

void ofApp::sad(){
    ofPath path;
        //drawface
        ofSetColor(246, 198, 22);
        ofDrawRectRounded(centerface, 250,300, 50);
         ofSetColor(0);
        ofNoFill();
        ofSetLineWidth(5);
         ofDrawRectRounded(centerface, 250,300, 50);
        ofSetColor(214, 214, 214);
        ofSetLineWidth(10);
        ofDrawEllipse(centerface + ofVec2f(-65,-20),110,110);
        ofDrawEllipse(centerface + ofVec2f(65,-20),110, 110);
        ofDrawRectangle(centerface+ ofVec2f(0,-20), 30, 2);
        
        ofFill();
        ofSetColor(0);
        ofDrawEllipse(centerface + ofVec2f(-65,-20), 40, 45);
        ofSetColor(0);
        ofDrawEllipse(centerface + ofVec2f(65,-20), 40, 45);
        ofSetColor(0);
        ofDrawEllipse(centerface + ofVec2f(0,70), 60, 60);
        
    
        
        //body
        ofNoFill();
        ofSetColor(0);
        ofSetLineWidth(10);
        ofDrawRectRounded(centerface+ ofVec2f(0,180), 250, 50, 10);
        ofFill();
        ofSetColor(12, 69, 122);
        ofDrawRectRounded(centerface+ ofVec2f(0,180), 250, 50, 10);
    
    
        // HAT
        
        path.moveTo(centerface + ofVec2f(0,-310));
        path.lineTo(centerface + ofVec2f(-140,-100));
        path.lineTo(centerface + ofVec2f(140,-100));
        path.close();
        gee = facecolor;
        path.setFillColor(gee);
        path.setFilled(true);
        path.draw();
        
    
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(centerface + ofVec2f(-65,-70));
        ofRotateZDeg(leftbrow);
        ofDrawRectangle(0, 0, 50, 10);
        ofPopMatrix();
        //righteyebrow
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(centerface + ofVec2f(65,-70));
        ofRotateZDeg(rightbrow);
        ofDrawRectangle(0, 0, 50, 10);
        ofPopMatrix();
}

  
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    screenSize = ofToString(w) + "x" + ofToString(h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}
