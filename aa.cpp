#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <user.h>

#include "alien.h"

#define SCREEN_DELAY    8000
#define FADE_SPEED      8
#define MAX_SHOTS       16
#define MAX_ENEMIES     8
#define SHOT_DELAY      16
#define TWINKLE_TIME    8
#define SHUDDER_DELAY   4
#define SHUDDER_TIME    8
#define PLAYER_LIFE     5

#define SCORE_FN	"battle2.qbt"
#define TITLE_FN	"title.bmp"
#define MENU_FN		"menu.bmp"
#define CONF_FN		".aakeys"

int CONTROL_LEFT = KEY_LEFT;
int CONTROL_RIGHT = KEY_RIGHT;
int CONTROL_FIRE = KEY_SPACE;
int CONTROL_BRAKE = KEY_DOWN;
int AUTO_BRAKING = 1;

void defdeath();
void fire(int);
void upfire();
void delfire(int);
void menu();
void aa();
void saveconf();
void loadconf();
void options();
void highscores();

Sprite *sht[MAX_SHOTS];
Sprite *pl;

Graphic *death[20];
int deathxoff[20];
int deathyoff[20];
Graphic *shotgraph;
int shq[MAX_SHOTS];
int shqp = 0;
unsigned long lastfire = SHOT_DELAY;
int shx[MAX_SHOTS];
int shy[MAX_SHOTS];
Screen *screen;
Keyboard *key=NULL;
Joystick *joy=NULL;
Speaker *spk;
const unsigned py = 180;

Aliens *enemies;

Sound *plboom, *pl_die, *pl_ow, *zap;

long Score = 0;

int main(int argc, char **argv)  {
  U2_Init(argc, argv);
  plboom = new Sound("play_exp.wav");
  pl_die = new Sound("play_die.wav");
  pl_ow = new Sound("play_hit.wav");
  zap = new Sound("shoot.wav");
  int tmp;
  screen = new Screen(320, 200, 8);
  screen->SetFrameRate(60);
  screen->SetFont("basic10.sgf");
  key = new Keyboard();
  joy = new Joystick();
  spk = new Speaker(0, 8, 11025, 512);

  loadconf();
  while(1)  {
    screen->FullScreenBMP(TITLE_FN);
    screen->SetPalette(TITLE_FN);
    screen->RefreshFull();
    screen->FadeIn(FADE_SPEED);
    Score = 0;
    tmp = key->GetAKey(SCREEN_DELAY);
    screen->FadeOut(FADE_SPEED);
    if((tmp == KEY_ESC) || (tmp == KEY_Q))  {
      U2_Exit(0);
      }
    if(tmp != 0)  {
      menu();
      }
    highscores();
    }
  screen->FadeOut(FADE_SPEED);
  U2_Exit(0);
  }

void loadconf()  {
  FILE *cf;
  cf = U2_FOpenHomeRead(CONF_FN);
  if(cf != NULL)  {
    fscanf(cf, "%d %d %d %d %d", &AUTO_BRAKING, &CONTROL_LEFT, &CONTROL_RIGHT,
	&CONTROL_FIRE, &CONTROL_BRAKE);
    fclose(cf);
    }
  }

void saveconf()  {
  FILE *cf;
  cf = U2_FOpenHomeWrite(CONF_FN);
  fprintf(cf, "%d %d %d %d %d\n", AUTO_BRAKING, CONTROL_LEFT, CONTROL_RIGHT,
	CONTROL_FIRE, CONTROL_BRAKE);
  fclose(cf);
  }

void highscores()  {
  int tmp, ctr, ctr2, inp = 0, ppos = 40;
  FILE *hscr;
  long scores[10];
  char names[10][40];
  char *cname;
  unsigned char buffer[10][100];
  unsigned char dbuffer[10][50];
  char pbuffer[40];
  screen->Clear();
  screen->RefreshFull();
  screen->SetPaletteEntry(0, 0, 0, 0);
  screen->SetPaletteEntry(1, 0xFF, 0xFF, 0xFF);
  screen->SetPaletteEntry(7, 0xFF, 0, 0);
  if(Score > 0)  screen->Printf(0, 0, 0, 1, "Your Score: %ld", Score);
  screen->Printf(0, 12, 0, 7, "      --High Scores--\n");
  hscr = U2_FOpenSystemRead(SCORE_FN);

  for(ctr = 0; ctr < 10; ctr++)  {
    buffer[ctr][0] = 0;
    dbuffer[ctr][0] = 0;
    }
  if(hscr != NULL)  {
    for(ctr = 0; ctr < 10; ctr++)  {
      inp = ' ';
      for(ctr2 = 0; (ctr2 < 98) && (inp != '\n'); ctr2++)  {
        inp = getc(hscr);
        if((inp != '\n') && (inp != EOF))  buffer[ctr][ctr2] = inp;
        else  {
	  buffer[ctr][ctr2] = 0;
	  if(inp == EOF)  buffer[ctr][0] = 0;
	  inp = '\n';
          }
        }
      }
    fclose(hscr);
    }
  for(ctr = 0; ctr < 10; ctr++)  {
    if(buffer[ctr][0] != 0)  {
      for(ctr2 = 0; (ctr2 < 49) && (ctr2*2 < (int)strlen((char *)buffer[ctr]));
		ctr2++)  {
        dbuffer[ctr][ctr2] = (buffer[ctr][ctr2*2] | 15);
        dbuffer[ctr][ctr2] -= (buffer[ctr][ctr2*2] & 15);
        }
      dbuffer[ctr][ctr2] = 0;
      scores[ctr] = strtol((char *)dbuffer[ctr], &cname, 10);
      strcpy(names[ctr], &cname[2]);
      if((Score > scores[ctr]) && (Score > 0) && (ppos == 40))
        ppos = ctr;
      }
    else  {
      if((ppos == 40) && (Score > 0))  ppos = ctr;
      }
    }
  if(ppos < 10)  {
    for(ctr = 9; ctr > ppos; ctr--)  {
      scores[ctr] = scores[ctr-1];
      strcpy(names[ctr], names[ctr-1]);
      strcpy((char *)dbuffer[ctr], (char *)dbuffer[ctr-1]);
      }
    scores[ppos] = Score;
    names[ppos][0] = 0;
    }
  for(ctr = 0; ctr < 10; ctr++)  {
    if(dbuffer[ctr][0] != 0)  {
      screen->Printf(0, 24+12*ctr, 0, 7, "%ld: %s", scores[ctr], names[ctr]);
      }
    }
  screen->RefreshFast();
  if(ppos < 10)  {
    screen->FadeIn(FADE_SPEED);
    memset(pbuffer, 0, sizeof(pbuffer));
    while(strlen(pbuffer) < 1)  {
      screen->Printf(0, 24+12*ppos, 0, 1, "%ld: -", Score);
      inp = key->WaitForChar();
      for(ctr = 0; (ctr < 30) && (inp != '\n'); ctr++)  {
	if((inp != CHAR_ESC) && (inp != CHAR_DEL) && (inp != CHAR_BACKSP))  {
	  pbuffer[ctr] = inp;
	  screen->Printf(0, 1, "%c", inp);
	  }
	else  if(inp != CHAR_ESC)  {
	  ctr--;
	  if(ctr > -1)  {
	    pbuffer[ctr] = 0;
	    ctr--;
	    screen->ClearArea(0, 24+12*ppos, 320, 12);
	    screen->Printf(0, 24+12*ppos, 0, 1, "%ld: -%s", Score, pbuffer);
	    }
	  }
        else  {
          screen->Hide();
	  Score = -66;
	  highscores();
	  return;
	  }
        inp = key->WaitForChar();
        }
      pbuffer[ctr] = 0;
      }
    sprintf((char *)dbuffer[ppos], "%ld: %s%c", Score, pbuffer, 0);
    screen->ClearArea(0, 24+12*ppos, 320, 12);
    screen->Printf(0, 24+12*ppos, 0, 1, "%s\n", dbuffer[ppos]);
    fflush(stdout);
    hscr = U2_FOpenSystemWrite(SCORE_FN);
    for(ctr = 0; ctr < 10; ctr++)  {
      if(dbuffer[ctr][0] != 0)  {
        for(ctr2 = 0; (ctr2 < 49) && (dbuffer[ctr][ctr2] != 0); ctr2++)  {
          buffer[ctr][ctr2*2] = (dbuffer[ctr][ctr2] | 15);
          buffer[ctr][ctr2*2] -= (dbuffer[ctr][ctr2] & 15);
          buffer[ctr][ctr2*2+1] = (unsigned char)(((ctr*80)+ctr2)%64)+32;
          }
	buffer[ctr][ctr2*2] = 0;
	fprintf(hscr, "%s\n", buffer[ctr]);
        }
      }
    fclose(hscr);
    }
  else  {
    screen->FadeIn(FADE_SPEED);
    }
  tmp = key->GetAKey(SCREEN_DELAY);
  if((tmp == KEY_Q) || (tmp == KEY_ESC)) {
    screen->FadeOut(FADE_SPEED);
    delete screen;
    delete key;
    exit(0);
    }
  screen->FadeOut(FADE_SPEED);
  }

void menu()  {
  int tmp = 'o';
  while ((tolower(tmp) == 'o') && (tmp != 0))  {
    screen->FullScreenBMP(MENU_FN);
    screen->SetPalette(MENU_FN);
    screen->RefreshFull();
    screen->FadeIn(FADE_SPEED);
    Score = 0;
    tmp = key->GetAKey(SCREEN_DELAY * 2);
    if((tmp == KEY_ESC) || (tmp == KEY_Q))  {
      screen->FadeOut(FADE_SPEED);
      delete screen;
      delete key;
      exit(0);
      }
    if(tolower(tmp) == 'o')  {
      screen->FadeOut(FADE_SPEED);
      options();
      }
    else  if(tmp != 0)  {
      screen->FadeOut(FADE_SPEED);
      aa();
      }
    }
  }

void options()  {
  screen->Clear();
  screen->RefreshFull();
  screen->SetPaletteEntry(0, 0, 0, 0);
  screen->SetPaletteEntry(1, 0xFF, 0xFF, 0xFF);
  screen->SetPaletteEntry(7, 0xFF, 0, 0);
  int in = 0;
  int tmp = 0;
  int cpos = 0;
  while((tmp != KEY_ESC) && (tolower(tmp) != 'q'))  {
    screen->Clear();
    screen->Printf(0, 0, 0, 1, "\n\n\n\n\n\n");
    if(AUTO_BRAKING == 0)
      screen->Printf(0, 1, "       Don't Use Auto Braking\n");
    else
      screen->Printf(0, 1, "       Use Auto Braking      \n");
    screen->Printf(0, 1, "       Change Left Key\n");
    screen->Printf(0, 1, "       Change Right Key\n");
    screen->Printf(0, 1, "       Change Fire Key       \n");
    if(AUTO_BRAKING == 0)
      screen->Printf(0, 1, "       Change Brake Key\n");
    else
      screen->Printf(0, 1, "                       \n");
    screen->Printf(0, 1, "\n\n -ESC or Q to exit\n");
    screen->Printf(0, 1, " -Enter to manipulate current option\n");
    screen->Printf(0, 1, " -Arrow Keys to move\n");
    screen->Printf(20, 72+12*cpos, 0, 1, "->\n");
    if(in == 0)  {
      screen->FadeIn(FADE_SPEED);
      in = 1;
      }
    tmp = key->WaitForKey();
    if((tmp == KEY_UP) && (cpos > 0))  {
      screen->Printf(20, 72+12*cpos, 0, 1, "  \n");
      cpos--;
      }
    else  if((tmp == KEY_DOWN) && (cpos < (4-AUTO_BRAKING)))  {
      screen->Printf(20, 72+12*cpos, 0, 1, "  \n");
      cpos++;
      }
    else  if(tmp == KEY_ENTER || tmp == KEY_RETURN)  {
      if(cpos == 0)  AUTO_BRAKING = (1 - AUTO_BRAKING);
      else  if(cpos == 1)  {
        screen->Clear();
	screen->Printf(60, 120, 0, 1, "Press the new left key.\n");
	CONTROL_LEFT = key->WaitForKey();
	}
      else  if(cpos == 2)  {
        screen->Clear();
	screen->Printf(60, 120, 0, 1, "Press the new right key.\n");
	CONTROL_RIGHT = key->WaitForKey();
	}
      else  if(cpos == 3)  {
        screen->Clear();
	screen->Printf(60, 120, 0, 1, "Press the new fire key.\n");
	CONTROL_FIRE = key->WaitForKey();
	}
      else  if(cpos == 4)  {
        screen->Clear();
	screen->Printf(60, 120, 0, 1, "Press the new brake key.\n");
	CONTROL_BRAKE = key->WaitForKey();
	}
      }
    }
  screen->FadeOut(FADE_SPEED);
  saveconf();
  }

void aa()  {
  key->DisableQueue();
  Score = 0;
  enemies = new Aliens(MAX_ENEMIES);
  char tmp, stpal[3] = { 0xFF, 0xBF, 0x7F };
  int ctr, stctr = TWINKLE_TIME;
  int en=1, timeout = 100;
  IntList damm;
  volatile int px = 10;
  int deathstage = 0;
  int pxx = 0;
  int plife = PLAYER_LIFE, pc=0xFF, pctr=0, pinj = 0;
  screen->SetPaletteEntry(1, 0xFF, 0xFF, 0xFF);
  screen->SetPaletteEntry(2, 0xFF, 0, 0);
  screen->SetPaletteEntry(10, stpal[0], stpal[0], stpal[0]);
  screen->SetPaletteEntry(11, stpal[1], stpal[1], stpal[1]);
  screen->SetPaletteEntry(12, stpal[2], stpal[2], stpal[2]);
  for(ctr = 0; ctr < 16; ctr++)  shq[ctr] = 0;
  shotgraph = new Graphic(2, 8);
  for(ctr = 0; ctr < 8; ctr++)  shotgraph->DefLinH("0202");
  screen->MakeFriendly(shotgraph);

  screen->Clear();
  screen->RefreshFull();
  pl = new Sprite();
  pl->DefSize(36, 18);
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("--------------------------------01010101--------------------------------");
  pl->DefLinH("----------------------------0101010101010101----------------------------");
  pl->DefLinH("--------------------01010101010101010101010101010101--------------------");
  pl->DefLinH("--01010101010101010101010101010101010101010101010101010101010101010101--");
  pl->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  pl->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  pl->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  pl->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  pl->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  defdeath();
  screen->MakeFriendly(pl);
  pl->Move(px, py);
  screen->SetPoint(106, 100, 10);
  screen->SetPoint(10, 110, 11);
  screen->SetPoint(150, 50, 12);
  screen->SetPoint(250, 80, 10);
  screen->SetPoint(280, 10, 11);
  screen->SetPoint(46, 40, 12);
  screen->Refresh();
  screen->FadeIn(FADE_SPEED);
  enemies->newalien(150, 0, 0, 1);
  screen->Refresh();
  while((!(key->IsPressed(KEY_Q))) && 
	(!(key->IsPressed(KEY_ESC))) && 
	(((plife > 0) && (en > 0)) ||(timeout > 0)))  {
    px += pxx;
    if(pxx != 0)  {
      if(px < 0)  {
	px = 0;
	pxx = 0;
	}
      if(px > (screen->XSize() - 42))  {
	px = (screen->XSize() - 42);
	pxx = 0;
	}
      pl->Move(px, py);
      }
    damm = enemies->update();
    en = enemies->num();
    if(plife < 0)  {
      if(deathstage == 0)  plboom->Play();
      if((deathstage < 20) && (death[deathstage] != NULL))  {
	pl->SetImage(death[deathstage]);
	pl->Move(px, py);
	}
      deathstage++;
      }
    if((plife > 0) && (damm == pl->Number()) && (pinj < 1))  {
      plife--;
      if(plife < 1)  pl_die->Play();
      else  pl_ow->Play();
      pinj = SHUDDER_TIME + 1;
      pctr = 0;
      pc = 0xFF;
      }
    if((plife > -1) && (pinj > 0))  {
      pctr--;
      if(pctr < 1)  {
	pinj--;
	if((pinj == 0) && (plife == 0))  plife = -1;
	pctr = SHUDDER_DELAY;
	if((pinj < 1) || (pc == 0))  pc = 0xFF;
	else  pc = 0;
        screen->SetPaletteEntry(1, 0xFF, (char)pc, (char)pc);
	}
      }
    screen->Printf(0, 0, 0, 1, "Tanks: %d", plife > 0 ? plife : 0);
    if(Score > 0) screen->Printf(100, 0, 0, 1, "Score: %ld", Score);
    screen->Refresh();
    screen->ClearArea(0, 0, 320, 12);
    if(plife > 0)  {
      if(key->IsPressed(CONTROL_LEFT) || joy->IsPressed(JS_AXIS + 0) < 0)
	{ pxx--; if(pxx < -2)  pxx = -2;  }
      else if(key->IsPressed(CONTROL_RIGHT) || joy->IsPressed(JS_AXIS + 0) > 0)
	{ pxx++; if(pxx > 2)  pxx = 2;  }
      else if((key->IsPressed(CONTROL_BRAKE) || joy->IsPressed(JS_AXIS + 1))
		|| (AUTO_BRAKING != 0))
	{ pxx = 0; }
      if(key->IsPressed(CONTROL_FIRE) || joy->Buttons())  fire(px);
      }
    upfire();
    tmp = stpal[0];
    stpal[0] = stpal[1];
    stpal[1] = stpal[2];
    stpal[2] = tmp;
    stctr--;
    if(stctr < 1)  {
      screen->SetPaletteEntry(10, stpal[0], stpal[0], stpal[0]);
      screen->SetPaletteEntry(11, stpal[1], stpal[1], stpal[1]);
      screen->SetPaletteEntry(12, stpal[2], stpal[2], stpal[2]);
      stctr = TWINKLE_TIME;
      }
    if((plife < 1) || (en < 1))  timeout--;
    }
  delete pl;
  enemies->deleteall();
  delete enemies;
  screen->FadeOut(FADE_SPEED);
  key->EnableQueue();
  }

void fire(int px)  {
  if(!(shqp < MAX_SHOTS))  return;
  if(lastfire < SHOT_DELAY)  return;
  zap->Play();
  Score -= 50;
  lastfire = 0;
  sht[shqp] = new Sprite();
  sht[shqp]->SetImage(shotgraph);
  shx[shqp] = px + 17;
  shy[shqp] = py - 8;
  sht[shqp]->Move(shx[shqp], shy[shqp]);
  shq[shqp] = 1;
  shqp = 0;
  while(shq[shqp] != 0)  shqp++;
  }

void upfire()  {
  int ctr, ctr2;
  IntList hit;
  lastfire++;
  for(ctr = 0; ctr < MAX_SHOTS; ctr++)  if(shq[ctr] != 0)  {
    int contact=0;
    shy[ctr] -= 8;
    if(shy[ctr] < 0)  delfire(ctr);
    else  {
      hit = sht[ctr]->CMove(shx[ctr], shy[ctr]);
      for(ctr2 = 0; (ctr2 < (int)hit.GetSize()); ctr2++)  {
	enemies->hitalien(hit[ctr2]);
	contact = 1;
	}
      if(contact) delfire(ctr);
      }
    }
  }
	
void delfire(int spn)  {
  delete sht[spn];
  shq[spn] = 0;
  if(shqp > spn)  shqp = spn;
  }
