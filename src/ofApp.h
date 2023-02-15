#pragma once

#include "ofMain.h"
#include <fstream>
#include <iostream>

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

		bool operator==(Pixel temp)
		{
			return r == temp.r && g == temp.g && b == temp.b;
		}
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

	void saveColor();
	void saveBW();
	void savePNG();
	void loadCanvas();

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

	std::string SaveDataPath;

};