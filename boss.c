#include "game.h"
int init_boss(BOSS1 *boss)
{
    boss->sx = DISPLAY_W/2.0-150;
    boss->sy = 2.0;
    boss->live = 100;
    boss->gone = 2;
    boss->speed=1.0;
    boss->xy = 0;
    boss->heading = 0.0;
    boss->old_blast=0;
    boss->time_b=0;
    boss->blast_type=1;
    boss->TX=10;
    boss->s_time=0;
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

            boss->old_blast=boss->old_blast+10;



        }
        if(boss->old_blast==BOSSBlast_number+10)
        {
            boss->old_blast=BOSSBlast_number;

        }
    }


    return 0;

}

int Draw_bs_blast(BOSS1 *boss)
{


    for(int i=0;i<=boss->old_blast;i++)
    {

        if(boss->blast1[i].gone==1)
        {
            al_draw_bitmap(boss_blast[0],boss->blast1[i].sx-10,boss->blast1[i].sy-10,0);
            boss->blast1[i].sx += boss->blast1[i].speed * cos(boss->blast1[i].heading);
            boss->blast1[i].sy += boss->blast1[i].speed * sin(boss->blast1[i].heading);

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

    if(boss->gone==1)
    {
       boss->live=1;                                      //防止一直加分
       if(boss->TX!=0)
       {


           al_draw_bitmap(boss_bz[10-boss->TX],boss->sx,boss->sy-50,0);
           boss->s_time=boss->s_time+2;
           if(boss->s_time==10)
           {
              boss->TX=boss->TX-1;;
              boss->s_time=0;
           }

       }

       if(boss->TX==0)boss->gone=0;

    }
    else if(boss->gone==2)
    {
        al_draw_bitmap(boss_image[0],boss->sx,boss->sy,0);
        al_draw_rectangle(boss->sx+100,boss->sy,boss->sx+200,boss->sy+5,yellow,3.0);
        al_draw_filled_rectangle(boss->sx+100,boss->sy,boss->sx+100+boss->live,boss->sy+5,red);
        if(boss->old_blast!=0)
        {
            hit_ship(s,boss);
        }

        Move_boss(boss,s);
    }
    return 0;
}

int Move_boss(BOSS1 *boss,Spaceship *s)
{

    boss->time_b++;
    if(boss->old_blast!=BOSSBlast_number)
    {
        if(boss->time_b==50)//释放子弹时间差
        {
                init_bs_blast(boss,s);
                boss->time_b=0;
        }
    }else
    {
        if(boss->time_b==300)//释放子弹时间差
        {



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
    if(boss.gone==2)
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

int init_xboss(XBOSS xb[],BOSS_Blast xb_blast[],int i)
{
    init_xb_blast(xb_blast);
    if(i==1)
    {
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
        double y=150+rand()%(DISPLAY_H/2);

        for(int i=0;i<XBOSS_number;i++)
        {

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
           xb[i].cylinder=1;
           if(heading==-1.5)
           {
               x=x-80;
           }
           else
           {
               x=x+80;
           }
        }
    }
    if(i==2)
    {
        for(int i=0;i<XBOSS_number;i++)
        {
           if(i==0)
           {
               xb[i].sx=300;
               xb[i].sy=-50;
               xb[i].heading=0;
           }
           else if(i==1)
           {
               xb[i].sx=400;
               xb[i].sy=0;
               xb[i].heading=0;
           }else if(i==2)
           {
               xb[i].sx=500;
               xb[i].sy=-50;
               xb[i].heading=0;
           }
           else if(i==3)
           {
               xb[i].sx=600;
               xb[i].sy=-50;
               xb[i].heading=0;
           }
           else if(i==4)
           {
               xb[i].sx=700;
               xb[i].sy=0;
               xb[i].heading=0;
           }else if(i==5)
           {
               xb[i].sx=800;
               xb[i].sy=-50;
               xb[i].heading=0;
           }
           else if(i==6)
           {
               xb[i].sx=0;
               xb[i].sy=rand()%500;
               xb[i].heading=-1.5;
           }
           else if(i==7)
           {
               xb[i].sx=0;
               xb[i].sy=rand()%300;
               xb[i].heading=-1.5;
           }
           else if(i==8)
           {
               xb[i].sx=DISPLAY_W;
               xb[i].sy=rand()%300;
               xb[i].heading=1.5;
           }
           else if(i==9)
           {
               xb[i].sx=DISPLAY_W;
               xb[i].sy=rand()%300;
               xb[i].heading=1.5;
           }
           xb[i].twist=-xb[i].heading;
           xb[i].rot_velocity = 0.025;
           xb[i].gone=2;
           xb[i].live=2;
           xb[i].xy=1;
           xb[i].TX=10;
           xb[i].s_time=0;
           xb[i].speed=3;
           xb[i].fly_mode=0;
           xb[i].ratation=0;
           xb[i].cylinder=1;
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

            al_draw_bitmap(xboss[xb->xy],-30,-30,0);
            Move_xboss(xb,xb_bl,s,xb->xy);
        }
    return 0;
}

int Move_xboss(XBOSS *xb,BOSS_Blast *xb_blast,Spaceship *s,int i)
{
    if(xb->xy==0)
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
                if(xb->heading>=(-xb->heading+(xb->rot_velocity*100)))
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
    else if(xb->xy==1)
    {
        xb->sx -= xb->speed * sin(xb->heading);
        xb->sy += xb->speed * cos(xb->heading);
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
        if(xb->sx>2*DISPLAY_W||xb->sy>2*DISPLAY_H||xb->sx<-DISPLAY_W||xb->sy<-DISPLAY_H)
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



int init_boss2(BOSS2 *boss)
{
    boss->sx = DISPLAY_W/2.0-150;
    boss->sy = 2.0;
    boss->live = 100;
    boss->gone = 2;
    boss->speed=1.0;
    boss->xy = 0;
    boss->heading = 0.0;
    boss->old_blast1=0;

    boss->time_b=0;
    boss->blast_type=1;
    boss->TX=10;
    boss->s_time=0;
    for(int i=0;i<BOSSBlast_number;i++)
    {
        boss->blast1[i].sx=0;
        boss->blast1[i].sy=0;
        boss->blast1[i].heading=0;
        boss->blast1[i].speed=0;
        boss->blast1[i].gone=2;
        boss->blast2[i].sx=0;
        boss->blast2[i].sy=0;
        boss->blast2[i].heading=0;
        boss->blast2[i].speed=0;
        boss->blast2[i].gone=2;
    }
    return 0;
}
int Move_boss2(BOSS2 *boss,Spaceship *s)
{

    boss->time_b++;
   // printf("%d\n",boss->time_b);
    if(boss->time_b==50)
    {
        if(boss->old_blast1!=BOSSBlast_number&&boss->blast_type==1)
        {

            init_bs_blast2(boss,s);
        }
        else if(boss->old_blast1==BOSSBlast_number)
        {



        }

        boss->time_b=0;

    }


        Scope_boss2_blast1(boss);
        Draw_bs_blast2_1(boss);
        Scope_boss2_blast2(boss);
        Draw_bs_blast2_2(boss);

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
int init_bs_blast2(BOSS2 *boss,Spaceship *s)
{

        if(boss->old_blast1<=BOSSBlast_number)
        {
            int xx=0;
            int x=100;
            int y=0;
            int f=0;
            double r=-0.8;
            for(int i=boss->old_blast1;i<boss->old_blast1+10;i++)
            {
                boss->blast2[i].sx=boss->sx+100+xx;
                boss->blast2[i].sy=boss->sy+230;
                boss->blast2[i].heading=count_head(boss->sx+100,boss->sy+230,s);
                boss->blast2[i].speed=boss->speed*5;
                boss->blast2[i].gone=1;

                boss->blast1[i].sx=boss->sx+100+x;
                boss->blast1[i].sy=boss->sy+230+y;
                boss->blast1[i].heading=count_head(boss->sx,boss->sy,s)+r;
                boss->blast1[i].speed=boss->speed*3;
                boss->blast1[i].gone=1;

                x=x-10;
                xx+=5;
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
            boss->old_blast1=boss->old_blast1+10;


        }
        if(boss->old_blast1==BOSSBlast_number+10)
        {
            boss->old_blast1=BOSSBlast_number;


        }
    return 0;

}
int Draw_boss2(BOSS2 *boss,Spaceship *s)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);

    if(boss->gone==1)
    {
       boss->live=1;                                      //防止一直加分
       if(boss->TX!=0)
       {


           al_draw_bitmap(boss_bz[10-boss->TX],boss->sx,boss->sy-50,0);
           boss->s_time=boss->s_time+2;
           if(boss->s_time==10)
           {
              boss->TX=boss->TX-1;;
              boss->s_time=0;
           }

       }

       if(boss->TX==0)boss->gone=0;

    }
    else if(boss->gone==2)
    {
        al_draw_bitmap(boss_image[1],boss->sx,boss->sy,0);
        al_draw_rectangle(boss->sx+100,boss->sy,boss->sx+200,boss->sy+5,yellow,3.0);
        al_draw_filled_rectangle(boss->sx+100,boss->sy,boss->sx+100+boss->live,boss->sy+5,blu);
        if(boss->old_blast1!=0)
        {
            hit_ship2(s,boss);
        }

        Move_boss2(boss,s);
    }
    return 0;
}
int hit_boss2(BOSS2 boss, struct Blast *blast_h)
{
    if(boss.gone==2)
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
int hit_ship2(Spaceship *s,BOSS2 *b)
{

    for(int i=0;i<b->old_blast1;i++)
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
    for(int i=0;i<b->old_blast1;i++)
    {
        if(b->blast2[i].gone==1)
        {
            if(b->blast2[i].sx>s->sx-35&&b->blast2[i].sx<=s->sx+35)
            {
                if(b->blast2[i].sy>s->sy-37&&b->blast2[i].sy<=s->sy+37)
                {
                    if(s->pro==0)
                    {
                         s->live--;
                    }

                    b->blast2[i].gone=0;
                }
            }
        }
    }
}
int Scope_boss2_blast1(BOSS2 *boss)
{

        for(int i=0;i<boss->old_blast1;i++)
        {
            if(boss->blast1[i].sx>2*DISPLAY_W||boss->blast1[i].sy>2*DISPLAY_H||boss->blast1[i].sx<-DISPLAY_W||boss->blast1[i].sy<-DISPLAY_H)
            {
                boss->blast1[i].gone=0;
            }
        }
        if(boss->blast1[BOSSBlast_number-2].gone==0)
        {
            boss->type=1;
            for(int i=0;i<BOSSBlast_number;i++)
            {
                boss->blast1[i].sx=0;
                boss->blast1[i].sy=0;
                boss->blast1[i].heading=0;
                boss->blast1[i].speed=0;
                boss->blast1[i].gone=2;

            }
            boss->old_blast1=0;
        }
}
int Scope_boss2_blast2(BOSS2 *boss)
{

    for(int i=0;i<boss->old_blast1;i++)
    {
        if(boss->blast2[i].sx>2*DISPLAY_W||boss->blast2[i].sy>2*DISPLAY_H||boss->blast2[i].sx<-DISPLAY_W||boss->blast2[i].sy<-DISPLAY_H)
        {
            boss->blast2[i].gone=0;
        }
    }
    if(boss->blast2[BOSSBlast_number-2].gone==0)
    {
        boss->type=0;
        for(int i=0;i<BOSSBlast_number;i++)
        {
            boss->blast2[i].sx=0;
            boss->blast2[i].sy=0;
            boss->blast2[i].heading=0;
            boss->blast2[i].speed=0;
            boss->blast2[i].gone=2;

        }
        boss->old_blast1=0;
    }

}

int Draw_bs_blast2_1(BOSS2 *boss)
{

    if(boss->old_blast1!=0)
    {
        for(int i=0;i<=boss->old_blast1;i++)
        {

            if(boss->blast1[i].gone==1)
            {
                al_draw_bitmap(boss_blast[0],boss->blast1[i].sx-10,boss->blast1[i].sy-10,0);
                boss->blast1[i].sx += boss->blast1[i].speed * cos(boss->blast1[i].heading);
                boss->blast1[i].sy += boss->blast1[i].speed * sin(boss->blast1[i].heading);

            }
        }
    }


    return 0;

}
int Draw_bs_blast2_2(BOSS2 *boss)
{


    if(boss->old_blast1!=0)
    {
        for(int i=0;i<=boss->old_blast1;i++)
        {

            if(boss->blast2[i].gone==1)
            {

                al_draw_bitmap(boss_blast[1],boss->blast2[i].sx-10,boss->blast2[i].sy-10,0);
                boss->blast2[i].sx += boss->blast2[i].speed * cos(boss->blast2[i].heading);
                boss->blast2[i].sy += boss->blast2[i].speed * sin(boss->blast2[i].heading);
            }
        }
    }


    return 0;

}
