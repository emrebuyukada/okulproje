/* Dijkstra Algoritmasý Ýle En Kýsa yol Mesafesi */ 
// Emre Büyükada 160201120
 #include<stdio.h> 
 #include<stdlib.h>
#define size 81
#define inf 9999
 typedef	struct { //sehir kodu için dönüþüm
		char sehir[14]; //en uuzun þehir 14 karakterli olduðu için 14 yaptým afyonkarahisar
		int x;
	}donusum;
  typedef	struct { //sehir mesafeleri için
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
// burdaki amacým sehir kod daki her bir sehiri ve kkodunu  struct yapýmýza duzgun bir þekilde atama
		{
			
			FILE *kod;
			char parca[14];
			char a;
			int i=0,sayac=0,kar=0,sayi=0,say[2];
			kod=fopen("sehir kod.txt","r"); //sehir kodlarýný parcalamak için
			while(!feof(kod))
			{
				fscanf(kod,"%s",parca);
				for(i=0;i<14;i++)
				{
					if(parca[i]>=48 && parca[i]<=57)
				{
					a=parca[i];
					parca[i]=' ';
	//parcanýn içini boþaltmaz isek mantýksal hata gözlenmekte  sayýlar farklý olmakta
					say[sayi]=a-48;
					sayi++; 
//burdaki sayi deðiþkeni þehirlerin kodunda þehir sayýsýna 
//göre alacagýmýzdan en fazla 2  karakterli olabilceðinden aþaðýdaki if sorgumuz o yüzden yazdým
					
				}
				if(parca[i]>=65 && parca[i]<=90||parca[i]>=97 && parca[i]<=122)
//sistem türkce karakter kabul etmediðinden örneðin eskiþehir i eskiehir olarak alcaktýr
//bu durum bizim için sýkýntý arz etmemekte
					{
					basla[sayac].sehir[kar]=parca[i];
					parca[i]=' ';
					kar++;					
					}	
				}
				if(sayi==1) //en fazla 81 il oldugu için 2 basamaklý sayýlar için 
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

			int Tsehirkodu,Tsehir2kodu,Tkm;//tamamiyle geçici degerler tutmak için

			Mesafe=fopen("sehir mesafe.txt","r"); //sehir kodlarýný parcalamak için

			while(!feof(Mesafe))
			{
				fscanf(Mesafe,"%s",parca);
				for(i=0;i<25;i++) // 2 sehir uzunlugu ve km uzunlugunu hesaben 25 kere dönüyor
				{
						
					if(parca[i]>=65 && parca[i]<=90||parca[i]>=97 && parca[i]<=122||parca[i]==45)
					{
					
						if(parca[i]==45)
//kaçýncý tire de oldugunu anlamak için
						{
							kontrol++;
						}
						
						 if(kontrol==0) 
			//1. sehir in almasý için struct yapýsýndan basla1 donusum1 kullanýyoruz
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
					if(sayi==1) //en fazla 81 il oldugu için 2 basamaklý sayýlar için 
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

				a=karsilastir1(basla1[say].sehir);//kod kýsýmlarýný cekme
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

				say++;//her bir ele2mana ulaþsýn diye
				say1=0; 
				sayac=0;
				kontrol=0;
				sehirsayisi++;

			}
			fclose(Mesafe);
	}
	int karsilastir1(char dizi2[14]) 
//2 diziyi karþýlaþtýrýp için þehrin koduna ulaþmak için
	{
		
	int esitmi=1,i=0,j=0;
	for(j=0;j<kodsayisi-1;j++)
	{
			for( i=0;i<10;++i)
		{
		
					if(basla[j].sehir[i]==dizi2[i])
//10 karakteri eþitse zaten þehirler birbirine eþittir diye fazla uzatmadým 14 de olabilirdi ama 10 olsun
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

 //bu kýsýmý http://www.mycomputerscience.net/2012/10/c-program-implement-dijkstra-algorithm.html#
	//bu adresten aldýgým kodu kendi koduma uyarladým
	int srch_min(int uzunluk[],int aktar[],int n)
{
				int min,i,min_index;
			min=inf,min_index;
			for(i=1;i<n;i++)
			{
				if(aktar[i]!=1)//aktarýn heryeri 0 sadece aktarýn baslancak elemanýn indisin oldugu yer 1 dir
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
				set[i]=0; //herbir sehir sayisi kadar alaný 0 yapýor

				for(i=0;i<n;i++)
				{
					if(a[s][i]==0)//baglantýlý olmayan yerlerde 0 var
					{
					length[i]=inf;//bu sýfýrýn oldugu yerleri 999 olarak belirterek diziye atadýk
					path[i]=0;//yol olmayan yerleri göstermek inin bu dizide boþ yerlere 0 atýyor
					}
					else
					{
					length[i]=a[s][i];//gelen ilk sehirin komþularýný bu dizide 9999 olmayan yerlere atýyoruz
					path[i]=s;//diger diziyede 0 dan farklý olarak gelen baslangic þehrin degerini atýyoruz
					}
				}

	set[ilk]=1;//tüm degerleri 0 olan bu dizinin baslancak sehrin kodunun oldugu yere 1 atýyoruz

	length[ilk]=0;//burada dizin tutugu yer zaten kendine olan uzaklýktýr kendine olan uzaklýga 0 deriz
		
	while(set[z]!=1)//setin sadece 1 tanesi 1 oda baþlangýç sehirin degeri olan kýsým
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
	 int i=0,j=0,sonuc=0;//döngüler için hali hazýrda 2 deðiþkenimiz var
	char parca[20];
	FILE *x;
	x=fopen("sehir kod.txt","r"); //sehir kodlarýný parcalamak için
	printf("SehirÝsmi-KODU\n\n");
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
