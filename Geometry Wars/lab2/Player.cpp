#include "Player.h"
#include "Opponent2Squares.h"
#include "OpponentDiamond.h"
#include "OpponentPlane.h"
#include "OpponentStar.h"
#include "OpponentTetris.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework\Visual2D.h"


Player::Player()
:angle(0)
,tx(0)
,ty(0)
,armState(0)
,center()
,player()
,playerSymbol()
,playerArm()
{
	//initializari
	center = new Point2D(DrawingWindow::width/2,DrawingWindow::height/2);
	
	//cerc exterior
	player = new Circle2D(*center, 20, Color( 0.666667, 0.666667, 0.666667), 1);
	//simbol centru 
	playerSymbol = new Polygon2D(Color(0.815686, 0.12549, 0.564706), 1);
	playerSymbol->addPoint(Point2D(center->x - 5, center->y));
	playerSymbol->addPoint(Point2D(center->x + 13, center->y + 8));
	playerSymbol->addPoint(Point2D(center->x, center->y + 13));
	playerSymbol->addPoint(Point2D(center->x - 13, center->y + 8));
	playerSymbol->addPoint(Point2D(center->x - 13, center->y - 8));
	playerSymbol->addPoint(Point2D(center->x, center->y - 13));
	playerSymbol->addPoint(Point2D(center->x + 13, center->y - 8));
	playerSymbol->addPoint(Point2D(center->x - 5, center->y));

	//bratul de atac
	playerArm = new Polygon2D(Color(0.815686, 0.12549, 0.564706), 1);
	playerArm->addPoint(Point2D(center->x + 25, center->y + 10));
	playerArm->addPoint(Point2D(center->x + 25, center->y - 10));
	playerArm->addPoint(Point2D(center->x + 75, center->y));
}

//desenare simbol player
void Player::drawingSymbol(Point2D coord){

	Polygon2D *symbol = new Polygon2D(Color(0.815686, 0.12549, 0.564706), 0);
	symbol->addPoint(Point2D(coord.x - 5, coord.y));
	symbol->addPoint(Point2D(coord.x + 13, coord.y + 8));
	symbol->addPoint(Point2D(coord.x, coord.y + 13));
	symbol->addPoint(Point2D(coord.x - 13, coord.y + 8));
	symbol->addPoint(Point2D(coord.x - 13, coord.y - 8));
	symbol->addPoint(Point2D(coord.x, coord.y - 13));
	symbol->addPoint(Point2D(coord.x + 13, coord.y - 8));
	symbol->addPoint(Point2D(coord.x - 5, coord.y));
	DrawingWindow::addObject2D_to_Visual2D(symbol, Opponent::top);
}
//desenare player
void Player::drawingPlayer(){
	
	DrawingWindow::addObject2D_to_Visual2D(playerSymbol, Opponent::bottom);
	DrawingWindow::addObject2D_to_Visual2D(player, Opponent::bottom);
	
	if(armState){
		Transform2D::applyTransform(playerArm);
		DrawingWindow::addObject2D_to_Visual2D(playerArm, Opponent::bottom);
	}
	return;
}
//rotire player
void Player::rotate(int direction){
	float pas;
	if(direction == 0){
		//sens trigonometric
		if(angle + 0.1 > 2*PI){
			angle = angle + 0.1 - 2*PI;
		}else{
			angle += 0.1;
		}
		pas = 0.1;
	}else{
		if(angle - 0.1 < 0){
			angle = angle - 0.1 + 2*PI;
		}else{
			angle -= 0.1;
		}
		pas = -0.1;
	}
	
	Transform2D::translateMatrix(-center->x,-center->y);
	Transform2D::rotateMatrix(pas);
	Transform2D::translateMatrix(center->x,center->y);

	Transform2D::applyTransform(player);
	Transform2D::applyTransform(playerSymbol);
	if(armState){
		Transform2D::applyTransform(playerArm);
	}
	
}
//miscare inainte
void Player::move(){
	
	int margin;
	if(armState){
		tx = 5 * cos(angle);
		ty = 5 * sin(angle);
		margin = 80;
	}else{
		tx = 15 * cos(angle);
		ty = 15 * sin(angle);
		margin = 20;
	}

	if(center->x + tx < DrawingWindow::width - margin && center->x + tx > margin 
		&& center-> y + ty < DrawingWindow::height - margin && center->y + ty > margin){
		Transform2D::translateMatrix(tx,ty);
		Transform2D::applyTransform(player);
		Transform2D::applyTransform(playerSymbol);
	
		if(armState){
			Transform2D::applyTransform(playerArm);
		}
		center->x = center->x + tx;
		center->y = center->y + ty;
	}
	
}
//functie returnare centru player
Point2D Player::getCenter(){
	Point2D *p = new Point2D(center->x, center->y);
	return *p;
}
//functie returnare daca arma este sau nu activata
int Player::getArmState(){
	return armState;
}
//functie activare arma
void Player::activateArm(){
	armState = !armState;
	if(armState){
		drawingPlayer();
	}else{
		DrawingWindow::removeObject2D_from_Visual2D(playerArm, Opponent::bottom);
	}
 }
//functie returnare unghi player
float Player::getAngle(){
	return angle;
}


Player::~Player(void)
{
	delete(center);
	delete(&angle);
	delete(player);
	delete(playerSymbol);
	delete(playerArm);
}
