#include"game.h"
int bomb(Asteroid *c,int time_bomb)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    if(time_bomb!=9){
        al_draw_bitmap(baoz[time_bomb],c->sx,c->sy,0);
        time_bomb++;
        if(time_bomb==9)
        {
            time_bomb=0;
        }
    }
}
