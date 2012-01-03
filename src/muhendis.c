#include "/ozgan/programs/h/genel.h"
#include "src/muhendis.h"
long kayit_adresi;
char *dataci;
TABLO_BILGI baslik;
TABLO_FORM *tablo;
MUHENDIS_DATA *muhendis_data;
int Islem_Kontrol = 0;
/*-----------------------------------------------------------------------*/
void mesaj_goster_kac(char *string)
{
	char *bellek;
	int alan;

	bellek = malloc(1000);
	gettext(7, 4, 35, 7, bellek);
	alan = strlen(string);

	if (alan > 20)
		strcpy(&string[18], "...");

	ince_cerceve(3, 6, 1, 22, SIYAH_ | A_BEYAZ);
	doldur(4, 7, ' ', 21, SIYAH_);
	harfler(4, 8, string, SIYAH_ | SARI);
	delay(350);
	puttext(7, 4, 35, 7, bellek);
	free(bellek);
}

int islem(void)
{
	int ch;

	ch = getkb();
	switch (ch) {
		case F1 : return ch;
		case F2 : f2_tusu(); return ch;
		case F3 : f3_tusu(); return ch;
		case F4 : f4_tusu(); return ch;
		case F5 : f5_tusu(); return ch;
		case F6 : f6_tusu(); return ch;
		case F7 : olustur(); return NULL;
		default : return ch;
	}
}

void kmenu_islem(char *data, TABLO_FORM *tablo, TABLO_BILGI *baslik, int sayac)
{
	switch (tablo[sayac].referans) {
		case 1:
		break;
	}
}

int menu_sec(char *veri, int satir, int kolon, int uzunluk, int eleman_referansi, char *depo_dizi)
{
	MENU menu;
	int ch;

	mib_al(&menu);

	switch (eleman_referansi) {
		case 1:;
	}
	if (depo_dizi == NULL)
		ch = menu_cagir(&menu, veri);
	else {
		if (veri[0] == 0)
			veri[0] = '0';

		dizi_yapici(&menu, (char) atoi(veri), depo_dizi);
		harfler(satir, kolon, depo_dizi, menu.AktifSecili);
	}
	mib_ver(&menu);
	return ch;
}

void cerceve(void)
{
	int n;

	for (n = 0; n < 25; n++)
		doldur(n, 0, 'Û', 80, GRI);
	for (n = 0; n < 22; n++) {
		doldur(1+n, 2, ' ', 75, CYAN_);
		doldur(1+n, 5, ' ', 69, BEYAZ_);
	}
	kalin_cerceve(1, 3, 20, 72, CYAN_ | A_BEYAZ);
	doldur(2, 5, ' ', 69, KAHVE_);
	harfler(2, 25, " Mhendis Yardmcs v.1.00a", KAHVE_ | A_BEYAZ);
	disa_pen(3, 6, 17, 66);
	harfler(4, 8, "Mal Sahibi                                     Kayt No", BEYAZ_ | SIYAH);
	harfler(5, 8, "   Yetkili                       Telefon", BEYAZ_ | SIYAH);
	harfler(6, 8, "     Adres", BEYAZ_ | SIYAH);
	harfler(7, 8, "      ˜l‡e                   Mahalle", BEYAZ_ | SIYAH);
	harfler(8, 8, "     Pafta                   Ada                Parsel", BEYAZ_ | SIYAH);
	cift_renk(9, 7, "Ruhsat No&³žantiye žefi&³Temel&³Bodrum&³T. Ustu&³Zemin&³1&³2&³3&³4&³5&³˜skan", CYAN_ | A_BEYAZ, CYAN_ | SIYAH);
	harfler(10, 7, "         ³            ³     ³      ³       ³     ³ ³ ³ ³ ³ ³", BEYAZ_ | SIYAH);
	doldur(11, 7, ' ', 65, CYAN_);
	harfler(11, 27, " Yap Snf Bedel Bilgisi", CYAN_ | A_BEYAZ);
	harfler(12, 7, "   Yap Bedeli                  Snf             Alan         ", BEYAZ_ | SIYAH);
	harfler(13, 7, "      Maliyeti             ", BEYAZ_ | SIYAH);
	harfler(14, 7, " Hizmet Bedeli                  Oran (binde)", BEYAZ_ | SIYAH);
	harfler(15, 7, "     K.D.V %17                         Toplam", BEYAZ_ | SIYAH);
	doldur(16, 7, ' ', 65, SIYAH_);
	cift_renk(16, 7, "          ™deme Plan         &³ Oran       Tutar       ˜stihkak ", CYAN_ | A_BEYAZ, CYAN_ | BEYAZ);
	harfler(17, 7, " 1. Taksit............Subasman", BEYAZ_ | SIYAH);
	harfler(18, 7, " 2. Taksit.....TaŸyc Sistem", BEYAZ_ | SIYAH);
	harfler(19, 7, " 3. Taksit..Svaya hazr durum", BEYAZ_ | SIYAH);
	harfler(20, 7, " 4. Taksit.........Kalan B”lm", BEYAZ_ | SIYAH);
	cift_renk(24, 0, "  &F&1 Yardm ³  &F&2 Ekle   &F&3 Sil   &F&4 Yeni   &F&5 Liste   &F&6 Yazc  ³ &F&7 OluŸtur  ", SIYAH_ | A_BEYAZ, SIYAH_ | SARI);
	harf(24, 12, '³', SIYAH_ | BEYAZ);
	harf(24, 66, '³', SIYAH_ | BEYAZ);
}

void form(void)
{
	TABLO_BILGI baslik2 = {42, sizeof(MUHENDIS_DATA), Form_MUHENDIS, 0};
	TABLO_FORM tablo2[] = {{Data_Muhendis, YAZI, 2, 18, 35, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 2, 63, 7, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Indeks_Bilgisi, SONRA},
						   {Data_Muhendis, YAZI, 3, 18, 21, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 3, 48, 17, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 4, 18, 52, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 5, 18, 17, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 5, 44, 13, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 6, 18, 17, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 6, 42, 12, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 6, 62, 8, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 8, 6, 9, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 8, 16, 12, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 31, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 37, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 45, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 52, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 56, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 58, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 60, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 62, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 64, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, KARE_KUTU, 8, 68, 1, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, SAYI, 10, 22, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 10, 45, 10, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 10, 63, 7, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, SAYI, 11, 22, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 12, 22, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 12, 52, 3, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, SAYI, 13, 22, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 13, 55, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, YAZI, 15, 38, 3, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 15, 43, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, TARIH, 15, 60, 10, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 16, 38, 3, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 16, 43, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, TARIH, 16, 60, 10, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 17, 38, 3, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 17, 43, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, TARIH, 17, 60, 10, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						   {Data_Muhendis, YAZI, 18, 38, 3, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, SAYI, 18, 43, 15, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, YOK},
						   {Data_Muhendis, TARIH, 18, 60, 10, SIYAH_ | A_BEYAZ, BEYAZ_ | A_BEYAZ, Data_Bos_Referans, SONRA},
						  };

	tabloyarat("bin/muhendis.tbl", &baslik2, tablo2);
	tablo = (TABLO_FORM *) tabloyukle("bin/muhendis.tbl", &baslik);
	dataci = (char *) malloc(baslik.data_uzunlugu);
	if (dataci == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	memset(dataci, 0, baslik.data_uzunlugu);
	muhendis_data = (MUHENDIS_DATA *) dataci;
	f4_tusu();
	tablo_oynatici(2, 1, Data_Muhendis, (char *) dataci, tablo, &baslik);
	git_xy(0, 0);
	kayit_adresi = 0;
	baslik.referans = 0;
	free(dataci);
}

void main(void)
{
	clrscr();
	uyarici = -1;
	renkli = 31;
	git_xy(-1, 0);
	cerceve();
BAS:
	form();
	cikis();
	goto BAS;
}