#include"game.h"
int Init_star(Asteroid *c)
{
    c->sx = rand() % DISPLAY_W;
    c->sy = rand() % DISPLAY_H;
    c->heading = (rand() % (int)(atan(1) * 8));
    c->twist = (rand() % (int)(atan(1) * 8));
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

        al_draw_bitmap(setting[1],-30,-30,0);
        move_star(c);
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
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    if(c->sx+35<0)
    {
        c->sx=c->sx+DISPLAY_W;
    }
    if(c->sy+37<0)
    {
        c->sy=c->sy+DISPLAY_H;
    }
    if(c->sx+35>DISPLAY_W)
    {
        c->sx=c->sx-DISPLAY_W;
    }
    if(c->sy+37>DISPLAY_H)
    {
        c->sy=c->sy-DISPLAY_H;
    }

    return 0;
}
int hit_star(Asteroid comet[],int *time_star1,Spaceship *ship)//彗星撞飞船
{
    for (int i=0;i<comet_lives;i++)             //画彗星
    {

        if(comet[i].gone!=0)
        {
            if(comet[i].gone==2)
            {
                if(ship->sx<=comet[i].sx+25&&ship->sx>=comet[i].sx-25) //彗星撞飞船
                {
                    if (ship->sy<=comet[i].sy+25&&ship->sy>=comet[i].sy-25)
                    {
                        if(ship->pro==0)
                        {
                        ship->live=ship->live-10;
                        }
                        comet[i].gone=1;
                    }
                }
            }

            Scope_star(&comet[i]);
            Draw_star(&comet[i]);

        }
        else if(comet[i].gone==0)
        {

            *time_star1=*time_star1+1;
            if(*time_star1==500)
            {
                Init_star(&comet[i]);
                *time_star1=0;
            }
        }

    }
}

