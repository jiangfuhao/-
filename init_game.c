#include"game.h"
int Baozha()
{
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
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[2] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt02.png");
    if(!baoz[2])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[3] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt03.png");
    if(!baoz[3])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[4] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt04.png");
    if(!baoz[4])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[5] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt05.png");
    if(!baoz[5])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[6] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt06.png");
    if(!baoz[6])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[7] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt07.png");
    if(!baoz[7])
    {
        fprintf(stderr,"b0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    baoz[8] = al_load_bitmap("../startrek/爆炸/LAZY_LOAD_normal_new_hurt08.png");
    if(!baoz[8])
    {
        fprintf(stderr,"b0:Failed to load image!");
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

    setting[0] = al_load_bitmap("../startrek/a-12.png");
    if(!setting[0])
    {
        fprintf(stderr,"0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[1] = al_load_bitmap("../startrek/resultbg.jpg");
    if(!setting[1])
    {
        fprintf(stderr,"1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[2] = al_load_bitmap("../startrek/WD_6.png");
    if(!setting[2])
    {
        fprintf(stderr,"2:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[3] = al_load_bitmap("../startrek/map01-01.png");
    if(!setting[3])
    {
        fprintf(stderr,"3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[4] = al_load_bitmap("../startrek/upgrade_bule_line_003.png");
    if(!setting[4])
    {
        fprintf(stderr,"4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[5] = al_load_bitmap("../startrek/mini-boss00.png");
    if(!setting[5])
    {
        fprintf(stderr,"4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    /*pro = al_load_bitmap("../startrek/图片/waihuan.png");
    if(!pro)
    {
        fprintf(stderr,"pro:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    buff = al_load_bitmap("../startrek/图片/LAZY_LOAD_equip_empty2.png");
    if(!pro)
    {
        fprintf(stderr,"buff:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }*/
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
