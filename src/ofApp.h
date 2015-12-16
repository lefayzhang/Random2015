#pragma once

#include "ofMain.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void updatePart1();
        void updatePart2();
        void drawPart1();
        void drawPart2();
    
    
		
    //---------------made a geometry/change circle res 1
    
    ofImage myimage;
    int myCircle;
    ofColor col;
   
    
    int circleRes1;
    ofPoint circlePosition1;
    float radius1;
    bool selected1;
    ofSoundPlayer mySound1;
    ofColor col1;
    
    //---------------made a geometry/change circle res 2
    int circleRes2;
    int myCircle2;
    ofPoint circlePosition2;
    float radius2;
    bool selected2;
    ofSoundPlayer mySound2;
    ofColor col2;

    
    //---------------made a geometry/change circle res 3
    int circleRes3;
    ofPoint circlePosition3;
    float radius3;
    bool selected3;
    ofSoundPlayer mySound3;
    ofColor col3;


    //---------------made a geometry/change circle res 4
    int circleRes4;
    ofPoint circlePosition4;
    float radius4;
    bool selected4;
    ofSoundPlayer mySound4;
    ofColor col4;

    
    //---------------made a geometry/change circle res 5
    int circleRes5;
    ofPoint circlePosition5;
    float radius5;
    bool selected5;
    ofSoundPlayer mySound5;
    ofColor col5;
    //---------------made a geometry/change circle res 6
    int circleRes6;
    ofPoint circlePosition6;
    bool selected6;
    float radius6;
    ofSoundPlayer mySound6;
    ofColor col6;


    
    
    vector<int>choosenshape;
    vector<ofColor>choosencolor;
    float space;
    bool changepart;
    
    int part;
    
    ofEasyCam cam;
    ofSoundPlayer bgm;
    
    ofFbo fbo;
    
    
};
