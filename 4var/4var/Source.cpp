#include<iostream>

using namespace std;
//сортировка 
void indexslian(int* a, int l, int center, int r) {
    int n1 = center - l + 1;
    int n2 = r - center;

    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[center + 1 + j];
    int k = l;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

//рекурсивное деление массива на части и сортировка
void slian(int* a, int l, int r) {
    if (l >= r) {
        return;
    }
    int center = l + (r - l) / 2;
    slian(a, center + 1, r);
    slian(a, l, center);
    indexslian(a, l, center, r);//сорт кусков массива
}


//сортировка и поиск центра
int indexfastsort(int* a, int l, int h)
{
	int pivot = a[h];
	int i = l - 1; 

	for (int j = l; j <= h - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return i + 1;
}
//рекурсивное деление массива на части и сортировка
void fastsort(int* a, int l, int h)
{
    int Index;
	if (l < h)
	{
		Index = indexfastsort(a, l, h);//центр 
        fastsort(a, l, Index - 1); 
        fastsort(a, Index + 1, h);
	}
}



int main() {
    setlocale(LC_ALL, "russian");
	int y,k;
	cout << "кол элементов в 1 массиве:";
	cin >> y;
	int* one = new int[y];
	for (int i = 0; i < y; i++) {
		cin >> one[i];
	}

    cout << "кол элементов в 2 массиве:";
    cin >> k;
    int* too = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> too[i];
    }



    fastsort(one, 0, y - 1);//  функция быстрой сортировки
    slian(too, 0, k - 1);//  функция  сортировки слиянием
      
    cout << "быстрая сортировка:";
    for (int i = 0; i < y; i++) {
            cout << one[i] << " ";
     }
    cout << endl << "сортировки слиянием:";;
    for (int i = 0; i < k; i++) {
        cout << too[i] << " ";
    }
       
      
    
    delete[] one;
    delete[] too;
}