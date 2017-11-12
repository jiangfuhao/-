#include "game.h"


int comp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

void Init_file(int grade)
{
    FILE *rank;
    FILE *plus;
    rank = fopen("../startrek/rank.txt","r");
    plus = fopen("../startrek/plus.txt","w");

    int buffer[3];
    int i = 0;

    for(i=0;i<3;i++){
        fscanf(rank,"%d ",&buffer[i]);
    }

    if(grade > buffer[2]){
        buffer[2] = grade;
    }
    qsort(buffer,3,sizeof(int),comp);

    for(i=0;i<3;i++){
        fprintf(plus,"%d ",buffer[i]);
    }

    fclose(rank);
    fclose(plus);

    unlink("../startrek/rank.txt");
    rename("../startrek/plus.txt","../startrek/rank.txt");
}

void gamegrade(int grade)
{
     //al_destroy_sample(sample[0]);
     //al_destroy_sample(sample[1]);
     //al_destroy_sample(sample[2]);
    int n=0;
    int q=1;
    int redraw2 = 1;

    al_clear_to_color(al_map_rgb(255,155,155));
    al_flip_display();
    Init_file(grade);

    FILE *fp;
    fp = fopen("../startrek/rank.txt","r");
    int number[3];
    int i = 0;
    for(i=0;i<3;i++){
        fscanf(fp,"%d ",&number[i]);
    }

    fclose(fp);


    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform,0,0);
    al_use_transform(&transform);

    char a[10], b[10], c[10], Grade[10];
    sprintf(Grade,"%d",grade);
    sprintf(a,"%d",number[0]);
    sprintf(b,"%d",number[1]);
    sprintf(c,"%d",number[2]);
    al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-175,ALLEGRO_ALIGN_CENTRE,"你的得分是:");
    al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-100,ALLEGRO_ALIGN_CENTRE,Grade);
    if(grade == number[0])
    {
        al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-30,ALLEGRO_ALIGN_CENTRE,"恭喜你获得了冠军!");
        al_draw_bitmap(photo[0],30,50,0);
    }
    else if(grade < number[2])
    {
        al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-30,ALLEGRO_ALIGN_CENTRE,"很遗憾未上榜，再接再厉");
        al_draw_bitmap(photo[1],30,50,0);
    }
    else if(grade ==number[1] || grade == number[2])
    {
        al_draw_text(font[1],black,DISPLAY_W/2,DISPLAY_H/3-30,ALLEGRO_ALIGN_CENTRE,"上榜啦！继续加油");
        al_draw_bitmap(photo[2],30,50,0);
    }

    al_draw_text(font[1],black,DISPLAY_W/2-100,DISPLAY_H/3+50,ALLEGRO_ALIGN_CENTRE,"第一名:");

    al_draw_text(font[1],black,DISPLAY_W/2+100,DISPLAY_H/3+50,ALLEGRO_ALIGN_CENTRE,a);
    al_draw_text(font[1],black,DISPLAY_W/2-100,DISPLAY_H/3+175,ALLEGRO_ALIGN_CENTRE,"第二名:");

    al_draw_text(font[1],black,DISPLAY_W/2+100,DISPLAY_H/3+175,ALLEGRO_ALIGN_CENTRE,b);
    al_draw_text(font[1],black,DISPLAY_W/2-100,DISPLAY_H/3+300,ALLEGRO_ALIGN_CENTRE,"第三名:");

    al_draw_text(font[1],black,DISPLAY_W/2+100,DISPLAY_H/3+300,ALLEGRO_ALIGN_CENTRE,c);


    al_flip_display();


    while(n!=1)
    {

        al_wait_for_event(event_queue,&ev);
        if(ev.type == ALLEGRO_EVENT_TIMER) {

            redraw2 = 1;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                if(q==1)
                {
                    n=1;
                }
                break;
            case ALLEGRO_KEY_UP:
                n=1;
                break;
            case ALLEGRO_KEY_DOWN:
                n=1;
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {

            }
        }
        if(redraw2 && al_is_event_queue_empty(event_queue))
        {
            redraw2 = 0;

            al_identity_transform(&transform);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);

            switch (n){
            case 0:
                if(q==1){
                    al_draw_text(font[1],white,DISPLAY_W/2-350,DISPLAY_H/2+150,ALLEGRO_ALIGN_CENTRE,"返回");
                }
                al_flip_display();
                break;
            case 1:
                break;
            }
        }
    }
}
