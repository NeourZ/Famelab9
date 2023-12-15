#include<iostream>
#include<iomanip>
using namespace std;

double FindInterest(double l, double r) {
    return ((l * r) / 100);
}

int main() {
    double l, r, py;
    cout << "Enter initial loan: ";
    cin >> l;
    cin.ignore();
    cout << "Enter interest rate per year (%): ";
    cin >> r;
    cin.ignore();
    cout << "Enter amount you can pay per year: ";
    cin >> py;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    int i = 1;
    while (true) {
        cout << fixed << setprecision(2);
        cout << setw(13) << left << i;
        cout << setw(13) << left << l;
        double interest = FindInterest(l, r);
        cout << setw(13) << left << interest;
        cout << setw(13) << left << (l + interest);

        if ((l + interest) - py < 0) {
            cout << setw(13) << left << (l + interest);
            cout << setw(13) << left << "0.00";
            break;
        }
        
        cout << setw(13) << left << py;
        cout << setw(13) << left << (l + interest) - py;
        l = (l + interest) - py;
        cout << "\n";
        i++;
    }
    return 0;
}
