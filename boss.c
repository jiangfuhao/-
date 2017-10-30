#include "game.h"
int init_boss(BOSS1 *boss)
{
    boss->sx = DISPLAY_W/2.0-150;
    boss->sy = 2.0;
    boss->live = 100;
    boss->gone = 1;
    boss->speed=1.0;
    boss->xy = 0;
    boss->heading = 0.0;
    return 0;

}
int Draw_boss(BOSS1 *boss)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_bitmap(setting[5],boss->sx,boss->sy,0);

    al_draw_rectangle(boss->sx+100,boss->sy,boss->sx+200,boss->sy+5,yellow,3.0);
    al_draw_filled_rectangle(boss->sx+100,boss->sy,boss->sx+100+boss->live,boss->sy+5,red);
    return 0;
}
int Move_boss(BOSS1 *boss)
{
    if(boss->sx==0)
    {
        boss->xy=0;
    }
    if(boss->sx+300==DISPLAY_W)
    {
        boss->xy=1;
    }
    if(boss->xy==0)
    {
         boss->sx=boss->sx+1;
    }
    else if(boss->xy==1)
    {
        boss->sx=boss->sx-1;
    }


    return 0;
}
