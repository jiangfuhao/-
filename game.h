#ifndef GAME_H
#define GAME_H

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/fmaths.h>
typedef struct {
    float sx;//位置
    float sy;
    float heading;//方向
    float twist;//角度
    float speed;//速度
    float rot_velocity; //转速;
    float scale;//大小
    int gone;//是否毁灭
    ALLEGRO_COLOR color;

}Asteroid;//彗星
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    //Blast *next;
    ALLEGRO_COLOR color;
}Blast;//炮弹
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;

}Spaceship;//飞船
ALLEGRO_DISPLAY *display ;
ALLEGRO_EVENT_QUEUE *event_queue ;
ALLEGRO_TIMER *timer ;
ALLEGRO_TRANSFORM transform;
ALLEGRO_FONT *font1;
ALLEGRO_FONT *font2;
ALLEGRO_FONT *font3;

ALLEGRO_EVENT ev;
#define black     al_map_rgb(0,0,0)       //黑色
#define green     al_map_rgb(0,255,0)   //绿色
#define yellow    al_map_rgb(255,255,0)     //黄色
#define white     al_map_rgb(255,255,255) //白色
#define red       al_map_rgb(255,0,0)   //红色
#define blu       al_map_rgb(0,100,255)
#endif // GAME_H
