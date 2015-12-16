#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundAuto(false);
    ofBackground(94,74,130);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(0);
    fbo.end();
    
    bgm.loadSound("bgm.wav");
    bgm.setVolume(0.75);
    bgm.play();

  

   //---------------------------sth has to set before draw circle
    mySound1.loadSound("D5.MP3");
    circleRes1=3;
    col1.set(191,152,232);

    radius1=50;
    selected1=false;
    
    mySound2.loadSound("F5.MP3");
    circleRes2=4;
    col2.set(218,193,255);
    radius2=50;
    selected2=false;
    
    mySound3.loadSound("D6.MP3");
    circleRes3=5;
    col3.set(228,211,236);
    radius3=50;
    selected3=false;
    
    mySound4.loadSound("F6.MP3");
    circleRes4=6;
    col4.set(193,209,250);
    radius4=50;
    selected4=false;
    
    mySound5.loadSound("D7.MP3");
    circleRes5=7;
    col5.set(180,181,232,200);
    radius5=50;
    selected5=false;
    
    mySound6.loadSound("F7.MP3");
    circleRes6=35;
    col6.set(175, 209, 240,200);
    radius6=50;
    selected6=false;

    
    part=1;
    cam.setDistance(500);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    cam.setDistance(ofMap(sin(ofGetElapsedTimef()),-1, 1, 500, 2000));
    
    if(bgm.getPosition()>0.99){
        bgm.play();
    }

    
    
    if(part==1){
        updatePart1();
    }
    else{
        updatePart2();
    }


}

void ofApp::updatePart1(){
    circlePosition1.x=ofGetWidth()/7;
    circlePosition1.y=ofGetHeight()/2;
    
    circlePosition2.x=ofGetWidth()/7*2;
    circlePosition2.y=ofGetHeight()/2;
    
    circlePosition3.x=ofGetWidth()/7*3;
    circlePosition3.y=ofGetHeight()/2;
    
    circlePosition4.x=ofGetWidth()/7*4;
    circlePosition4.y=ofGetHeight()/2;
    
    circlePosition5.x=ofGetWidth()/7*5;
    circlePosition5.y=ofGetHeight()/2;
    
    circlePosition6.x=ofGetWidth()/7*6;
    circlePosition6.y=ofGetHeight()/2;
    
}
void ofApp::updatePart2(){
    
}


//--------------------------------------------------------------

void ofApp::draw(){
    fbo.begin();
    ofFill();
    ofSetColor(94,74,130,5);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    
    ofSetColor(255);
    if(part==1){
        drawPart1();
    }
    else{
        drawPart2();
    }
    fbo.end();
    
    ofSetColor(255);
    fbo.draw(0, 0);
}

void ofApp::drawPart1(){

   //--------------------------mouse circle
    ofNoFill();
    col.set(255 , 233, 163);
    ofSetColor(col);
    ofDrawSphere(mouseX, mouseY,4);
    
    
 //------------------------------------------------------------------------// no1 circle
    if (selected1) {

        ofFill();
    }
    else{
        ofNoFill();
    }

    ofSetColor(col1);
    //---------------------------connect with(what i've set in) the setup;
    ofSetCircleResolution(circleRes1);
    //------------------------and draw circle
    ofCircle(circlePosition1.x, circlePosition1.y, radius1);
    

//    
//    //------------------------------------------------------------------------//no2 circle
    if (selected2) {
//
//        ofFill();
//        ofSetColor(209,206,255,200);
//        ofSetCircleResolution(myCircle);
//        ofCircle(ofGetWidth()/2, ofGetHeight()/5*4, radius);
//        
//
//        
        ofFill();
    }
    else{
        ofNoFill();
    }

    ofSetColor(col2);
        ofSetCircleResolution(circleRes2);
        ofCircle(circlePosition2.x, circlePosition2.y,radius2);

    
//   //--------------------------------------------------------------------------no3 circle
    if (selected3) {
        
//        ofFill();
//        ofSetColor(171,152,232,200);
//        ofSetCircleResolution(myCircle);
//        ofCircle(ofGetWidth()/2, ofGetHeight()/5*4, radius);
        
        ofFill();
    }
    else{
        ofNoFill();
    }
    ofSetColor(col3);
    ofSetCircleResolution(circleRes3);
    ofCircle(circlePosition3.x, circlePosition3.y,radius3);
    

//    //-------------------------------------------------------------------------no4 circle
    if (selected4) {
//
//        ofFill();
//        ofSetColor(218,193,255,200);
//        ofSetCircleResolution(myCircle);
//        ofCircle(ofGetWidth()/2, ofGetHeight()/5*4, radius);
//        
        ofFill();
    }
    else{
        ofNoFill();
    }
    ofSetColor(col4);
    ofSetCircleResolution(circleRes4);
    ofCircle(circlePosition4.x, circlePosition4.y,radius4);
    
//-------------------------------------------------------------------------no5 circle
    if (selected5) {
//
//        ofFill();
//        ofSetColor(193, 209, 255,200);
//        ofSetCircleResolution(myCircle);
//        ofCircle(ofGetWidth()/2, ofGetHeight()/5*4, radius);
//        
        ofFill();
    }
    else{
        ofNoFill();
    }
    ofSetColor(col5);
    ofSetCircleResolution(circleRes5);
    ofCircle(circlePosition5.x, circlePosition5.y,radius5);
    //------------------------------------------------------------------------选中的图形；
//    ofNoFill();
//
//    for(int i=0;i<choosenshape.size();i++){
//        float x =space+i*(2*radius1+space);
//        float y= ofGetHeight()/5*4;
//        //  circleRes =choosenshape[i];
//        ofSetCircleResolution(choosenshape[i]);
//        ofSetColor(choosencolor[i]);
//        ofCircle(x, y, radius1);
//    }
    //-------------------------------------------------------------------------no6 circle
    if (selected6) {
        
        ofFill();
    }
    else{
        ofNoFill();
    }
    ofSetColor(col6);
    ofSetCircleResolution(circleRes6);
    ofCircle(circlePosition6.x, circlePosition6.y,radius1);
}


void ofApp::drawPart2(){
    cam.begin();
    
    float radius0=ofMap(mouseX, 0, ofGetWidth(), 20, 30);
    float distance0= ofMap(mouseX, 0, ofGetWidth(), 50, 10);
    float apha= ofMap(mouseX, 0, ofGetWidth(), 60, 200);
    
    
    ofRotateX(ofGetElapsedTimef()*10);
    ofRotateY(ofGetElapsedTimef()*10);
    ofRotateZ(ofGetElapsedTimef()*5);
    
    ofFill();
    for(int i=0;i<choosenshape.size();i++){
        
        if(i==0){
            float x = 0;//ofGetWidth()/2;
            float y= 0;//ofGetHeight()/2;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            for (float angle = 0; angle < 360; angle+=360){
                ofPushMatrix();
                ofRotateZ(angle+ofGetElapsedTimef()*40);
                ofRotateX(angle+ofGetElapsedTimef()*-20);
                ofRotateY(angle+ofGetElapsedTimef()*-20);
                ofCircle(x, y, radius0);
                ofDrawSphere(0, 0, 10);
                ofPopMatrix();
            }
        }
        
        if(i==1){
            
            float x =radius0+distance0;
            float y= radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            
            for (float angle = 0; angle < 360; angle+=10){
                ofPushMatrix();
                
                ofRotateY(ofGetElapsedTimef()*80);
                ofRotateZ(angle+ofGetElapsedTimef()*80);
                
              //  cout<<vel<<vel+angle+ofGetElapsedTimef()*80<<endl;
                ofNoFill();
                ofCircle(x,y, radius0-10);
                ofFill();
                ofDrawSphere(x, y, 4);
                ofPopMatrix();
            }
        }
        
        if(i==2){
            float x =radius0*4+distance0;
            float y= 0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            // ofSeedRandom(6);
            for (float angle = 0; angle < 360; angle+=6){
                ofPushMatrix();
                
                ofRotateY(angle + ofGetElapsedTimef()* -100);
                ofTranslate(x, y);
                ofNoFill();
                ofCircle(0,0, radius0/2);
                ofFill();
                ofDrawSphere(0, 0, 3);
                
                ofPopMatrix();
            }
        }
        
        if(i==3){
            ofFill();
            float x =radius0*4+distance0;
            float y= radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            
            for (float angle = 0; angle < 360; angle+=6){
                ofPushMatrix();
                
                ofRotateY(ofGetElapsedTimef()*80);
                ofRotateZ(angle+ofGetElapsedTimef()*80);
                ofCircle(x,y, radius0-20);
                ofPopMatrix();
            }
        }
        if(i==4){
            ofFill();
            float x = radius0*5+distance0;
            float y = radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            
            for (float angle = 0; angle < 360; angle+=10){
                ofPushMatrix();
                
                ofRotateY(ofGetElapsedTimef()*80);
                ofRotateZ(angle+ofGetElapsedTimef()*80);
                ofCircle(x,y, radius0/4);
                ofPopMatrix();
            }
        }
        
        if(i==5){
            ofFill();
            float x = radius0*5+distance0;
            float y = radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            ofSeedRandom(10);
            for (float angle = 0; angle < 360; angle+=1){
                ofPushMatrix();
                ofRotateY(angle*5+ofGetElapsedTimef()*80*ofRandom(3));
                ofRotateZ(angle*3+ofGetElapsedTimef()*80);
                ofCircle(x,y, radius0/15);
                ofPopMatrix();
            }
        }
        
        if(i==6){
            ofFill();
            float x = radius0*7+distance0;
            float y = radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            
            for (float angle = 0; angle < 360; angle+=10){
                ofPushMatrix();
                
                ofRotateY(ofGetElapsedTimef()*80);
                ofRotateZ(angle+ofGetElapsedTimef()*80);
                ofCircle(x,y, radius0/5);
                ofPopMatrix();
            }
        }
        
        ofFill();
        if(i==7){
            float x =radius0*7+distance0*6;
            float y= 0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i]);
            ofSeedRandom(6);
            for (float angle = 0; angle < 360; angle+=10){
                ofPushMatrix();
                //ofRotateY(angle + ofGetElapsedTimef()*80);
                
                ofRotateY(angle + ofGetElapsedTimef()* -100*ofRandom(3));
                //ofTranslate(x, y);
                //ofRotateZ(angle + ofGetElapsedTimef()*40);
                ofFill();
                ofCircle(x,y, radius0/2);
                ofDrawSphere(x,y, 4);
                
                ofPopMatrix();
            }
        }
        
        
        ofFill();
        if(i==8){
            float x =radius0*5+distance0*3+30;
            float y= radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i],apha*2);
            ofSeedRandom(12);
            for (float angle = 0; angle < 360; angle+=20){
                ofPushMatrix();
                
                ofRotateZ(angle+ofGetElapsedTimef()*80);
                ofTranslate(x, y);
                ofRotateY(ofGetElapsedTimef()*80);
                ofCircle(0,0, radius0/3);
                ofPopMatrix();
            }
        }
        ofNoFill();
        if(i==9){
            float x =radius0*5+distance0*6;
            float y= radius0;
            ofSetCircleResolution(choosenshape[i]);
            ofSetColor(choosencolor[i],apha);
            ofSeedRandom(12);
            for (float angle = 0; angle < 360; angle+=6){
                ofPushMatrix();
                ofRotateZ(angle + ofGetElapsedTimef()*80);
                ofTranslate(x, y);
                ofRotateY(angle + ofGetElapsedTimef()*20*ofRandom(20));
                
                ofCircle(0,0, radius0/2-2);
                
                ofDrawSphere(2);
                ofPopMatrix();
            }
        }
        
    }
    cam.end();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==' ') {
        if (part == 2){
        part=1;
        choosenshape.clear();
        choosencolor.clear();
       // ofBackground(255);
        }
        else{
            part=2;
           // ofBackground(0);
        }
    }
    
 //   if (key=='3') {
  //        cam.reset();
 //   }
   
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
   
    if(part==1){
    
    //-------------------------------创建点坐标----------------------------------------- 1
    ofPoint mousePoint(x,y);
    //--------固定公式。距离等于鼠标点到图形中心点间的距离）；
    float distance1 = mousePoint.distance(circlePosition1);
    if( distance1< radius1){
        cout<<"1choosen"<<endl;
        selected1=true;
        mySound1.play ();
        
        choosenshape.push_back(circleRes1);
        choosencolor.push_back(col1);
        
//        myCircle=circleRes;
        //-------==means 等值。＝
//----------------------------------下面这一段是点一下再点一下／出现／消失；
//        if(selected==true){
//            selected=false;
//        }
//        else{
//            selected=true;
//        }
//--------------------------------- 上面这一段是点一下出现消失；
    }
   //--------------------------------------------------------------------------------- 2
    float distance2 = mousePoint.distance(circlePosition2);
    if(distance2 < radius2){
        cout<<"2choosen"<<endl;
        selected2=true;
        mySound2.play ();
//        myCircle=circleRes1;
        choosenshape.push_back(circleRes2);
        choosencolor.push_back(col2);
    }
    //--------------------------------------------------------------------------------- 3

    float distance3= mousePoint.distance(circlePosition3);
    if( distance3 < radius3){
        cout<<"3choosen"<<endl;
        selected3=true;
        mySound3.play ();
      //  myCircle=circleRes2;
        choosenshape.push_back(circleRes3);
        choosencolor.push_back(col3);
    }
    //--------------------------------------------------------------------------------- 4

    float distance4 = mousePoint.distance(circlePosition4);
    if( distance4 < radius4){
        cout<<"4choosen"<<endl;
        selected4=true;
        mySound4.play ();
      //  myCircle=circleRes3;
        choosenshape.push_back(circleRes4);
        choosencolor.push_back(col4);

    }
    //--------------------------------------------------------------------------------- 5

    float distance5 = mousePoint.distance(circlePosition5);
    if( distance5 < radius5){
        cout<<"5choosen"<<endl;
        selected5=true;
        mySound5.play ();
        //myCircle=circleRes4;
        choosenshape.push_back(circleRes5);
        choosencolor.push_back(col5);

    }
        //--------------------------------------------------------------------------------- 6
        
        float distance6 = mousePoint.distance(circlePosition6);
        if( distance6 < radius6){
       
            selected6=true;
            mySound6.play ();
            choosenshape.push_back(circleRes6);
            choosencolor.push_back(col6);
            
        }

    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
   
    ofPoint mousePoint(x,y);
    float distance1 = mousePoint.distance(circlePosition1);

        selected1=false;
    
    float distance2 = mousePoint.distance(circlePosition2);
        selected2=false;
    
    float distance3 = mousePoint.distance(circlePosition3);
           selected3=false;
    
    float distance4 = mousePoint.distance(circlePosition4);
        selected4=false;
    
    float distance5 = mousePoint.distance(circlePosition5);
        selected5=false;
    float distance6 = mousePoint.distance(circlePosition6);
    selected6=false;

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
