// Tahir Özdemir
//Mart 2016
#include <iostream>
#include <time.h>
#define MAX 20
using namespace std;
void siralama(int a[], int);
void arama(int a[], int);
void dizi(int dizi[],int);
int kabarcik(int a[], int, int*);
int insertion(int a[], int, int*);
int selection(int a[], int, int*);

int main() {
	int secim, a[MAX], esayisi;
	cout << "\tMENU" << endl;
	cout << "-------------------" << endl;
	cout << "- [1] Siralama Algoritmalari" << endl;
	cout << "- [2] Arama Algoritmalari" << endl;
	cout << "- [3] Cik" << endl;
	cout << "Seciminizi giriniz (1, 2, 3): ";
	cin >> secim;

	if (secim == 3) {
		return 0;
	}
	else if(secim ==1 || secim ==2) {
		cout << "Test dizisine konulacak eleman sayisi: ";
		cin >> esayisi;
		while (esayisi > MAX || esayisi<2) {
			cout << "Gecersiz deger!" << endl;
			cout << "Test dizisine konulacak eleman sayisi: ";
			cin >> esayisi;
		}
			
		dizi(a, esayisi);
		if (secim == 1) {
			siralama(a, esayisi);
		}
		else if (secim == 2) {
			arama(a, esayisi);
		}
	}
	else {
		cout << "Gecersiz bir deger girdiniz!" << endl;
	}
	system("pause");
}

void siralama(int a[], int esayisi) {
	int dsayisi, kyds = 0, iyds = 0, syds=0;
	int kks = 0, iks = 0, sks = 0;
	int *kksp = &kks, *iksp=&iks, *sksp=&sks;
	cout << "Kac deneme yapilsin: ";
	cin >> dsayisi;
	for (int i = 0; i < dsayisi; i++) {
		dizi(a, esayisi);
		kyds += kabarcik(a, esayisi, kksp);

		dizi(a, esayisi);
		iyds += insertion(a, esayisi, iksp);

		dizi(a, esayisi);
		syds += selection(a, esayisi, sksp);
	}
	cout << endl << "Buble sort ortalama karsilastirma sayisi: " << kks / dsayisi << endl;
	cout << "Buble sort ortalama yer degistirme sayisi: " << kyds/dsayisi << endl<< endl;
	
	cout << "Insertion sort ortalama karsilastirma sayisi: " << iks / dsayisi << endl;
	cout << "Insertion sort ortalama yer degistirme sayisi: " << iyds/dsayisi << endl << endl;
	
	cout << "Selection sort ortalama karsilastirma sayisi: " << sks/dsayisi << endl;
	cout << "Selection sort ortalama yer degistirme sayisi: " << syds / dsayisi << endl;
}

void arama(int a[], int esayisi) {
	int aranan, i = 0;
	int *b= &i; //formalite
	dizi(a, esayisi);
	kabarcik(a, esayisi, b);
	cout << "Orjinal Dizi" << endl << "-------------------------" << endl;
	for (int j = 0; j < esayisi; j++)
		cout << "Dizi[" << j << "]= " << a[j] << endl;

	cout << "Aranacak elemani giriniz: ";
	cin >> aranan;
	//Lineer arama
	for (i = 0; i < esayisi; i++) {
		if (a[i] == aranan) {
			cout << "Pozisyon: " << i << endl;
			cout << "Lineer search karsilastirma sayisi: " << i + 1<< endl;
			break;
		}
	}
	if (i == esayisi) {
		cout << "Dizide boyle bir eleman yok!" << endl;
	}
		
	else {
		//Ýkili (Binary) Arama
		int basla = 0, bit = esayisi-1, k, ksayisi = 1;
		while (basla <= bit) {
			k = (basla + bit) / 2;

			if (a[k] == aranan) {
				cout << "Binary search karsilastirma sayisi: " << ksayisi << endl;
				break;
			}
			else if (a[k] > aranan) {
				bit = k-1;
			}
			else {
				basla = k+1;
			}
			ksayisi++;
		}
		//Interpolation (ara deðer atamalý)
		int orta, interk = 0;
		basla = 0;
		bit = esayisi - 1;
		while (1) {
			orta = basla + ((bit - basla) * (aranan - a[basla]) / (a[bit] - a[basla]));
			interk++;
			if (aranan == a[orta]) {
				cout << "Interpolation search karsilastirma sayisi: " << interk << endl;
				break;
			}
			else if (aranan < a[orta]) {
				bit = orta - 1;
				interk++;
			}
			else {
				basla = orta + 1;
				interk+=2;
			}
		}
	}
}

void dizi(int a[], int esayisi) {
	srand(time(NULL));
	a[0] = rand() % 1000;
	for (int i = 1; i < esayisi; i++) {
		a[i] = rand() % 1000;
		for (int j = 0; j <i; j++) {
			if (a[i] == a[j]) {
				a[i] = rand() % 1000;
				j = 0;
			}
		}
	}
}

int kabarcik(int a[], int esayisi, int *kksp){
	int gecici, ydsayisi=0;
	int kks = *kksp;
	//kabarcýk sýralama -elemanlarý ikililer olarak kontrol ediyor-
	for (int i = 1; i < esayisi; i++) {
		for (int j = 0; j < esayisi - 1; j++) {
			if (a[j] > a[j + 1]) {
				gecici = a[j];
				a[j] = a[j + 1];
				a[j + 1] = gecici;
				ydsayisi++;
			}
			kks++;
		}
	}
	*kksp = kks;
	return ydsayisi;

}

int insertion(int a[], int esayisi, int *iksp){
	int  ydsayisi = 0;
	int iks = *iksp;
	//insertion (eklemeli) -büyük olan deðerleri ileriye kaydýrýyor-
	for (int k = 1; k < esayisi; k++) {
		int z = k;
		int temp = a[k];
		while (a[z - 1]> temp) {
			a[z] = a[z - 1];
			z--;
			ydsayisi++; 
		}
		a[z] = temp;
		iks++;
	}
	*iksp = iks;
	return ydsayisi;
}

int selection(int a[], int esayisi, int *sksp) {
	//Selection (Seçmeli) -iki dizi gibi davranýr-
	int ekucuk, yedek, ydsayisi = 0;
	int sks = *sksp;
	for (int q = 0; q < esayisi; q++) {
		ekucuk = q;
		for (int w = q + 1; w < esayisi; w++) {
			if (a[w] < a[ekucuk])
				ekucuk = w;
			sks++;
		}

		if (ekucuk != q) {
			yedek = a[q];
			a[q] = a[ekucuk];
			a[ekucuk] = yedek;
			ydsayisi++;
		}

	}
	*sksp = sks;
	return ydsayisi;
}
