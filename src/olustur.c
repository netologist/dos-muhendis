#include "/ozgan/programs/h/genel.h"
#include "src/muhendis.h"

void sinifi_bul(void)
{
	int i;
	char *tutarlar[11] = { "30045000\0      ", "59277000\0      ", "99901000\0      ", "114233000\0     ",
						   "128496000\0     ", "142762000\0     ", "171342000\0     ", "214134000\0     ",
						   "256977000\0     ", "299838000\0     ", "351413000\0     " };

	char *siniflar[11] = { " I. SINIF ", " II.SINIF ", " III - A  ", " III - B  ",
						   "  IV - A  ", "  IV - B  ", "  IV - C  ", "  V - A  ",
						   "  V - B   ", "  V - C   ", "  V - D   " };

	for (i = 0; i < 11; i++) {
		if ((sayi_kontrol(muhendis_data->Yapi_Bedeli, tutarlar[i]) < 0))
			break;
		sayi_temizle(muhendis_data->Yapi_Bedeli, 16);
	}
	sayi_temizle(muhendis_data->Yapi_Bedeli, 16);
	if (i != 0)
		strcpy(muhendis_data->Yapi_Sinifi, siniflar[i-1]);
	else
		strcpy(muhendis_data->Yapi_Sinifi, siniflar[i]);
}

void bedel_hesapla(void)
{
	char gecici[50], binde[20], gecici_sonuc[20];

	memset(gecici_sonuc, 0, 20);
	memset(binde, 0, 20);
	strcpy(binde, "1000");

	memset(gecici, 0, 50);
	strcpy(gecici, muhendis_data->Yapi_Alani);
	carpma(gecici, muhendis_data->Yapi_Bedeli, muhendis_data->Maliyeti);

	bolme(muhendis_data->Maliyeti, binde, gecici_sonuc);
	memset(gecici, 0, 50);
	strcpy(gecici, muhendis_data->Hizmet_Orani);
	carpma(gecici, gecici_sonuc, muhendis_data->Hizmet_Bedeli);

	memset(binde, 0, 20);
	strcpy(binde, "100");
	bolme(muhendis_data->Hizmet_Bedeli, binde, gecici_sonuc);
	memset(gecici, 0, 50);
	strcpy(gecici, "17");
	carpma(gecici_sonuc, gecici, muhendis_data->KDV);
	toplama(muhendis_data->KDV, muhendis_data->Hizmet_Bedeli, muhendis_data->Toplam);
}

void odeme_plani(void)
{
	char oran1[20], oran2[20], oran3[20], oran4[20];
	char yuzde[20], gecici_sonuc[20];

	memset(yuzde, 0, 20);
	strcpy(yuzde, "100");
	memset(oran1, 0, 20);
	memset(oran2, 0, 20);
	memset(oran3, 0, 20);
	memset(oran4, 0, 20);

	if (muhendis_data->Bodrum[0] == 1) {
		strcpy(muhendis_data->Taksit1_Oran, "%25");
		strcpy(oran1, "25");
		strcpy(muhendis_data->Taksit2_Oran, "%35");
		strcpy(oran2, "35");
		strcpy(muhendis_data->Taksit3_Oran, "%20");
		strcpy(oran3, "20");
		strcpy(muhendis_data->Taksit4_Oran, "%20");
		strcpy(oran4, "20");
	}
	else {
		strcpy(muhendis_data->Taksit1_Oran, "%20");
		strcpy(oran1, "20");
		strcpy(muhendis_data->Taksit2_Oran, "%40");
		strcpy(oran2, "40");
		strcpy(muhendis_data->Taksit3_Oran, "%20");
		strcpy(oran3, "20");
		strcpy(muhendis_data->Taksit4_Oran, "%20");
		strcpy(oran4, "20");
	}
	memset(gecici_sonuc, 0, 20);
	bolme(muhendis_data->Toplam, yuzde, gecici_sonuc);
	carpma(gecici_sonuc, oran1, muhendis_data->Taksit1_Tutar);
	carpma(gecici_sonuc, oran2, muhendis_data->Taksit2_Tutar);
	carpma(gecici_sonuc, oran3, muhendis_data->Taksit3_Tutar);
	carpma(gecici_sonuc, oran4, muhendis_data->Taksit4_Tutar);
}

int muhendis_kontrol(void)
{
	if (strlen(muhendis_data->Yapi_Bedeli) == 0) {
		msj_kutu(NULL, "Yapç bedeli kaydçnç girmelisiz...", UYARI);
		uyari_gonder(22);
		return 1;
	}
	else if (strlen(muhendis_data->Yapi_Alani) == 0) {
		msj_kutu(NULL, "Yapç alani kaydçnç girmelisiz...", UYARI);
		uyari_gonder(24);
		return 1;
	}
	else if (strlen(muhendis_data->Hizmet_Orani) == 0) {
		msj_kutu(NULL, "Yapç hizmet oranç kaydçnç girmelisiz...", UYARI);
		uyari_gonder(27);
		return 1;
	}
	return 0;
}

void olustur(void)
{
	if (muhendis_kontrol() == 0) {
		sinifi_bul();
		bedel_hesapla();
		odeme_plani();
		tablo_yerlestir(2, 1, Data_Muhendis, (char *) dataci, tablo, &baslik);
		Islem_Kontrol = 1;
	}
}

