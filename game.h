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
    int TX; //特效
    int s_time;
    ALLEGRO_COLOR color;


}Asteroid;//彗星

struct Blast{
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    struct Blast *next;
    ALLEGRO_COLOR color;
};//炮弹
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    int live;//生命值
    int energy;
    int pro;

}Spaceship;//飞船
typedef struct {
    float sx;//位置
    float sy;
    float heading;//方向
    float speed;//速度
    float live;  //生命值
    int xy;//范围
    int gone;//是否毁灭
}BOSS1;
typedef struct {
    float sx;
    float sy;
    float heading;
    float twist;//角度
    float speed;//速度
    float rot_velocity; //转速;
    int kind;
}BUFF;
ALLEGRO_DISPLAY *display ;
ALLEGRO_EVENT_QUEUE *event_queue ;
ALLEGRO_TIMER *timer ;
ALLEGRO_TRANSFORM transform;
ALLEGRO_FONT *font[5];

ALLEGRO_SAMPLE *sample[10];
ALLEGRO_BITMAP *setting[10];
ALLEGRO_BITMAP *baoz[10];
ALLEGRO_BITMAP *photo[5];
//ALLEGRO_BITMAP *pro;// 保护罩
ALLEGRO_BITMAP *buff;
ALLEGRO_EVENT ev;
//const int DISPLAY_W = 1100;//屏幕宽度
//const int DISPLAY_H = 700;//屏幕高度
#define DISPLAY_H 700          //屏幕高度
#define DISPLAY_W 1250              //屏幕宽度
#define FPS 60

//彗星函数
int Init_star(Asteroid *c);
int Draw_star(Asteroid *c);
int move_star(Asteroid *c);
int Scope_star(Asteroid *c);
//初始化
int GameInit();
//战机函数
int Ship_grade(int grade);
int Init_ship(Spaceship *s ,int i);
int Draw_ship(Spaceship *s);
//音乐
int music_game(int i,float choose);
//boss
int init_boss(BOSS1 *boss);
int Draw_boss(BOSS1 *boss);
int Move_boss(BOSS1 *boss);
//地图
//爆炸
int Baozha();
int bomb(Asteroid *c,int time_bomb);
//int map_game();
#define black     al_map_rgb(0,0,0)       //黑色
#define green     al_map_rgb(0,255,0)   //绿色
#define yellow    al_map_rgb(255,255,0)     //黄色
#define white     al_map_rgb(255,255,255) //白色
#define red       al_map_rgb(255,0,0)   //红色
#define blu       al_map_rgb(0,100,255)
#endif // GAME_H
