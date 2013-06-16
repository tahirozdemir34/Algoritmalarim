#include <iostream>

using namespace std;

int main()
{
    int i, d, n, a, z;
    cout << "=========================================================[_][O][X]\n";
    cout << "|| *  *   *   *   * ****  *     ***  *  * ***** **** *  * *   * ||\n";
    cout << "|| *  *  * *  **  * *	        *  *	     *  *         **  * ||\n";
    cout << "|| **** ***** * * * ****  *     *  * *  *   *   **** *  * * * * ||\n";
    cout << "|| *  * *   * *  ** *  *  *     *  * *  *  *    *  * *  * *  ** ||\n";
    cout << "|| *  * *   * *   * ****  *     ***  **** ***** **** **** *   * ||\n";
    cout << "||                                                              ||\n";
    cout << "|| ***** ***** *  * **** **** *   *                             ||\n";
    cout << "|| *     *   * * *  *    *    **  *                             ||\n";
    cout << "|| *     *   * **   **** **** * * *                             ||\n";
    cout << "|| *     *   * * *  *  * *    *  **                             ||\n";
    cout << "|| ***** ***** *  * **** **** *   *                             ||\n";
    cout << "||   *                                                          ||\n";
    cout << "||                                                              ||\n";
    cout << "|| 1 ) Duzgun cokgenin bir ic acisini biliyorum                 ||\n";
    cout << "|| 2 ) Duzgun cokgenin bir dis acisini biliyorum                ||\n";
    cout << "|| 3 ) Duzgun cokgenin kenar sayisini biliyorum                 ||\n";
    cout << "||                                                              ||\n";
    cout << "==================================================================\n";
    cout << "Alternatiflerden hangisini seciyorsun ?";
    cin >> z;
    if ( z == 1) {
          cout << "Lutfen ic aci degerini giriniz... ";
          cin >> i;
          n = 360 / (180 - i);
          cout << n << " kenari, kosesi, ic ve dis acisi var\n";
          cout << "Bir kosesinden en cok " << (n - 3) << " kosegen cizilir\n";
          cout << (n * (n - 3))/2 << " kosegeni var\n";
          cout << "Ic acilar toplami " << (n - 2) * 180;
          cin >> a;
          }
    if ( z == 2 ) {
         cout << "Lutfen dis aci degerini giriniz... ";
         cin >> d;
         n = 360 / d;
         cout << n << " kenari, kosesi, ic ve dis acisi var\n";
         cout << "Bir kosesinden en cok " << (n - 3) << " kosegen cizilir\n";
         cout << (n * (n - 3))/2 << " kosegeni var\n";
         cout << "Ic acilar toplami " << (n - 2) * 180;
         cin >> a;
         }
    if ( z == 3 ) {
         cout << "Lutfen kenar sayisini giriniz... ";
         cin >> n;
         cout << n << " kenari, kosesi, ic ve dis acisi var\n";
         cout << "Bir kosesinden en cok " << (n - 3) << " kosegen cizilir\n";
         cout << (n * (n - 3))/2 << " kosegeni var\n";
         cout << "Ic acilar toplami " << (n - 2) * 180;
         cin >> a;
         }
}
