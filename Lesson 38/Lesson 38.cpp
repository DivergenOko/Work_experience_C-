// Lesson 38. сложение двух массивов, заполнение из файла.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream Input = fstream("Input.txt", ios::in);
	fstream Output = fstream("Output.txt", ios::out);
	int n, m;
	int** mas1 = 0;
	int** mas2 = 0;

	if (Input.good()) {

		Input >> n >> m;
		mas1 = new int* [n];
		mas2 = new int* [n];


		int index1 = 0;
		for (int i = 0; i < n; i++) {
			mas1[index1] = new int[m];
			for (int j = 0; j < m; j++) {
				Input >> mas1[i][j];
			}
			index1++;
		}


		int index2 = 0;
		for (int i = 0; i < n; i++) {
			mas2[index2] = new int[m];
			for (int j = 0; j < m; j++) {
				Input >> mas2[i][j];
			}
			index2++;
		}
		Input.close();
	}

	if (Output.good()) {

		if (mas1 != 0 && mas2 != 0) {
			int** mas3 = new int* [n];
			int index3 = 0;
			for (int i = 0; i < n; i++) {
				mas3[index3] = new int[m];
				for (int j = 0; j < m; j++) {
					mas3[i][j] = mas1[i][j] + mas2[i][j];
				}
				index3++;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) cout << mas3[i][j] << " ";
				cout << "\n";
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) Output << mas3[i][j] << " ";
				Output << "\n";
			}

			//for (int i = 0; i < n; i++) delete[] mas3[i];
			//delete[] mas3;

			Output.close();
			fstream BinaryFile = fstream("Output.bin", ios::out);
			if (BinaryFile.good()) {
				// функция райт записывает в файл бинарные значения
				BinaryFile.write((char*)&n, sizeof(n));//в файл выводится в бинарном виде кол-во строк
				BinaryFile.write((char*)&m, sizeof(m));// в файл выводится кол-во столбцов в бинарном виде
				for (int i = 0; i < n; i++) {
					BinaryFile.write((char*)mas3[i], sizeof(mas3[0][0]) * m);//выыодится i-ая строка в бинарном виде
				}
				BinaryFile.close();
			}

			//чтение из бинарного файла и вывод на экран
			BinaryFile.open("Output.bin");
			if (BinaryFile.good()) {
				BinaryFile.read((char*)&n, sizeof(n));
				BinaryFile.read((char*)&m, sizeof(m));
				for (int i = 0; i < n; i++)
					BinaryFile.read((char*)mas3[i], sizeof(mas3[0][0]) * m);
				for (int i = 0; i < n; i++) cout << mas3[i] << " ";
			}
			for (int i = 0; i < n; i++) delete[] mas3[i];
			delete[] mas3;
		}
	}

	//for (int i = 0; i < n; i++) delete[] mas1[i];
	//for (int i = 0; i < n; i++) delete[] mas2[i];

	//delete[] mas1;
	//delete[] mas2;
}