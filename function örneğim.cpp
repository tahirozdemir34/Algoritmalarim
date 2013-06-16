#include <iostream>
#include <string>
using namespace std;

int toplam(int a, int b) {
	int t;
	t = a+b;
	return (t);
}
void selam() {
	string isim;
	cout << "Adiniz? ";
	cin >> isim;
	cout << "Hos geldin " << isim << "\n";
}

int main(){
	int z, b, a;
	cout << "Bu bir toplama programidir\n";
	
	selam();
	cout << "A= ";
	cin >>a;
	cout << "B= ";
	cin >>b;
	z = toplam(a,b);
	cout << "Sonuc= " << z;
	return 0;
	
}
