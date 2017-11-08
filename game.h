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
#define DISPLAY_H 700          //屏幕高度
#define DISPLAY_W 1250              //屏幕宽度
#define FPS 60
#define BOSSBlast_number 100
#define XBOSS_number 6
#define comet_lives 10//彗星个数
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

}BOSS_Blast;//boss炮弹
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
    int old_blast;
    int time_b;
    int blast_type;//子弹类型
    int TX;
    BOSS_Blast blast1[BOSSBlast_number];
    BOSS_Blast blast2[BOSSBlast_number];
}BOSS1;
typedef struct {
    float sx;//位置
    float sy;
    float heading;//方向
    float twist;//角度
    float speed;//速度
    float rot_velocity; //转速;
    float live;  //生命值
    int xy;//范围
    int gone;//是否毁灭
    int TX; //特效
    int s_time;
    int fly_mode;//运动模式
    int ratation;
    BOSS_Blast blast;
}XBOSS;
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
ALLEGRO_BITMAP *xboss;
ALLEGRO_BITMAP *setting[6];
ALLEGRO_BITMAP *baoz[10];
ALLEGRO_BITMAP *baoz_xb[11];
ALLEGRO_BITMAP *xb_bl;
ALLEGRO_BITMAP *pro;// 保护罩
ALLEGRO_BITMAP *buff;
ALLEGRO_BITMAP *boss_blast[5];
ALLEGRO_EVENT ev;

//彗星函数
int Init_star(Asteroid *c);
int Draw_star(Asteroid *c);
int move_star(Asteroid *c);
int Scope_star(Asteroid *c);
int hit_star(Asteroid comet[],int *time_star1,Spaceship *ship);

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
int Draw_boss(BOSS1 *boss,Spaceship *s);
int Move_boss(BOSS1 *boss,Spaceship *s);
int hit_boss(BOSS1 boss, struct Blast *blast_h);
int init_bs_blast(BOSS1 *boss,Spaceship *s);
int Draw_bs_blast(BOSS1 *boss);
double count_head(double x,double y,Spaceship *s);
int hit_ship(Spaceship *s,BOSS1 *b);
//地图
int map_game(int *map_h);
//爆炸
int Baozha();
int bomb(Asteroid *c,int time_bomb);
//子弹
int Init_Blast(struct Blast* *b);
int Insert_Blast(struct Blast* *b,Spaceship s);
int Delete_Blast(struct Blast* *b,int pos);
int Draw_Blast(struct Blast* *b,Spaceship s);
int Scope_Blast(struct Blast* *b,Spaceship s);
int Move_Blast( struct Blast* *b);

int init_xb_blast(BOSS_Blast xb_blast[]);                 //初始xboss子弹
int lord_xb_blast(XBOSS *xb,BOSS_Blast *xb_blast,Spaceship *s);         //发射子弹
int Draw_xb_blast(BOSS_Blast xb_blast[]);
int Move_xb_blast(BOSS_Blast *xb_bl);
double count_head(double x,double y,Spaceship *s);         //追宗飞船
int xb_bhit_star(BOSS_Blast xb_blast[],Spaceship *s);
//xboss
int init_xboss(XBOSS xb[],BOSS_Blast xb_blast[]);
int Draw_xboss(XBOSS *xb,BOSS_Blast *xb_bl,Spaceship *s);
int hit_ship_xb(Spaceship *s,XBOSS xb[],BOSS_Blast xb_blast[]);
int judge_xboss(XBOSS xb[]);                              //判断xboss是否全部消失
int Move_xboss(XBOSS *xb,BOSS_Blast *xb_blast,Spaceship *s);

#define black     al_map_rgb(0,0,0)       //黑色
#define green     al_map_rgb(0,255,0)   //绿色
#define yellow    al_map_rgb(255,255,0)     //黄色
#define white     al_map_rgb(255,255,255) //白色
#define red       al_map_rgb(255,0,0)   //红色
#define blu       al_map_rgb(0,100,255)
#endif // GAME_H
