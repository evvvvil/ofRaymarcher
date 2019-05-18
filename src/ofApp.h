#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDeferredShading.h"

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

	ofxDeferredProcessing deferred;
	ofPtr<ofxDeferred::SsaoPass> ssao;
	//ofPtr<ofxDeferred::PointLightPass> points;
	//ofPtr<ofxDeferred::ShadowLightPass> shadow;
	//ofPtr<ofxDeferred::BloomPass> bloom;
	ofParameter<float> fov;
	bool bHide;
	ofxPanel gui;
	ofShader raymarchShader;
	ofFbo fbo1;
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