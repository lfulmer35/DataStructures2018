//Lucas Fulmer
#include "grid.h"

Grid::Grid()
{
	rows = 10;
	cols = 10;
	playerVec;//first grid
	torpedoVec;//second grid
}

Grid::Grid(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
}
void Grid::setVec(Grid _userGrid)
{
	vector< vector<char> > tempVec(rows, vector<char>(cols));
	for (int i = 0; i < cols; i++)
		for (int h = 0; h < rows; h++)
			tempVec[h][i] = 'O';
	playerVec = tempVec;
	torpedoVec = tempVec;
}
void Grid::displayGrid(Grid _grid)
{	//displays the grids
	cout << "********Target Grid*********" << endl;
	cout << "A  B  C  D  E  F  G  H  I  J" << endl;
	for (int i = 0; i < _grid.cols; i++)
	{
		for (int x = 0; x < _grid.rows; x++)
			cout << _grid.torpedoVec[i][x] << "  ";
		cout << i + 1;
		cout << endl;
	}
	cout << endl;
	cout << "*********User Grid**********" << endl;
	cout << "A  B  C  D  E  F  G  H  I  J" << endl;
	for (int i = 0; i < _grid.cols; i++)
	{
		for (int x = 0; x < _grid.rows; x++)
			cout << _grid.playerVec[i][x] << "  ";
		cout << i + 1;
		cout << endl;
	}
	cout << endl;
}
void Grid::placeShip(Grid& _userGrid, WaterVehicle& _ship)
{
	int yIndex, xIndex, stopY, stopX;
	yIndex = _ship.startingY - 1;
	xIndex = (_ship.startingX - 5) % 10;
	stopY = yIndex + _ship.shipLength;
	stopX = xIndex + _ship.shipLength;
	if (_ship.orientation == 'H')
		for (int x = xIndex; x < stopX; x++)
			_userGrid.playerVec[yIndex][x] = _ship.shipSymbol;
	else
		for (int y = yIndex; y < stopY; y++)
			_userGrid.playerVec[y][xIndex] = _ship.shipSymbol;
}