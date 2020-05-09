#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;
ofSoundPlayer hyper;

//music credit to http://musmus.main.jp/bgm.html
//--------------------------------------------------------------
void ofApp::setup(){
    myfont.load("fonts/RobotoMono-Regular.ttf", 20);
    ofSetFrameRate(10);
    
    std::string url = "https://api.darksky.net/forecast/ed205d304f447a76411815985890bd69/29.8683, 121.5440";

    // Now parse the JSON
    bool parsingSuccessful = root.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    //setup the basic circle info
    ofSetLineWidth(3);
    ofSetCircleResolution(128);
    
    gui.setup();
    gui.add(Time.setup("Time",2,0,24));
    gui.add(WindSpeed.setup("Wind Speed",0,0,10.0));
    gui.add(Pressure.setup("Pressure",0,50,3000));
    gui.add(uiAmount.set("Visibility", 0, 0, 10));
    gui.add(uiPower.set("Humidity", ofVec3f(0), ofVec3f(0), ofVec3f(3.0)));
    gui.add(uiRadius.set("Temperature", 0, 0, 80.0));
    gui.add(uiPosition.set("Latitude,Longitude",
                            ofVec2f(0),
                            ofVec2f(-ofGetWidth(), -ofGetHeight()),
                            ofVec2f(ofGetWidth(), ofGetHeight())));
    
    hyper.load("sound/music.mp3");
    hyper.setLoop(true);
    hyper.setMultiPlay(true);
    hyper.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){
     hyper.setSpeed(WindSpeed/8);
}

std::ostringstream text;

//--------------------------------------------------------------
void ofApp::draw(){
    
        std::string summary = root["currently"]["summary"].asString();
        int sample = root["currently"]["time"].asInt(); // get sample epoch
        float temp = root["currently"]["temperature"].asFloat();
        float latitude = root["latitude"].asFloat();
        float longitude = root["longitude"].asFloat();
        float humidity = root["currently"]["humidity"].asFloat();
        float visibility = root["currently"]["visibility"].asFloat();
        float pressure = root["currently"]["pressure"].asFloat();
        float windSpeed = root["currently"]["windSpeed"].asFloat();

    int year = sample/31556926+1970;
    int month = (sample%31556926)/2629743+1;
    int day = (sample%2629743)/86400+2;
    int hour = (sample%86400)/3600-4;
    
    if(hour<0){
        hour += 24;
        day -= 1;
    }
    int minute = (sample%3600)/60;
   

    //time controls the color of the background
    ofSetBackgroundColor(Time*10, Time*9, Pressure/10);
    
    ofPushMatrix();
    cam.begin();
    ofTranslate(uiPosition->x, uiPosition->y);
    float radius = uiRadius;
    for (int i = 0; i < uiAmount*10; i++){
      float noisex = ofNoise((ofGetElapsedTimef() + i) * uiPower->x);
      float noisey = ofNoise((ofGetElapsedTimef() + i) * uiPower->y);
      float noisez = ofNoise((ofGetElapsedTimef() + i) * uiPower->z);
      
      float x = ofGetWidth() / 2 * noisex;
      float y = ofGetHeight() / 2 * noisey;
      float z = ofGetHeight() / 2 * noisez;
      
      ofNoFill();
      ofSetColor(255);
      ofDrawCircle(x, y, z, radius);
      radius += i;
    }
    cam.end();
    ofPopMatrix();

    
    ofSetColor(0);
    gui.draw();
    
       if (ofGetFrameNum() == 1){
           text<<"City Info"<<endl;
           text<<" "<<endl;
           text<<"Latitude,Longitude:" << latitude<< "," << longitude << endl;
           text<<"Wind Speed: " << windSpeed << endl;
        //   text<<"Date: " << month << "/" << day << "/" << year << endl;
           text<<"Humidity: " << humidity << endl;
           text<<"Visibility: " << visibility << endl;
           text<<"Pressure: "<<pressure<<"."<<endl;

       }
 
       myfont.drawString(text.str(), 20,500);

   
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
