#include"pancakecookie.h"

PanCakeCookie::PanCakeCookie(int w, int h, int maxC, int u, int d){
	//TODO
	this->w = w;
	this->h = h;
	this->x = 0;
	this->y = 0;
	this->t = 0;
	this->score = 0;
	this->maxC = maxC;
	this->curC = maxC;
	this->u = u;
	this->d = d;
	bool** map = new bool*[w + 1];
	for (int i = 0; i < w + 1; i++) {
		map[i] = new bool[h + 1];
		for (int j = 0; j < h + 1; j++)
			if (j == 0)
				map[i][j] = false; //y=0 ø°º± ¡©∏Ææ¯¿Ω
			else
				map[i][j] = true; //¡©∏Æª˝º∫
	}
}

int PanCakeCookie::getX() {return this->x;}
int PanCakeCookie::getY(){ return this->y;}
int PanCakeCookie::getU(){ return this->u;}
int PanCakeCookie::getD(){ return this->d;}
int PanCakeCookie::getScore() {return this->score;}
int PanCakeCookie::getC(){ return this->curC;}

void PanCakeCookie::reset(){
	// TODO 
	//¡©∏Æ√ ±‚»≠
	for (int i = 0; i < w + 1; i++) {
		for (int j = 0; j < h + 1; j++)
			if (j == 0)
				this->map[i][j] = false;
			else
				this->map[i][j] = true; 
	}
	//
}

void PanCakeCookie::setU(int x){
	// TODO 
}

void PanCakeCookie::setD(int x){
	// TODO
}

void PanCakeCookie::setC(int x){
	// TODO
}

void PanCakeCookie::setT(int t){

	// TODO

}
