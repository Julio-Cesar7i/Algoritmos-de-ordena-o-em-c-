# Algoritmos-de-ordena-o-em-c++.
Repositório com os algortimos de ordenação em c++. 

+++++++++++++++++++  InsertionSort +++++++++++++++++++
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    std::vector<int> numElementos = {10, 100, 1000, 10000, 100000};
    for (int num : numElementos) {
        std::vector<int> numeros(num);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        for (int i = 0; i < num; ++i) {
            numeros[i] = dis(gen);
        }
        auto start = std::chrono::steady_clock::now();
        insertionSort(numeros);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = end - start;
        std::cout << "Tempo para ordenar " << num << " elementos: " << elapsedSeconds.count() << " segundos" << std::endl;
    }
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
+++++++++++++++++++  QuickSort  +++++++++++++++++++
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void quickSort(vector<int> &arr, int baixo, int alto) {
    if (baixo < alto) {
        int pivo = arr[(baixo + alto) / 2];
        int i = baixo - 1;
        int j = alto + 1;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivo);
            do {
                j--;
            } while (arr[j] > pivo);

            if (i >= j) {
                break;
            }

            swap(arr[i], arr[j]);
        }

        quickSort(arr, baixo, j);
        quickSort(arr, j + 1, alto);
    }
}

int main() {
    vector<int> numeros;
    vector<int> tamanhos = {10, 100, 1000, 10000, 100000};

    srand(time(0));

    for (int tamanho : tamanhos) {
        numeros.clear(); 

        for (int i = 0; i < tamanho; i++) {
            numeros.push_back(rand() % 1000000);
        }

        clock_t inicio = clock();
        quickSort(numeros, 0, numeros.size() - 1);
        clock_t fim = clock();

        double tempo_levado = double(fim - inicio) / CLOCKS_PER_SEC;

        cout << "Tempo para organizar vetor de tamanho " << tamanho << ": " << tempo_levado << " segundos" << endl;
    }

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
+++++++++++++++++++  SelectionSort  +++++++++++++++++++
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}
int main() {
    for (int i = 1; i <= 100; ++i) {
        int tamanho = i * 1000;
        std::vector<int> numeros(tamanho);
        for (int j = 0; j < tamanho; ++j) {
            numeros[j] = rand() % 10000;
        }
        std::vector<int> arr(numeros);
        std::chrono::steady_clock::time_point inicio = std::chrono::steady_clock::now();
        selectionSort(arr);
        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        std::cout << "Tempo levado para ordenar o vetor de tamanho " << tamanho << ": " << std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count() << " microssegundos" << std::endl;
    }
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
+++++++++++++++++++  BubbleSort  +++++++++++++++++++
#include <iostream>
#include <chrono>
#include <vector>
#include <random>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (const int size : sizes) {
        std::vector<int> numbers;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 1000000);

        for (int i = 0; i < size; i++) {
            numbers.push_back(dis(gen));
        }

        auto start = std::chrono::high_resolution_clock::now();

        bubbleSort(numbers);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        std::cout << "Tempo levado para ordenar o algoritmo de " << size << " numeros usando Bubble Sort: " << duration.count() << " segundos" << std::endl;
    }

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
+++++++++++++++++++  ShellSort  +++++++++++++++++++
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    std::vector<int> numeros = {10, 100, 1000, 10000, 100000};

    for (int n : numeros) {
        int arr[n];

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, n);

        for (int i = 0; i < n; ++i) {
            arr[i] = dist(gen);
        }

        auto start = std::chrono::high_resolution_clock::now();

        shell_sort(arr, n);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;

        std::cout << "Tempo de organização para " << n << " números: " << elapsed_microseconds.count() << " microssegundos" << std::endl;
    }

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
+++++++++++++++++++  MergeSort  +++++++++++++++++++
#include <iostream>
#include <chrono>
#include <vector>
#include <random>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (int size : sizes) {
        int arr[size];
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 1000);

        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen);
        }

        auto start = std::chrono::high_resolution_clock::now();

        mergeSort(arr, 0, size - 1);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        std::cout << "Tempo para organizar " << size << " números: " << duration.count() << " segundos" << std::endl;
    }

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
