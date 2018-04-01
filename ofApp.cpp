#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor line_color;
	int span = 50;
	float threshold = 0.35;
	float param_x = ofRandom(1000);
	float param_y = ofRandom(1000);

	for (int x = 0; x < ofGetWidth(); x += span) {

		float noise_value = ofNoise(param_x, x * 0.005, ofGetFrameNum() * 0.005);
		if (noise_value > threshold) {

			line_color.setHsb(ofMap(x, 0, ofGetWidth(), 0, 255), 239, 239);
			ofSetColor(line_color, ofMap(noise_value, threshold, 1.0, 0, 255));

			ofDrawLine(ofPoint(x, 0), ofPoint(x, ofGetHeight()));
		}
	}

	for (int y = 0; y < ofGetHeight(); y += span) {

		float noise_value = ofNoise(param_y, y * 0.005, ofGetFrameNum() * 0.005);
		if (noise_value > threshold) {

			line_color.setHsb(ofMap(y, 0, ofGetHeight(), 255, 0), 239, 239);
			ofSetColor(line_color, ofMap(noise_value, threshold, 1.0, 0, 255));

			ofDrawLine(ofPoint(0, y), ofPoint(ofGetWidth(), y));
		}
	}

	for (int x = 0; x < ofGetWidth(); x += 50) {

		for (int y = 0; y < ofGetHeight(); y += 50) {

			float noise_value_1 = ofNoise(param_x, x * 0.005, ofGetFrameNum() * 0.005);
			float noise_value_2 = ofNoise(param_y, y * 0.005, ofGetFrameNum() * 0.005);
			if (noise_value_1 > threshold && noise_value_2 > threshold) {

				ofColor color_1, color_2;
				color_1.setHsb(ofMap(x, 0, ofGetWidth(), 0, 255), 239, 239);
				color_2.setHsb(ofMap(y, 0, ofGetHeight(), 255, 0), 239, 239);
				ofColor blend_color = color_1 + color_2;

				ofSetColor(blend_color, ofMap(noise_value_1 > noise_value_2 ? noise_value_1 : noise_value_2, threshold, 1.0, 0, 255));
				ofDrawCircle(x, y, 5);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}