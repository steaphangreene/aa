#define MAX_ENEMIES	8
#define FLIPPER_TIME	1
#define FLIPPER_DELAY	8

#include "../user/user.h"

class Aliens  {
  public:
  int eqty, espd, edge;
  int *ey, *eyy, *ee, *ex, *exx;
  Sprite **enm;
  int max;
  Graphic *aliengraph[4][6];
  int *alienmode, *alienframe, *aliendelay, *alientype;
  int flctr;
  int number;
  int growled;

  Aliens(int MAX)  {
//    snd_die = new DigSample("aliendie.wav");
//    snd_appear = new DigSample("alienapp.wav");
    eqty = 1;
    espd = 1;
    edge = 0;
    number = 0;
    growled = 0;
    max = MAX;
    enm = new Sprite *[MAX];
    ee = new int[MAX];
    ey = new int[MAX];
    eyy = new int[MAX];
    ex = new int[MAX];
    exx = new int[MAX];
    aliendelay = new int[MAX];
    alienframe = new int[MAX];
    alienmode = new int[MAX];
    alientype = new int[MAX];
    flctr = FLIPPER_TIME;
    init();
    };

  ~Aliens()  {
//    delete snd_die;
//    delete snd_appear;
    delete enm;
    delete ey; 
    delete ee; 
    delete eyy; 
    delete ex; 
    delete exx;
    delete aliendelay; 
    delete alienframe;
    delete alienmode;
    delete alientype;
    }
  void init();
  void hitalien(int);
  void explodealien(int);
  void deletealien(int);
  int num()  {
    return number;
    }
  IntList update();
  void deleteall();
  void newalien(int, int, int, int);
  private:
//  DigSample *snd_appear;
//  DigSample *snd_die;
  };
