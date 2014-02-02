#include "../user/screen.h"

#include "alien.h"

extern long Score;
extern Screen *screen;
extern Keyboard *key;
extern Sprite *pl;
extern Speaker spk;

Sound *snd_appear, *snd_die;

void Aliens::init()  {
  snd_appear = new Sound("alienapp.wav");
  snd_die = new Sound("aliendie.wav");
  int ctr;
  for(ctr = 0; ctr < max; ctr++)  {
    alienmode[ctr] = 1;
    alienframe[ctr] = 0;
    aliendelay[ctr] = 0;
    alientype[ctr] = 1;
    ee[ctr] = 0;
    }
  for(ctr = 0; ctr < 6; ctr++)  {
    aliengraph[1][ctr] = new Graphic(20,18);
    aliengraph[3][ctr] = new Graphic(20,18);
    }
  screen->SetPaletteEntry(3, 0x7F, 0xFC, 0);
  screen->SetPaletteEntry(4, 0xB3, 0, 0);
  screen->SetPaletteEntry(5, 0xFF, 0, 0);
  screen->SetPaletteEntry(6, 0xFF, 0x7F, 0);
  screen->SetPaletteEntry(7, 0xFF, 0xFF, 0);

  aliengraph[1][0]->DefLinH("----------0303------------0303----------");
  aliengraph[1][0]->DefLinH("----------0303------------0303----------");
  aliengraph[1][0]->DefLinH("----------0303------------0303----------");
  aliengraph[1][0]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][0]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][0]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][0]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][0]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][0]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][0]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][0]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][0]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][0]->DefLinH("--030303------------------------030303--");
  aliengraph[1][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][0]->DefLinH("--0303----------------------------0303--");
  screen->MakeFriendly(aliengraph[1][0]);

  aliengraph[1][1]->DefLinH("----------0303------------0303----------");
  aliengraph[1][1]->DefLinH("----------0303------------0303----------");
  aliengraph[1][1]->DefLinH("----------0303------------0303----------");
  aliengraph[1][1]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][1]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][1]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][1]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][1]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][1]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][1]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][1]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][1]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][1]->DefLinH("--030303------------------------030303--");
  aliengraph[1][1]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][1]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][1]->DefLinH("----0303------------------------0303----");
  aliengraph[1][1]->DefLinH("----0303------------------------0303----");
  aliengraph[1][1]->DefLinH("----0303------------------------0303----");
  screen->MakeFriendly(aliengraph[1][1]);

  aliengraph[1][2]->DefLinH("----------0303------------0303----------");
  aliengraph[1][2]->DefLinH("----------0303------------0303----------");
  aliengraph[1][2]->DefLinH("----------0303------------0303----------");
  aliengraph[1][2]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][2]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][2]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][2]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][2]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][2]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][2]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][2]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][2]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][2]->DefLinH("--030303------------------------030303--");
  aliengraph[1][2]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][2]->DefLinH("----0303------------------------0303----");
  aliengraph[1][2]->DefLinH("----0303------------------------0303----");
  aliengraph[1][2]->DefLinH("------0303--------------------0303------");
  aliengraph[1][2]->DefLinH("------0303--------------------0303------");
  screen->MakeFriendly(aliengraph[1][2]);

  aliengraph[1][3]->DefLinH("----------0303------------0303----------");
  aliengraph[1][3]->DefLinH("----------0303------------0303----------");
  aliengraph[1][3]->DefLinH("----------0303------------0303----------");
  aliengraph[1][3]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][3]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][3]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][3]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][3]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][3]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][3]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][3]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][3]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][3]->DefLinH("--030303------------------------030303--");
  aliengraph[1][3]->DefLinH("--0303----------------------------0303--");
  aliengraph[1][3]->DefLinH("----0303------------------------0303----");
  aliengraph[1][3]->DefLinH("------0303--------------------0303------");
  aliengraph[1][3]->DefLinH("------0303--------------------0303------");
  aliengraph[1][3]->DefLinH("--------0303----------------0303--------");
  screen->MakeFriendly(aliengraph[1][3]);

  aliengraph[1][4]->DefLinH("----------0303------------0303----------");
  aliengraph[1][4]->DefLinH("----------0303------------0303----------");
  aliengraph[1][4]->DefLinH("----------0303------------0303----------");
  aliengraph[1][4]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][4]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][4]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][4]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][4]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][4]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][4]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][4]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][4]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][4]->DefLinH("--030303------------------------030303--");
  aliengraph[1][4]->DefLinH("----0303------------------------0303----");
  aliengraph[1][4]->DefLinH("------0303--------------------0303------");
  aliengraph[1][4]->DefLinH("------0303--------------------0303------");
  aliengraph[1][4]->DefLinH("--------0303----------------0303--------");
  aliengraph[1][4]->DefLinH("----------0303------------0303----------");
  screen->MakeFriendly(aliengraph[1][4]);

  aliengraph[1][5]->DefLinH("----------0303------------0303----------");
  aliengraph[1][5]->DefLinH("----------0303------------0303----------");
  aliengraph[1][5]->DefLinH("----------0303------------0303----------");
  aliengraph[1][5]->DefLinH("----------03030303030303030303----------");
  aliengraph[1][5]->DefLinH("------0303030303030303030303030303------");
  aliengraph[1][5]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[1][5]->DefLinH("--030303030404030303030303040403030303--");
  aliengraph[1][5]->DefLinH("--030303030404040303030304040403030303--");
  aliengraph[1][5]->DefLinH("--030303030304040303030304040303030303--");
  aliengraph[1][5]->DefLinH("--030303030303030303030303030303030303--");
  aliengraph[1][5]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[1][5]->DefLinH("--03030303--------------------03030303--");
  aliengraph[1][5]->DefLinH("--030303------------------------030303--");
  aliengraph[1][5]->DefLinH("----0303------------------------0303----");
  aliengraph[1][5]->DefLinH("------0303--------------------0303------");
  aliengraph[1][5]->DefLinH("--------0303----------------0303--------");
  aliengraph[1][5]->DefLinH("----------0303------------0303----------");
  aliengraph[1][5]->DefLinH("------------0303--------0303------------");
  screen->MakeFriendly(aliengraph[1][5]);

  aliengraph[3][0]->DefLinH("----------0303------------0303----------");
  aliengraph[3][0]->DefLinH("----------0303------------0303----------");
  aliengraph[3][0]->DefLinH("----------0303------------0303----------");
  aliengraph[3][0]->DefLinH("----------03030303030303030303----------");
  aliengraph[3][0]->DefLinH("------0303030303030303030303030303------");
  aliengraph[3][0]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[3][0]->DefLinH("--0303030304040303-5-50303040403030303--");
  aliengraph[3][0]->DefLinH("--03030303040404-5-5-5-504040403030303--");
  aliengraph[3][0]->DefLinH("--03030303030404-5-5-5-504040303030303--");
  aliengraph[3][0]->DefLinH("--030303030303-5-5-5-5-5-5030303030303--");
  aliengraph[3][0]->DefLinH("--0303030303----------------0303030303--");
  aliengraph[3][0]->DefLinH("--03030303--------------------03030303--");
  aliengraph[3][0]->DefLinH("--030303------------------------030303--");
  aliengraph[3][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][0]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][0]->DefLinH("--0303----------------------------0303--");
  screen->MakeFriendly(aliengraph[3][0]);

  aliengraph[3][1]->DefLinH("----------0303------------0303----------");
  aliengraph[3][1]->DefLinH("----------0303------------0303----------");
  aliengraph[3][1]->DefLinH("----------0303------------0303----------");
  aliengraph[3][1]->DefLinH("----------03030303030303030303----------");
  aliengraph[3][1]->DefLinH("------0303030303030303030303030303------");
  aliengraph[3][1]->DefLinH("----03030303030303030303030303030303----");
  aliengraph[3][1]->DefLinH("--030303030404-5-5-5-5-5-5040403030303--");
  aliengraph[3][1]->DefLinH("--0303030304-5-5-5-5-5-5-5-50403030303--");
  aliengraph[3][1]->DefLinH("--0303030303-5-5-5-6-6-5-5-50303030303--");
  aliengraph[3][1]->DefLinH("--03030303-5-5-5-6-6-6-6-5-5-503030303--");
  aliengraph[3][1]->DefLinH("--03030303-5-----------------503030303--");
  aliengraph[3][1]->DefLinH("--03030303--------------------03030303--");
  aliengraph[3][1]->DefLinH("--030303------------------------030303--");
  aliengraph[3][1]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][1]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][1]->DefLinH("----0303------------------------0303----");
  aliengraph[3][1]->DefLinH("----0303------------------------0303----");
  aliengraph[3][1]->DefLinH("----0303------------------------0303----");
  screen->MakeFriendly(aliengraph[3][1]);

  aliengraph[3][2]->DefLinH("----------0303------------0303----------");
  aliengraph[3][2]->DefLinH("----------0303------------0303----------");
  aliengraph[3][2]->DefLinH("----------0303------------0303----------");
  aliengraph[3][2]->DefLinH("----------03030303030303030303----------");
  aliengraph[3][2]->DefLinH("------03030303-5-5-5-5-5-503030303------");
  aliengraph[3][2]->DefLinH("----03030303-5-5-5-5-5-5-5-503030303----");
  aliengraph[3][2]->DefLinH("--03030303-5-5-6-6-6-6-6-6-5-503030303--");
  aliengraph[3][2]->DefLinH("--030303-5-5-6-6-6-6-6-6-6-6-5-5030303--");
  aliengraph[3][2]->DefLinH("--0303-5-5-5-6-6-6-7-7-6-6-6-5-5-50303--");
  aliengraph[3][2]->DefLinH("--0303-5-5-6-6-6-7-7-7-7-6-6-6-5-50303--");
  aliengraph[3][2]->DefLinH("--0303-5-5-6-----------------6-5-50303--");
  aliengraph[3][2]->DefLinH("--0303-5-5---------------------5-50303--");
  aliengraph[3][2]->DefLinH("--030303------------------------030303--");
  aliengraph[3][2]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][2]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][2]->DefLinH("----0303------------------------0303----");
  aliengraph[3][2]->DefLinH("----0303------------------------0303----");
  aliengraph[3][2]->DefLinH("----0303------------------------0303----");
  screen->MakeFriendly(aliengraph[3][2]);

  aliengraph[3][3]->DefLinH("----------0303------------0303----------");
  aliengraph[3][3]->DefLinH("----------0303------------0303----------");
  aliengraph[3][3]->DefLinH("----------0303------------0303----------");
  aliengraph[3][3]->DefLinH("----------03030303030303030303----------");
  aliengraph[3][3]->DefLinH("------0303-5-5-5-5-5-5-5-5-5-50303------");
  aliengraph[3][3]->DefLinH("----0303-5-5-5-6-6-6-6-6-6-5-5-50303----");
  aliengraph[3][3]->DefLinH("--0303-5-5-6-6-6-6-7-7-6-6-6-6-5-50303--");
  aliengraph[3][3]->DefLinH("--03-5-5-6-6-7-7-7-7-7-7-7-7-6-5-5-503--");
  aliengraph[3][3]->DefLinH("03-5-5-6-6-7-7-7---------7-7-6-6-5-5-503");
  aliengraph[3][3]->DefLinH("03-5-6-6-6-7-7-------------7-6-6-6-5-503");
  aliengraph[3][3]->DefLinH("03-5-6-6-6---------------------6-6-5-503");
  aliengraph[3][3]->DefLinH("03-5-5-6-------------------------6-5-503");
  aliengraph[3][3]->DefLinH("---5-5-5-------------------------5-5-5--");
  aliengraph[3][3]->DefLinH("---5-5-----------------------------5-5--");
  aliengraph[3][3]->DefLinH("--0303----------------------------0303--");
  aliengraph[3][3]->DefLinH("----0303------------------------0303----");
  aliengraph[3][3]->DefLinH("----0303------------------------0303----");
  aliengraph[3][3]->DefLinH("----0303------------------------0303----");
  screen->MakeFriendly(aliengraph[3][3]);

  aliengraph[3][4]->DefLinH("----------------------------------------");
  aliengraph[3][4]->DefLinH("------------0303--------0303------------");
  aliengraph[3][4]->DefLinH("----------0303------------0303----------");
  aliengraph[3][4]->DefLinH("-----------5-5-5-5-5-5-5-5-5-5----------");
  aliengraph[3][4]->DefLinH("-------5-5-5-5-6-6-6-6-6-6-5-5-5-5------");
  aliengraph[3][4]->DefLinH("-----5-5-6-6-6-6-7-7-7-7-6-6-6-5-5-5----");
  aliengraph[3][4]->DefLinH("---5-5-5-5-6-7-7-7-----7-7-7-6-6-5-5-5--");
  aliengraph[3][4]->DefLinH("---5-5-5-6-7-----------------7-6-6-5-5--");
  aliengraph[3][4]->DefLinH("-5-5-5-6-7---------------------7-6-5-5-5");
  aliengraph[3][4]->DefLinH("-5-5-6-6-7---------------------7-6-6-5-5");
  aliengraph[3][4]->DefLinH("-5-5-6-6-7---------------------7-6-6-5-5");
  aliengraph[3][4]->DefLinH("-5-5-6-7-------------------------7-6-5-5");
  aliengraph[3][4]->DefLinH("---5-5-6-------------------------6-5-5--");
  aliengraph[3][4]->DefLinH("---5-5-----------------------------5-5--");
  aliengraph[3][4]->DefLinH("---5-5-----------------------------5-5--");
  aliengraph[3][4]->DefLinH("----0303------------------------0303----");
  aliengraph[3][4]->DefLinH("------03------------------------03------");
  aliengraph[3][4]->DefLinH("----------------------------------------");
  screen->MakeFriendly(aliengraph[3][4]);

  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("---------------5---------5--------------");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("-------7-6---------------------6-7------");
  aliengraph[3][5]->DefLinH("-----7-7-6---------------------6-7-7----");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("-5-6-6-7-------------------------7-6-6-5");
  aliengraph[3][5]->DefLinH("-5-6---------------------------------6-5");
  aliengraph[3][5]->DefLinH("-5-6---------------------------------6-5");
  aliengraph[3][5]->DefLinH("-5-5-6-----------------------------6-5-5");
  aliengraph[3][5]->DefLinH("---5---------------------------------5--");
  aliengraph[3][5]->DefLinH("---5---------------------------------5--");
  aliengraph[3][5]->DefLinH("---5-6-----------------------------6-5--");
  aliengraph[3][5]->DefLinH("-------7-------------------------7------");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  aliengraph[3][5]->DefLinH("----------------------------------------");
  screen->MakeFriendly(aliengraph[3][5]);
  }

void Aliens::deleteall()  {
  int ctr;
  number = 0;
  for(ctr = 0; ctr < max; ctr++)  {
    if(ee[ctr] != 0)  {
      delete enm[ctr];
      ee[ctr] = 0;
      }
    }
  }

void Aliens::newalien(int X, int Y, int XX, int YY)  {
  int ctr;
  number++;
  for(ctr = 0; (ctr < max) && (ee[ctr] != 0); ctr++);
  if(ctr == max)  return;
  ee[ctr] = 1;
  ex[ctr] = X;
  ey[ctr] = Y;
  exx[ctr] = XX;
  eyy[ctr] = YY;
  enm[ctr] = new Sprite();
  alientype[ctr] = 1;
  alienframe[ctr] = 0;
  alienmode[ctr] = 1;
  enm[ctr]->SetImage(aliengraph[alientype[ctr]][0]);
  enm[ctr]->Move(ex[ctr], ey[ctr]);
  if(!growled) snd_appear->Play();
  growled = 1;
  }

void Aliens::hitalien(int ali)  {
  int ctr;
  for(ctr = 0; (ctr < max) && ((ee[ctr] == 0) ||
	(enm[ctr]->Number() != ali)); ctr++);
  if(ctr >= max)  return;
  explodealien(ctr);
  }

void Aliens::explodealien(int ali)  {
  if(alientype[ali] > 1)  return;
  snd_die->Play();
  alientype[ali] += 2;
  alienframe[ali] = -1;
  aliendelay[ali] = 1;
  Score += 1000;
  }

void Aliens::deletealien(int ali)  {
  ee[ali] = 0;
  delete enm[ali];
  number --;
  if(number < 1)  {
    int ctr;
    growled = 0;
    if(edge < espd)  {
      edge++;
      }
    else  {
      if(espd < (eqty * 1))  {
	espd ++;
	edge --;
	}
      else  {
	eqty++;
	espd=1;
	edge=0;
	}
      }
    for(ctr = 0; ctr < eqty; ctr++)  {
      int cspd = (espd-ctr);
      while(cspd < 1)  cspd+= espd;
      newalien(((50+(100*ctr)) % 310), 0, ((edge-ctr) * (((ctr%2)*2)-1)),
	cspd);
      }
    }
  }

IntList Aliens::update()  {
  int ctr;
  IntList ret, tmp;
  for(ctr = 0; ctr < max; ctr++)
      if(ee[ctr] != 0)  {
    ey[ctr] += eyy[ctr];
    ex[ctr] += exx[ctr];
    if(ey[ctr] > 180)  {
      ey[ctr] = 180;
      eyy[ctr] = -eyy[ctr];
      }
    if(ey[ctr] < 0)  {
      ey[ctr] = 0;
      eyy[ctr] = -eyy[ctr];
      }
    if(ex[ctr] > 300)  {
      ex[ctr] = 300;
      exx[ctr] = -exx[ctr];
      }
    if(ex[ctr] < 0)  {
      ex[ctr] = 0;
      exx[ctr] = -exx[ctr];
      }
    }
  flctr--;
  if(flctr < 1)  {
    for(ctr = 0; ctr < max; ctr++)  {
      if(ee[ctr] != 0)  {
        if((alienframe[ctr] == 5) && (alientype[ctr] > 1))  deletealien(ctr);
        else  if(ee[ctr] != 0)  {
	  if(aliendelay[ctr] == 0)  {
	    alienframe[ctr] += alienmode[ctr];
	    if(alienframe[ctr] > 5)  {
	      alienframe[ctr] = 4;
	      alienmode[ctr] = -1;
	      }
	    if(alienframe[ctr] < 0)  {
	      alienframe[ctr] = 1;
	      alienmode[ctr] = 1;
	      }
	    if(alientype[ctr] > 1) aliendelay[ctr] = 1;
	    else  if(alienframe[ctr] == 0)  aliendelay[ctr] = FLIPPER_DELAY * 2;
	    else  aliendelay[ctr] = 2;
	    enm[ctr]->SetImage(aliengraph[alientype[ctr]][alienframe[ctr]]);
	    }
	  else  aliendelay[ctr]--;
	  }
        }
      }
    flctr = FLIPPER_TIME;
    }
  for(ctr = 0; ctr < max; ctr++)  if(ee[ctr] != 0)  {
    tmp = enm[ctr]->CMove(ex[ctr], ey[ctr]);
//    ret += tmp;
    if(tmp == pl->Number())  ret += pl->Number();
    }
  return ret;
  }
