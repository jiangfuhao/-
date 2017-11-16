#include"game.h"
int map_game(int *map_h)
{

    int a,b;
    a=*map_h-DISPLAY_H;
    b=*map_h;
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_bitmap(setting[2],0,a,0);
    al_draw_bitmap(setting[2],0,b,0);
    if(*map_h==DISPLAY_H)
    {
        *map_h=0;
    }
    return 0;

}
