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
int init_xboss(XBOSS xb[],BOSS_Blast xb_blast[])
{
    init_xb_blast(xb_blast);
    int t=rand()%2;
    float heading;
    int x;
    if(t==1)
    {
        x=0;
        heading=-1.5;

    }else{
        x=DISPLAY_W;
        heading=1.5;
    }
    int ratation=rand()%300;
    int y=200+rand()%(int)(DISPLAY_H/4.0);
    for(int i=0;i<XBOSS_number;i++)
    {
        //printf("%d\n",i);
       xb[i].sx=x;
       xb[i].sy=y;
       xb[i].heading=heading;
       xb[i].twist=-xb[i].heading;
       xb[i].rot_velocity = 0.025;
       xb[i].gone=2;
       xb[i].live=2;
       xb[i].xy=0;
       xb[i].TX=10;
       xb[i].s_time=0;
       xb[i].speed=3;
       xb[i].fly_mode=0;
       xb[i].ratation=ratation;
       if(heading==-1.5)
       {
           x=x-80;
       }
       else
       {
           x=x+80;
       }
    }

    return 0;
}
int Draw_xboss(XBOSS *xb,BOSS_Blast *xb_bl,Spaceship *s)
{

        al_identity_transform(&transform);
        al_rotate_transform(&transform,xb->heading);
        al_translate_transform(&transform,xb->sx,xb->sy);
        al_use_transform(&transform);
        if(xb->gone==1)
        {

           if(xb->TX!=0)
           {

               //printf("%d\n",xb->TX);
               al_draw_bitmap(baoz_xb[10-xb->TX],-30,-30,0);
               xb->s_time=xb->s_time+5;
               if(xb->s_time==10)
               {
                  xb->TX=xb->TX-1;;
                  xb->s_time=0;
               }

           }
           if(xb->TX==0)xb->gone=0;
        }
        else if(xb->gone==2)
        {

            al_draw_bitmap(xboss,-30,-30,0);
            Move_xboss(xb,xb_bl,s);
        }
    return 0;
}
int Move_xboss(XBOSS *xb,BOSS_Blast *xb_blast,Spaceship *s)
{

        if(xb->gone==2)
        {
            if(xb->sx>300&&xb->sx<800&&xb->heading<(-xb->twist+(xb->rot_velocity*250)))
            {

                xb->fly_mode=1;
            }
            if(xb->fly_mode==1)
            {
                if(xb_blast->gone==0)
                {
                    lord_xb_blast(xb,xb_blast,s);
                }
                xb->heading+=xb->rot_velocity;
                xb->sx -= xb->speed * sin(xb->heading);
                xb->sy += xb->speed * cos(xb->heading);
                if(xb->heading>=(-xb->heading+(xb->rot_velocity*300)))
                {
                    xb->fly_mode=0;
                }
            }
            else
            {

                xb->sx -= xb->speed * sin(xb->heading);
                xb->sy += xb->speed * cos(xb->heading);
            }

        }

}

int Scope_xboss(XBOSS *xb)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    for(int i=0;i<XBOSS_number;i++)
    {
        if(xb->sx>2*DISPLAY_W)
        {
            xb->gone=0;
        }
    }
    return 0;
}
int hit_ship_xb(Spaceship *s,XBOSS xb[],BOSS_Blast xb_blast[])
{


    for(int i=0;i<XBOSS_number;i++)
    {

        if(xb[i].gone!=0)
        {
            if(xb[i].gone==2)
            {
                if(s->sx>xb[i].sx-30&&s->sx<xb[i].sx+30)
                {
                    if(s->sy>xb[i].sy-30&&s->sy<xb[i].sy+20)
                    {
                        //printf("sx:%f,sy:%f,x,%f,y:%faa\n",s->sx,s->sy,xb[i].sx,xb[i].sy);
                        if(s->pro==0)
                        {
                             s->live=s->live-10;
                        }

                        xb[i].gone=1;
                    }
                }
            }
            Scope_xboss(&xb[i]);
            Draw_xboss(&xb[i],&xb_blast[i],s);

        }
    }
    return 0;
}
int judge_xboss(XBOSS xb[])
{
    for(int i=0;i<XBOSS_number;i++)
    {
        if(xb[i].gone!=0)
        {
            return 1;
        }

    }
    return 0;
}
