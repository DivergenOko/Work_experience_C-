#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    double X0, XN, h, a, b, c;
    int N;

    //cin >> X0 >> XN >> N >> a >> b >> c;
    fstream In = fstream("input.txt", ios::in);
    if (In.good())
    {
        In >> X0 >> XN >> N >> a >> b >> c;
        h = (XN - X0) / N;

        vector<double> X(N + 1);
        vector<double> y(N + 1);
        X[0] = X0;
        X[N] = XN;
        for (int i = 1; i < N; i++)
            X[i] = X[i - 1] + h;

        for (int i = 0; i <= N; i++)
            y[i] = (a * X[i] + b) * X[i] + c;

        cout.precision(4);
        for (int i = 0; i <= N; i++)
            cout << setw(10) << fixed << X[i] << " "
            << setw(10) << fixed << y[i] << "\n";
        fstream FOut = fstream("Output.csv", ios::out);
        stringstream SOut = stringstream(ios::out);
        if (FOut.good())
        {
            SOut << N + 1 << "\n";
            for (int i = 0; i <= N; i++)
            {
                SOut << X[i] << ";" << y[i];
                if (i < N) SOut << "\n";
            }

            string Buffer = SOut.str();
            for (int i = 0; i < Buffer.size(); i++)
                if (Buffer[i] == '.') Buffer[i] = ',';
            FOut << Buffer;


            FOut.close();
        }
    }
    else cout << "File \"input.txt\" not found \n";
}
