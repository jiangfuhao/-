#include"game.h"
int music_game(int i,float choose)
{

    //音频文件载入

    if(i==0)
    {

        al_play_sample(sample[0],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);//龙吼
    }
    else if(i==1)
    {
        //al_destroy_sample(sample[3]);
        //al_destroy_sample(sample[2]);
        al_play_sample(sample[1],1.0,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);//界面

    }
    else if(i==2)
    {

        //al_destroy_sample(sample[1]);
        //al_destroy_sample(sample[3]);
        al_play_sample(sample[2],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);//对战
    }
    else if(i==3)
    {
        //al_destroy_sample(sample[1]);
        //al_destroy_sample(sample[2]);
        al_play_sample(sample[3],1.0,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);//boss
    }
    return 0;
}
