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
    boss->old_blast=0;
    boss->time_b=0;
    boss->blast_type=1;
    return 0;

}
int init_bs_blast(BOSS1 *boss,Spaceship *s)
{
    if(boss->blast_type==1)
    {
        if(boss->old_blast<=BOSSBlast_number)
        {

            int x=100;
            int y=0;
            int f=0;
            double r=-0.8;
            for(int i=boss->old_blast;i<boss->old_blast+10;i++)
            {
                // printf("y:%d,",y);
                boss->blast1[i].sx=boss->sx+100+x;
                boss->blast1[i].sy=boss->sy+230+y;
                boss->blast1[i].heading=count_head(boss->sx,boss->sy,s)+r;
                boss->blast1[i].speed=boss->speed*4;
                boss->blast1[i].gone=1;

                x=x-10;
                r=r+0.2;
                if(y==40||f==1)
                {
                    f=1;
                    if(x!=50)
                    {
                        y=y-10;
                    }

                }
                else
                {
                    y=y+10;
                }
            }
           // printf("\n");
            boss->old_blast=boss->old_blast+10;



        }
        if(boss->old_blast==BOSSBlast_number+10)
        {
            boss->old_blast=BOSSBlast_number;
            printf("%d\n",boss->old_blast);
        }
    }


    return 0;

}
double count_head(double x,double y,Spaceship *s)
{
    double heading=0;
    x=s->sx-x-150;

    y=s->sy-y-200;
    //heading =atan(x/y);
    /*if(y>0)
    {
        heading =atan(x/y);
    }
    else
    {
        heading =atan(y/x);
    }*/

    return 0;
}

int Draw_bs_blast(BOSS1 *boss)
{


    for(int i=0;i<=boss->old_blast;i++)
    {
        //printf("aaa;%d\n",boss->old_blast);
        if(boss->blast1[i].gone==1)
        {
            al_draw_bitmap(boss_blast[0],boss->blast1[i].sx-10,boss->blast1[i].sy-10,0);
            boss->blast1[i].sx += boss->blast1[i].speed * sin(boss->blast1[i].heading);
            boss->blast1[i].sy += boss->blast1[i].speed * cos(boss->blast1[i].heading);

        }
    }
    return 0;

}
int hit_ship(Spaceship *s,BOSS1 *b)
{

    for(int i=0;i<b->old_blast;i++)
    {
        if(b->blast1[i].gone==1)
        {
            if(b->blast1[i].sx>s->sx-35&&b->blast1[i].sx<=s->sx+35)
            {
                if(b->blast1[i].sy>s->sy-37&&b->blast1[i].sy<=s->sy+37)
                {
                    if(s->pro==0)
                    {
                         s->live--;
                    }

                    b->blast1[i].gone=0;
                }
            }
        }
    }

}

int Draw_boss(BOSS1 *boss,Spaceship *s)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_bitmap(setting[5],boss->sx,boss->sy,0);

    al_draw_rectangle(boss->sx+100,boss->sy,boss->sx+200,boss->sy+5,yellow,3.0);
    al_draw_filled_rectangle(boss->sx+100,boss->sy,boss->sx+100+boss->live,boss->sy+5,red);
    if(boss->old_blast!=0)
    {
        hit_ship(s,boss);
    }

    Move_boss(boss,s);
    return 0;
}
int Move_boss(BOSS1 *boss,Spaceship *s)
{

    boss->time_b++;
    if(boss->old_blast!=BOSSBlast_number)
    {
        if(boss->time_b==50)//释放子弹时间差
        {
           // printf("%d\n",boss->sx);


                init_bs_blast(boss,s);
                boss->time_b=0;


        }
    }else
    {
        if(boss->time_b==100)//释放子弹时间差
        {
           // printf("%d\n",boss->sx);


                boss->old_blast=0;
                boss->time_b=0;


        }
    }

    if(boss->old_blast!=0)
    {
         Draw_bs_blast(boss);
    }


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
int hit_boss(BOSS1 boss, struct Blast *blast_h)
{
    if(boss.gone==1)
    {
        if(blast_h->sx>=boss.sx+100&&blast_h->sx<=boss.sx+200) //子弹射中boss
        {
            if (blast_h->sy<=boss.sy+200&&blast_h->sy>=boss.sy)
            {

                return 1;
            }
            else
            {
                return 0;
            }

        }
    }
    else
    {
        return 0;
    }
}
