#include "ofApp.h"
ofSoundPlayer music;
ofVec2f center, A, B, C, D;
ofPoint MouseClick1;
int PosX =400;
int PosY =400;
float x= 5;
int y= 4;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowShape(800, 800);
    ofSetBackgroundColor(0);
    ofEnableSmoothing();
    ofSetCircleResolution(128);
    music.load("sound/music.mp3");
    music.setMultiPlay(true);
    music.play();
 //tears
    box2d.init();
    box2d.setGravity(0, 30);
    box2d.createGround();
    box2d.registerGrabbing();
    box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
    
    circle.setPhysics(3.0, 0.5, 1.0);
    circle.setup(box2d.getWorld(), 400, 400, 10);
    
}

//--------------------------------------------------------------
void ofApp::update(){
  box2d.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
     int frame = ofGetFrameNum();
      //3 mintues = 180 sec
      int num = (frame/60)%185;
      
    if (num >= 0 and num <= 16){
       // typewriter.play();
        open();
      }
    
    if (num >= 17 and num <= 20){
          // typewriter.play();
           eyewake();
         }
    if (num >= 21 and num <= 40){
     // typewriter.play();
      eyemovearound();
    }
    
    if (num >= 41 and num <= 51){
        // typewriter.play();
         eyeclosed();
       }
    
     if (num >= 52 and num <= 115){
           // typewriter.play();
            ballcomein();
        }
    if (num >= 55 and num <= 59){
           // typewriter.play();
            ballspeak();
        }
    if (num >= 62 and num <= 67){
            // typewriter.play();
             eyespeak();
         }
    if (num >= 69 and num <= 74){
               // typewriter.play();
                ballspeak2();
            }
    if (num >= 76 and num <= 81){
                  // typewriter.play();
                eyespeak2();
               }
    if (num >= 83 and num <= 88){
                   // typewriter.play();
                 eyespeak3();
                }
    
    if (num >= 65 and num <= 88){
             // typewriter.play();
            eyewake();
          }
    if (num >= 89 and num <= 113){
              // typewriter.play();
             eyechase();
           }
    if (num >= 100 and num <= 105){
            eyespeak4();
        }
    if (num >= 107 and num <= 112){
            ballspeak3();
        }
    if (num >= 114 and num <= 118){
            eyespeak5();
            eyechase2();
         }
    if (num >= 119 and num <= 180){
        eyewake();
        tears();
         }
    
    if (num >= 181 and num <= 185){
        end();
     }
  
    
    
}

void ofApp::open(){
     string thisIsMyText = "Long long time ago \n\nIn an universe with no light \n\nan eye has just born from the dark          \n\nhe is young and navie              \n\n\n\n\nand wishing to explore more...                           ";
       float timePerLetter = 0.1;
       float timeToTakeToType = thisIsMyText.length() * timePerLetter;
       float time = ofGetElapsedTimef();
       time = fmodf( time, timeToTakeToType );
       string drawString = thisIsMyText.substr( 0, ofMap(time, 0.0, timeToTakeToType, 0, thisIsMyText.length()-1 ));
       ofDrawBitmapString(drawString, 250, 300);
}

void ofApp::eyewake(){
     
    ofPath path;
    center.set(400,400);
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

void ofApp::eyemovearound(){
   ofPath path;
      
      center.set(PosX,PosY);
      PosX = PosX + x;
      PosY = PosY + y;
        x = x + 0.1;
      if (PosX<0 ||PosX> ofGetWidth()){
          x = -x;
          
      }
      if (PosY<0 ||PosY> ofGetHeight()){
          y = -y;
      }
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

void ofApp::eyeclosed(){
     string thisIsMyText = "He moves around\n\ntrying to find more friends,\n\nbut he finds nothing...\n\nhe feels so lonely\n\nhe decides to go to sleep again\n\n\n\nAt the very moment...a lost lightball enters the dark                                                                 ";
           ofDrawBitmapString(thisIsMyText, 250, 300 );
}

void ofApp::ballcomein(){
      ofSetColor(255, 255, 255);
    float time = ofGetElapsedTimef();
    ofDrawCircle(ofGetWidth()*ofNoise(time * 0.5),ofGetHeight()*ofNoise(time *0.7), 10);
}

void ofApp::ballspeak(){
    string thisIsMyText = "Naughty Lightball: Why it is so dark here? Anyone Home?\n\n";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::eyespeak(){
    string thisIsMyText = "The eye heard the noise. He wakes up again\n\nEye: Who are you?";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::ballspeak2(){
    string thisIsMyText = "Naughty Lightball: I am lightball. Come! Play with me!\n\n";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::eyespeak2(){
    string thisIsMyText = "[Light?] Eye thinks: [That's a new word, but I like it.]";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::eyespeak3(){
    string thisIsMyText = "Eye: Wait for me! I will chase you!";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::eyespeak4(){
    string thisIsMyText = "Eye: You are too fast!!! I can't catch you!";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::ballspeak3(){
    string thisIsMyText = "Naughty Lightball: Hey! I need to go! We will see each other again!\n\n";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}

void ofApp::eyespeak5(){
    string thisIsMyText = "Eye: No! Don't leave me alone! I am so loney.\n\nEye starts to cry.";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
}


void ofApp::eyechase(){
    ofPath path;
    float time = ofGetElapsedTimef();
       center.set(ofGetWidth()*ofNoise(time * 0.3),ofGetHeight()*ofNoise(time *0.6));
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

void ofApp::eyechase2(){
    ofPath path;
    float time = ofGetElapsedTimef();
       center.set(ofGetWidth()*ofNoise(time * 1),ofGetHeight()*ofNoise(time));
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

void ofApp::tears(){
    circle.draw();
    ofSetColor(255);
     for (auto circle:circles) {
       circle->draw();
     }
    auto circle = make_shared<ofxBox2dCircle>();
         circle->setPhysics(3.0, 0.5, 1.0);
         circle->setup(box2d.getWorld(), 400,500, 10);
         circles.push_back(circle);
}

void ofApp::end(){
    ofSetColor(0);
    string thisIsMyText = "The universe invites the light.\n\n Eye realize himself can becomes the light.";
    ofDrawBitmapString(thisIsMyText, 190, 700 );
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
