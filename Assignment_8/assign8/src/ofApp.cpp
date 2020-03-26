#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;

ofImage window;

ofSoundPlayer hyper;



//--------------------------------------------------------------
void ofApp::setup(){
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

    
    gui.setup();
    gui.add(Time.setup("Time/BG Color",2,0,24));
    gui.add(Temperature.setup("Temp/Tri Color",42.01,0,100));
    gui.add(WindSpeed.setup("Wind Speed/Volume",0,WindSpeed,10.0));
    gui.add(Pressure.setup("Pressure/Transparency",0,50,300));
    ofSetWindowShape(1600, 900);
    
    hyper.load("sound/music.mp3");
    hyper.setLoop(true);
    hyper.setMultiPlay(true);
    hyper.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    hyper.setVolume(WindSpeed/40);
}

std::ostringstream text;
float phase;

//--------------------------------------------------------------
void ofApp::draw(){
    
        std::string summary = root["currently"]["summary"].asString();
        int sample = root["currently"]["time"].asInt(); // get sample epoch
        float temp = root["currently"]["temperature"].asFloat();
        float pressure = root["currently"]["pressure"].asFloat();
        float windSpeed = root["currently"]["windSpeed"].asFloat();
        int sunriseTime = root["daily"]["data"][0]["sunriseTime"].asInt();
        int sunsetTime = root["daily"]["data"][0]["sunsetTime"].asInt();
        
        
    int year = sample/31556926+1970;
    int month = (sample%31556926)/2629743+1;
    int day = (sample%2629743)/86400+2;
    int hour = (sample%86400)/3600-4;
    
    if(hour<0){
        hour += 24;
        day -= 1;
    }
    int minute = (sample%3600)/60;
    
    int sunriseHour = (sunriseTime%86400)/3600-4;
   
    
    
    if(sunriseHour<0){sunriseHour += 24;}
    int sunriseMinute = (sunriseTime%3600)/60;
    
    int sunsetHour = (sunsetTime%86400)/3600-4;
    if(sunsetHour<0){
        sunsetHour += 24;
    }
    int sunsetMinute = (sunsetTime%3600)/60;
    
    
    
    //windspeed controls the sound volume
    hyper.setVolume(WindSpeed);
    
    ofColor LivingCoral = ofColor(252,118,106);
    ofColor PacificCoast = ofColor(Temperature*2.5,ofRandom(255),177,150);
    

        //time controls the color of the background
        ofSetBackgroundColor(Time*10, Time*9, Pressure);
    
        //drawtriangles, control the color with temperature
        int numTriangles = 200;
        int minOffset = 6;
        int maxOffset = 500;

        for (int t=0; t<numTriangles; ++t) {
            float offsetDistance = ofRandom(minOffset, maxOffset);

            ofVec2f Pos(ofGetWidth()/2,ofGetHeight()/2);

            ofVec2f p1(0, 10);
            ofVec2f p2(80, 0);
            ofVec2f p3(0, -10);

            float rotation = ofRandom(360);
            p1.rotate(rotation);
            p2.rotate(rotation);
            p3.rotate(rotation);

            ofVec2f triangleOffset(offsetDistance, 0.0);
            triangleOffset.rotate(rotation);

            p1 += Pos + triangleOffset;
            p2 += Pos + triangleOffset;
            p3 += Pos + triangleOffset;

            ofSetColor(PacificCoast);
            ofDrawTriangle(p1, p2, p3);
        }
    


    
    ofSetColor(0);
    gui.draw();
    
       if (ofGetFrameNum() == 1){
           text<<"Ningbo，China"<<endl;
           text<<" "<<endl;
           text<<"Wind Speed: " << windSpeed << endl;
           text<<"Date: " << month << "/" << day << "/" << year << endl;
           text<<"Time: " << hour << ":" << minute << endl;
           text<<"Sunrise Time: " << sunriseHour << ":" << sunriseMinute << endl;
           text<<"Sunset Time: " << sunsetHour << ":" << sunsetMinute << endl;
           text<<"Temperature: " << temp << endl;
           text<<"Pressure: "<<pressure<<"."<<endl;


       }
       ofDrawBitmapString(text.str(), 280, 33);
       
    
   
    

   
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
