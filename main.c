#include "game.h"

const int REC_SIZE= 10;
const int Blast_number=1000;//子弹个数
const int ship_live=3;
int decision=0;
int grade = 0;
int Blast_old=0;
int D_blast =0;//子弹已经发射的个数
int map_h;
int time_pro=0;//保护罩时间
int xboss_out=0;//xboss出现时间
int boss_out=0;//boss出现

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_SPASE,KEY_E,KEY_F,KEY_S,KEY_D,KEY_A
};
//boss


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
                     choose=1;
                     decision++;
                 }
                 if(choose==3)
                 {
                     choose=1;
                     decision=0;
                 }
                 if(choose==4)
                 {
                     decision=-1;
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
             case 0:
                 al_draw_text(font[3],blu,15,18,ALLEGRO_ALIGN_CENTRE,"版本：startrek-0.6");
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
                     al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-w- 300,ALLEGRO_ALIGN_CENTRE,"设置");
                 }
                 else
                 {
                     al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-w- 300,ALLEGRO_ALIGN_CENTRE,"设置");
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
                     al_draw_text(font[1],yellow,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"返回菜单");
                 }
                 else
                 {
                     al_draw_text(font[2],green,DISPLAY_W/2,DISPLAY_H-200,ALLEGRO_ALIGN_CENTRE,"返回菜单");
                 }
                 break;
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
   bool redraw = true;
   bool key[10] = {false, false, false, false,false,false, false, false, false,false};
   Asteroid comet[comet_lives];            //彗星数组
   Spaceship ship[2];//飞船数组
   BUFF ship_buff;
   struct Blast ship_blast,*p_blast,*blast_h;//飞机子弹
   BOSS1 boss; //boss定义
   XBOSS xboss[XBOSS_number];//xboss定义
   BOSS_Blast xb_blast[XBOSS_number]; //xb_blast定义
   int bt=1;
   int time_blast1=0;
   int boss_blast_time=0;
   int time_star1=0;
   GameInit();

   Init_screen();

   for (int i=0;i<comet_lives;i++)
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
         if(grade==100&&boss_out==0)
         {
             boss_out=1;
             init_boss(&boss);
         }
         if(grade!=0&&grade%5==0&&xboss_out==0)
         {
             xboss_out=1;
             init_xboss(xboss,xb_blast);
         }
         if(xboss_out==1)
         {

             hit_ship_xb(&ship[0],xboss,xb_blast);

             if(judge_xboss(xboss)==0)
             {
                 xboss_out=0;
             }
             Draw_xb_blast(xb_blast);
             xb_bhit_star(xb_blast,&ship[0]);
         }
         if(boss.gone==1)
         {
             Draw_boss(&boss,&ship[0]);
             if(boss.live<=0)
             {
                 grade=grade+100;
                 boss.gone=0;
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
                         if (blast_h->sy-20<=comet[b].sy+25&&blast_h->sy-20>=comet[b].sy-25)
                         {
                             comet[b].gone=1;

                             Delete_Blast(&p_blast,bt);
                             if(ship[0].energy!=100)    // 能量增加
                             {
                                 ship[0].energy++;

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
                                 ship[0].energy++;

                             }
                             grade++;
                         }

                     }
                 }
             }

             if(hit_boss(boss,blast_h)==1)
             {
                 boss.live--;
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
             if(time_pro==1000)
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
          decision=0;
      }


   }

   free(p_blast);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
