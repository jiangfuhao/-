#include "game.h"



const float FPS = 60;
const int DISPLAY_W = 1100;//屏幕宽度
const int DISPLAY_H = 700;//屏幕高度
const int REC_SIZE= 10;
const int Blast_number=1000;//子弹个数
const int ship_live=3;
 int decision=0;
const int comet_lives = 10;
int grade = 0;
enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,KEY_SPASE,KEY_E,KEY_F,KEY_S,KEY_D,KEY_A
};
//彗星
int Init_star(Asteroid *c)
{
    c->sx = rand() % DISPLAY_W;
    c->sy = rand() % DISPLAY_H;
    c->heading = (rand() % (int)(atan(1) * 8));
    c->twist = (rand() % (int)(atan(1) * 8));
    c->speed = 1.0;
    c->rot_velocity = 0.1;
    c->scale = 1;
    c->gone =1;
    c->color =  al_map_rgb(80, 100, 100);
    return 0;
}
int Draw_star(Asteroid *c)
{

    al_identity_transform(&transform);
    al_rotate_transform(&transform,c->twist);
    al_translate_transform(&transform,c->sx,c->sy);
    al_use_transform(&transform);

    al_draw_line(-20 * c->scale,20* c->scale,-25* c->scale,5 * c->scale,c->color,2.0f);
    al_draw_line(-25 * c->scale,5 * c->scale,-25 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(-25 * c->scale,-10 * c->scale,-5 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(-5 * c->scale,-10 * c->scale,-10 * c->scale,-20 * c->scale,c->color,2.0f);
    al_draw_line(-10 * c->scale,-20 * c->scale,5 * c->scale,-20 * c->scale,c->color,2.0f);
    al_draw_line(5 * c->scale,-20 * c->scale,20 * c->scale,-10 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,-10 * c->scale,20 * c->scale,-5 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,-5 * c->scale,0 * c->scale,0 * c->scale,c->color,2.0f);
    al_draw_line(0 * c->scale,0 * c->scale,20 * c->scale,10 * c->scale,c->color,2.0f);
    al_draw_line(20 * c->scale,10 * c->scale,10 * c->scale,20 * c->scale,c->color,2.0f);
    al_draw_line(10 * c->scale,20 * c->scale,0 * c->scale,15 * c->scale,c->color,2.0f);
    al_draw_line(0 * c->scale,15 * c->scale,-20 * c->scale,20 * c->scale,c->color,2.0f);
    return 0;
}
int move_star(Asteroid *c)
{
        c->twist += c->rot_velocity;
        c->sx += c->speed * sin(c->heading);
        c->sy -= c->speed * cos(c->heading);
        return 0;
}
int Scope_star(Asteroid *c)
{
    if(c->sx<=0||c->sy<=0||c->sx>=DISPLAY_W||c->sy>=DISPLAY_H) c->heading = (rand() % (int)(atan(1) * 8));
    return 0;
}
//彗星完结
//飞机
int Init_ship(Spaceship *s ,int i)
{
    if(i==1)
    {
    s->sx = DISPLAY_W /2.0 ;
    s->sy = DISPLAY_H / 2.0 ;
    s->gone = false;
    s->heading= 0;
    }
    else
    {
        s->sx = 10 ;
        s->sy = DISPLAY_H / 2.0 ;
        s->gone = false;
        s->heading= 2;
    }
    return 0;
}
int Draw_ship(Spaceship *s,float x,float y)
{

    al_identity_transform(&transform);
    al_rotate_transform(&transform,s->heading);
    al_translate_transform(&transform,s->sx,s->sy);
    al_use_transform(&transform);

    ALLEGRO_COLOR color_blue = al_map_rgb(0, 255, 255);
    al_draw_line(-8,9,0,-11,color_blue,3.0f);
    al_draw_line(0,-11,8,9,color_blue,3.0f);
    al_draw_line(-6,4,-1,4,color_blue,3.0f);
    al_draw_line(6,4,1,4,color_blue,3.0f);
    return 0;

    /*ALLEGRO_COLOR color_blue = al_map_rgb(0, 0, 255);
    al_draw_line(s->sx-8,s->sy+9,s->sx,s->sy-11,color_blue,3.0f);
    al_draw_line(s->sx,s->sy-11,s->sx+8,s->sy+9,color_blue,3.0f);
    al_draw_line(s->sx-6,s->sy+4,s->sx-1,s->sy+4,color_blue,3.0f);
    al_draw_line(s->sx+6,s->sy+4,s->sx+1,s->sy+4,color_blue,3.0f);
    return 0;*/
}


//飞机完结
//子弹
int Init_Blast(Blast *b,Spaceship s)
{
    b->sx=s.sx;
    b->sy=s.sy;
    b->heading=s.heading;
    b->gone=false;
    b->speed=1.0;
    return 0;
}
int Draw_Blast(Blast *b,Spaceship s)
{
    al_identity_transform(&transform);
    al_rotate_transform(&transform,s.heading);
    al_translate_transform(&transform,b->sx,b->sy);
    al_use_transform(&transform);

    al_draw_filled_rectangle(-3,-15,2,-5,green);
    return 0;
}
int Move_Blast(Blast *b)
{

    b->sx += b->speed * sin(b->heading)*10;
    b->sy -= b->speed * cos(b->heading)*10;
    return 0;

}
int Scope_Blast(Blast *b,Spaceship s)
{
    if(b->sx>=DISPLAY_W||b->sy>=DISPLAY_H)
    {
        Init_Blast(b,s);
    }
    return 0;
}
//子弹完结
//初始游戏的屏幕
int Init_screen()
{
    bool key[4]={false, false, false,false};
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
                 decision = 1;
                 break;

             }

         }
         else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {
               case ALLEGRO_KEY_ENTER:
                decision=0;
                  break;
            case ALLEGRO_KEY_UP:
                if(choose!=1)
                {
                    choose-=1;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                if(choose!=3)
                {
                    choose+=1;
                }
                break;
            }
         }
         else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
             decision = 1;

         }

         if(redraw && al_is_event_queue_empty(event_queue))
         {
             redraw = 0;

             al_clear_to_color(black);
             al_identity_transform(&transform);
             al_translate_transform(&transform,0,0);
             al_use_transform(&transform);
             al_draw_text(font1,blu,DISPLAY_W/2,0,ALLEGRO_ALIGN_CENTRE,"爆破彗星");
             if(choose==1)
             {
                 al_draw_text(font2,yellow,DISPLAY_W/2,DISPLAY_H - 440,ALLEGRO_ALIGN_CENTRE,"开始游戏");
             }
             else
             {
                 al_draw_text(font3,green,DISPLAY_W/2,DISPLAY_H - 440,ALLEGRO_ALIGN_CENTRE,"开始游戏");
             }
             if(choose==2)
             {
                 al_draw_text(font2,yellow,DISPLAY_W/2,DISPLAY_H - 330,ALLEGRO_ALIGN_CENTRE,"设置");
             }
             else
             {
                 al_draw_text(font3,green,DISPLAY_W/2,DISPLAY_H - 330,ALLEGRO_ALIGN_CENTRE,"设置");
             }
             if(choose==3)
             {
                 al_draw_text(font2,yellow,DISPLAY_W/2,DISPLAY_H - 220,ALLEGRO_ALIGN_CENTRE,"音效");
             }
             else
             {
                 al_draw_text(font3,green,DISPLAY_W/2,DISPLAY_H - 220,ALLEGRO_ALIGN_CENTRE,"音效");
             }




             al_flip_display();


         }
         if(decision==1)
         {
             break;
         }

    }
    return 0;

}
int Ship_grade()
{
    int i=grade*10;
    char grades[20];
    sprintf(grades,"%d",i);
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);
    al_draw_text(font3,yellow,40,10,ALLEGRO_ALIGN_CENTRE,grades);
    return 0;
}
int GameInit()
{
    if(!al_init()) {
        fprintf(stderr,"error1:have not allegro\n");
        return -1;
    }
    if (!al_install_keyboard()) {
        fprintf(stderr,"error2:Key\n");
        return -1;
    }
    if(!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize image addon!\n");
       return -1;
    }

    if (!al_install_mouse()) {
        fprintf(stderr,"error3:mouse\n");
        return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    font1 = al_load_ttf_font("../startrek/a.ttf",80,0);
    if(!font1){
        fprintf(stderr,"error:font1");
        return -1;
    }
    font2 = al_load_ttf_font("../startrek/a.ttf",40,0);
    if(!font2){
        fprintf(stderr,"error:font2");
        return -1;
    }
    font3 = al_load_ttf_font("../startrek/a.ttf",30,0);
    if(!font2){
        fprintf(stderr,"error:font3");
        return -1;
    }
    timer = al_create_timer(1.0/FPS);
    if(!timer) {
        fprintf(stderr,"error4:timer\n");
        return -1;
    }
    display = al_create_display(DISPLAY_W, DISPLAY_H);
    if(!display) {
        fprintf (stderr,"error5:display\n");
        al_destroy_timer(timer);
        return -1;
    }
    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr,"error6:event_queue\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(100,0,255));
    al_start_timer(timer);
    return 0;
}

int main(void)
{

   float sx = DISPLAY_W  - REC_SIZE / 2.0;
   float sy = DISPLAY_H / 2.0 - REC_SIZE / 2.0;
   bool redraw = true;
   bool key[10] = {false, false, false, false,false,false, false, false, false,false};
   Asteroid comet[comet_lives];            //彗星数组
   Spaceship ship[3];             //飞船数组
   Blast ship_blast[Blast_number];//飞机子弹
   Blast ship_blast1[Blast_number];//飞机子弹
   GameInit();
   Init_screen();

   for (int i=0;i<comet_lives;i++)
   {
       Init_star(&comet[i]);
   }
   Init_ship(&ship[0],1); //飞船初始化
  // Init_ship(&ship[1],2);
   int Blast_old=0;  //子弹已经发射的个数
   int Blast_old1=0;
   int time_blast1=0;
   int time_blast2=0;
   int time_star1=0;
   int time_star2=0;
   while(decision)
   {


      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
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
              ship[0].heading-=0.1;
          }
          if(key[KEY_RIGHT])
          {
              ship[0].heading+=0.1;
          }
          if(key[KEY_SPASE])
          {

                Init_Blast(&ship_blast[Blast_old],ship[0]);
                Blast_old++;

          }
          if(key[KEY_E])
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
         /*case ALLEGRO_KEY_E:
            key[KEY_E] = true;
            break;

         case ALLEGRO_KEY_S:
            key[KEY_S] = true;
            break;

         case ALLEGRO_KEY_A:
            key[KEY_A] = true;
            break;

         case ALLEGRO_KEY_D:
            key[KEY_D] = true;
            break;
        case ALLEGRO_KEY_F:
            key[KEY_F] = true;
*/
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
         Ship_grade();
         for (int i=0;i<comet_lives;i++)             //画彗星
         {
             Scope_star(&comet[i]);
             Draw_star(&comet[i]);
             move_star(&comet[i]);

         }
         Draw_ship(&ship[0],sx,sy);

          //彗星1
         for (int a=0;a<Blast_old;a++)
         {

             if(Blast_old<Blast_number)
             {
                 if(Blast_old==Blast_number-1)
                 {
                     a=0;
                     Blast_old=0;

                 }
                 if(time_blast1==5)
                 {
                     Init_Blast(&ship_blast[Blast_old],ship[0]);

                     Draw_Blast(&ship_blast[a],ship[0]);

                     time_blast1=1;
                 }

                 Move_Blast(&ship_blast[a]);
                 time_blast1++;
                 for(int b=0;b<comet_lives;b++)
                 {
                     if(ship[0].sx<=comet[b].sx+5&&ship[0].sx>=comet[b].sx-5)//飞船死亡
                     {
                         if (ship[0].sy<=comet[b].sy+5&&ship[0].sy>=comet[b].sy-5)
                         {

                             Init_ship(&ship[0],1);
                           //Init_star(&comet[b]);
                           //Init_Blast(&ship_blast[a],ship[0]);
                         }
                     }

                    if(ship_blast[a].sx<=comet[b].sx+10&&ship_blast[a].sx>=comet[b].sx-10) //子弹射中彗星
                     {
                         if (ship_blast[a].sy<=comet[b].sy+10&&ship_blast[a].sy>=comet[b].sy-10)
                         {

                           grade++;
                           if(time_star1==10)
                           {

                               Init_star(&comet[b]);
                               Init_Blast(&ship_blast[a],ship[0]);
                               time_star1=0;
                           }
                           time_star1++;
                         }
                     }
                 }
             }

         }
         // Draw_ship(&ship[1],sx,sy);
          //彗星2
         /*for (int a=0;a<Blast_old1;a++)
         {

             if(Blast_old1<Blast_number)
             {
                 if(Blast_old1==Blast_number-1)
                 {
                     a=0;
                     Blast_old1=0;

                 }
                 if(time_blast2==5)
                 {
                     Init_Blast(&ship_blast1[Blast_old1],ship[1]);

                     Draw_Blast(&ship_blast1[a],ship[1]);

                     time_blast2=1;
                 }

                 Move_Blast(&ship_blast1[a]);
                 time_blast2++;
                 for(int b=0;b<comet_lives;b++)
                 {
                     if(ship[1].sx<=comet[b].sx+5&&ship[1].sx>=comet[b].sx-5)//飞船死亡
                     {
                         if (ship[1].sy<=comet[b].sy+5&&ship[1].sy>=comet[b].sy-5)
                         {

                             Init_ship(&ship[1],2);
                           //Init_star(&comet[b]);
                           //Init_Blast(&ship_blast[a],ship[0]);
                         }
                     }

                    if(ship_blast1[a].sx<=comet[b].sx+10&&ship_blast1[a].sx>=comet[b].sx-10) //子弹射中彗星
                     {
                         if (ship_blast1[a].sy<=comet[b].sy+10&&ship_blast1[a].sy>=comet[b].sy-10)
                         {

                           grade++;
                           if(time_star2==10)
                           {

                               Init_star(&comet[b]);
                               Init_Blast(&ship_blast1[a],ship[1]);
                               time_star2=0;
                           }
                           time_star2++;
                         }
                     }
                 }
             }

         }*/


         al_flip_display();

      }

   }

   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
