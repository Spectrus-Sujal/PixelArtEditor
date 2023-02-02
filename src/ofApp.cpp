#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	resizeGrid();
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetBackgroundColor(100);

	//Only run one of the following at a time

	//draw batman
	//drawPixels(batman, gridWidth, gridHeight);

	//toggle parts black/white
	drawPixels(grid, gridWidth, gridHeight);
}

void ofApp::resizeGrid()
{
	grid.resize(gridSize.y);
	for (auto col{ 0 }; col < grid.size(); ++col)
	{
		grid[col].resize(gridSize.x);

		for (auto row{ 0 }; row < gridSize.x; ++row)
		{
			grid[col][row] = false;
		}
	}
}

void ofApp::drawPixels(std::vector<std::vector<bool>>& pixels, int width, int height) const
{
	const int h = height / pixels.size();
	const int w = width / pixels[0].size();
	for (auto row{ 0 }; row < pixels[0].size(); ++row)
	{
		for (auto col{ 0 }; col < pixels.size(); ++col)
		{
			if (pixels[col][row])
			{
				ofSetColor(0);
				ofDrawRectangle(row * w, col * h, w, h);
			}
			else
			{
				ofSetColor(255);
				ofDrawRectangle(row * w, col * h, w - 1, h - 1);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if ((key == 'd' || key == 'D') && gridWidth < ofGetWidth())
	{
		gridWidth += gridWidth / gridSize.x;
		gridSize.x++;
		resizeGrid();
	}

	if ((key == 'a' || key == 'A') && gridSize.x > 2)
	{
		gridWidth -= gridWidth / gridSize.x;
		gridSize.x--;
		resizeGrid();
	}

	if ((key == 's' || key == 'S') && gridHeight < ofGetHeight())
	{
		gridHeight += gridHeight / gridSize.y;
		gridSize.y++;
		resizeGrid();
	}

	if ((key == 'w' || key == 'W') && gridSize.y > 2)
	{
		gridHeight -= gridHeight / gridSize.y;
		gridSize.y--;
		resizeGrid();
	}

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
void ofApp::mousePressed(int x, int y, int button)
{
	bool breaker{ false };
	for (auto row{ 0 }; row < gridSize.x; ++row)
	{
		for (auto col{ 0 }; col < gridSize.y; ++col)
		{
			if (x < ((row + 1) * (gridWidth / gridSize.x)))
			{
				if (y < ((col + 1) * (gridHeight / gridSize.y)))
				{
					grid[col][row] = !grid[col][row];
					breaker = true;
				}
			}
			else
			{
				break;
			}

			if (breaker)
			{
				break;
			}
		}
		if (breaker)
		{
			break;
		}
	}
}