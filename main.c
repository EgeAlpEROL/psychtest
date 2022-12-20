#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "dosyaokuma.h"

#define SORU_SAYI 15

int main(void)
{
    char secenek[][20]={"A. Katiliyorum.","B. Emin Degilim.","C. Katilmiyorum."};
    char cevap[15];
    char isim[30];
    int sor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int uyumluluk=3,duygusaldenge=3,disadonukluk=3,sorumluluk=3,aciklik=3;
    srand(time(NULL));
    for (int j = 0; j < 15; j++)
    {   
    
    int temp = sor[j];
    int randomIndex = rand() % 15;

    sor[j]           = sor[randomIndex];
    sor[randomIndex] = temp;
    }
    printf("\n\n\n\t\t\t\t\t***BES BUYUK KIŞILIK TESTINE HOSGELDINIZ***\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***ONCELIKLE BIRAZ BILGI VERMEKTE FAYDA VAR TEST 15 SORUDAN OLUSUYOR***\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***BES BUYUK KISILIK OZELLIGI SUNLARDIR:\n\t\t\t***ACIKLIK***\n\t\t\t***SORUMLULUK***\n\t\t\t***DISA DONUKLUK***\n\t\t\t***UYUMLULUK***\n\t\t\t***DUYGUSAL DENGE***\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***ACIKLIK:Bir bireyin yeni ve alisilmamis fikirler, degerler, bakis acilari ve deneyimlere olan istahini ifade eder.\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***SORUMLULUK:Bir bireyin ugraslarini duzene koyma derecesini ifade eder.\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***DISA DONUKLUK:Olumlu duygular, digerlerinin tesvik ve ortakliklarini arama egilimi olarak tanimlanir.\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***UYUMLULUK:Bireyin sosyallesirken sevimlilik ve cana yakinlik seviyesini ifade eder.\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\t***DUYGUSAL DENGE:Bireyin huzunlu ve olumsuz duygudurumlari yasamama egilimini ifade eder.\n");
    printf("\n\t\t\t***********************************************************************\n");
    printf("\n\t\t\tAdinizi giriniz:");
    scanf("%s",isim);
    fflush(stdin);

    for (int a = 0; a < SORU_SAYI; a++)
    {   
        while (1)
        {
        printf("\n\t\t\t***********************************************************************\n");
        printf("\n\t\t\t");
        soruOkuma(sor[a]);
        printf("\t\t\t%s\t\t%s\t\t%s\n", secenek[0],secenek[1],secenek[2]);
        printf("\t\t\tSeciniz: ");
        cevap[a]= toupper(getchar());
        printf("\n\t\t\t***********************************************************************\n");
        fflush(stdin);
        if(cevap[a]=='A'|| cevap[a]=='B'||cevap[a]=='C'){
            break;
        }
        else{
            printf("\n\t\t\t***Lutfen dogru karakteri girdiginizden emin olunuz.***\n");
        }
        }
        fflush(stdin);
        switch (cevap[a])
        {
        case 'A' :
            if(sor[a]>=1 && sor[a]<=3){
                uyumluluk--;
            }
            else if (sor[a]>3 && sor[a]<=6)
            {
                aciklik--;
            }
            else if (sor[a]>6 && sor[a]<=9)
            {
                sorumluluk++;
            }
            else if (sor[a]>9 && sor[a]<=12)
            {
                duygusaldenge--;
            }
            else if (sor[a]>12 && sor[a]<=15)
            {
                disadonukluk--;
            }
            
            break;
        case 'B':
            break;
        case 'C':
            if(sor[a]>=1 && sor[a]<=3){
                uyumluluk++;
            }
            else if (sor[a]>3 && sor[a]<=6)
            {
                aciklik++;
            }
            else if (sor[a]>6 && sor[a]<=9)
            {
                sorumluluk--;
            }
            else if (sor[a]>9 && sor[a]<=12)
            {
                duygusaldenge++;
            }
            else if (sor[a]>12 && sor[a]<=15)
            {
                disadonukluk++;
            }
            break;
        }        
    }
    sonucYaz(isim, aciklik, sorumluluk, disadonukluk, uyumluluk, duygusaldenge);
    return 0;
}