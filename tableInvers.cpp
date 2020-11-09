#include <iostream>
#include <fstream>

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
#include <map>
void move(char* arr, int size) {
    using namespace std;
    map <char, int> perm;
    for (int i{ 0 }; i < size; ++i) {

    }
}

int generatePermutation(std::string file1, std::string file2) {
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
    int t{ 0 };
    while (fin >> temp){
        size = temp.size();
        //Очистка perm
        for (int i{ 0 }; i < size; ++i) {
            perm[i] = -1;
        }
        for (int i{ 0 }; i < size; ++i) {
            t = 0;
            for (int k{ beg }; k < temp[i] + beg - '0'; ++k) {
                if (perm[k] != -1) {
                    ++t;
                }
            }
            //perm[k] = i;
            for (int k{ temp[i] + beg - '0' + t}; k < size; ++k) {
                //Если место свободно
                if (perm[k] == -1) {
                    perm[k] = i;
                    break;
                }
                else cout << ' ';
            }
            beg = 0;
            for (int j{ 0 }; j < size; ++j) {
                if (perm[j] != -1)
                    ++beg;
                else
                    break;
            }
        }
        for (int i{ 0 }; i < size; ++i) {
            fout << perm[i];
        }
        fout << endl;
        beg = 0;
    }
    fout.close();
    fin.close();
    return 0;
}

int main() {
    using namespace std;
    createTable(5, "file1.txt");
    generatePermutation("file1.txt", "file2.txt");
    return 0;
}
