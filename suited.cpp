#include <iostream>
using namespace std;

int main()
{
    int U[9] = {};
    int V[9] = {};
    cout << " entrer U[0] = ";
    cin >> U[0];
    cout << " entrer V[0] = ";
    cin >> V[0];
    for (int i = 0; i < 9; i++)
    {
        U[i + 1] = U[i] + 2 * V[i] - 1;
        V[i + 1] = U[i] - V[i];
    }
    cout << " -------- " << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << i << "\t" << U[i] << "\t" << V[i] << endl;
    }
    return 0;
}