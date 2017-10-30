#include"game.h"
int music_game(int i,float choose)
{
    if(i==1)
    {
        al_play_sample(sample[0],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
    }
    else if(i==2)
    {

        al_play_sample(sample[1],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
    }
    return 0;
}
