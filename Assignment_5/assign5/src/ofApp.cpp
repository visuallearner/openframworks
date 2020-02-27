#include "ofApp.h"

ofVec2f centerface,lefteyebrow, righteyebrow, lefteyecenter, righteyecenter, mouthcenter, offset;
bool start;
float x = 0;
float y = 0;
float z = 0;
ofPath path;
ofColor gee;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    

    ofBackground(255,255,255);
    centerface.set(300,300);
    lefteyecenter.set(235,280);
    righteyecenter.set(365,280);
    lefteyebrow.set(235,230);
    righteyebrow.set(365,230);
    
    mouthcenter.set(300,370);
    offset.set(0,17);
    start = false;
    soundPlayer.load("music.mp3");
    soundPlayer.setMultiPlay(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()>0){
        start = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(start == false){
        //        drawShapes();
    }
    
    if(start == true){
        if ((ofGetFrameNum())%120 == 0) {
            soundPlayer.play();
        }
        
        int num = ((ofGetFrameNum())/60)%8;
            face();
        if( num >= 0 and num <= 1){
           happy();
        } else if(num > 1 and num <= 2){
            move1();
        } else if(num > 2 and num <= 3){
            sad();
        } else if(num > 3 and num <= 4){
            move2();
        }else if(num > 4 and num <= 5){
            surprise();
        }else if(num > 5 and num <= 6){
            move3();
        }
        else if(num > 6 and num <= 7){
            angry();
        }
        else{
            move4();
        }
    }
}
void ofApp::face(){
    
    


    ofSetColor(237, 126, 57);
    ofDrawEllipse(centerface, 250, 300);
    ofSetColor(0);
    ofDrawEllipse(lefteyecenter, 30, 35);
    ofSetColor(0);
    ofDrawEllipse(righteyecenter, 30, 35);
    ofSetColor(0);
    ofDrawEllipse(mouthcenter, 60, 60);

    path.moveTo(300,50,0);
    path.lineTo(175,220,0);
    path.lineTo(425,220,0);
    path.close();
    path.setFillColor(ofColor::green);
    path.setFilled(true);
    path.draw();
}

void ofApp::happy(){
    x = 0;
    y = 0;
    z = 0;
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(lefteyebrow, 50, 10);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(righteyebrow, 50, 10);
    
    ofSetColor(237,126, 57);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle((mouthcenter-offset), 60, 30);
}

void ofApp::move1(){
//lefteyebrow
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(lefteyebrow);
    ofRotateZDeg(x);
    x -= 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
//righteyebrow
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(righteyebrow);
    ofRotateZDeg(y);
    y += 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
//rectanglemove
    ofSetColor(237,126, 57);
    ofSetRectMode(OF_RECTMODE_CENTER);
    if (z >= 37) {
        z +=0.01;
       offset.y = offset.y - z;
    }

    ofDrawRectangle((mouthcenter-offset), 60, 30);
    
}

void ofApp::sad(){
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(lefteyebrow);
    ofRotateZDeg(x);
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(righteyebrow);
    ofRotateZDeg(y);
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
    ofSetColor(237, 126, 57);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle((mouthcenter-offset), 60, 30);
}

void ofApp::move2(){
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(lefteyebrow);
    ofRotateZDeg(x);
    x += 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
    
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(righteyebrow);
    ofRotateZDeg(y);
    y -= 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
    //rectanglemove
//    ofSetColor(237,126, 57);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    z -=0.01;
//    offset.y = offset.y + z;
//    ofDrawRectangle((mouthcenter-offset), 60, 30);

    
}

void ofApp::surprise(){
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(lefteyebrow, 50, 10);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(righteyebrow, 50, 10);
}

void ofApp::move3(){
//lefteyebrow
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(lefteyebrow);
    ofRotateZDeg(x);
    x += 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
//righteyebrow
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(righteyebrow);
    ofRotateZDeg(y);
    y -= 0.5 ;
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
}

void ofApp::angry(){
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(lefteyebrow);
    ofRotateZDeg(x);
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(righteyebrow);
    ofRotateZDeg(y);
    ofDrawRectangle(0, 0, 50, 10);
    ofPopMatrix();
}

void ofApp::move4(){
    //lefteyebrow
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(lefteyebrow);
        ofRotateZDeg(x);
        x -= 0.5 ;
        ofDrawRectangle(0, 0, 50, 10);
        ofPopMatrix();
    //righteyebrow
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(righteyebrow);
        ofRotateZDeg(y);
        y += 0.5 ;
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
void ofApp::mouseMoved(int x, int y){

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
