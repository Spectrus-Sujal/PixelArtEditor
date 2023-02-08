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
	drawPixels(grid, gridWidth, gridHeight);
}

void ofApp::resizeGrid()
{
	grid.resize(gridSize.y);

	for (auto col{ 0 }; col < grid.size(); ++col)
	{
		grid[col].resize(gridSize.x);

		for (auto row{ 0 }; row < grid[col].size(); ++row)
		{
			Pixel temp{ 255, 255, 255 };
			grid[col][row] = temp;
		}
	}
}

void ofApp::drawPixels(std::vector<std::vector<Pixel>>& pixels, int width, int height) const
{
	const int h = height / pixels.size();
	const int w = width / pixels[0].size();

	for (auto col{ 0 }; col < pixels.size(); ++col)
	{
		for (auto row{ 0 }; row < pixels[col].size(); ++row)
		{
			ofSetColor(pixels[col][row].r, pixels[col][row].g, pixels[col][row].b);
			ofDrawRectangle(row * w, col * h, w, h);
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

	switch (key)
	{
		case '1':
			colorSelected = white;
		break;

		case '3':
			colorSelected = red;
		break;

		case '4':
			colorSelected = green;
		break;

		case '5':
			colorSelected = blue;
		break;

		case '2':
		default:
			colorSelected = black;
		break;

	}

	if(key == 'p' || key == 'P')
	{
		saveBW();
	}

	if(key == 'o' || key == 'O')
	{
		saveColor();
	}

	if(key == 'l' || key == 'L')
	{
		loadCanvas();
	}

}

void ofApp::saveBW()
{
	// Save Art
	std::ofstream outputFile{ "SaveData.ppm" };
	outputFile.clear();
	outputFile << "P1\n";
	outputFile << gridSize.x << "   " << gridSize.y << "\n";

	for(auto i {0}; i < gridSize.y; ++i)
	{
		for (auto j{ 0 }; j < gridSize.x; ++j)
		{
			if(grid[i][j] == Pixel {255, 255, 255})
			{
				outputFile << 0 << " ";
			}
			else
			{
				outputFile << 1 << " ";
			}
			
		}
		outputFile << "\n";
	}
	outputFile.close();
}


void ofApp::saveColor() const
{
	// Save Art
	std::ofstream outputFile{ "SaveData.ppm" };

	outputFile.clear();

	outputFile << "P3\n";

	outputFile << gridSize.x << "   " << gridSize.y << "\n" << 255 << "\n";

	for(auto i {0}; i < gridSize.y; ++i)
	{
		for (auto j{ 0 }; j < gridSize.x; ++j)
		{
			outputFile << grid[i][j].r << " " << grid[i][j].g << " " << grid[i][j].b << "\n";
		}
	}

	outputFile.close();
}

void ofApp::loadCanvas()
{
	std::ifstream inputFile{"SaveData.ppm"};

	string mode;
	int sizeX;
	int sizeY;
	int maxSize;

	inputFile >> mode >> sizeX >> sizeY >> maxSize;

	gridWidth -= (gridWidth / gridSize.x) * (gridSize.x - sizeX);
	gridHeight -= (gridHeight / gridSize.y) * (gridSize.y - sizeY);
	gridSize.x = sizeX;
	gridSize.y = sizeY;
		
	resizeGrid();

	for(auto i {0}; i < gridSize.y; ++i)
	{
		for (auto j{ 0 }; j < gridSize.x; ++j)
		{
			if(mode == "P1")
			{
				int temp;
				inputFile >> temp;
				if(temp == 1)
				{
					grid[i][j] = Pixel {0, 0, 0};
				}
				else
				{
					grid[i][j] = Pixel {255, 255, 255};
				}
			}
			else
			{
				int r;
				int g;
				int b;
				inputFile >> r >> g >> b;
				grid[i][j] = Pixel{r, g, b};
			}
		}
	}
	inputFile.close();
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (auto row{ 0 }; row < gridSize.x; ++row)
	{
		for (auto col{ 0 }; col < gridSize.y; ++col)
		{
			if (x < ((row + 1) * (gridWidth / gridSize.x)))
			{
				if (y < ((col + 1) * (gridHeight / gridSize.y)))
				{
					grid[col][row] = colorSelected;
					return;
				}
			}
			else
			{
				break;
			}
		}
	}
}