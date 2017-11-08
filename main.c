#include "game.h"

const int REC_SIZE= 10;
const int Blast_number=1000;//子弹个数
const int ship_live=3;
int decision=0;
const int comet_lives = 20;//彗星个数
int grade = 0;
int Blast_old=0;
int D_blast =0;//子弹已经发射的个数
int map_h;
int time_pro=0;


enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_SPASE,KEY_E,KEY_F,KEY_S,KEY_D,KEY_A
};
//boss

//飞机
int map_game()
{

    int a,b;
    a=map_h-DISPLAY_H;
    b=map_h;
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_bitmap(setting[3],0,a,0);
    al_draw_bitmap(setting[3],0,b,0);
    if(map_h==DISPLAY_H)
    {
        map_h=0;
    }


}

//子弹
int Init_Blast(struct Blast* *b)
{

    *b=NULL;
    return 0;
}
void traverseList(struct Blast* *hl)
{
    int len=0;
    while(*hl!=NULL)
    {

        (*hl)=(*hl)->next;
        len++;
    }
    printf("len:%d\n",len);


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
        D_blast--;
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
//初始游戏的屏幕
int Init_screen()
{

    music_game(1,1.0);
    int w=100;
    //bool key[4]={false, false, false,false};
    int redraw = 1;
    int choose=1;

    while (1)
    {

        al_wait_for_event(event_queue,&ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {

            redraw = 1;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                if(choose==1)
                {
                    decision++;
                }
                if(choose==2)
                {
                    decision = 3;
                }
                if(choose==4)
                {
                    decision=4;
                }
                break;
            case ALLEGRO_KEY_UP:
                if(choose!=1)
                {
                    choose-=1;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                if(choose!=4)
                {
                    choose+=1;
                }
                break;
            }

        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {


            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            decision++;

        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = 0;

            al_clear_to_color(black);
            al_identity_transform(&transform);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);
            al_draw_bitmap(setting[1],0,0,0);
            switch (decision) {
loop:case 0:
                al_draw_text(font[0],blu,DISPLAY_W/2,0,ALLEGRO_ALIGN_CENTRE,"爆破彗星");
                if(choose==1)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H/3,ALLEGRO_ALIGN_CENTRE,"开始游戏");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H/3,ALLEGRO_ALIGN_CENTRE,"开始游戏");
                }
                if(choose==2)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w- 300,ALLEGRO_ALIGN_CENTRE,"排行榜");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w- 300,ALLEGRO_ALIGN_CENTRE,"排行榜");
                }
                if(choose==3)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w-250,ALLEGRO_ALIGN_CENTRE,"音效");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w-250,ALLEGRO_ALIGN_CENTRE,"音效");
                }
                if(choose==4)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w-200,ALLEGRO_ALIGN_CENTRE,"退出游戏");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w-200,ALLEGRO_ALIGN_CENTRE,"退出游戏");
                }
                break;
            case 1:
                if(choose==1)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H/3,ALLEGRO_ALIGN_CENTRE,"单人模式");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H/3,ALLEGRO_ALIGN_CENTRE,"单人模式");
                }
                if(choose==2)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H- 340,ALLEGRO_ALIGN_CENTRE,"双人模式");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H- 340,ALLEGRO_ALIGN_CENTRE,"双人模式");
                }
                if(choose==3)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"双人对战");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"双人对战");
                }
                break;
            case 3:
            {
                int redraw = 1;
                int c = 1;
                int result = 0;
                char a[10], b[10], ch[10], Grade[10];
                int number[3];
                int i = 0;
                FILE *fp;
                Init_file(grade);


                fp = fopen("../startrek/rank.txt","r");


                for(i=0;i<3;i++){
                    fscanf(fp,"%d ",&number[i]);
                }


                sprintf(a,"%d",number[0]);
                sprintf(b,"%d",number[1]);
                sprintf(ch,"%d",number[2]);

                fclose(fp);

                while(1)
                {

                    al_wait_for_event(event_queue,&ev);
                    if(ev.type == ALLEGRO_EVENT_TIMER) {

                        redraw = 1;
                    }

                    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

                        break;
                    }
                    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                        switch (ev.keyboard.keycode) {
                        case ALLEGRO_KEY_ENTER:
                            if(c==1)
                            {
                                result=1;
                            }
                            if(c==2)
                            {
                                result=2;
                            }
                            break;
                        case ALLEGRO_KEY_UP:
                            c=1;
                            break;
                        case ALLEGRO_KEY_DOWN:
                            c=2;
                            break;
                        }
                    }
                    else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
                        switch(ev.keyboard.keycode) {

                        }
                    }
                    if(redraw && al_is_event_queue_empty(event_queue))
                    {
                        redraw = 0;

                        al_identity_transform(&transform);
                        al_translate_transform(&transform,0,0);
                        al_use_transform(&transform);

                        switch (result){
                        case 0:
                            al_clear_to_color(al_map_rgb(255,155,155));
                            al_draw_bitmap(photo[3],30,50,0);
                            al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-50,ALLEGRO_ALIGN_CENTRE,"游戏排行榜");
                            al_draw_text(font[1],black,DISPLAY_W/2-90,DISPLAY_H/3+50,ALLEGRO_ALIGN_CENTRE,"第一名:");
                            al_draw_text(font[1],black,DISPLAY_W/2+90,DISPLAY_H/3+50,ALLEGRO_ALIGN_CENTRE,a);
                            al_draw_text(font[1],black,DISPLAY_W/2-90,DISPLAY_H/3+175,ALLEGRO_ALIGN_CENTRE,"第二名:");
                            al_draw_text(font[1],black,DISPLAY_W/2+90,DISPLAY_H/3+175,ALLEGRO_ALIGN_CENTRE,b);
                            al_draw_text(font[1],black,DISPLAY_W/2-90,DISPLAY_H/3+300,ALLEGRO_ALIGN_CENTRE,"第三名:");
                            al_draw_text(font[1],black,DISPLAY_W/2+90,DISPLAY_H/3+300,ALLEGRO_ALIGN_CENTRE,ch);
                            if(c==1)
                            {
                                al_draw_text(font[1],white,DISPLAY_W/2-500,DISPLAY_H/2+150,ALLEGRO_ALIGN_CENTRE,"返回");
                                al_draw_text(font[2],black,DISPLAY_W/2-500,DISPLAY_H/2+200,ALLEGRO_ALIGN_CENTRE,"退出");

                            }
                            if(c==2)
                            {
                                al_draw_text(font[1],white,DISPLAY_W/2-500,DISPLAY_H/2+200,ALLEGRO_ALIGN_CENTRE,"退出");
                                al_draw_text(font[2],black,DISPLAY_W/2-500,DISPLAY_H/2+150,ALLEGRO_ALIGN_CENTRE,"返回");
                            }
                            al_flip_display();
                            break;
                        case 1:
                            decision = 0;
                            goto loop;
                        case 2:
                            exit(1);
                        }
                    }

                }


            }
                break;
            case 4:
                exit(0);
            default:
                al_destroy_sample(sample[0]);
                return 0;
            }

            al_flip_display();


        }


    }


}


int main(void)
{

    while(1)
    {
        int result = 0;


        GameInit();
        Init_screen();

        float sx = DISPLAY_W  - REC_SIZE / 2.0;
        float sy = DISPLAY_H / 2.0 - REC_SIZE / 2.0;
        bool redraw = true;
        bool key[10] = {false, false, false, false,false,false, false, false, false,false};
        Asteroid comet[comet_lives];            //彗星数组
        Spaceship ship[2];//飞船数组
        BUFF ship_buf;
        struct Blast ship_blast,*p_blast,*blast_h;//飞机子弹
        BOSS1 boss;
        int bt=1;
        int time_blast1=0;
        int time_star1=0;

        for(int i=0;i<comet_lives;i++)
        {
            Init_star(&comet[i]);
        }
        Init_ship(&ship[0],1); //飞船初始
        //子弹定义
        p_blast=&ship_blast;
        //blast_head=&ship_blast;
        Init_Blast(&p_blast);

        //   p_blast=p_blast->next;

        blast_h=p_blast;
        // int time_star2=0;
        // int time_map=0;
        music_game(2,1.0);
        while(decision==2)
        {
            al_wait_for_event(event_queue, &ev);

            if(ev.type == ALLEGRO_EVENT_TIMER)
            {
                if(key[KEY_UP])
                {

                    ship[0].sx += 4.0 * sin(ship[0].heading);
                    ship[0].sy -= 4.0 * cos(ship[0].heading);

                }
                if(key[KEY_DOWN])
                {

                    ship[0].sx -= 4.0 * sin(ship[0].heading);
                    ship[0].sy += 4.0 * cos(ship[0].heading);


                }
                if(key[KEY_LEFT])
                {
                    ship[0].heading-=0.05;
                }
                if(key[KEY_RIGHT])
                {
                    ship[0].heading+=0.05;
                }
                if(key[KEY_SPASE])
                {
                    time_blast1++;
                    if(time_blast1==6)
                    {
                        al_play_sample(sample[2],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        Insert_Blast(&p_blast,ship[0]);
                        time_blast1=0;
                    }


                }
                /* if(key[KEY_E])
          {
              ship[1].sx += 4.0 * sin(ship[1].heading);
              ship[1].sy -= 4.0 * cos(ship[1].heading);
          }
          if(key[KEY_D])
          {
              ship[1].sx -= 4.0 * sin(ship[1].heading);
              ship[1].sy += 4.0 * cos(ship[1].heading);
          }
          if(key[KEY_S])
          {
              ship[1].heading-=0.1;
          }
          if(key[KEY_F])
          {
              ship[1].heading+=0.1;
          }
          if(key[KEY_A])
          {

                Init_Blast(&ship_blast1[Blast_old],ship[1]);
                Blast_old1++;

          }*/
                redraw = true;
            }
            else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {

                break;
            }
            else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;

                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;

                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = true;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    key[KEY_SPASE] = true;
                    break;

                }
            }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = false;
                    break;

                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = false;
                    break;

                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = false;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = false;
                    break;

                case ALLEGRO_KEY_SPACE:
                    key[KEY_SPASE] = false;
                    break;
                    /*case ALLEGRO_KEY_E:
            key[KEY_E] = false;
            break;

         case ALLEGRO_KEY_S:
            key[KEY_S] = false;
            break;

         case ALLEGRO_KEY_A:
            key[KEY_A] = false;
            break;

         case ALLEGRO_KEY_D:
            key[KEY_D] = false;
            break;
        case ALLEGRO_KEY_F:
            key[KEY_F] = false;*/
                }
            }

            //如果鼠标被用户移动并且鼠标的位置在显示屏内部
            else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
                    ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
            {
                //如果鼠标移动，发射子弹

                // sx = ev.mouse.x;
                //sy = ev.mouse.y;


            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                key[KEY_SPASE] = false;
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {

                key[KEY_SPASE] = true;
            }

            if(redraw && al_is_event_queue_empty(event_queue))
            {
                redraw = false;
                al_clear_to_color(al_map_rgb(250,155,155));
                map_game();
                map_h++;
                Ship_grade(grade);
                if(grade==10)
                {
                    init_boss(&boss);
                }
                if(boss.gone==1)
                {
                    Draw_boss(&boss);
                    Move_boss(&boss);
                    if(boss.live<=0)
                    {
                        grade=grade+100;
                        boss.gone=0;
                    }

                }

                for (int i=0;i<comet_lives;i++)             //画彗星
                {

                    if(comet[i].gone!=0)
                    {
                        if(comet[i].gone==2)
                        {
                            if(ship[0].sx<=comet[i].sx+25&&ship[0].sx>=comet[i].sx-25) //子弹射中彗星
                            {
                                if (ship[0].sy<=comet[i].sy+25&&ship[0].sy>=comet[i].sy-25)
                                {
                                    if(ship[0].pro==0)
                                    {
                                        ship[0].live=ship[0].live-10;
                                    }
                                    comet[i].gone=1;


                                }
                            }
                        }

                        Scope_star(&comet[i]);
                        Draw_star(&comet[i]);
                        move_star(&comet[i]);
                    }
                    else if(comet[i].gone==0)
                    {
                        time_star1++;
                        if(time_star1==500)
                        {
                            Init_star(&comet[i]);
                            time_star1=0;
                        }
                    }

                }

                Draw_ship(&ship[0]);
                while(blast_h!=NULL)
                {
                    Draw_Blast(&blast_h,ship[0]);
                    if(blast_h->sy<-DISPLAY_H||blast_h->sy>DISPLAY_H*2||blast_h->sx<-DISPLAY_W||blast_h->sx>DISPLAY_W*2)
                    {

                        // printf("bt:%d,x:%d y:%d\n",bt,blast_h->sx,blast_h->sy);
                        Delete_Blast(&p_blast,bt);

                    }
                    for(int b=0;b<comet_lives;b++)
                    {
                        if(comet[b].gone==2)
                        {
                            if(blast_h->sx<=comet[b].sx+25&&blast_h->sx>=comet[b].sx-25) //子弹射中彗星
                            {
                                if (blast_h->sy<=comet[b].sy+25&&blast_h->sy>=comet[b].sy-25)
                                {
                                    comet[b].gone=1;
                                    Delete_Blast(&p_blast,bt);
                                    if(ship[0].energy!=100)
                                    {
                                        ship[0].energy++;
                                        //printf("%d",ship[0].energy);
                                    }
                                    grade++;
                                }

                            }
                        }
                    }

                    if(boss.gone==1)
                    {
                        if(blast_h->sx>=boss.sx+100&&blast_h->sx<=boss.sx+200) //子弹射中彗星
                        {
                            if (blast_h->sy<=boss.sy+200&&blast_h->sy>=boss.sy)
                            {
                                boss.live--;
                                Delete_Blast(&p_blast,bt);

                            }

                        }
                    }
                    Move_Blast(&blast_h);
                    blast_h=blast_h->next;
                    bt++;
                }
                blast_h=p_blast;
                bt=1;
                /*if(ship[0].pro==1)
         {
             if(time_pro==1000)
             {
                 ship[0].pro=0;
                 time_pro=0;
             }
             time_pro++;

         }*/
                al_flip_display();
            }
            if(ship[0].live<=0)
            {
                break;
            }

        }

        gamegrade(grade);
        result = 1;
        if(result==1){
            free(p_blast);
            al_destroy_timer(timer);
            al_destroy_display(display);
            al_destroy_event_queue(event_queue);
            decision = 0;
            continue;
        }

    }


}



