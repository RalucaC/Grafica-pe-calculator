#include "Opponent.h"
#include "Framework\Visual2D.h"
#include "Framework\DrawingWindow.h"

//intitializarea celor 2 contexte vizuale
Visual2D * Opponent::bottom = new Visual2D(
		0,
		0,
		DrawingWindow::width,
		DrawingWindow::height,
		0,
		100,
		DrawingWindow::width,
		DrawingWindow::height);

Visual2D * Opponent::top = new Visual2D(
		0,
		0,
		DrawingWindow::width,
		DrawingWindow::height,
		0,
		0,
		DrawingWindow::width, 
		100);

Opponent::Opponent(void)
:center()

{
	
}

Point2D Opponent::getCenter(){
	return *center;
}

Opponent::~Opponent(void)
{
}
