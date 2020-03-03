#include "ofApp.h"
ofPoint myMouse;
ofPoint MouseClick1;
ofVec2f center, A, B, C, D;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowShape(800, 800);
    ofSetBackgroundColor(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    center.set(myMouse);
    
    eye();
    ofSetColor(255, 255, 255);
    ofDrawCircle(MouseClick1, 10);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Story 1 Title: Chase the light", 200,100);
    ofDrawBitmapString("This is dark", 200,200);
    ofDrawBitmapString("move the eye to chase the light ball", 200,230);
    
}

void ofApp::eye(){
    ofPath path;

   // center = center + (mouse);
    A.set(center + ofVec2f(0,-20));
    B.set(center + ofVec2f(40,0));
    C.set(center + ofVec2f(0,20));
    D.set(center + ofVec2f(-40,0));
    path.moveTo(A);
    path.lineTo(B);
    path.lineTo(C);
    path.lineTo(D);

    path.close();
    path.setStrokeColor(ofColor::white);
    path.setStrokeWidth(4);
    path.setFillColor(ofColor::black);
    path.setFilled(true);
    path.draw();
    ofSetColor(255, 255, 255);
    ofDrawCircle(center, 19);
  
   

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
       int step = 10;
       if(key == OF_KEY_UP) myMouse.y = myMouse.y - step;
       if(key == OF_KEY_DOWN) myMouse.y = myMouse.y + step;
       if(key == OF_KEY_RIGHT) myMouse.x = myMouse.x - step;
       if(key == OF_KEY_LEFT) myMouse.x = myMouse.x + step;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    myMouse.x = x-100;
    myMouse.y = y-100;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    MouseClick1.x = x+100;
    MouseClick1.y = y+100;
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
