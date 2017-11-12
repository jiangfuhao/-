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
int Start_imge()
{

    kaichang[0] = al_load_bitmap("../startrek/开场/0.png");
    if(!kaichang[0])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[1] = al_load_bitmap("../startrek/开场/1.png");
    if(!kaichang[1])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[2] = al_load_bitmap("../startrek/开场/2.png");
    if(!kaichang[2])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[3] = al_load_bitmap("../startrek/开场/3.png");
    if(!kaichang[3])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[4] = al_load_bitmap("../startrek/开场/4.png");
    if(!kaichang[4])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[5] = al_load_bitmap("../startrek/开场/5.png");
    if(!kaichang[5])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[6] = al_load_bitmap("../startrek/开场/6.png");
    if(!kaichang[6])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[7] = al_load_bitmap("../startrek/开场/7.png");
    if(!kaichang[7])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[8] = al_load_bitmap("../startrek/开场/8.png");
    if(!kaichang[8])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[9] = al_load_bitmap("../startrek/开场/9.png");
    if(!kaichang[9])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[10] = al_load_bitmap("../startrek/开场/10.png");
    if(!kaichang[10])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[11] = al_load_bitmap("../startrek/开场/11.png");
    if(!kaichang[11])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[12] = al_load_bitmap("../startrek/开场/12.png");
    if(!kaichang[12])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[13] = al_load_bitmap("../startrek/开场/13.png");
    if(!kaichang[13])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[14] = al_load_bitmap("../startrek/开场/14.png");
    if(!kaichang[14])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[15] = al_load_bitmap("../startrek/开场/15.png");
    if(!kaichang[15])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[16] = al_load_bitmap("../startrek/开场/16.png");
    if(!kaichang[16])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[17] = al_load_bitmap("../startrek/开场/17.png");
    if(!kaichang[17])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[18] = al_load_bitmap("../startrek/开场/18.png");
    if(!kaichang[18])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[19] = al_load_bitmap("../startrek/开场/19.png");
    if(!kaichang[19])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[20] = al_load_bitmap("../startrek/开场/20.png");
    if(!kaichang[20])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[21] = al_load_bitmap("../startrek/开场/21.png");
    if(!kaichang[21])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[22] = al_load_bitmap("../startrek/开场/22.png");
    if(!kaichang[22])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[23] = al_load_bitmap("../startrek/开场/23.png");
    if(!kaichang[23])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[24] = al_load_bitmap("../startrek/开场/24.png");
    if(!kaichang[24])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[25] = al_load_bitmap("../startrek/开场/25.png");
    if(!kaichang[25])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[26] = al_load_bitmap("../startrek/开场/26.png");
    if(!kaichang[26])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[27] = al_load_bitmap("../startrek/开场/27.png");
    if(!kaichang[27])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[28] = al_load_bitmap("../startrek/开场/28.png");
    if(!kaichang[28])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[29] = al_load_bitmap("../startrek/开场/29.png");
    if(!kaichang[29])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[30] = al_load_bitmap("../startrek/开场/30.png");
    if(!kaichang[30])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[31] = al_load_bitmap("../startrek/开场/31.png");
    if(!kaichang[31])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    kaichang[32] = al_load_bitmap("../startrek/开场/32.png");
    if(!kaichang[32])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[33] = al_load_bitmap("../startrek/开场/33.png");
    if(!kaichang[33])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[34] = al_load_bitmap("../startrek/开场/34.png");
    if(!kaichang[34])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[35] = al_load_bitmap("../startrek/开场/35.png");
    if(!kaichang[35])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[36] = al_load_bitmap("../startrek/开场/36.png");
    if(!kaichang[36])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[37] = al_load_bitmap("../startrek/开场/37.png");
    if(!kaichang[37])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[38] = al_load_bitmap("../startrek/开场/38.png");
    if(!kaichang[38])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[39] = al_load_bitmap("../startrek/开场/39.png");
    if(!kaichang[39])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[40] = al_load_bitmap("../startrek/开场/40.png");
    if(!kaichang[40])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[41] = al_load_bitmap("../startrek/开场/41.png");
    if(!kaichang[41])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[42] = al_load_bitmap("../startrek/开场/42.png");
    if(!kaichang[42])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[43] = al_load_bitmap("../startrek/开场/43.png");
    if(!kaichang[43])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[44] = al_load_bitmap("../startrek/开场/44.png");
    if(!kaichang[44])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[45] = al_load_bitmap("../startrek/开场/45.png");
    if(!kaichang[45])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[46] = al_load_bitmap("../startrek/开场/46.png");
    if(!kaichang[46])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[47] = al_load_bitmap("../startrek/开场/47.png");
    if(!kaichang[47])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[48] = al_load_bitmap("../startrek/开场/48.png");
    if(!kaichang[48])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[49] = al_load_bitmap("../startrek/开场/49.png");
    if(!kaichang[49])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[50] = al_load_bitmap("../startrek/开场/50.png");
    if(!kaichang[50])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[51] = al_load_bitmap("../startrek/开场/51.png");
    if(!kaichang[51])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[52] = al_load_bitmap("../startrek/开场/52.png");
    if(!kaichang[52])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[53] = al_load_bitmap("../startrek/开场/53.png");
    if(!kaichang[53])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[54] = al_load_bitmap("../startrek/开场/54.png");
    if(!kaichang[54])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[55] = al_load_bitmap("../startrek/开场/55.png");
    if(!kaichang[55])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[56] = al_load_bitmap("../startrek/开场/56.png");
    if(!kaichang[56])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[57] = al_load_bitmap("../startrek/开场/57.png");
    if(!kaichang[57])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[58] = al_load_bitmap("../startrek/开场/58.png");
    if(!kaichang[58])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[59] = al_load_bitmap("../startrek/开场/59.png");
    if(!kaichang[59])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[60] = al_load_bitmap("../startrek/开场/60.png");
    if(!kaichang[60])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[61] = al_load_bitmap("../startrek/开场/61.png");
    if(!kaichang[61])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    kaichang[62] = al_load_bitmap("../startrek/开场/62.png");
    if(!kaichang[62])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[63] = al_load_bitmap("../startrek/开场/63.png");
    if(!kaichang[63])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[64] = al_load_bitmap("../startrek/开场/64.png");
    if(!kaichang[64])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[65] = al_load_bitmap("../startrek/开场/65.png");
    if(!kaichang[65])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[66] = al_load_bitmap("../startrek/开场/66.png");
    if(!kaichang[66])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[67] = al_load_bitmap("../startrek/开场/67.png");
    if(!kaichang[67])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[68] = al_load_bitmap("../startrek/开场/68.png");
    if(!kaichang[68])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[69] = al_load_bitmap("../startrek/开场/69.png");
    if(!kaichang[69])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[70] = al_load_bitmap("../startrek/开场/70.png");
    if(!kaichang[70])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[71] = al_load_bitmap("../startrek/开场/71.png");
    if(!kaichang[71])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[72] = al_load_bitmap("../startrek/开场/72.png");
    if(!kaichang[72])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[73] = al_load_bitmap("../startrek/开场/73.png");
    if(!kaichang[73])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[74] = al_load_bitmap("../startrek/开场/74.png");
    if(!kaichang[74])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[75] = al_load_bitmap("../startrek/开场/75.png");
    if(!kaichang[75])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[76] = al_load_bitmap("../startrek/开场/76.png");
    if(!kaichang[76])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[77] = al_load_bitmap("../startrek/开场/77.png");
    if(!kaichang[77])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[78] = al_load_bitmap("../startrek/开场/78.png");
    if(!kaichang[78])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[79] = al_load_bitmap("../startrek/开场/79.png");
    if(!kaichang[79])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[80] = al_load_bitmap("../startrek/开场/80.png");
    if(!kaichang[80])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[81] = al_load_bitmap("../startrek/开场/81.png");
    if(!kaichang[81])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[82] = al_load_bitmap("../startrek/开场/82.png");
    if(!kaichang[82])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[83] = al_load_bitmap("../startrek/开场/83.png");
    if(!kaichang[83])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    kaichang[84] = al_load_bitmap("../startrek/开场/84.png");
    if(!kaichang[84])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[85] = al_load_bitmap("../startrek/开场/85.png");
    if(!kaichang[85])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[86] = al_load_bitmap("../startrek/开场/86.png");
    if(!kaichang[86])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[87] = al_load_bitmap("../startrek/开场/87.png");
    if(!kaichang[87])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[88] = al_load_bitmap("../startrek/开场/88.png");
    if(!kaichang[88])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[89] = al_load_bitmap("../startrek/开场/89.png");
    if(!kaichang[89])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[90] = al_load_bitmap("../startrek/开场/90.png");
    if(!kaichang[90])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[91] = al_load_bitmap("../startrek/开场/91.png");
    if(!kaichang[91])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    kaichang[92] = al_load_bitmap("../startrek/开场/92.png");
    if(!kaichang[92])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[93] = al_load_bitmap("../startrek/开场/93.png");
    if(!kaichang[93])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[94] = al_load_bitmap("../startrek/开场/94.png");
    if(!kaichang[94])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[95] = al_load_bitmap("../startrek/开场/95.png");
    if(!kaichang[95])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[96] = al_load_bitmap("../startrek/开场/96.png");
    if(!kaichang[96])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[97] = al_load_bitmap("../startrek/开场/97.png");
    if(!kaichang[97])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[98] = al_load_bitmap("../startrek/开场/98.png");
    if(!kaichang[98])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[99] = al_load_bitmap("../startrek/开场/99.png");
    if(!kaichang[99])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[100] = al_load_bitmap("../startrek/开场/100.png");
    if(!kaichang[100])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    kaichang[101] = al_load_bitmap("../startrek/开场/101.png");
    if(!kaichang[101])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[102] = al_load_bitmap("../startrek/开场/102.png");
    if(!kaichang[102])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[103] = al_load_bitmap("../startrek/开场/103.png");
    if(!kaichang[103])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[104] = al_load_bitmap("../startrek/开场/104.png");
    if(!kaichang[104])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[105] = al_load_bitmap("../startrek/开场/105.png");
    if(!kaichang[105])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[106] = al_load_bitmap("../startrek/开场/106.png");
    if(!kaichang[106])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[107] = al_load_bitmap("../startrek/开场/107.png");
    if(!kaichang[107])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[108] = al_load_bitmap("../startrek/开场/108.png");
    if(!kaichang[108])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[109] = al_load_bitmap("../startrek/开场/109.png");
    if(!kaichang[109])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[110] = al_load_bitmap("../startrek/开场/110.png");
    if(!kaichang[110])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[111] = al_load_bitmap("../startrek/开场/111.png");
    if(!kaichang[111])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[112] = al_load_bitmap("../startrek/开场/112.png");
    if(!kaichang[112])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[113] = al_load_bitmap("../startrek/开场/113.png");
    if(!kaichang[113])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[114] = al_load_bitmap("../startrek/开场/114.png");
    if(!kaichang[114])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    kaichang[115] = al_load_bitmap("../startrek/开场/115.png");
    if(!kaichang[115])
    {
        fprintf(stderr,"kai0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }



}
int Music_init()
{
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

    sample[0] = al_load_sample("../startrek/音乐素材/73590.wav");
    if (!sample[0]){
       fprintf(stderr, "0:Audio clip sample not loaded!\n" );
       return -1;
    }

    sample[1] = al_load_sample("../startrek/音乐素材/2134.wav");
    if (!sample[1]){
       fprintf(stderr, "1:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[2] = al_load_sample("../startrek/音乐素材/2133.wav");
    if (!sample[2]){
       fprintf(stderr, "2:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[3] = al_load_sample("../startrek/音乐素材/2132.wav");
    if (!sample[3]){
       fprintf(stderr, "3:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[4] = al_load_sample("../startrek/音乐素材/GE2_BattleLose.wav");
    if (!sample[4]){
       fprintf(stderr, "4:Audio clip sample not loaded!\n" );
       return -1;
    }
    sample[5] = al_load_sample("../startrek/音乐素材/GE2_BattleMap.wav");
    if (!sample[5]){
       fprintf(stderr, "5:Audio clip sample not loaded!\n" );
       return -1;
    }

}

int GameInit(int i)
{

    if(!al_init()) {
        fprintf(stderr,"error1:have not allegro\n");
        return -1;
    }

    //
    if (!al_install_keyboard()) {
        fprintf(stderr,"error2:Key\n");
        return -1;
    }
    //图片文件
    if(!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize image addon!\n");
       return -1;
    }
    if(i==0)
    {
        Start_imge();      //开场动漫
    }
    photo[0] = al_load_bitmap("../startrek/图片/photo1.png");
    if(!photo[0])
    {
        fprintf(stderr,"ph0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    photo[1] = al_load_bitmap("../startrek/图片/photo2.png");
    if(!photo[1])
    {
        fprintf(stderr,"ph1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    photo[2] = al_load_bitmap("../startrek/图片/photo3.png");
    if(!photo[2])
    {
        fprintf(stderr,"ph2:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    photo[3] = al_load_bitmap("../startrek/图片/photo4.png");
    if(!photo[2])
    {
        fprintf(stderr,"ph3:Failed to load image!");
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
    setting[1] = al_load_bitmap("../startrek/beijing.jpeg");
    if(!setting[1])
    {
        fprintf(stderr,"1:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[2] = al_load_bitmap("../startrek/敌机/1 (151).png");
    if(!setting[2])
    {
        fprintf(stderr,"2:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[3] = al_load_bitmap("../startrek/map/第一关.png");
    if(!setting[3])
    {
        fprintf(stderr,"3:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[4] = al_load_bitmap("../startrek/子弹/bullet_06_01.png");
    if(!setting[4])
    {
        fprintf(stderr,"4:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    setting[5] = al_load_bitmap("../startrek/boss/1 (81).png");
    if(!setting[5])
    {
        fprintf(stderr,"seting5:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    xboss = al_load_bitmap("../startrek/敌机/1 (75).png");
    if(!xboss)
    {
        fprintf(stderr,"xboss:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    pro = al_load_bitmap("../startrek/图片/witch_cast_02.png");
    if(!pro)
    {
        fprintf(stderr,"pro:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }

    boss_blast[0] = al_load_bitmap("../startrek/子弹/bullet_07_01.png");
    if(!boss_blast[0])
    {
        fprintf(stderr,"boss_blast0:Failed to load image!");
        al_destroy_display(display);
        return -1;
    }
    xb_bl = al_load_bitmap("../startrek/子弹/bullet_01_03.png");
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
