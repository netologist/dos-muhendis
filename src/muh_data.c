#include "/ozgan/programs/h/genel.h"
#include "src/muhendis.h"

void f2_tusu(void)
{
	DOSYA handle;

	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = (char *) dataci;

	strcpy(handle.ana_dosya, "muhendis.dat");
	strcpy(handle.indeks_dosya, "muhendis.ind");
	strcpy(handle.yol, "data/");

//	dosya_yarat(&handle);
	if (Islem_Kontrol == 0)
		msj_kutu(NULL, "Ltfen ”nce \"F7 OluŸtur\" iŸlemini yapn", UYARI);
	else {
		if (kayit_adresi == 0) {
			kayit_adresi = dosya_kayit(&handle);
			if (kayit_adresi == 0)
				msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);
			else {
				mesaj_goster_kac("Kayt_Eklendi");
				indeks_bilgisi(tablo, &baslik, INDEKS_KAPA);
			}
		}
		else {
			dosya_ac(&handle);
			detay_oku(&handle, kayit_adresi, DATA_ALMA);
			memcpy(handle.ana_detay->data, dataci, baslik.data_uzunlugu);
			indeks_uzunlugu(&handle, handle.indeks_detay->data);
			eski_kayit(&handle, kayit_adresi);
			dosya_kapa(&handle);
			mesaj_goster_kac("De§iŸtirildi !..");
		}
	}
}

void f3_tusu(void)
{

}

void f4_tusu(void)
{
	memset(muhendis_data, 0, baslik.data_uzunlugu);
	strcpy(muhendis_data->Hizmet_Orani, "76");
	otomatik();
	Islem_Kontrol = 0;
	kayit_adresi = 0;
	tablo_yerlestir(2, 1, Data_Muhendis, (char *) dataci, tablo, &baslik);
	uyari_gonder(0);
}

void f5_tusu(void)
{

}

void f6_tusu(void)
{

}

void otomatik(void)
{
	DOSYA handle;
	MUHENDIS_DATA *data_muhendis;
	unsigned int sayi;

	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = (char *) dataci;

	strcpy(handle.ana_dosya, "muhendis.dat");
	strcpy(handle.indeks_dosya, "muhendis.ind");
	strcpy(handle.yol, "data/");

	dosya_ac(&handle);
	detay_oku(&handle, handle.indeks_baslik->son_kayit, DATA_AL);
	data_muhendis = (MUHENDIS_DATA *) handle.ana_detay->data;
	sayi = atoi(data_muhendis->Kayit_No);
	sayi++;
	sprintf(muhendis_data->Kayit_No, "%07u", sayi);
	dosya_kapa(&handle);
}