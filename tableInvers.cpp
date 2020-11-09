#include <iostream>
#include <fstream>
#include <map>

int createTable(int num, std::string filename) {
    using namespace std;
    ofstream fout(filename, std::ofstream::out | std::ofstream::trunc);
    fout.clear();
    char* array = new char[num] { 0 };
    for (int i{ 0 }; i < num; ++i) {
        array[i] = '0';
    }
    for (int i{ num - 1 }; i >= 0; --i) {
        for (int k{ 0 }; k < num; ++k) {
            fout << array[k];
        }
        fout << endl;
        //Увеличение на единицу
        array[num - 1] += 1;
        //Проверка на превышение максимального значения
        for (int j{ num - 1 }; j >= 0; --j) {
            if (array[j] - '0' > num - j - 1) {
                //Конец таблицы
                if (j == 0) {
                    return 0;
                }
                //Перенос единицы в следующий разряд
                else {
                    array[j - 1] += 1;
                    array[j] = '0';
                    i = num - 1;
                }
            }
        }
    }
    fout.close();
    delete[] array;
}

void generatePermutation(std::string file1, std::string file2) {
    using namespace std;
    ofstream fout(file2, std::ofstream::out | std::ofstream::trunc);
    ifstream fin(file1);
    //строка, в которую считываются данные
    string temp{ "" };
    map <int, int> perm;
    //размер строки
    int size{ 0 };
    //Первый пустой элемент в perm
    int beg{ 0 };
    //Количество пропущенных заполненных
    int filled{ 0 };
    while (fin >> temp) {
        beg = 0;
        for (int j{ 0 }; j < size; ++j) {
            if (perm[j] != -1)
                ++beg;
            else
                break;
        }
        if (beg == size)
            beg = 0;
        size = temp.size();
        //Очистка perm
        for (int i{ 0 }; i < size; ++i) {
            perm[i] = -1;
        }
        for (int i{ 0 }; i < size; ++i) {
            filled = 0;
            for (int k{ beg }; k <= temp[i] + beg - '0' + filled; ++k) {
                if (perm[k] != -1) {
                    ++filled;
                }
            }
            perm[temp[i] + beg - '0' + filled] = i;

        }
        for (int i{ 0 }; i < size; ++i) {
            fout << perm[i];
        }
        fout << endl;
    }
    fout.close();
    fin.close();
}

int main() {
    using namespace std;
    createTable(5, "file1.txt");
    generatePermutation("file1.txt", "file2.txt");
    return 0;
}