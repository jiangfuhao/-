#include "game.h"
int Init_Blast(struct Blast* *b)
{

    *b=NULL;
    return 0;
}
int Blast_mode(struct Blast* *p_blast,Spaceship s)   //飞机子弹种类
{
    if(s.blast_mode==1)
    {
       int a=10;
       for(int i=0;i<3;i++)
       {
        Insert_Blast(p_blast,s,a,0,0);
        a=a-10;
       }
    }
    else if(s.blast_mode==2)
    {
        //double x=20;
        double y=0;
        //double j=0;
        double heading=0.4;
        for(int i=0;i<5;i++)
        {

            Insert_Blast(p_blast,s,0,y,heading);
            //x=x-10;
            heading=heading-0.2;

           /* if(i==2)
            {
                j=1;
            }
            if(j==1)
            {
                y=y+10;
            }else{
                y=y-10;
            }*/
        }
    }
    else{
        Insert_Blast(p_blast,s,0,0,0);
    }

}
int Insert_Blast(struct Blast* *b,Spaceship s,double x,double y,double heading)
{
    struct Blast *tail;
    tail=(struct Blast *)malloc(sizeof(struct Blast));
    if(tail==NULL)
    {
        printf("Error----> Mallco Fail!\n");
        return 1;
    }

    tail->sx = s.sx+x;
    tail->sy = s.sy+y;
    tail->type=s.blast_mode;
    tail->heading = s.heading + heading;
    tail->speed = s.speed*3;
    tail->color = al_map_rgb(255,255,255);
    tail->next=*b;
    *b=tail;

    return 0;
}
int Delete_Blast(struct Blast* *b,int pos)
{
    int len=0;
    struct Blast *list,*last;
    list=(*b);
    if(list==NULL)
    {
        printf("Error----> Empty list!\n");
        return 0;
    }

    if(pos==1)
    {

        (*b)=(*b)->next;
       // free(list);
        return 0;
    }
    else
    {

        last=list;
        while(list!=NULL)
        {
            len++;
            if(len==pos)
            {
                last->next=list->next;
                return 0;
            }
            last=list;
            list=list->next;
        }
    }




}
int Draw_Blast(struct Blast* *b,Spaceship s)
{


    al_identity_transform(&transform);
    al_rotate_transform(&transform,(*b)->heading);
    al_translate_transform(&transform,(*b)->sx,(*b)->sy);
    al_use_transform(&transform);

    if((*b)->type==1)
    {
        al_draw_bitmap(blast_ship[0],7.5,-45,0);
    }else if((*b)->type==2)
    {
        al_draw_bitmap(blast_ship[1],7.5,-45,0);
    }else
    {
        al_draw_bitmap(blast_ship[2],9,-45,0);

    }

    return 0;
}
int Move_Blast( struct Blast* *b)
{

    (*b)->sx += (*b)->speed * sin((*b)->heading)*5;
    (*b)->sy -= (*b)->speed * cos((*b)->heading)*5;

    return 0;

}
int Scope_Blast(struct Blast* *b,Spaceship s)
{
    if((*b)->sx>=DISPLAY_W||(*b)->sy>=DISPLAY_H)
    {
        Init_Blast(b);
    }
    return 0;
}
//ship子弹完结
//xboss_blast
int init_xb_blast(BOSS_Blast xb_blast[])
{
    for(int i=0;i<XBOSS_number;i++)
    {
        xb_blast[i].gone=0;
        xb_blast[i].heading=0;
        xb_blast[i].speed=0;
        xb_blast[i].sx=0;
        xb_blast[i].sy=0;
    }

    return 0;

}
int lord_xb_blast(XBOSS *xb,BOSS_Blast *xb_blast,Spaceship *s)
{
    xb_blast->sx=xb->sx;
    xb_blast->sy=xb->sy;
    xb_blast->heading=count_head(xb_blast->sx,xb_blast->sy,s);
    xb_blast->speed=xb->speed*2;
    xb_blast->gone=1;
}

double count_head(double x,double y,Spaceship *s)
{
    double heading=0;
    double deltax=s->sx-x;
    double deltay=s->sy-y;
    if(deltax==0)
    {
        if(s->sy>=y)
        {
            deltax=0.000001;
        }
        else{
            deltax=-0.000001;
        }
    }
    if(deltay==0)
    {
        if(s->sx>=x)
        {
            deltay=0.000001;
        }
        else{
            deltay=-0.000001;
        }
    }
    if(deltax>0 && deltay>0)
        heading=atan(fabs(deltay/deltax));
    else if(deltax<0 && deltay>0)
        heading=3.1415926-atan(fabs(deltay/deltax));
    else if(deltax<0 && deltay<0)
        heading=3.1415926+atan(fabs(deltay/deltax));
    else
        heading=2*3.1415926-atan(fabs(deltay/deltax));

    return heading;
}
int Draw_xb_blast(BOSS_Blast xb_blast[])
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    for(int i=0;i<XBOSS_number;i++)
    {

        if(xb_blast[i].gone==1)
        {

            al_draw_bitmap(xb_bl,xb_blast[i].sx,xb_blast[i].sy,0);
            Move_xb_blast(&xb_blast[i]);

        }
    }
}
int Move_xb_blast(BOSS_Blast *xb_bl)
{
    xb_bl->sx += xb_bl->speed * cos(xb_bl->heading);
    xb_bl->sy += xb_bl->speed * sin(xb_bl->heading);
}
int xb_bhit_star(BOSS_Blast xb_blast[],Spaceship *s)
{
    for(int i=0;i<XBOSS_number;i++)
    {
        if(xb_blast[i].gone==1)
        {
            if(xb_blast[i].sx>s->sx-30&&xb_blast[i].sx<=s->sx+30)
            {
                if(xb_blast[i].sy>s->sy-30&&xb_blast[i].sy<=s->sy+30)
                {
                    if(s->pro==0)
                    {
                         s->live--;
                    }

                    xb_blast[i].gone=0;
                }
            }
        }
    }
}


