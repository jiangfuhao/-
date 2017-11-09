#include"game.h"
int Baozha()
{
    //comet
    baoz[0] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt00.png");
    if(!baoz[0])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[1] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt01.png");
    if(!baoz[1])
    {
        fprintf(stderr,"b1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[2] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt02.png");
    if(!baoz[2])
    {
        fprintf(stderr,"b3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[3] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt03.png");
    if(!baoz[3])
    {
        fprintf(stderr,"b3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[4] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt04.png");
    if(!baoz[4])
    {
        fprintf(stderr,"b4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[5] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt05.png");
    if(!baoz[5])
    {
        fprintf(stderr,"b5:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[6] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt06.png");
    if(!baoz[6])
    {
        fprintf(stderr,"b6:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[7] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt07.png");
    if(!baoz[7])
    {
        fprintf(stderr,"b7:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[8] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt08.png");
    if(!baoz[8])
    {
        fprintf(stderr,"b8:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    //xboss
    baoz_xb[0] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_00.png");
    if(!baoz_xb[0])
    {
        fprintf(stderr,"xb0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   baoz_xb[1] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_01.png");
    if(!baoz_xb[1])
    {
        fprintf(stderr,"xb1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[2] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_02.png");
    if(!baoz_xb[2])
    {
        fprintf(stderr,"xb3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[3] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_03.png");
    if(!baoz_xb[3])
    {
        fprintf(stderr,"xb3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[4] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_04.png");
    if(!baoz_xb[4])
    {
        fprintf(stderr,"xb4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[5] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_05.png");
    if(!baoz_xb[5])
    {
        fprintf(stderr,"xb5:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[6] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_06.png");
    if(!baoz_xb[6])
    {
        fprintf(stderr,"xb6:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[7] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_07.png");
    if(!baoz_xb[7])
    {
        fprintf(stderr,"xb7:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[8] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_08.png");
    if(!baoz_xb[8])
    {
        fprintf(stderr,"xb8:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[9] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_09.png");
    if(!baoz_xb[7])
    {
        fprintf(stderr,"xb7:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz_xb[10] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_gravity_1_10.png");
    if(!baoz_xb[8])
    {
        fprintf(stderr,"xb8:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    //boss
   boss_bz[0] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center00.png");
    if(!boss_bz[0])
    {
        fprintf(stderr,"bs0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[1] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center01.png");
    if(!boss_bz[1])
    {
        fprintf(stderr,"bs1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[2] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center02.png");
    if(!boss_bz[2])
    {
        fprintf(stderr,"bs3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[3] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center03.png");
    if(!boss_bz[3])
    {
        fprintf(stderr,"bs3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[4] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center04.png");
    if(!boss_bz[4])
    {
        fprintf(stderr,"bs4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[5] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center05.png");
    if(!boss_bz[5])
    {
        fprintf(stderr,"bs5:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[6] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center06.png");
    if(!boss_bz[6])
    {
        fprintf(stderr,"bs6:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[7] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center07.png");
    if(!boss_bz[7])
    {
        fprintf(stderr,"bs7:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[8] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center08.png");
    if(!boss_bz[8])
    {
        fprintf(stderr,"bs8:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[9] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center09.png");
    if(!boss_bz[9])
    {
        fprintf(stderr,"bs9:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
   boss_bz[10] = al_load_bitmap("../startrek/爆炸/boss_bomb/LAZY_LOAD_indra_cross_hurt_center10.png");
    if(!boss_bz[10])
    {
        fprintf(stderr,"bs10:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }


}

int GameInit()
{


    if(!al_init()) {
        fprintf(stderr,"error1:have not allegro\n");
        return -1;
    }
    //初始化音频系统
    if(!al_install_audio()){
       fprintf(stderr, "failed to initialize audio!\n");
       return -1;
    }
    if(!al_init_acodec_addon()){
       fprintf(stderr, "failed to initialize audio codecs!\n");
       return -1;
    }

    if (!al_reserve_samples(10)){
       fprintf(stderr, "failed to reserve samples!\n");
       return -1;
    }
    //音频文件载入
    sample[0] = al_load_sample("../startrek/音乐素材/GE2_LoadingAnimation.wav");
    if (!sample[0]){
       fprintf(stderr, "0:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[1] = al_load_sample("../startrek/音乐素材/GE2_Battle.wav");
    if (!sample[1]){
       fprintf(stderr, "1:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[2] = al_load_sample("../startrek/音乐素材/sfx_weapon_snowball_impact.wav");
    if (!sample[2]){
       fprintf(stderr, "2:Audio clip sample not loaded!\n" );
       return -1;
    }
    if (!al_install_keyboard()) {
        fprintf(stderr,"error2:Key\n");
        return -1;
    }
    //图片文件
    if(!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize image addon!\n");
       return -1;
    }
    photo[0] = al_load_bitmap("../startrek/photo1.png");
    if(!photo[0])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    photo[1] = al_load_bitmap("../startrek/photo2.png");
    if(!photo[1])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    photo[2] = al_load_bitmap("../startrek/photo3.png");
    if(!photo[2])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    photo[3] = al_load_bitmap("../startrek/photo4.png");
    if(!photo[2])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    setting[0] = al_load_bitmap("../startrek/1509544151865.png");
    if(!setting[0])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[1] = al_load_bitmap("../startrek/2620808089223323183.jpg");
    if(!setting[1])
    {
        fprintf(stderr,"1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[2] = al_load_bitmap("../startrek/1 (151).png");
    if(!setting[2])
    {
        fprintf(stderr,"2:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[3] = al_load_bitmap("../startrek/第一关.png");
    if(!setting[3])
    {
        fprintf(stderr,"3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[4] = al_load_bitmap("../startrek/bullet_06_01.png");
    if(!setting[4])
    {
        fprintf(stderr,"4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[5] = al_load_bitmap("../startrek/1 (81).png");
    if(!setting[5])
    {
        fprintf(stderr,"5:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    xboss = al_load_bitmap("../startrek/1 (75).png");
    if(!xboss)
    {
        fprintf(stderr,"xboss:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    pro = al_load_bitmap("../startrek/witch_cast_03.png");
    if(!pro)
    {
        fprintf(stderr,"pro:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    boss_blast[0] = al_load_bitmap("../startrek/bullet_07_01.png");
    if(!boss_blast[0])
    {
        fprintf(stderr,"boss_blast0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    xb_bl = al_load_bitmap("../startrek/bullet_01_03.png");
    if(!xb_bl)
    {
        fprintf(stderr,"xb_bl:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    //boff
    buffs[0] = al_load_bitmap("../startrek/buff/territorial_buff06.png");
    if(!buffs[0])
    {
        fprintf(stderr,"buff0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    buffs[1] = al_load_bitmap("../startrek/buff/territorial_buff01.png");
    if(!buffs[1])
    {
        fprintf(stderr,"buff1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    buffs[2] = al_load_bitmap("../startrek/buff/territorial_buff02.png");
    if(!buffs[2])
    {
        fprintf(stderr,"buff2:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    buffs[3] = al_load_bitmap("../startrek/buff/territorial_buff03.png");
    if(!buffs[3])
    {
        fprintf(stderr,"buff3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    buffs[4] = al_load_bitmap("../startrek/buff/territorial_buff04.png");
    if(!buffs[4])
    {
        fprintf(stderr,"buff4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    Baozha();
    if (!al_install_mouse()) {
        fprintf(stderr,"error3:mouse\n");
        return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    font[0] = al_load_ttf_font("../startrek/a.ttf",80,0);
    if(!font[0]){
        fprintf(stderr,"error:font1");
        return -1;
    }
    font[1] = al_load_ttf_font("../startrek/a.ttf",40,0);
    if(!font[1]){
        fprintf(stderr,"error:font2");
        return -1;
    }
    font[2] = al_load_ttf_font("../startrek/a.ttf",30,0);
    if(!font[2]){
        fprintf(stderr,"error:font3");
        return -1;
    }
    font[3] = al_load_ttf_font("../startrek/a.ttf",10,0);
    if(!font[3]){
        fprintf(stderr,"error:font3");
        return -1;
    }
    font[4] = al_load_ttf_font("../startrek/a.ttf",12,0);
    if(!font[4]){
        fprintf(stderr,"error:font4");
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
