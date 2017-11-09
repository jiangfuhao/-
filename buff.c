#include"game.h"
int Init_buff(BUFF *buff)
{
   buff->sx = rand() % (DISPLAY_W/2);
   buff->sy = rand() % (DISPLAY_H/2);
   buff->heading = (rand() % (int)(atan(1) * 8));
   buff->twist = (rand() % (int)(atan(1) * 8));
   buff->speed = 1.0;
   buff->rot_velocity = 0.1;
   buff->scale = 1;
   buff->gone =2;
   buff->XG=rand()%5;
   buff->s_time=0;
    return 0;
}

int SHIP_buff(Spaceship *ship,BUFF *buff)
{
    if(buff->gone==2)
    {

        Draw_buff(buff);
        move_buff(buff);
        Scope_buff(buff);
        if(ship->sx<=buff->sx+25&&ship->sx>=buff->sx-25) //彗星撞飞船
        {
            if (ship->sy<=buff->sy+25&&ship->sy>=buff->sy-25)
            {
                buff_XG(ship,buff);
                buff->gone=1;
            }
        }
    }

}
int Draw_buff(BUFF *buff)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,buff->twist);
    al_translate_transform(&transform,buff->sx,buff->sy);
    al_use_transform(&transform);

    if(buff->gone==2)
    {

            al_draw_bitmap(buffs[buff->XG],-30,-30,0);


    }
}
int move_buff(BUFF *buff)
{
    if(buff->gone==2)
    {
        buff->twist += buff->rot_velocity;
        buff->sx += buff->speed * sin(buff->heading);
        buff->sy -= buff->speed * cos(buff->heading);
    }
    return 0;
}
int Scope_buff(BUFF *buff)
{

    if(buff->sx+35<0)
    {
        buff->sx=buff->sx+DISPLAY_W;
    }
    else if(buff->sy+37<0)
    {
        buff->sy=buff->sy+DISPLAY_H;
    }
    else if(buff->sx+35>DISPLAY_W)
    {
        buff->sx=buff->sx-DISPLAY_W;
    }
    else if(buff->sy+37>DISPLAY_H)
    {
        buff->sy=buff->sy-DISPLAY_H;
    }

    return 0;
}
int buff_XG(Spaceship *ship,BUFF *buff)
{
    if(buff->XG==4)
    {
        ship->pro=1;
    }
    else if(buff->XG==2)
    {
        ship->blast_mode=1;
    }
    else if(buff->XG==3)
    {
        if(100-ship->live>=20)
        {
            ship->live=ship->live+20;
        }
        else{
            ship->live=100;
        }
    }
    else if(buff->XG==1)
    {
        ship->blast_mode=2;;
    }
    else if(buff->XG==0)
    {
        ship->energy=100;
    }
}
