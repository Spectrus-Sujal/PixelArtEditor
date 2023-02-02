#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

	struct Point {
		double x{ 0 };
		double y{ 0 };
	};

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);

	void resizeGrid();
	void drawPixels(std::vector<std::vector<bool>>& pixels, int width, int height) const;

	void pixelClicker();

	int gridWidth{ 1000 };
	int gridHeight{ 1000 };
	Point gridSize{ 20, 20 };
	std::vector<std::vector<bool>> grid;

	std::vector<std::vector<bool>> batman
	{
		{false, false, false, false, false, false, false, false, false},
		{false, false, true, false, false, false, true, false, false},
		{false, false, true, true, true, true, true, false, false},
		{false, false, true, false, true, false, true, false, false},
		{false, false, true, true, true, true, true, false, false},
		{false, false, true, false, true, false, true, false, false},
		{false, false, true, false, false, false, true, false, false},
		{false, false, true, true, true, true, true, false, false},
		{false, false, false, false, false, false, false, false, false}
	};


};