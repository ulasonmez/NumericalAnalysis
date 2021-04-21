#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
const float hata = 0.001;
float f(float a);
int durmakosulu(float a, float b,int adim);
int us(int a,int b);
int veritipi(char *input);

int main(int argc, char *argv[]) {
printf("Denklem : 2x^3-3x^2-4x+5\n");
char altsinirs[3],ustsinirs[3];
float altsinir,ustsinir;
int input;
	printf("Alt sinir ve ust siniri giriniz.[a,b]\n");
	while(1){
		printf("Alt siniri giriniz (a):\n");
		scanf("%s",altsinirs);

		if(veritipi(altsinirs)==1 || veritipi(altsinirs)==0){
			altsinir = atof(altsinirs);
			break;
		}
	}
	while(1){
		printf("Ust siniri giriniz (a):\n");
		scanf("%s",ustsinirs);
	 	 if(veritipi(ustsinirs)==1 || veritipi(ustsinirs)==0){
			ustsinir = atof(ustsinirs);
			break;
		}
	}

	if(f(altsinir)*f(ustsinir)>0){
		//alt sinir ile ust sinirin carpimip pozitif ise bu aralikta kok olmadigini belirtir ve program burda biter.
		printf("Iterasyona gidilmeyecek");
	}
	else if(f(altsinir)*f(ustsinir)<0){
		//carpimlari negatif ise denklemin grafiği pozitiften negatife yada negatiften pozitife gecmistir.
		//(x eksenini kesmistir) yani kok vardir
		printf("Tekrar(#)             a                 b                    c                      Hata\n");
		printf("*****************************************************************************************\n");
		float ilk,orta,son;
		ilk = altsinir;
		son = ustsinir;
		for(int i =1;i<=10;i++){
			orta = (ilk+son)/2;
			int kontrol = durmakosulu(ilk,son,i);
			if(f(orta)==0){
				printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
				printf("\n\nKok degeri : %f",orta);
				break;
			}
			if(kontrol == 0){
				printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
				if(f(ilk)*f(orta)<0){
					son = orta;
					orta = (ilk+son)/2;
				}
				else if(f(orta)*f(son)<0){
					ilk = orta;
					orta =(ilk+son)/2;
				}
			}
			else{
				printf("Kok degeri: %f",orta);
				break;
			}
		}
	}
	else{
		//alt sinir ve ust sinir carpimi 0 hangisinin sifir oldugunu kontrol ediyoruz eger 2 si birden kok ise ikisini de yazdiriyoruz
		// eger yine de bu degerlerin arasinda da kok olduguna bakmak icin 0.00001 degerini ekliyoruz ki aradaki degeri de bulabilelim.
		if(f(altsinir)==0 && f(ustsinir)==0){
			float ilk,orta,son;
			ilk = altsinir+0.00001;
			son = ustsinir-0.00001;
			if(f(altsinir)*f(ustsinir)<0){
				printf("Tekrar(#)             a                 b                    c                    Hata   \n");
				printf("*****************************************************************************************\n");
				float ilk,orta,son;
				ilk = altsinir;
				son = ustsinir;
				for(int i =1;i<=10;i++){
					orta = (ilk+son)/2;
					int kontrol = durmakosulu(ilk,son,i);
					if(f(orta)==0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						printf("\n\nKok degeri : %f",orta);
						break;
					}
					if(kontrol == 0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						if(f(ilk)*f(orta)<0){
							son = orta;
							orta = (ilk+son)/2;
						}
						else if(f(orta)*f(son)<0){
						ilk = orta;
						orta =(ilk+son)/2;
						}
					}
					else{
						printf("1. Kesin kok degeri: %f\n",altsinir);
						printf("2. Kesin kok degeri: %f\n",ustsinir);
						printf("3. Kok degeri: %f\n",orta);
						break;
					}
				}
			}
			else{
				printf("1. Kesin kok degeri: %f\n",altsinir);
				printf("2. Kesin kok degeri: %f\n",ustsinir);
			}

		}
		else if(f(altsinir)==0){
			altsinir += 0.00001;
			if(f(altsinir)*f(ustsinir)<0){
				printf("Tekrar(#)             a                 b                    c                    Hata   \n");
				printf("*****************************************************************************************\n");
				float ilk,orta,son;
				ilk = altsinir;
				son = ustsinir;
				for(int i =1;i<=10;i++){
					orta = (ilk+son)/2;
					int kontrol = durmakosulu(ilk,son,i);
					if(f(orta)==0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						printf("\n\nKok degeri : %f",orta);
						break;
					}
					if(kontrol == 0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						if(f(ilk)*f(orta)<0){
							son = orta;
							orta = (ilk+son)/2;
						}
						else if(f(orta)*f(son)<0){
						ilk = orta;
						orta =(ilk+son)/2;
						}
					}
					else{
						printf("1. Kesin kok degeri: %f\n",altsinir-0.00001);
						printf("2. Kok degeri: %f\n",orta);
						break;
					}
				}

			}
			else{
				printf("Kok degeri : %f",altsinir-0.00001);
			}
		}
		else if(f(ustsinir)== 0){
			ustsinir -= 0.00001;
			if(f(altsinir)*f(ustsinir)<0){
				printf("Tekrar(#)             a                 b                    c                    Hata   \n");
				printf("*****************************************************************************************\n");
				float ilk,orta,son;
				ilk = altsinir;
				son = ustsinir;
				for(int i =1;i<=10;i++){
					orta = (ilk+son)/2;
					int kontrol = durmakosulu(ilk,son,i);
					if(f(orta)==0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						printf("\n\nKok degeri : %f",orta);
						break;
					}
					if(kontrol == 0){
						printf("%d               %f            %f              %f            %f\n",i,ilk,son,orta,((son-ilk))/2);
						if(f(ilk)*f(orta)<0){
							son = orta;
							orta = (ilk+son)/2;
						}
						else if(f(orta)*f(son)<0){
						ilk = orta;
						orta =(ilk+son)/2;
						}
					}
					else{
						printf("1. Kesin kok degeri: %f\n",ustsinir+0.00001);
						printf("2. Kok degeri: %f\n",orta);
						break;
					}
				}

			}
			else{
				printf("Kok degeri : %f",ustsinir+0.00001);
			}
		}
	}

	return 0;

}
//fonksiyonun icine verilen degerin sonucunu donduren fonksiyon
float f(float a){
	return 2*(a*a*a)-3*(a*a)-4*(a)+5;
}
//durma kosulunu kontrol eden kisim
//a = alt sinir, b = ust sinir, adim = tekrar sayisi
int durmakosulu(float a,float b,int adim){
	if(((b-a)/us(2,adim))<hata){
		return 1;
	}
	else return 0;
}
//pow fonksiyonu float olarak calistigi ve bizim isimiz integer sayi olan tekrar sayisinin
// ussunu almak oldugu icin integer degerle calisan us alma fonksiyonu ekledim
int us(int a,int b){
	int c = 1;
	if(b==1){
		return a;
	}
	for(int i =0;i<b;i++){
		c *= a;
	}
	return c;
}
//Girilen sayini numerik olup olmadigini kontrol eden fonksiyon
int veritipi(char *sayi){
    short int intMi=0;
    short int floatMi=0;
    short int tanimsizMi=0;
    int sayac;

    for(sayac = 0 ; sayi[sayac]!='\0'; sayac++)
    {
        if(isdigit(sayi[sayac]) || sayi[sayac]=='-')
            intMi=1;
        else if(sayi[sayac] == '.' || sayi[sayac]=='-')
            floatMi=1;
        else
            return -1;//charlar   "." (nokta) veya "-" (eksi) harici karakterler ici
    }
    if(intMi == 1 && floatMi ==1)
        return 1; //floatsa 1 dondur
    else if(intMi == 1 && floatMi ==0)
        return 0; //integerse 0 dondur
    else
    	return -1; //farkli karakter ise
}
