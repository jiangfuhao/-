#include"game.h"
int Init_ship(Spaceship *s ,int i)
{
    s->sx = DISPLAY_W /2.0 ;
    s->sy = DISPLAY_H / 2.0 ;
    s->gone = false;
    s->heading=0;
    s->speed=1;
    s->live=100;
    s->energy=100;
    s->blast_mode=0;
    s->pro=1;
    s->type=i;
    s->yORn=0;
    s->TX=18;
    return 0;
}
int Draw_ship(Spaceship *s)
{

    al_identity_transform(&transform);
    al_rotate_transform(&transform,s->heading);
    al_translate_transform(&transform,s->sx,s->sy);
    al_use_transform(&transform);
    al_draw_bitmap(ship_imge[s->type],-27,-20,0);
    if(s->pro==1)
    {
        al_draw_bitmap(pro,-40,-40,0);
    }
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);

    al_draw_rectangle(1140,6,1240,12,red,3.0);
    al_draw_filled_rectangle(1140,6,1140+s->live,12,red);
    al_draw_text(font[3],red,1110,3,ALLEGRO_ALIGN_CENTRE,"生命值：");
    al_draw_rectangle(1140,15,1240,20,blu,3.0);

    al_draw_filled_rectangle(1140,15,1140+s->energy,20,blu);
    al_draw_text(font[3],blu,1110,12,ALLEGRO_ALIGN_CENTRE,"能量：");
    return 0;

    /*ALLEGRO_COLOR color_blue = al_map_rgb(0, 0, 255);
    al_draw_line(s->sx-8,s->sy+9,s->sx,s->sy-11,color_blue,3.0f);
    al_draw_line(s->sx,s->sy-11,s->sx+8,s->sy+9,color_blue,3.0f);
    al_draw_line(s->sx-6,s->sy+4,s->sx-1,s->sy+4,color_blue,3.0f);
    al_draw_line(s->sx+6,s->sy+4,s->sx+1,s->sy+4,color_blue,3.0f);
    return 0;*/
}
int Ship_grade(int grade)
{
    int i=grade;
    char grades[20];
    sprintf(grades,"%d",i);
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_text(font[2],yellow,90,10,ALLEGRO_ALIGN_CENTRE,grades);
    return 0;
}
int Scope_ship(Spaceship *s)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    if(s->sx+35<0)
    {
        s->sx=s->sx+DISPLAY_W;
    }
    if(s->sy+37<0)
    {
        s->sy=s->sy+DISPLAY_H;
    }
    if(s->sx+35>DISPLAY_W)
    {
        s->sx=s->sx-DISPLAY_W;
    }
    if(s->sy+37>DISPLAY_H)
    {
        s->sy=s->sy-DISPLAY_H;
    }

}
int BIG_SHIP_B(Spaceship *s,Asteroid comet[],BOSS1 *boss1,BOSS2 *boss2, XBOSS xboss1[], XBOSS xboss2[])
{
    if(s->TX==9)
    {
        for(int i=0;i<comet_lives;i++)
        {
            if(comet[i].gone==2)
            {
                comet[i].gone=1;
            }
        }
        for(int i=0;i<XBOSS_number;i++)
        {
            if(xboss1[i].gone==2)
            {
                xboss1[i].gone=1;
            }
            if(xboss2[i].gone==2)
            {
                xboss2[i].gone=1;
            }
        }
        if(boss1->gone==2)
        {
            boss1->live-=3;
        }
        if(boss2->gone==2)
        {
            boss2->live-=2;
        }
    }
    if(s->TX!=0)
    {

        al_draw_bitmap(big_blast[18-s->TX],0,-50,0);
        s->s_time=s->s_time+1;
        if(s->s_time==10)
        {
            s->TX=s->TX-1;
            s->s_time=0;
        }
    }
    if(s->TX==0)
    {
        s->TX=18;
        s->s_time=0;
        s->yORn=0;
    }

}

//飞机完结
