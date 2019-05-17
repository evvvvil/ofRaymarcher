#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	gui.setup("GUI Broski");
	//gui.add(posOffset.set("Position Offset", ofVec3f(0, 0, 0), ofVec3f(-50, -50, -50), ofVec3f(50, 50, 50)));
	gui.add(fov.set("FOV broh", 70,0,100));
	bHide = false;
	timer = 0.0;
	raymarchShader.load("shader");
	if (raymarchShader.isLoaded()) {
		cout << "SHADER LOADED" << endl;
	}
	else {
		cout << "BOOOOO! SHADER DIDN'T LOAD" << endl;
	}
	renderSize = ofVec2f(ofGetWidth(), ofGetHeight());
	centerXY = renderSize / 2;
	plane.set(renderSize.x, renderSize.y);
	fbo1.allocate(renderSize.x, renderSize.y);
	camNearFarPlane = ofVec2f(0.01f, 100.f);
	cam.setAutoDistance(false);
	cam.setPosition(0, 0, 40);
	cam.setNearClip(camNearFarPlane.x);
	cam.setFarClip(camNearFarPlane.y);	
	raymarchShader.begin();
		raymarchShader.setUniform2f("resolution", renderSize);
		raymarchShader.setUniform2f("nearFarPlane", camNearFarPlane*2);
	raymarchShader.end();
}

//--------------------------------------------------------------
void ofApp::update() {
	timer = ofGetElapsedTimef();
	cam.setFov((float)fov);
}

//--------------------------------------------------------------
void ofApp::draw() {
	fbo1.begin();
		raymarchShader.begin();
			ofTranslate(centerXY);
			cam.begin();
				matView = cam.getModelViewMatrix();
				matProj = cam.getProjectionMatrix();
				matProj = matProj.getInverse();
				camPos = matView.getTranslation();
			cam.end();
			raymarchShader.setUniform1f("time", timer);
			raymarchShader.setUniformMatrix4f("matView", matView);
			raymarchShader.setUniformMatrix4f("matProj", matProj);
			raymarchShader.setUniform3f("camPos", camPos*2);
			//raymarchShader.setUniform3f("posOffset", (ofVec3f)posOffset);
			plane.draw();
		raymarchShader.end();
	fbo1.end();
	fbo1.draw(0, 0);
	cam.begin();
		ofEnableDepthTest();
		ofDrawBox(0, 0, 0, 10);
		ofDisableDepthTest();
	cam.end();
	if (!bHide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
