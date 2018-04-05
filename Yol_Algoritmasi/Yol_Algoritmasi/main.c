/* Dijkstra Algoritmas� �le En K�sa yol Mesafesi */ 
// Emre B�y�kada 160201120
 #include<stdio.h> 
 #include<stdlib.h>
#define size 81
#define inf 9999
 typedef	struct { //sehir kodu i�in d�n���m
		char sehir[14]; //en uuzun �ehir 14 karakterli oldu�u i�in 14 yapt�m afyonkarahisar
		int x;
	}donusum;
  typedef	struct { //sehir mesafeleri i�in
		char sehir[14];
		int sehirkodu;
		char sehir2[14];
		int sehir2kodu;
		int km;
	}donusum1;

			int kmatrisi[81][81];
			donusum basla[81];
		    donusum1 basla1[500];
			int sehirsayisi=0,kodsayisi=0;
 

	void parcala() 
// burdaki amac�m sehir kod daki her bir sehiri ve kkodunu  struct yap�m�za duzgun bir �ekilde atama
		{
			
			FILE *kod;
			char parca[14];
			char a;
			int i=0,sayac=0,kar=0,sayi=0,say[2];
			kod=fopen("sehir kod.txt","r"); //sehir kodlar�n� parcalamak i�in
			while(!feof(kod))
			{
				fscanf(kod,"%s",parca);
				for(i=0;i<14;i++)
				{
					if(parca[i]>=48 && parca[i]<=57)
				{
					a=parca[i];
					parca[i]=' ';
	//parcan�n i�ini bo�altmaz isek mant�ksal hata g�zlenmekte  say�lar farkl� olmakta
					say[sayi]=a-48;
					sayi++; 
//burdaki sayi de�i�keni �ehirlerin kodunda �ehir say�s�na 
//g�re alacag�m�zdan en fazla 2  karakterli olabilce�inden a�a��daki if sorgumuz o y�zden yazd�m
					
				}
				if(parca[i]>=65 && parca[i]<=90||parca[i]>=97 && parca[i]<=122)
//sistem t�rkce karakter kabul etmedi�inden �rne�in eski�ehir i eskiehir olarak alcakt�r
//bu durum bizim i�in s�k�nt� arz etmemekte
					{
					basla[sayac].sehir[kar]=parca[i];
					parca[i]=' ';
					kar++;					
					}	
				}
				if(sayi==1) //en fazla 81 il oldugu i�in 2 basamakl� say�lar i�in 
				{
					basla[sayac].x=say[0];
				}
				else
				{
					basla[sayac].x=say[0]*10+say[1];
				}
				kar=0;
				sayi=0;
				sayac++;
				kodsayisi++;
			}
			fclose(kod);
		}
	void sehirlerarasi(){
		
				FILE *Mesafe;
			char parca[25],temp;
			int KM[3];
			int i=0,sayac=0,say=0,say1=0,kontrol=0,a=0,sayi=0;

			int Tsehirkodu,Tsehir2kodu,Tkm;//tamamiyle ge�ici degerler tutmak i�in

			Mesafe=fopen("sehir mesafe.txt","r"); //sehir kodlar�n� parcalamak i�in

			while(!feof(Mesafe))
			{
				fscanf(Mesafe,"%s",parca);
				for(i=0;i<25;i++) // 2 sehir uzunlugu ve km uzunlugunu hesaben 25 kere d�n�yor
				{
						
					if(parca[i]>=65 && parca[i]<=90||parca[i]>=97 && parca[i]<=122||parca[i]==45)
					{
					
						if(parca[i]==45)
//ka��nc� tire de oldugunu anlamak i�in
						{
							kontrol++;
						}
						
						 if(kontrol==0) 
			//1. sehir in almas� i�in struct yap�s�ndan basla1 donusum1 kullan�yoruz
						{
							basla1[say].sehir[say1]=parca[i];
							say1++;
						}
						if(kontrol==1 && parca[i]!=45)
						{
						
							basla1[say].sehir2[sayac]=parca[i];
							sayac++;
						}

					}
					if(parca[i]>=48 && parca[i]<=57)
						{
							temp=parca[i];
							parca[i]=' ';
							KM[sayi]=temp-48;
							sayi++; 
						}
					if(sayi==1) //en fazla 81 il oldugu i�in 2 basamakl� say�lar i�in 
					{
					basla1[say].km=KM[0];
					}
					else if(sayi==2)
					{
					basla1[say].km=KM[0]*10+KM[1];
					}
					else
					{
						basla1[say].km=KM[0]*100+KM[1]*10+KM[2];
					}
				}
				sayi=0;

				a=karsilastir1(basla1[say].sehir);//kod k�s�mlar�n� cekme
				basla1[say].sehirkodu=basla[a].x;

				a=karsilastir1(basla1[say].sehir2);
				basla1[say].sehir2kodu=basla[a].x;
				//1 den 2 ye 78 km ise 2 den 1 e de 78 km dir
					Tsehirkodu=	basla1[say].sehirkodu;
					Tsehir2kodu=basla1[say].sehir2kodu;
					Tkm=basla1[say].km;
					say++;
					basla1[say].sehirkodu=Tsehir2kodu;
					basla1[say].sehir2kodu=Tsehirkodu;
					basla1[say].km=Tkm;

				say++;//her bir ele2mana ula�s�n diye
				say1=0; 
				sayac=0;
				kontrol=0;
				sehirsayisi++;

			}
			fclose(Mesafe);
	}
	int karsilastir1(char dizi2[14]) 
//2 diziyi kar��la�t�r�p i�in �ehrin koduna ula�mak i�in
	{
		
	int esitmi=1,i=0,j=0;
	for(j=0;j<kodsayisi-1;j++)
	{
			for( i=0;i<10;++i)
		{
		
					if(basla[j].sehir[i]==dizi2[i])
//10 karakteri e�itse zaten �ehirler birbirine e�ittir diye fazla uzatmad�m 14 de olabilirdi ama 10 olsun
					{
					esitmi++;
					}
					if(esitmi==11)
					{
					return j;
					}
		}
			esitmi=1;
	}
	return 0;
}

	void	komsulukmatrisi()
	{
		int i=0,j=0;
			for(i=0;i<kodsayisi;i++)
			{
				for(j=0;j<sehirsayisi*2-2;j++) 
				{
					if(i+1==basla1[j].sehirkodu)
					{
					kmatrisi[i][(basla1[j].sehir2kodu)-1]=basla1[j].km;
					}
				}
			}
	}

 //bu k�s�m� http://www.mycomputerscience.net/2012/10/c-program-implement-dijkstra-algorithm.html#
	//bu adresten ald�g�m kodu kendi koduma uyarlad�m
	int srch_min(int uzunluk[],int aktar[],int n)
{
				int min,i,min_index;
			min=inf,min_index;
			for(i=1;i<n;i++)
			{
				if(aktar[i]!=1)//aktar�n heryeri 0 sadece aktar�n baslancak eleman�n indisin oldugu yer 1 dir
				{
					if(uzunluk[i]<min)
					{
					min=uzunluk[i];
					min_index=i;
					}
				}
			}
return min_index;
}

	int dijkstra(int a[size][size],int  n,int ilk,int son)
	{
		int length[size],set[size],path[size],i,j,s,z;
		int tmp,temp[size],c=0,f=0,kontrol=0;
		if(ilk>son)
		{
			tmp=son;
			son=ilk;
			ilk=tmp;
			kontrol++;
		}
				s=ilk;
				z=son;

				for(i=0;i<n;i++)
				set[i]=0; //herbir sehir sayisi kadar alan� 0 yap�or

				for(i=0;i<n;i++)
				{
					if(a[s][i]==0)//baglant�l� olmayan yerlerde 0 var
					{
					length[i]=inf;//bu s�f�r�n oldugu yerleri 999 olarak belirterek diziye atad�k
					path[i]=0;//yol olmayan yerleri g�stermek inin bu dizide bo� yerlere 0 at�yor
					}
					else
					{
					length[i]=a[s][i];//gelen ilk sehirin kom�ular�n� bu dizide 9999 olmayan yerlere at�yoruz
					path[i]=s;//diger diziyede 0 dan farkl� olarak gelen baslangic �ehrin degerini at�yoruz
					}
				}

	set[ilk]=1;//t�m degerleri 0 olan bu dizinin baslancak sehrin kodunun oldugu yere 1 at�yoruz

	length[ilk]=0;//burada dizin tutugu yer zaten kendine olan uzakl�kt�r kendine olan uzakl�ga 0 deriz
		
	while(set[z]!=1)//setin sadece 1 tanesi 1 oda ba�lang�� sehirin degeri olan k�s�m
		{
			j=srch_min(length,set,n);
			
			set[j]=1;

				for(i=0;i<n;i++)
				{
					if(set[i]!=1)
					{
						if(a[i][j]!=0)
						{
							if(length[j]+a[i][j]<length[i])
							{
							length[i]=length[j]+a[i][j];
							path[i]=j;
							}
						}
					}
				}
		}

j=0;
i=z;
					while(i!=s)
					{
						tmp=path[i];
						temp[j]=tmp;
						i=tmp;
						j++;
						c++;
					}
					printf("\n");

				for(j=c-1;j>=0;j--)
				{
					if(kontrol==0)
					printf("%s -> ",basla[temp[j]].sehir);
					if(kontrol==1)
					printf("%s <- ",basla[temp[j]].sehir);
						if(temp[j]==z)
							f=1;
				}
			if(f!=1)
				printf("%s",basla[z].sehir);
			printf("\n");

	return length[z];
	}



 int main () 
 { 
	 int i=0,j=0,sonuc=0;//d�ng�ler i�in hali haz�rda 2 de�i�kenimiz var
	char parca[20];
	FILE *x;
	x=fopen("sehir kod.txt","r"); //sehir kodlar�n� parcalamak i�in
	printf("Sehir�smi-KODU\n\n");
			while(!feof(x))
			{
				fscanf(x,"%s",parca);
				printf("%s\n",parca);
			}
			fclose(x);
		parcala();
		sehirlerarasi();
		komsulukmatrisi();

			printf("Lutfen Baslangic sehri kodunu giriniz  :");
	scanf("%d",&i);
		if(i>kodsayisi-1||i<0)
		{
			printf("Baslangic sehrini duzgun giriniz....\n ");
		 return;
		}
	printf("Lutfen Gitmek istediginiz sehrin kodunu giriniz  :");
	scanf("%d",&j);
		if(i<0||i>kodsayisi-1||j<0||j>kodsayisi-1)
		{
			printf("Yanlis Secim \n");
			return;
		}

		printf("\nBu sehirler Arasi mesafe %s & %s : \n",basla[i-1].sehir,basla[j-1].sehir);
	sonuc=dijkstra(kmatrisi,sehirsayisi,i-1,j-1);
	printf("\n %s dan  %s arasi mesafe : ",basla[i-1].sehir,basla[j-1].sehir);
	printf("%d  km dir. \n",sonuc);
			
	printf("\n");
		
   return 0;
 } 
