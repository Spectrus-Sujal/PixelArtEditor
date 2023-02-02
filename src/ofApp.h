#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

	struct Point {
		double x{ 0 };
		double y{ 0 };
	};

	struct Pixel
	{
		int r;
		int g;
		int b;
	};

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);


	void resizeGrid();
	void drawPixels(std::vector<std::vector<Pixel>>& pixels, int width, int height) const;

	void pixelClicker();

	int gridWidth{ 1000 };
	int gridHeight{ 1000 };
	Point gridSize{ 20, 20 };
	std::vector<std::vector<Pixel>> grid;

	Pixel white{ 255, 255, 255 };
	Pixel black{ 0, 0, 0 };
	Pixel red{ 255, 0, 0 };
	Pixel green{ 0, 255, 0 };
	Pixel blue{ 0, 0, 255 };

	Pixel colorSelected;

};