#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Text.h"
#include "Player.h"
#include "OpponentTetris.h"
#include "OpponentPlane.h"
#include "OpponentStar.h"
#include "OpponentDiamond.h"
#include "Opponent.h"
#include "Opponent2Squares.h"
#include "Bullet.h"
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <vector>

#define PI 3.14159265358979323846

using namespace std;
float pas=0;
float tx;
float ty;
int score = 0;
int lives = 3;
Player *player;
Object2D *obj;
float angle;
Point2D *center;
Text *scoreBar;
Text *scoreValue;
Text *livesBar;
Text *xSymbol;
Text *gameover;
int stopOnidle = 0;
int sleepTime = 0;

std::vector<Opponent2Squares> op2squares;
std::vector<OpponentDiamond> opDiamonds;
std::vector<OpponentPlane> opPlanes;
std::vector<OpponentStar> opStars;
std::vector<OpponentTetris> opTetris;
std::vector<Bullet> bullets;


// functie pentru calcularea distantei intre 2 puncte
float distance2(Point2D p1, Point2D p2){
	float op1, op2, dist;
	op1 = (p1.x - p2.x)*(p1.x - p2.x);
	op2 = (p1.y - p2.y)*(p1.y - p2.y);
	dist = sqrt(op1 + op2);
	return dist;
} 

//functie pentru adaugarea unui adeversar intr-o pozitie aleatoariu aleasa
void addMoreOpponents(){
	//srand (time(NULL));
	int randomOpponent;
	float xCoord, yCoord; 
	cout<<rand()<<"  "<<rand();
	randomOpponent = rand() % 5;
	xCoord = rand() % 500 + 50;
	yCoord = rand() % 300 + 130;
	while(distance2(Point2D(xCoord, yCoord), player->getCenter()) < 100){
		//prea aproape de jucator => genereaza noi coordonate
		xCoord = rand() % 500 + 50;
		yCoord = rand() % 300 + 50;
	}
	if(randomOpponent == 0){
		op2squares.push_back(Opponent2Squares(Point2D(xCoord,yCoord)));
		op2squares[op2squares.size() - 1].drawingPlayer();
	}
	if(randomOpponent == 1){
		opDiamonds.push_back(OpponentDiamond(Point2D(xCoord,yCoord)));
		opDiamonds[opDiamonds.size() - 1].drawingPlayer();
	}
	if(randomOpponent == 2){
		opPlanes.push_back(OpponentPlane(Point2D(xCoord,yCoord)));
		opPlanes[opPlanes.size() - 1].drawingPlayer();
	}
	if(randomOpponent == 3){
		opStars.push_back(OpponentStar(Point2D(xCoord,yCoord)));
		opStars[opStars.size() - 1].drawingPlayer();
	}
	if(randomOpponent == 4){
		opTetris.push_back(OpponentTetris(Point2D(xCoord,yCoord)));
		opTetris[opTetris.size() - 1].drawingPlayer();
	}
}

//functii pentru contactul cu adversari (atat al jucatorului cat si al gloantelor)
//pentru fiecare tip de adversar in parte
int contact2squares(){
	Point2D playerCenter = player->getCenter();
	float distToBullet;
	float distToPlayer;
	int partialScore = 0;
	int index = 0;
	int toRemoveOppPlayer = -1;
	int isRemoved = 0;
	std::vector<int> toRemoveOpp;
	std::vector<int> toRemoveBullet;
	for (unsigned int i = 0; i < op2squares.size(); i++){
		for(unsigned int j = 0; j < bullets.size(); j++){
			Point2D p = bullets[j].getCircleCenter(); 
			distToBullet = distance2(p, op2squares[i].getCenter());
			if(distToBullet < 12){
				toRemoveOpp.push_back(i);
				toRemoveBullet.push_back(j);
				partialScore += 5;
				isRemoved = 1;
			}
		}

		distToPlayer = distance2(player->getCenter(), op2squares[i].getCenter());
		if(distToPlayer < 30){
			lives--;
			livesBar->text = to_string(lives);
			if(isRemoved == 0){
				toRemoveOppPlayer = i;
			}
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Opponent::bottom);
				return -1;
			}
		}

	}

	if(toRemoveOppPlayer >= 0){
		op2squares[toRemoveOppPlayer].removeOpponent();
		op2squares.erase(op2squares.begin() + toRemoveOppPlayer);
	}

	for(unsigned int i = 0; i < toRemoveOpp.size(); i++){
		op2squares[toRemoveOpp[i]].removeOpponent();
		op2squares.erase(op2squares.begin() + toRemoveOpp[i]);
		bullets[toRemoveBullet[i]].removeBullet();
		bullets.erase(bullets.begin() + toRemoveBullet[i]);
		addMoreOpponents();
	}
	return partialScore;
}

int contactTetris(){
	Point2D playerCenter = player->getCenter();
	float dist;
	float distToPlayer;
	int toRemoveOppPlayer = -1;
	int isRemoved = 0;
	int index = 0;
	int partialScore = 0;
	std::vector<int> toRemoveOpp;
	std::vector<int> toRemoveBullet;
	for (unsigned int i = 0; i < opTetris.size(); i++){
		for(unsigned int j = 0; j < bullets.size(); j++){
			Point2D p = bullets[j].getCircleCenter(); 
			dist = distance2(p, opTetris[i].getCenter());
			if(dist < 12){
				toRemoveOpp.push_back(i);
				toRemoveBullet.push_back(j);
				partialScore += 7;
			}
		}
		distToPlayer = distance2(player->getCenter(), opTetris[i].getCenter());
		if(distToPlayer < 40){
			
			lives--;
			livesBar->text = to_string(lives);
			if(isRemoved == 0){
				toRemoveOppPlayer = i;
			}
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Opponent::bottom);
				return -1;
			}
			
		}

	}
	
	if(toRemoveOppPlayer >= 0){
		opTetris[toRemoveOppPlayer].removeOpponent();
		opTetris.erase(opTetris.begin() + toRemoveOppPlayer);
	}

	for(unsigned int i = 0; i < toRemoveOpp.size(); i++){
		opTetris[toRemoveOpp[i]].removeOpponent();
		opTetris.erase(opTetris.begin() + toRemoveOpp[i]);
		bullets[toRemoveBullet[i]].removeBullet();
		bullets.erase(bullets.begin() + toRemoveBullet[i]);
		addMoreOpponents();
	}
	return partialScore;
}

int contactDiamonds(){
	Point2D playerCenter = player->getCenter();
	float dist;
	float distToPlayer;
	int toRemoveOppPlayer = -1;
	int isRemoved = 0;
	int partialScore = 0;
	int index = 0;
	std::vector<int> toRemoveOpp;
	std::vector<int> toRemoveBullet;
	for (unsigned int i = 0; i < opDiamonds.size(); i++){
		for(unsigned int j = 0; j < bullets.size(); j++){
			Point2D p = bullets[j].getCircleCenter(); 
			dist = distance2(p, opDiamonds[i].getCenter());
			if(dist < 12){
				toRemoveOpp.push_back(i);
				toRemoveBullet.push_back(j);
				partialScore += 20;
			}
		}
		distToPlayer = distance2(player->getCenter(), opDiamonds[i].getCenter());
		if(distToPlayer < 40){
			
			lives--;
			livesBar->text = to_string(lives);
			if(isRemoved == 0){
				toRemoveOppPlayer = i;
			}
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Opponent::bottom);
				return -1;
			}
		}
	}

	if(toRemoveOppPlayer >= 0){
		opDiamonds[toRemoveOppPlayer].removeOpponent();
		opDiamonds.erase(opDiamonds.begin() + toRemoveOppPlayer);
	}

	for(unsigned int i = 0; i < toRemoveOpp.size(); i++){
		opDiamonds[toRemoveOpp[i]].removeOpponent();
		opDiamonds.erase(opDiamonds.begin() + toRemoveOpp[i]);
		bullets[toRemoveBullet[i]].removeBullet();
		bullets.erase(bullets.begin() + toRemoveBullet[i]);
		addMoreOpponents();
	}
	return partialScore;
}

int contactStars(){
	Point2D playerCenter = player->getCenter();
	float dist;
	float distToPlayer;
	int toRemoveOppPlayer = -1;
	int isRemoved = 0;
	int partialScore = 0;
	int index = 0;
	std::vector<int> toRemoveOpp;
	std::vector<int> toRemoveBullet;
	for (unsigned int i = 0; i < opStars.size(); i++){
		for(unsigned int j = 0; j < bullets.size(); j++){
			Point2D p = bullets[j].getCircleCenter(); 
			dist = distance2(p, opStars[i].getCenter());
			if(dist < 12){
				toRemoveOpp.push_back(i);
				toRemoveBullet.push_back(j);
				partialScore += 10;
			}
		}

		distToPlayer = distance2(player->getCenter(), opStars[i].getCenter());
		if(distToPlayer < 40){
			
			lives--;
			livesBar->text = to_string(lives);
			if(isRemoved == 0){
				toRemoveOppPlayer = i;
			}
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Opponent::bottom);
				return -1;
			}
			
		}
	}
	if(toRemoveOppPlayer >= 0){
		opStars[toRemoveOppPlayer].removeOpponent();
		opStars.erase(opStars.begin() + toRemoveOppPlayer);
	}
	for(unsigned int i = 0; i < toRemoveOpp.size(); i++){
		opStars[toRemoveOpp[i]].removeOpponent();
		opStars.erase(opStars.begin() + toRemoveOpp[i]);
		bullets[toRemoveBullet[i]].removeBullet();
		bullets.erase(bullets.begin() + toRemoveBullet[i]);
		addMoreOpponents();
	}
	return partialScore;
}

int contactPlanes(){
	Point2D playerCenter = player->getCenter();
	float dist;
	float distToPlayer;
	int toRemoveOppPlayer = -1;
	int isRemoved = 0;
	int partialScore = 0;
	int index = 0;
	std::vector<int> toRemoveOpp;
	std::vector<int> toRemoveBullet;
	for (unsigned int i = 0; i < opPlanes.size(); i++){
		for(unsigned int j = 0; j < bullets.size(); j++){
			Point2D p = bullets[j].getCircleCenter(); 
			dist = distance2(p, opPlanes[i].getCenter());
			if(dist < 12){
				toRemoveOpp.push_back(i);
				toRemoveBullet.push_back(j);
				partialScore += 1;
			}
		}
		distToPlayer = distance2(player->getCenter(), opPlanes[i].getCenter());
		if(distToPlayer < 40){
			
			lives--;
			livesBar->text = to_string(lives);
			if(isRemoved == 0){
				toRemoveOppPlayer = i;
			}
			if(lives <= 0){
				DrawingWindow::addText_to_Visual2D(gameover,Opponent::bottom);
				return -1;
			}
			
		}

	}
	if(toRemoveOppPlayer >= 0){
		opPlanes[toRemoveOppPlayer].removeOpponent();
		opPlanes.erase(opPlanes.begin() + toRemoveOppPlayer);
	}
	for(unsigned int i = 0; i < toRemoveOpp.size(); i++){
		opPlanes[toRemoveOpp[i]].removeOpponent();
		opPlanes.erase(opPlanes.begin() + toRemoveOpp[i]);
		bullets[toRemoveBullet[i]].removeBullet();
		bullets.erase(bullets.begin() + toRemoveBullet[i]);
		addMoreOpponents();
	}
	return partialScore;
}

//functia care permite adaugarea de obiecte la initializare
void DrawingWindow::init()
{
		
	DrawingWindow::addVisual2D(Opponent::bottom);
	DrawingWindow::addVisual2D(Opponent::top);

	player = new Player();
	player->drawingPlayer();

	Opponent::top->cadruPoarta(Color(1,1,1));
	Opponent::bottom->cadruPoarta(Color(1,1,1));
	
	scoreBar = new Text("Score",Point2D(260,50),Color(0.815686, 0.12549, 0.564706),BITMAP_TIMES_ROMAN_24);
	scoreValue = new Text(to_string(score),Point2D(275,20),Color(0.815686, 0.12549, 0.564706),BITMAP_TIMES_ROMAN_24);
	
	xSymbol = new Text("X",Point2D(500,20),Color(0.815686, 0.12549, 0.564706),BITMAP_HELVETICA_18);

	livesBar = new Text(to_string(lives),Point2D(520,20),Color(0.815686, 0.12549, 0.564706),BITMAP_TIMES_ROMAN_24);
	player->drawingSymbol(Point2D(550, 28));


	gameover = new Text("Game Over!",Point2D(DrawingWindow::width/2 - 100,
		DrawingWindow::height/2),Color(0.815686, 0.12549, 0.564706),BITMAP_TIMES_ROMAN_24);
	DrawingWindow::addText_to_Visual2D(scoreValue,Opponent::top);
	DrawingWindow::addText_to_Visual2D(scoreBar,Opponent::top);
	DrawingWindow::addText_to_Visual2D(livesBar,Opponent::top);
	DrawingWindow::addText_to_Visual2D(xSymbol,Opponent::top);

	for(int i = 0; i < 30; i++){
		addMoreOpponents();
	}
}

//functia care permite animatia
void DrawingWindow::onIdle()
{
	
	if(stopOnidle == 1){
	}else{
		if(sleepTime > 5){
			for(int i = 0; i < bullets.size(); i++){
				bullets[i].move();
			}

			for(int i = 0; i < op2squares.size(); i++){
				op2squares[i].move();
			}
			for(int i = 0; i < opTetris.size(); i++){
				opTetris[i].move();
			}
			for(int i = 0; i < opStars.size(); i++){
				opStars[i].move();
			}
			for(int i = 0; i < opDiamonds.size(); i++){
				opDiamonds[i].move();
			}
			for(int i = 0; i < opPlanes.size(); i++){
				opPlanes[i].move();
			}
			sleepTime = 0;
		}
		sleepTime++;
		int scoreAux = score;
	
		score += contact2squares();
		scoreValue->text = to_string(score);
		score += contactTetris();
		scoreValue->text = to_string(score);
		score += contactDiamonds();
		scoreValue->text = to_string(score);
		score += contactStars();
		scoreValue->text = to_string(score);
		score += contactPlanes();
		if(score < scoreAux){
			stopOnidle = 1;
			scoreValue->text = to_string(score+1);
			return;
		}else{
			scoreValue->text = to_string(score);
		}
	}
}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
	Opponent::top->poarta(0,0,width, 100);
	Opponent::top->fereastra(0,0,width, 100);
 	Opponent::bottom->poarta(0,100,width, height);
 	Opponent::bottom->fereastra(0,0,width, height);
}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
		case 27 : exit(0);
		case 'd' : { 
			player->rotate(0);
			angle = player->getAngle();
			
			break;
				  }
		case 'f' : {
			player->rotate(1);
			angle = player->getAngle();
			break;
				   }
		case 'e' : {
			player->move();
			break;
				   }
		case 'g' : {
			player->activateArm();
			break;
				  }
		case 32 : {
			if(player->getArmState() == 1){
				float tx = 75 * cos(player->getAngle()) + player->getCenter().x;
				float ty = 75 * sin(player->getAngle()) + player->getCenter().y;

				Bullet *bullet = new Bullet(Point2D(tx, ty), player->getAngle());
				bullets.push_back(*bullet);
			}
		    break;
				  }

	}
}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{
	
}


int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 600, 500, 200, 100, "Tema 1");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;

}