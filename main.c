#include "game.h"

const int REC_SIZE= 10;
const int Blast_number=1000;//子弹个数
const int ship_live=3;
int ship_type =1;
int decision=0;
int grade =0;   //分数
int Blast_old=0;
int D_blast =0;//子弹已经发射的个数
int map_h;
int time_pro=0;//保护罩时间
int xboss1_out=0;//xboss出现时间
int xboss2_out=0;
int boss1_out=0;//boss1出现
int boss2_out=0;//boss2出现
int boss3_out=0;//boss3出现
int buff_out_time=0;// buff出现时间
int buff_out = 0;
int buff_xs=0;
enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_SPASE,KEY_Q,KEY_F,KEY_S,KEY_D,KEY_A
};
//boss


//初始游戏的屏幕
int Init_screen()
{


    music_game(1,1.0);
    int w=100;
    int redraw = 1;
    int choose=1; //选项
    int jiemian = 0;//界面
    int xiaxian = 4;
    int RorL=1;
    int RMAX=3;

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
                if(jiemian==0&&choose==1)
                {
                    ship_type=RorL-1;
                    decision=2;
                    jiemian=5;
                }
                else if(jiemian==0&&choose==4)
                {
                    jiemian=4;
                }
                else if(jiemian==0&&choose==2)
                {
                    jiemian=2;
                }
                else if(jiemian==0&&choose==3)
                {
                    jiemian=1;
                    choose=1;
                    xiaxian=3;
                }
                else if(jiemian==1&&choose==3)
                {
                    jiemian=0;
                    choose=1;
                    xiaxian=4;
                }
               break;
            case ALLEGRO_KEY_UP:
                if(choose!=1)
                {
                    choose-=1;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                if(choose!=xiaxian)
                {
                    choose+=1;
                }
                break;
            case ALLEGRO_KEY_LEFT:
                if(RorL!=1)
                {
                    RorL-=1;
                }
                break;

            case ALLEGRO_KEY_RIGHT:
                if(RorL!=RMAX)
                {
                    RorL+=1;
                }
                break;
            }

        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {


            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {


        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = 0;

            al_clear_to_color(black);
            al_identity_transform(&transform);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);
            al_draw_bitmap(setting[0],0,0,0);
            switch (jiemian) {
loop:case 0:
                al_draw_text(font[4],blu,60,15,ALLEGRO_ALIGN_CENTRE,"版本：startrek-0.9.0");
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
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w-250,ALLEGRO_ALIGN_CENTRE,"设置");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w-250,ALLEGRO_ALIGN_CENTRE,"设置");
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
                    al_draw_text(font[1],yellow,DISPLAY_W/4,DISPLAY_H-w-400,ALLEGRO_ALIGN_CENTRE,"音乐：");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/4,DISPLAY_H-w-400,ALLEGRO_ALIGN_CENTRE,"音乐：");
                }
                if(choose==2)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/4,DISPLAY_H-w-200,ALLEGRO_ALIGN_CENTRE,"角色:");
                    al_draw_bitmap(xuan[0],DISPLAY_W/4+100,DISPLAY_H-w-100,0);
                    al_draw_bitmap(xuan[0],DISPLAY_W/4+300,DISPLAY_H-w-100,0);
                    al_draw_bitmap(xuan[0],DISPLAY_W/4+500,DISPLAY_H-w-100,0);
                    if(RorL==1)
                    {
                         al_draw_bitmap(ship_imge[5],DISPLAY_W/4+100,DISPLAY_H-w-200,0);
                         al_draw_bitmap(xuan[1],DISPLAY_W/4+105,DISPLAY_H-w-90,0);

                    }
                    else{
                         al_draw_bitmap(ship_imge[0],DISPLAY_W/4+100,DISPLAY_H-w-200,0);
                    }
                    if(RorL==2)
                    {
                         al_draw_bitmap(ship_imge[4],DISPLAY_W/4+300,DISPLAY_H-w-200,0);
                         al_draw_bitmap(xuan[1],DISPLAY_W/4+305,DISPLAY_H-w-90,0);
                    }
                    else{
                         al_draw_bitmap(ship_imge[1],DISPLAY_W/4+310,DISPLAY_H-w-200,0);

                    }
                    if(RorL==3)
                    {
                         al_draw_bitmap(ship_imge[3],DISPLAY_W/4+500,DISPLAY_H-w-200,0);
                         al_draw_bitmap(xuan[1],DISPLAY_W/4+505,DISPLAY_H-w-90,0);
                    }
                    else{
                         al_draw_bitmap(ship_imge[2],DISPLAY_W/4+500,DISPLAY_H-w-200,0);
                    }
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/4,DISPLAY_H-w-200,ALLEGRO_ALIGN_CENTRE,"角色:");
                    al_draw_bitmap(ship_imge[0],DISPLAY_W/4+100,DISPLAY_H-w-200,0);
                    al_draw_bitmap(ship_imge[1],DISPLAY_W/4+300,DISPLAY_H-w-200,0);
                    al_draw_bitmap(ship_imge[2],DISPLAY_W/4+500,DISPLAY_H-w-200,0);
                }
                if(choose==3)
                {
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w-50,ALLEGRO_ALIGN_CENTRE,"返回");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w-50,ALLEGRO_ALIGN_CENTRE,"返回");
                }
               /* if(choose==1)
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
                    al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"返回菜单");
                }
                else
                {
                    al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"返回菜单");
                }*/
                break;
            case 2:
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
                            jiemian = 0;
                            goto loop;
                        case 2:
                            exit(1);
                        }
                    }

                }


            }
                break;
            case 3:
                break;
            case 4:
                exit(0);
            default:
                al_destroy_sample(sample[1]);
                return 0;
            }

            al_flip_display();


        }


    }


}



int main(void)
{
    int o_or_c_start=0;

    while(1)
    {
        GameInit(o_or_c_start);
        Music_init();
        if(o_or_c_start==0)
        {
            int x=115;
            int y=0;
           // GameInit(1);

            while(x!=-1)
            {

                if(x==35)
                {
                    music_game(0,0);
                }

                al_draw_bitmap(kaichang[x],0,0,0);
                al_flip_display();

                if(y==5)
                {
                    x--;
                    y=0;
                }
                y++;

            }
            o_or_c_start=1;
        }
        int result = 0;
        //Music_init();
        Init_screen();


        bool redraw = true;
        bool key[10] = {false, false, false, false,false,false, false, false, false,false};
        Asteroid comet[comet_lives];            //彗星数组
        Spaceship ship[2];//飞船数组
        BUFF ship_buff;
        struct Blast ship_blast,*p_blast,*blast_h;//飞机子弹
        BOSS1 boss;                        //boss1定义
        BOSS2 boss2;                       //boss2定义
        BOSS3 boss3;                       //boss3定义
        XBOSS xboss[XBOSS_number];         //xboss定义
        XBOSS xboss2[XBOSS_number];        //xboss2
        BOSS_Blast xb_blast[XBOSS_number]; //xb_blast定义
        int bt=1;
        int time_blast1=0;
        int boss_blast_time=0;
        int time_star1=0;
        for (int i=0;i<comet_lives;i++)
        {
            Init_star(&comet[i]);
        }

        Init_ship(&ship[0],ship_type); //飞船初始
        //子弹定义
        p_blast=&ship_blast;
        Init_Blast(&p_blast);
        blast_h=p_blast;

        music_game(2,1.0);   //音乐

        while(decision==2)
        {
            al_wait_for_event(event_queue, &ev);

            if(ev.type == ALLEGRO_EVENT_TIMER) {
                if(key[KEY_UP])
                {
                    Scope_ship(&ship[0]);
                    ship[0].sx += 4.0 * sin(ship[0].heading);
                    ship[0].sy -= 4.0 * cos(ship[0].heading);

                }
                if(key[KEY_DOWN])
                {
                    Scope_ship(&ship[0]);
                    ship[0].sx -= 4.0 * sin(ship[0].heading);
                    ship[0].sy += 4.0 * cos(ship[0].heading);


                }
                if(key[KEY_LEFT])
                {
                    ship[0].heading-=0.05;
                    //printf("%f\n",ship[0].heading);
                }
                if(key[KEY_RIGHT])
                {
                    ship[0].heading+=0.05;
                    // printf("%f\n",ship[0].heading);
                }
                if(key[KEY_SPASE])
                {
                    time_blast1++;
                    if(time_blast1==6)
                    {
                        //al_play_sample(sample[2],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        Blast_mode(&p_blast,ship[0]);
                        time_blast1=0;
                    }


                }
                if(key[KEY_Q])
                {
                    if(ship[0].energy==100)
                    {
                        ship[0].yORn=1;
                        ship[0].energy=0;
                        al_play_sample(sample[5],1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);//龙吼
                    }
                }

                redraw = true;
            }
            else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

                break;
            }
            else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
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
                case ALLEGRO_KEY_Q:
                    key[KEY_Q] = true;
                    break;

                }
            }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch(ev.keyboard.keycode) {
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
                case ALLEGRO_KEY_Q:
                    key[KEY_Q] = false;
                    break;

                }
            }

            //如果鼠标被用户移动并且鼠标的位置在显示屏内部
            else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
                    ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
                //如果鼠标移动，发射子弹

                // sx = ev.mouse.x;
                //sy = ev.mouse.y;


            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                key[KEY_SPASE] = false;
            }
            else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

                key[KEY_SPASE] = true;
            }

            if(redraw && al_is_event_queue_empty(event_queue)) {
                redraw = false;
                al_clear_to_color(al_map_rgb(250,155,155));
                map_game(&map_h);
                map_h++;
                Ship_grade(grade);
                //大招
                if(ship[0].yORn==1)
                {
                    BIG_SHIP_B(&ship[0],comet,&boss,&boss2,xboss,xboss2);
                }

                if(grade>=100&&boss1_out==0)    //boss1出现
                {
                    boss1_out=1;
                    init_boss(&boss);
                }
                //xboss
                if(grade!=0&&grade%15==0&&xboss1_out==0)  //xboss
                {
                    xboss1_out=1;
                    init_xboss(xboss,xb_blast,1);
                }
                if(xboss1_out==1)
                {

                    hit_ship_xb(&ship[0],xboss,xb_blast);

                    if(judge_xboss(xboss)==0)
                    {
                        xboss1_out=0;
                    }
                    Draw_xb_blast(xb_blast);
                    xb_bhit_star(xb_blast,&ship[0]);
                }
                if(grade!=0&&grade%5==0&&xboss2_out==0)  //xboss
                {
                    xboss2_out=1;
                    init_xboss(xboss2,xb_blast,2);
                }
                if(xboss2_out==1)
                {

                    hit_ship_xb(&ship[0],xboss2,xb_blast);

                    if(judge_xboss(xboss2)==0)
                    {
                        xboss2_out=0;
                    }
                    Draw_xb_blast(xb_blast);
                    xb_bhit_star(xb_blast,&ship[0]);
                }
                //xbossendl
                if(boss.gone!=0)
                {

                    Draw_boss(&boss,&ship[0]);
                    if(boss.live<0&&boss.TX!=0)
                    {
                        grade=grade+100;
                        boss.gone=1;

                    }

                }
                if(grade>=400&&boss2_out==0)
                {
                    boss2_out=1;
                    init_boss2(&boss2);
                }
                if(boss2.gone!=0)
                {

                    Draw_boss2(&boss2,&ship[0]);
                    if(boss2.live<0&&boss2.TX!=0)
                    {
                        grade=grade+300;
                        boss2.gone=1;

                    }

                }
                //buff出现
                if(buff_out_time==500&&buff_out==0)
                {
                    buff_out=1;
                    Init_buff(&ship_buff);//初始化buff
                    buff_out_time=0;

                }
                if(buff_out==0)
                {
                    buff_out_time++;
                }


                if(buff_out==1)
                {
                    buff_xs++;
                    SHIP_buff(&ship[0],&ship_buff);
                    if(buff_xs==800)
                    {
                        ship_buff.gone=1;
                        buff_out=0;
                    }
                    if(ship_buff.gone==1)
                    {
                        buff_out=0;
                    }

                }

                hit_star(comet,&time_star1,&ship[0]);//彗星主函数

                Draw_ship(&ship[0]);
                while(blast_h!=NULL)
                {
                    Draw_Blast(&blast_h,ship[0]);
                    if(blast_h->sy<-DISPLAY_H||blast_h->sy>DISPLAY_H*2||blast_h->sx<-DISPLAY_W||blast_h->sx>DISPLAY_W*2)
                    {

                        Delete_Blast(&p_blast,bt);

                    }
                    for(int b=0;b<comet_lives;b++)//子弹射中彗星
                    {


                        if(comet[b].gone==2)
                        {
                            if(blast_h->sx<=comet[b].sx+25&&blast_h->sx>=comet[b].sx-25) //子弹射中彗星
                            {
                                if (blast_h->sy<=comet[b].sy+25&&blast_h->sy>=comet[b].sy-25)
                                {
                                    comet[b].gone=1;

                                    Delete_Blast(&p_blast,bt);
                                    if(ship[0].energy!=100)    // 能量增加
                                    {
                                        ship[0].energy+=5;
                                        if(ship[0].energy>100)
                                        {
                                            ship[0].energy=100;
                                        }

                                    }
                                    grade++;
                                }

                            }
                        }
                    }

                    for(int i=0;i<XBOSS_number;i++)
                    {

                        if(xboss[i].gone==2)
                        {
                            al_identity_transform(&transform);
                            al_rotate_transform(&transform,xboss[i].twist);
                            al_translate_transform(&transform,xboss[i].sx,xboss[i].sy);
                            al_use_transform(&transform);
                            if(blast_h->sx>xboss[i].sx-20&&blast_h->sx<xboss[i].sx+20) //子弹射中彗星
                            {
                                if (blast_h->sy-20>xboss[i].sy-20&&blast_h->sy-20<xboss[i].sy+20)
                                {
                                    xboss[i].gone=1;
                                    //al_rest(2);
                                    Delete_Blast(&p_blast,bt);
                                    if(ship[0].energy!=100)    // 能量增加
                                    {
                                        ship[0].energy+=2;
                                        if(ship[0].energy>100)
                                        {
                                            ship[0].energy=100;
                                        }
                                    }
                                    grade=grade+2;
                                }

                            }
                        }
                    }
                    for(int i=0;i<XBOSS_number;i++)
                    {

                        if(xboss2[i].gone==2)
                        {
                            al_identity_transform(&transform);
                            al_rotate_transform(&transform,xboss2[i].twist);
                            al_translate_transform(&transform,xboss2[i].sx,xboss2[i].sy);
                            al_use_transform(&transform);
                            if(blast_h->sx>xboss2[i].sx-20&&blast_h->sx<xboss2[i].sx+20) //子弹射中彗星
                            {
                                if (blast_h->sy-20>xboss2[i].sy-20&&blast_h->sy-20<xboss2[i].sy+20)
                                {
                                    xboss2[i].gone=1;
                                    //al_rest(2);
                                    Delete_Blast(&p_blast,bt);
                                    if(ship[0].energy!=100)    // 能量增加
                                    {

                                        ship[0].energy+=3;
                                        if(ship[0].energy>100)
                                        {
                                            ship[0].energy=100;
                                        }

                                    }
                                    grade=grade+2;
                                }

                            }
                        }
                    }
                    if(hit_boss(boss,blast_h)==1)
                    {
                        boss.live--;
                        Delete_Blast(&p_blast,bt);
                    }
                    if(hit_boss2(boss2,blast_h)==1)
                    {
                        boss2.live-=0.5;
                        Delete_Blast(&p_blast,bt);
                    }
                    Move_Blast(&blast_h);
                    blast_h=blast_h->next;
                    bt++;
                }
                blast_h=p_blast;
                bt=1;
                if(ship[0].pro==1)
                {
                    if(time_pro==500)
                    {
                        ship[0].pro=0;
                        time_pro=0;
                    }
                    time_pro++;

                }
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
            al_destroy_sample(sample[0]);
             al_destroy_sample(sample[2]);
             al_destroy_timer(timer);
             al_destroy_display(display);
             al_destroy_event_queue(event_queue);
            decision = 0;
            grade =  0;
            continue;

        }
    }


}
