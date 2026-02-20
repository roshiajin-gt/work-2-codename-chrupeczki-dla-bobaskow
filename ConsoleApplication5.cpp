#include <iostream>;
#include <iomanip>;
#include <chrono>

using namespace std;
using namespace std::chrono;

const int arrLenght = 100;

void elementsExchange(int* arr1, int* arr2) {
	for (int i = 0; i < arrLenght; ++i) {
		arr2[i] = arr1[i];
	}
}

int biggestCommonDivision(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	if (b % a == 0) {
		return a;
	}
	if (a > b) {
		return biggestCommonDivision(b, a % b);
	}
	else {
		return biggestCommonDivision(b % a, a);
	}
}

void bubbleSort(int* arr) {
	for (int i = 0; i < arrLenght - 1; ++i) {
		for (int j = 0; j < arrLenght - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void shakerSort(int* arr) {
	int left = 0, right = arrLenght - 1;
	while (left <= right) {
		for (int i = left; i < right; ++i) {
			if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
		}
		--right;
		for (int i = right; i > left; --i) {
			if (arr[i] < arr[i - 1]) swap(arr[i], arr[i - 1]);
		}
		++left;
	}
}

void insertionSort(int* arr) {
	for (int i = 1; i < arrLenght; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}
void gnomeSort(int* arr) {
	int i = 0;
	while (i < arrLenght) {
		if (i == 0 || arr[i - 1] <= arr[i]) {
			++i;
		}
		else {
			swap(arr[i], arr[i - 1]);
			--i;
		}
	}
}
void quicksort(int* arr, int end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quicksort(arr, l, begin);
	if (f < end) quicksort(arr, end, f);
}
int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == value) {
			return mid;
		}
		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}
		return binarySearch(arr, value, mid + 1, end);
	}
	return -1;
}
void findTwoMinAndTwoMax(int* arr, int size) {
	int min1 = arr[0];
	int min2 = arr[1];
	int max1 = arr[0];
	int max2 = arr[1];
	if (min1 > min2) {
		swap(min1, min2);
	}
	if (max1 < max2) {
		swap(max1, max2);
	}
	for (int i = 2; i < size; i++) {
		if (arr[i] < min1) {
			min2 = min1;
			min1 = arr[i];
		}
		else if (arr[i] < min2) {
			min2 = arr[i];
		}
		if (arr[i] > max1) {
			max2 = max1;
			max1 = arr[i];
		}
		else if (arr[i] > max2) {
			max2 = arr[i];
		}
	}
	cout << "два минимальных элемента " << min1 << " и " << min2 << endl;
	cout << "два максимальных элемента " << max1 << " и " << max2 << endl;
}
int main() {
	setlocale(0, "");
	int n;
	int arr[arrLenght];
	while (true) {
		srand(time(NULL));
		for (int i = 0; i < arrLenght; ++i) {
			arr[i] = rand() % 199 - 99;
		}
		break;
	}
	do
	{
		cout << "номер задания от 1 до 8, 9 ИДЗ, 0 для выхода \n";
		cin >> n;
		int randomArr[arrLenght], sortingArr[arrLenght], sortedArr[arrLenght];
		elementsExchange(arr, randomArr);
		elementsExchange(randomArr, sortingArr);
		elementsExchange(randomArr, sortedArr);
		quicksort(sortedArr, arrLenght - 1, 0);
		if (n == 1) {
			cout << "целочисленный массив со случайными значениями с диапазоне от -99 до 99 \n";
			for (int i = 0; i < arrLenght; ++i) {
				cout << setw(4) << randomArr[i];
			}
			cout << '\n';
		}
		if (n == 2) {
			cout << "сортировки завершились за следующее время \n";
			auto start1 = high_resolution_clock::now();
			bubbleSort(sortingArr);
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "bubbleSort завершилась за " << duration1 << " наносекунд\n";
			elementsExchange(randomArr, sortingArr);
			auto start2 = high_resolution_clock::now();
			shakerSort(sortingArr);
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "shakerSort завершилась за " << duration2 << " наносекунд\n";
			elementsExchange(randomArr, sortingArr);
			auto start3 = high_resolution_clock::now();
			insertionSort(sortingArr);
			auto end3 = high_resolution_clock::now();
			auto duration3 = duration_cast<nanoseconds>(end3 - start3).count();
			cout << "insertionSort завершилась за " << duration3 << " наносекунд\n";
			elementsExchange(randomArr, sortingArr);
			auto start4 = high_resolution_clock::now();
			gnomeSort(sortingArr);
			auto end4 = high_resolution_clock::now();
			auto duration4 = duration_cast<nanoseconds>(end4 - start4).count();
			cout << "gnomeSort завершилась за " << duration4 << " наносекунд\n";
			elementsExchange(randomArr, sortingArr);
			auto start5 = high_resolution_clock::now();
			quicksort(sortingArr, arrLenght - 1, 0);
			auto end5 = high_resolution_clock::now();
			auto duration5 = duration_cast<nanoseconds>(end5 - start5).count();
			cout << "quicksort завершилась за " << duration5 << " наносекунд\n";
			cout << "Отсортированный масив имеет следующий вид\n";
			for (int i = 0; i < arrLenght; ++i) {
				cout << setw(4) << sortingArr[i];
			}
			cout << '\n';
		}
		if (n == 3) {
			int mn = randomArr[0], mx = randomArr[0];
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx) {
					mx = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] < mn) {
					mn = randomArr[i];
				}
			}
			cout << "макс элемент равен" << mx << endl;
			cout << "мин элемент равен" << mn << endl;
			auto start1 = high_resolution_clock::now();
			int mn0 = randomArr[0], mx0 = randomArr[0];
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx0) {
					mx0 = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] < mn0) {
					mn0 = randomArr[i];
				}
			}
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "время поиска макс и мин элементов в неотсортированном массиве составило " << duration1 << " наносекунд\n";
			auto start2 = high_resolution_clock::now();
			int mn1 = sortedArr[0], mx1 = sortedArr[arrLenght - 1];
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "время поиска макс и мин элементов в отсолтированном массиве составилл " << duration2 << " наносекунд\n";
			cout << '\n';
		}
		if (n == 4) {
			auto start1 = high_resolution_clock::now();
			int mn = randomArr[0], mx = randomArr[0], k = 0;
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx) {
					mx = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] < mn) {
					mn = randomArr[i];
				}
			}
			int middleValue = (mn + mx) / 2;
			cout << "индекс элементов равных среднему значению максимального и минимального элементов неотсортированного массива" << ' ';
			for (int i = 0; i < arrLenght; ++i) {
				if (randomArr[i] == middleValue) {
					cout << i << ' ';
					k += 1;
				}
			}
			cout << '\n' << "колво элементоу" << k << '\n';
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "время поиска таких элементоу в неотсортированном массиве составило " << duration1 << " наносекунд\n";
			cout << '\n';
			auto start2 = high_resolution_clock::now();
			int mn1 = sortedArr[0], mx1 = sortedArr[0], k1 = 0;
			for (int i = 1; i < arrLenght; ++i) {
				if (sortedArr[i] > mx1) {
					mx1 = sortedArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (sortedArr[i] < mn1) {
					mn1 = sortedArr[i];
				}
			}
			int middleValue1 = (mn1 + mx1) / 2;
			cout << "индексы элементов равных среднему значению максимального и минимального элементов отсортированного массива" << ' ';
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] == middleValue1) {
					cout << i << ' ';
					k1 += 1;
				}
			}
			cout << '\n' << "количество таких элементов" << k1 << '\n';
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "время поиска таких элементов в отсортированном массиве составило " << duration2 << " наносекунд\n";

		}
		if (n == 5) {
			cout << "введите значение а \n";
			int a;
			cin >> a;
			int k = 0;
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] < a) {
					k += 1;
				}
			}
			cout << "элементов меньших а в отсортированном массиве" << ' ' << k << '\n';
		}
		if (n == 6) {
			cout << "введите значение b: \n";
			int b;
			cin >> b;
			int k = 0;
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] > b) {
					k += 1;
				}
			}
			cout << "элементов больших b в отсортированном массиве" << ' ' << k << '\n';
		}
		if (n == 7) {
			int n, k = 0;
			cout << "введите искомое значение n: \n";
			cin >> n;
			auto start = high_resolution_clock::now();
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] == n) {
					cout << "искомое значение n  " << n << " есть в отсортированном массиве он находится на позиции " << i << '\n';
					k += 1;
					break;
				}
			}
			if (k == 0) {
				cout << "искомый элемент не найден в отсортированном масиве\n";
			}
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start).count();
			cout << "поиск заданного значения методом обычного перебора занял " << duration << " наносекунд\n";
			auto start1 = high_resolution_clock::now();
			int result = binarySearch(sortedArr, n, 0, arrLenght - 1);
			if (result == -1) {
				cout << "искомый элемент не найден в отсортированном масиве\n";
			}
			else {
				cout << "искомое значение n = " << n << " есть в отсортированном массиве он находится на позиции " << result << '\n';
			}
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "поиск заданного значения методом бинарного поиска занял " << duration1 << " наносекунд\n";
		}
		if (n == 8) {
			int l, p;
			cout << "введи индекс элементов места которых ты хочешь поменять \n";
			cin >> l >> p;
			if ((l <= 99) and (l >= 0) and (p <= 99) and (p >= 0)) {
				swap(sortedArr[l], sortedArr[p]);
				cout << "массив с измененными индексами\n";
				for (int i = 0; i < arrLenght; ++i) {
					cout << setw(4) << sortedArr[i];
				}
			}
			else {
				cout << "значения неправильные!!!!1!!";
			}
			cout << '\n';
		}
		//идз ватафа
		if (n == 9) {
			findTwoMinAndTwoMax(randomArr, arrLenght);
		}
	} while (n != 0);
}