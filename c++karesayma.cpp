// Tahir �zdemir 152120141047
// May�s 2016

#include <iostream>
#include <fstream>

using namespace std;
ifstream input("input.txt", ios::in);
ofstream output("output.txt", ios::out);

char d;					 //Y�n bilgisini tutmak i�in - (d)irection
int n, m, i, j;			 //n^2 nokta say�s� ; m �izgi say�s� ; i ve j koordinatlar
char matrix[17][17];     //�ekili tutmak i�in
int H[72][2] = {};		 //Yatay �izgilerin ba�lang�� nokta koordinatlr� 
int V[72][2] = {};		 //Dikey �izgilerin ba�lang�� nokta koordinatlr� 
int prblmcnt = 1;		 //Dosyaya yazd�r�rken problemleri saymak i�in

int counter(int r) {
	int count = 0;		 //Kare say�s�n� d�nd�rmek i�in
	int flag = 0;		 //�izgilei saymak i�in

	for (int i = 0; i < n + (n - 1); i++) {
		for (int j = 0; j < n + (n - 1); j++) {

			for (int k = 0; k < 2; k++) {
				for (int z = 0; z < r; z++)
					if (matrix[i + (k * (r * 2))][j + (z * 2)] == '-')
						flag++;

				if (flag == r * 2)
					for (int k = 0; k < r; k++)
						for (int z = 0; z < 2; z++)
							if (matrix[i + (2 * k + 1)][j + (z * (r * 2) - 1)] == '|')
								flag++;
			}

			if (flag == r * 4)
				count++;
			flag = 0;
		}
	}
	return count;
}

//Noktalar� matrise yele�tirmek i�in
void fillmatrix() {
	for (int k = 0; k < n + (n - 1); k++) {
		for (int z = 0; z < n + (n - 1); z++) {
			matrix[k][z] = '+';
			if (k % 2 == 1)
				for (int i = 0; i < n + (n - 1); i++)
					matrix[k][i] = ' ';
			else if (z % 2 == 1)
				matrix[k][z] = ' ';
		}
	}
}

//�izgileri okuyup matrise yerle�tirmek i�in
void readHV() {
	int flag = 0;
	int fh = 0, fv = 0;

	while (flag < m) {
		input >> d;
		input >> i;
		input >> j;
		if (d == 'H') {
			H[0][fh++] = i;
			H[0][fh++] = j;
		}
		else {
			V[0][fv++] = i;
			V[0][fv++] = j;
		}
		flag++;
	}

	for (int i = 0; i < fh/2; i++) {
		matrix[2 * H[0][2 * i] - 2][2 * H[0][2 * i + 1] - 1] = '-';
	}
	for (int i = 0; i < fv/2; i++) {
		matrix[2 * V[0][2 * i + 1] - 1][2 * V[0][2 * i] - 2] = '|';
	}
}

void answer() {
	output << "Problem " << prblmcnt++ << endl << endl;

	if (m <= 3)
		output << "No completed squares can be found." << endl;

	else {
		int flag = 0;
		for (int i = 1; i < n; i++) {
			if (counter(i) > 0)
				output << counter(i) << " square (s) of size " << i << endl;
			else
				flag++;
		}

		if (flag == n - 1)
			output << "No completed squares can be found." << endl;
	}
}

int main() {	if (!input.is_open()) {		cout << "Error openning input file!\n";		system("pause");		exit(0);	}	input >> n >> m;

	fillmatrix();
	readHV();
	answer();

	for (int k = 0; k < n + (n - 1); k++) {
		for (int z = 0; z< n + (n - 1); z++)
			output << matrix[k][z] << " ";
		output << endl;
	}
	output << endl << "*****************************" << endl << endl;

	if (!input.eof()) {
		main();
	}
	else {
		input.close();
		output.close();
		cout << "Process DONE! Check output.txt\n";
		system("pause");
	}
}