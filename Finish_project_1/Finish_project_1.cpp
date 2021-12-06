#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	fstream Output = fstream("Output.csv", ios::out);
	fstream Input = fstream("Input.txt", ios::in);
	double t1, t2, h, k1, k2, k3, v, a;
	int N;

	if (Input.good());
	else cout << "File not find!\n";

	if (Input.good()) 
	{
		Input >> N;
		vector<double> m(N + 1);
		vector<double> S(N + 1);
		vector<double> a(N + 1);
		vector<double> v(N + 1);
		Input >> t1 >> t2 >> k1 >> k2 >> k3;
		Input.close();
		h = (t2 - t1) / N;
		m[0] = t1;
		m[N] = t2;

		for (int i = 1; i < N; i++) 
		{
			m[i] = m[i - 1] + h;
		}

		for (int i = 0; i <= N; i++) 
		{
			S[i] = k1 * m[i] * m[i] + k2 * m[i] + k3;
		}
		
		v[0] = (S[1] - S[0]) / (m[1] - m[0]);
		v[N] = (S[N] - S[N - 1]) / (m[N] - m[N - 1]);

		for (int i = 1; i < N; i++)
		{
			v[i] = (S[i + 1] - S[i - 1]) / (h * 2);
		}

		a[0] = ((v[1] - v[0]) / h) * 2;
		a[N] = ((v[N] - v[N - 1]) / h) * 2;

		for (int i = 1; i < N; i++)
		{
			a[i] = (S[i - 1] - 2 * S[i] + S[i + 1]) / (h * h);
		}

		stringstream out = stringstream(ios::out);

		if (out.good() && Output.good()) {
			out.precision(4);
			for (int i = 0; i <= N; i++) 
			{
				out << fixed << m[i] << ";"
					<< fixed << S[i] << ";"
					<< fixed << v[i] << ";"
					<< fixed << a[i];
				if (i != N) out << "\n";
			}
		}
		string Buf = out.str();
		for (int i = 0; i < Buf.size(); i++) 
		{
			if (Buf[i] == '.') Buf[i] = ',';
		}
		Output << Buf;
		Output.close();
	}
}
