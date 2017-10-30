#include"game.h"
int Init_star(Asteroid *c)
{
    c->sx = rand() % DISPLAY_W;
    c->sy = rand() % DISPLAY_H;
    c->heading = (rand() % (int)(atan(1) * 4));
    c->twist = (rand() % (int)(atan(1) * 4));
    c->speed = 1.0;
    c->rot_velocity = 0.1;
    c->scale = 1;
    c->gone =2;
    c->color =  al_map_rgb(80, 100, 100);
    c->TX=9;
    c->s_time=0;
    return 0;
}
int Draw_star(Asteroid *c)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,c->twist);
    al_translate_transform(&transform,c->sx,c->sy);
    al_use_transform(&transform);
    if(c->gone==1)
    {
       if(c->TX!=0)
       {

           //printf("%d\n",c->TX);
           al_draw_bitmap(baoz[9-c->TX],-100,-100,0);
           c->s_time=c->s_time+5;
           if(c->s_time==10)
           {
              c->TX=c->TX-1;;
              c->s_time=0;
           }

       }
       if(c->TX==0)c->gone=0;
    }
    else if(c->gone==2)
    {

        al_draw_bitmap(setting[2],-30,-30,0);
    }

    /*al_draw_line(-20 * c->scale,20* c->scale,-25* c->scale,5 * c->scale,c->color,2.0f);
    al_draw_line(-25 * c->scale,5 * c->scale,-25 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(-25 * c->scale,-10 * c->scale,-5 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(-5 * c->scale,-10 * c->scale,-10 * c->scale,-20 * c->scale,c->color,2.0f);
    al_draw_line(-10 * c->scale,-20 * c->scale,5 * c->scale,-20 * c->scale,c->color,2.0f);
    al_draw_line(5 * c->scale,-20 * c->scale,20 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,-10 * c->scale,20 * c->scale,-5 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,-5 * c->scale,0 * c->scale,0 * c->scale,c->color,2.0f);
    al_draw_line(0 * c->scale,0 * c->scale,20 * c->scale,10 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,10 * c->scale,10 * c->scale,20 * c->scale,c->color,2.0f);
    al_draw_line(10 * c->scale,20 * c->scale,0 * c->scale,15 * c->scale,c->color,2.0f);
    al_draw_line(0 * c->scale,15 * c->scale,-20 * c->scale,20 * c->scale,c->color,2.0f);*/
    return 0;
}
int move_star(Asteroid *c)
{
    if(c->gone==2)
    {
        c->twist += c->rot_velocity;
        c->sx += c->speed * sin(c->heading);
        c->sy -= c->speed * cos(c->heading);
    }
    return 0;
}
int Scope_star(Asteroid *c)
{
    if(c->sx<=0||c->sy<=0||c->sx>=DISPLAY_W||c->sy>=DISPLAY_H) c->heading = (rand() % (int)(atan(1) * 8));
    return 0;
}
