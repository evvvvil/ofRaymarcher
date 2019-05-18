#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	gui.setup("GUI Broski");
	//gui.add(posOffset.set("Position Offset", ofVec3f(0, 0, 0), ofVec3f(-50, -50, -50), ofVec3f(50, 50, 50)));
	gui.add(fov.set("FOV broh", 70,0,100));
	gui.add(showText.set("show layer 1", true));
	bHide = false;
	timer = 0.0;
	raymarchShader.load("raymarchShader");
	//cout << "SHADER LOADED" << endl;	
	renderSize = ofVec2f(ofGetWidth(), ofGetHeight());
	centerXY = renderSize / 2;
	plane.set(renderSize.x, renderSize.y);
	ofFbo::Settings settings;
	settings.width = renderSize.x;
	settings.height = renderSize.y;
	settings.internalformat = GL_RGB; // or GL_RGBA?
	settings.useDepth = true;
	settings.depthStencilAsTexture = true;
	raymarchFbo.allocate(settings);
	geometryFbo.allocate(renderSize.x, renderSize.y);
	camNearFarPlane = ofVec2f(0.01f, 100.f);
	cam.setAutoDistance(false);
	cam.setPosition(0, 0, 40);
	cam.setNearClip(camNearFarPlane.x);
	cam.setFarClip(camNearFarPlane.y);	
	raymarchShader.begin();
		raymarchShader.setUniform2f("resolution", renderSize);
		raymarchShader.setUniform2f("nearFarPlane", camNearFarPlane*2);
	raymarchShader.end();
	box.set(10);
}

//--------------------------------------------------------------
void ofApp::update() {
	timer = ofGetElapsedTimef();
	cam.setFov((float)fov);
	matView = cam.getModelViewMatrix();
	matProj = cam.getProjectionMatrix();
	matProj = matProj.getInverse();
	raymarchFbo.begin();
		raymarchShader.begin();
			ofTranslate(centerXY);			
			camPos = matView.getTranslation();
			raymarchShader.setUniform1f("time", timer);
			raymarchShader.setUniformMatrix4f("matView", matView);
			raymarchShader.setUniformMatrix4f("matProj", matProj);
			raymarchShader.setUniform3f("camPos", camPos * 2);
			//raymarchShader.setUniform3f("posOffset", (ofVec3f)posOffset);
			plane.draw();
		raymarchShader.end();
	raymarchFbo.end();
	geometryFbo.begin();	
		ofClear(0, 0, 0, 255);
		cam.begin();
			ofEnableDepthTest();
			ofTranslate(0, 0, 5);
			box.draw();	
			ofDisableDepthTest();
		cam.end();
	geometryFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {
	raymarchFbo.draw(0, 0);
	if((bool)showText) geometryFbo.draw(0, 0);
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
