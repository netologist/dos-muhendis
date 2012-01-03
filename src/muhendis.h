#ifndef _CEZA_H_
#define _CEZA_H_
#include "/ozgan/programs/h/genel.h"

typedef struct _MUHENDIS_DATA {
	char Mal_Shibi[36];
	char Kayit_No[8];
	char Yetkili[22];
	char Telefon[18];
	char Adres[53];
	char Ilce[18];
	char Mahalle[14];
	char Pafta[18];
	char Ada[13];
	char Parsel[9];
	char Ruhsat[10];
	char Santiye_Sefi[13];
	char Temel[2];
	char Bodrum[2];
	char Temel_Ustu[2];
	char Zemin[2];
	char Kat1[2];
	char Kat2[2];
	char Kat3[2];
	char Kat4[2];
	char Kat5[2];
	char Iskan[2];
	char Yapi_Bedeli[16];
	char Yapi_Sinifi[11];
	char Yapi_Alani[8];
	char Maliyeti[16];
	char Hizmet_Bedeli[16];
	char Hizmet_Orani[4];
	char KDV[16];
	char Toplam[16];
	char Taksit1_Oran[4];
	char Taksit1_Tutar[16];
	char Taskit1_Tarih[11];
	char Taksit2_Oran[4];
	char Taksit2_Tutar[16];
	char Taskit2_Tarih[11];
	char Taksit3_Oran[4];
	char Taksit3_Tutar[16];
	char Taskit3_Tarih[11];
	char Taksit4_Oran[4];
	char Taksit4_Tutar[16];
	char Taskit4_Tarih[11];
} MUHENDIS_DATA;

extern MUHENDIS_DATA *muhendis_data;
extern long kayit_adresi;
extern char *dataci;
extern TABLO_BILGI baslik;
extern TABLO_FORM *tablo;
extern int Islem_Kontrol;

#define Data_Muhendis		500
#define Form_MUHENDIS		10

void sinifi_bul(void);
void olustur(void);
int muhendis_kontrol(void);
void odeme_plani(void);
void bedel_hesapla(void);
void form(void);
void f2_tusu(void);
void f3_tusu(void);
void f4_tusu(void);
void f5_tusu(void);
void f6_tusu(void);
void otomatik(void);

#endif
