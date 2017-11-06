#include "game.h"
int Init_Blast(struct Blast* *b)
{

    *b=NULL;
    return 0;
}
int Insert_Blast(struct Blast* *b,Spaceship s)
{

    struct Blast *tail;
    tail=(struct Blast *)malloc(sizeof(struct Blast));
    if(tail==NULL)
    {
        printf("Error----> Mallco Fail!\n");
        return 1;
    }

    tail->sx = s.sx;
    tail->sy = s.sy;
    tail->heading = s.heading;
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
    //al_draw_filled_rectangle(-3,-15,2,-5,(*b)->color);
    al_draw_bitmap(setting[4],-4.5,-25,0);
    return 0;
}
int Move_Blast( struct Blast* *b)
{

    (*b)->sx += (*b)->speed * sin((*b)->heading)*10;
    (*b)->sy -= (*b)->speed * cos((*b)->heading)*10;

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
//子弹完结
