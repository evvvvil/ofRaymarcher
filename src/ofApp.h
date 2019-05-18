#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//ofParameter<bool> InvertView;
	//ofParameter<ofVec3f> posOffset;	
	ofParameter<float> fov;
	ofParameter<bool> showText;
	bool bHide;
	ofxPanel gui;
	ofShader raymarchShader;
	ofFbo raymarchFbo;
	ofFbo geometryFbo;
	ofBoxPrimitive box;
	ofPlanePrimitive plane;
	ofVec2f renderSize;
	ofVec2f centerXY;
	float timer;
	ofEasyCam cam;
	ofMatrix4x4 matView;
	ofMatrix4x4 matProj;
	ofVec2f camNearFarPlane;
	ofVec3f camPos;
};