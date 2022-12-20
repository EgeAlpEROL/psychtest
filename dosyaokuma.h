#include <stdio.h>
#include <ctype.h>

void soruOkuma(int aranansayi) // Istenen soru nosunu verince soruyu yazdirir
{
    FILE *dosya = fopen("sorular.txt","r");
    if (dosya == NULL)
    {
        printf("Sorular Bulunamadi.\n");
        return;
    }
    char ch, lastch;
    int status, sayi = 0; //Status, dosya sonu durumu kontrolu için
    while (sayi != aranansayi) // Aranan sayi bulunmadiği surece devam
    {
        lastch = ch; //Onceki karakteri kaydet
        status = fscanf(dosya, "%c", &ch);
        if (isdigit(ch) && isdigit(lastch)) //Her iki karakter de sayiysa donuştur.
        {
            ch -= '0';     // Dosyadan okunan değerler ASCII Karakteri olduğu için
            lastch -= '0'; // '0' Karakterinin değerinden çikartarak gerçek Sayiya donuşturuyoruz.
            sayi = lastch*10 + ch*1; //dosyadan alinan iki sayiyi bir onluk değere donuştur.
            ch += '0';
            // Bir sonraki dongude sikinti olmamasi için Tekrar ASCII'ya donuştur.
        }
        if (status == EOF) //Sayi bulunamadan dosya sonu (EOF) varsa hata yazdir
        {
            printf("Soru Bulunamadi");
            return;
        }
    }
    do //Başka bir sayiya gelinceye kadar soruyu yazdir
    {  //Sayilar sorularda bulunmadiği için sorulari boyle ayirabiliriz
        status = fscanf(dosya, "%c", &ch);
        if (isdigit(ch))
            return;
        printf("%c", ch);
    } while (status != EOF);
    fclose(dosya);
}

void sonucYaz(char *isim, int aciklik, int sorumluluk, int disadonukluk, int uyumluluk, int duygusaldenge)
{
    printf("\t\t\tSonuclar\n\t\t\tAciklik: %d/6\n\t\t\tSorumluluk: %d/6\n\t\t\tUyumluluk: %d/6\n\t\t\tDisa donukluk: %d/6\n\t\t\tDuygusal denge: %d/6\n",aciklik,sorumluluk,disadonukluk,uyumluluk,duygusaldenge);
    if(aciklik>=0 && aciklik<3){
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tDusuk aciklik duzeyindeki kisiler daha gercekci ve gelenekseldir.\n\t\t\tAciklik duzeyi dusuk insanlar muhasebede polislik ve satis alaninda daha avantajlidir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (aciklik>=3 && aciklik<=5){
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tNormal aciklik duzeyi ne cok geleneksel ne de cok yenilikci.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (aciklik==6)
    {  
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tYuksek aciklik duzeyindeki kisiler iyi bi hayal gucune sahip, ozgun ve yenilige aciktir.\n\t\t\tAciklik duzeyi yuksek insanlar yaratici ugraslar ve arastirmada avantajlidir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    if (sorumluluk>=0 && sorumluluk<3)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tDusuk sorumluluk duzeyindeki insanlar daha ziyade 'Yarinin isini yarin dusunuruz.' yaklasimina sahiptir.\n\t\t\tDolayisiyla da daha spontane ve tepkiseldirler.\n\t\t\tBu duzey basarili olmak icin iyi bir durum degildir ve duzeltilmesi gerekir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (sorumluluk>=3 && sorumluluk<=5)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tNormal sorumluluk duzeyi yuksek olsa iyi ama dusuk olmasindan iyidir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (sorumluluk==6)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tYuksek sorumluluk duzeyi yuksek sorumlulugun faydalari aciktir.\n\t\t\tSorumluluk sahibi bireyler kasitli planlama yapar.\n\t\t\tBunda sureklilik gostererek yuksek basari duzeyine ulasirlar ve sorunlardan kacarlar.\n\t\t\tDigerleri tarafindan guvenilir ve zeki olarak adlandirilir. Zorlayici mukemmeliyetci ve iskolik olabilirler.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    if (disadonukluk>=0 && disadonukluk<3)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tDusuk disadonukluk duzeyine sahip kisiler asosyal veya baskalariyla ilgilenmeyen kisiler olarak gorulmemelidir.\n\t\t\tOnlar yalnizca daha az dissal uyarima ihtiyac duyarlar.\n\t\t\tKendi baslarina daha fazla zaman gecirmeyi tercih ederler.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (disadonukluk>=3 && disadonukluk<=5)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tNormal disadonukluk duzeyi ne cok sosyal ne de asosyal diyebiliriz.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (disadonukluk==6)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tYuksek disadonukluk duzeyindeki kisiler ust duzeyde dis yonlu aktivite ile karakterize edilir.\n\t\t\tOnlar enerjik, sosyal, haz arayan ve konuskan kisilerdir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    if (uyumluluk>=0 && uyumluluk<3)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tDusuk uyumluluk duzeyindeki kisiler alayci ve kendi cikarlarini dusunen kisiler olarak gorulebilirler.\n\t\t\tTipik olarak baskalarinin iyiligiyle daha az ilgilenirler.\n\t\t\tDolayisiyla da insanlar genellikle uyumlu kisileri uyumsuz kisilere gore daha fazla sever.\n\t\t\tDusuk uyumluluk duzeylerine sahip olmak liderlik ve yonetim alanlarinda\n\t\t\tsiyasal kariyerler ve askeriyede ve bazi bilim dallarinda avantajli olabilmektedir.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (uyumluluk>=3 && uyumluluk<=5)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tNormal uyumluluk duzeyi yerine gore uyumlu olmak iyidir bukalemun misali.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (uyumluluk==6)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tYuksek uyumluluk duzeyindeki kisiler, digerlerine samimi bir ilgi duyarlar.Ilimli, nazik ve dusuncelidirler.\n\t\t\tOnlar dogal olarak sefkatli ve dusuncelidir.Rekabet yerine isbirligi yapma egilimi gosterirler.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    if (duygusaldenge>=0 && duygusaldenge<3)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tDusuk duygusal denge duzeyindeki kisiler, olumsuz duygusal tepkileri tetiklendigi zaman dusuk esiklere sahiptir.\n\t\t\tDolayisiyla da daha fazla ofke, stres ve depresyon yasamaya aciktirlar.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (duygusaldenge>=3 && duygusaldenge<=5)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tNormal duygusal denge duzeyi arada sirada abarti duygular yasaniyor.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    else if (duygusaldenge==6)
    {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\tYuksek duygusal denge duzeyindeki kisiler ise zorluk karsisinda kolay yenilgiye ugramazlar.\n\t\t\tKotu haberle karsilastiklari zaman daha sakin ve sogukkanli olurlar.\n\t\t\tDuygusal dengesizligin dusuk olmasi bu nedenle arzu edilen bir sey olarak algilanabilir.\n\t\t\tFakat yuksek duygusal denge skoru olan kisiler cok kaygisiz olabilirler.\n\t\t\tDolayisiyla cevrelerindeki potansiyel tehditleri hafife alma egiliminde olabilirler.\n");
        printf("\n\t\t\t***********************************************************************\n");
    }
    FILE *dosya = fopen("sonuc.txt","a+");
    if (dosya == NULL)
    {
        printf("Sonuc yazmak icin dosya acilamadi.\n");
        return;
    }
    fprintf(dosya, "%s Aciklik:%d Sorumluluk:%d DişaDonukluk:%d Uyumluluk:%d DuygusalDenge:%d\n", isim, aciklik, sorumluluk, disadonukluk, uyumluluk, duygusaldenge);
    fclose(dosya);
}