#include <stdlib.h>

#include "../user/user.h"

extern int deathxoff[20];
extern int deathyoff[20];
extern Graphic *death[20];
extern Screen *screen;

void defdeath()  {
  death[2] = NULL;
  death[3] = NULL;
  death[4] = NULL;
  death[5] = NULL;
  death[6] = NULL;
  death[7] = NULL;
  death[8] = NULL;
  death[9] = NULL;
  death[10] = NULL;
  death[11] = NULL;
  death[12] = NULL;
  death[13] = NULL;
  death[14] = NULL;
  death[15] = NULL;
  death[16] = NULL;
  death[17] = NULL;
  death[18] = NULL;
  death[19] = NULL;

  death[0] = new Graphic(36, 18);
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("--------------------------------01010101--------------------------------");
  death[0]->DefLinH("----------------------------0101010505010101----------------------------");
  death[0]->DefLinH("--------------------01010101010105050505010101010101--------------------");
  death[0]->DefLinH("--01010101010101010101010101010105050505010101010101010101010101010101--");
  death[0]->DefLinH("010101010101010101010101010101010105050101010101010101010101010101010101");
  death[0]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  death[0]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  death[0]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  death[0]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  screen->MakeFriendly(death[0]);

  death[1] = new Graphic(36, 18);
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01010101--------------------------------");
  death[1]->DefLinH("--------------------------------01050501--------------------------------");
  death[1]->DefLinH("-----------------------------015050505050501----------------------------");
  death[1]->DefLinH("--------------------------01050505060605050501--------------------------");
  death[1]->DefLinH("--------------------01010105050506060606050505010101--------------------");
  death[1]->DefLinH("--01010101010101010101010105050506060606050505010101010101010101010101--");
  death[1]->DefLinH("010101010101010101010101010105050506060505050101010101010101010101010101");
  death[1]->DefLinH("010101010101010101010101010101050505050505010101010101010101010101010101");
  death[1]->DefLinH("010101010101010101010101010101010105050101010101010101010101010101010101");
  death[1]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  death[1]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  screen->MakeFriendly(death[1]);

  death[2] = new Graphic(36, 18);
  death[2]->DefLinH("----------------------------------01010101------------------------------");
  death[2]->DefLinH("----------------------------------01010101------------------------------");
  death[2]->DefLinH("----------------------------------01010101------------------------------");
  death[2]->DefLinH("----------------------------------01010101------------------------------");
  death[2]->DefLinH("--------------------------------01010101--------------------------------");
  death[2]->DefLinH("--------------------------------01010101--------------------------------");
  death[2]->DefLinH("--------------------------------01010101--------------------------------");
  death[2]->DefLinH("--------------------01--------010505050501--------------------------------");
  death[2]->DefLinH("------------------------------050506060505------------------------------");
  death[2]->DefLinH("--------------------------05050606060606060505------01------------------");
  death[2]->DefLinH("------------------------050506060607070506060505------------------------");
  death[2]->DefLinH("--------------------01050506060607070707060606050501--------------------");
  death[2]->DefLinH("--01010101010101010101050506060607070707060606050501010101010101010101--");
  death[2]->DefLinH("010101010101010101010105050506060607070606060505050101010101010101010101");
  death[2]->DefLinH("010101010101010101010101050505060606060606050505010101010101010101010101");
  death[2]->DefLinH("010101010101010101010101010505050506060505050501010101010101010101010101");
  death[2]->DefLinH("010101010101010101010101010101050505050505010101010101010101010101010101");
  death[2]->DefLinH("010101010101010101010101010101010101010101010101010101010101010101010101");
  screen->MakeFriendly(death[2]);

  death[3] = new Graphic(36, 18);
  death[3]->DefLinH("------------------------------------------------------------------------");
  death[3]->DefLinH("--------------------------------------01010101--------------------------");
  death[3]->DefLinH("--------------------------------------01010101--------------------------");
  death[3]->DefLinH("------------------------------------01010101----------------------------");
  death[3]->DefLinH("------------------------------------01010101----------------------------");
  death[3]->DefLinH("----01----------------------------01010101------------------------------");
  death[3]->DefLinH("----------------------------------01010101------------------------------");
  death[3]->DefLinH("--------------------050505----0106060606010505--------------------------");
  death[3]->DefLinH("------------------0505050505--06060707060605050505--------------------");
  death[3]->DefLinH("--------------01050505050506060707070707070606050505------------------");
  death[3]->DefLinH("----------0101010505050506060707070707070707060605050505--01------------");
  death[3]->DefLinH("------0101010105050505060607070707070707070707060605050505--------------");
  death[3]->DefLinH("--01010101010105050505060607070707070707070707060605050101010101010101--");
  death[3]->DefLinH("010101010101010105050506060607070707070707070606060501010101010101010101");
  death[3]->DefLinH("010101010101010101050505060606070707070707060606050501010101010101010101");
  death[3]->DefLinH("010101010101010101010505050606060607070606060605050501010101010101010101");
  death[3]->DefLinH("010101010101010101010105050505060606060606050505050101010101010101010101");
  death[3]->DefLinH("010101010101010101010101050505050505050505050505050101010101010101010101");
  screen->MakeFriendly(death[3]);

  death[4] = new Graphic(36, 18);
  death[4]->DefLinH("------------------------------------------------------------------------");
  death[4]->DefLinH("------------------------------------------------------------------------");
  death[4]->DefLinH("----------------------------------------01010101------------------------");
  death[4]->DefLinH("--------------------------------05050501010101--------------------------");
  death[4]->DefLinH("----------------------------050505050505050505--------------------------");
  death[4]->DefLinH("----------------------05050505050505050505050505------------------------");
  death[4]->DefLinH("------------------0505050505050606060606060505050505--------------------");
  death[4]->DefLinH("----------------05050505050606060606060606060605050505------------------");
  death[4]->DefLinH("--------------05050505050606060606070706060606060505050505------------");
  death[4]->DefLinH("------------050505050506050606070707070707060606060505050505----------");
  death[4]->DefLinH("----------0505050505060606060707070707070707060606060505050505----------");
  death[4]->DefLinH("------0101050505050606060607070707070707070707060606060505050505--------");
  death[4]->DefLinH("--01010101050505050606060607070707070707070707060606060505050505010101--");
  death[4]->DefLinH("010101010505050505060606060607070707070707070606060606050505050501010101");
  death[4]->DefLinH("010101010505050505050606060606070707070707060606060605050505050501010101");
  death[4]->DefLinH("010101010505050505050506060606060607070606060606060505050505050501010101");
  death[4]->DefLinH("010101010505050505050505060606060606060606060606050505050505050501010101");
  death[4]->DefLinH("010101010105050505050505050606060606060606060605050505050505050501010101");
  screen->MakeFriendly(death[4]);

  death[5] = new Graphic(36, 18);
  death[5]->DefLinH("------------------------------------------------------------------------");
  death[5]->DefLinH("------------------------------------------------------------------------");
  death[5]->DefLinH("----------------------------------------01010101------------------------");
  death[5]->DefLinH("----------------------------050505050505050505--------------------------");
  death[5]->DefLinH("----------------------0505050506060606060606050505----------------------");
  death[5]->DefLinH("----------------050505050505060606060606060606060505--------------------");
  death[5]->DefLinH("--------------050505050505060606060606060606060606050505----------------");
  death[5]->DefLinH("------------050505050505060606060706060606060606060605050505------------");
  death[5]->DefLinH("----------050505050505060606070707070706060606060606050505050505--------");
  death[5]->DefLinH("--------0505050505050606050707070707070707060606060505050505050505------");
  death[5]->DefLinH("------0505050505050606060607070707070707070706060606050505050505050505--");
  death[5]->DefLinH("------0505050505060606060707070707070707070707060606060505050505050505--");
  death[5]->DefLinH("--0105050505050506060606070707070707070707070706060606050505050505050505");
  death[5]->DefLinH("010105050505050506060607070707070707070707070606060606050505050505050505");
  death[5]->DefLinH("010505050505050506060606070707070707070707070606060606050505050505050505");
  death[5]->DefLinH("010505050505050505060606060707070707070707070606060605050505050505050505");
  death[5]->DefLinH("010505050505050505050606060607070707070707060606060606050505050505050505");
  death[5]->DefLinH("010105050505050505050506060606070707070707060606060605050505050505050501");
  screen->MakeFriendly(death[5]);

  death[6] = new Graphic(36, 18);
  death[6]->DefLinH("------------------------------------------------------------------------");
  death[6]->DefLinH("--------------------------------060606----------------------------------");
  death[6]->DefLinH("------------------------------0607070706--------------------------------");
  death[6]->DefLinH("----------------------------050506060605050505--------------------------");
  death[6]->DefLinH("----------------------0505050506060606060606050505----------------------");
  death[6]->DefLinH("----------------050505050505060606060606060606060505--------------------");
  death[6]->DefLinH("--------------050505050505070707070707070606060606050505----------------");
  death[6]->DefLinH("------------05050505050507070707--07070707060606060605050505------------");
  death[6]->DefLinH("----------050505050505070707----------07070706060606050505050505--------");
  death[6]->DefLinH("--------050505050505070707----------------070707060505050505050505------");
  death[6]->DefLinH("------05050505050507070707------------------070707070505050505050505----");
  death[6]->DefLinH("------050505050507070707----------------------070707060505050505050505--");
  death[6]->DefLinH("----05050505050507070707----------------------070707060505050505050505--");
  death[6]->DefLinH("--05050605050505070707----------------------0707070706050505050505050505");
  death[6]->DefLinH("--0506060505050507070707--------------------0707070606050505050505050505");
  death[6]->DefLinH("--050606050505050507070707------------------0707070605050505050505050505");
  death[6]->DefLinH("--05060605050505050507070707--------------0707070606060505050505050505--");
  death[6]->DefLinH("----05060606060606060607070707------------0707070606050505050505050505--");
  screen->MakeFriendly(death[6]);

  death[7] = new Graphic(36, 18);
  death[7]->DefLinH("------------------------------------------------------------------------");
  death[7]->DefLinH("--------------------------------050505----------------------------------");
  death[7]->DefLinH("------------------------------0506060605--------------------------------");
  death[7]->DefLinH("--------------------------------050505----------------------------------");
  death[7]->DefLinH("------------------------------050505050505------------------------------");
  death[7]->DefLinH("--------------------------050505050505050505----------------------------");
  death[7]->DefLinH("----------------------0505070707070707070606050505----------------------");
  death[7]->DefLinH("--------------------050506060606--070707070605050505--------------------");
  death[7]->DefLinH("--------------------------------------06060605050505--------------------");
  death[7]->DefLinH("--------------0505050606------------------06060606050505----------------");
  death[7]->DefLinH("----------0505050507070706------------------06060606050505--------------");
  death[7]->DefLinH("----------05050507070706----------------------0606060605050505----------");
  death[7]->DefLinH("--------0505050507070706----------------------06060606050505050505------");
  death[7]->DefLinH("------0605050505070706----------------------060606060605050505050505----");
  death[7]->DefLinH("------060505050507070706--------------------060606060605050505050505----");
  death[7]->DefLinH("------06050505050507070706------------------060606060505050505050505----");
  death[7]->DefLinH("--------05050505050507070706--------------060606060606050505050505------");
  death[7]->DefLinH("----------06060606060607070706------------0606060606050505050505--------");
  screen->MakeFriendly(death[7]);
  
  death[8] = new Graphic(36, 18);
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("--------------------------------050505----------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("--------------------------060606060606060-------------------------------");
  death[8]->DefLinH("----------------------------------06060606------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("------------------------------------------------------------------------");
  death[8]->DefLinH("--------------0505060606--------------------------0505------------------");
  death[8]->DefLinH("------------0505060606--------------------------0505050505--------------");
  death[8]->DefLinH("------------0505060706--------------------------050506050505------------");
  death[8]->DefLinH("------------0505060706------------------------0505060605050505----------");
  death[8]->DefLinH("------05----050506070706----------------------0505060605050505----------");
  death[8]->DefLinH("------------050505060707----------------------0505060505050505----------");
  death[8]->DefLinH("--------------0505050606------------------------050506050505------------");
  death[8]->DefLinH("----------------06060606--------------------------05050505--------------");
  screen->MakeFriendly(death[8]);
  
  death[9] = new Graphic(36, 18);
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("----------------------------------0606----------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("----------------------------------------------------05------------------");
  death[9]->DefLinH("--------------------0706--------------------------0505------------------");
  death[9]->DefLinH("--------------------06------------------------------05------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  death[9]->DefLinH("------------------------------------------------------------------------");
  screen->MakeFriendly(death[9]);
  
  death[10] = new Graphic(36, 18);
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  death[10]->DefLinH("------------------------------------------------------------------------");
  screen->MakeFriendly(death[10]);
  }
