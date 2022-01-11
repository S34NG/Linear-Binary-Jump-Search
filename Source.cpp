#include<iostream>
#include<conio.h>
#include<math.h>
#define min(p,q) ((p) < (q) ? (p) : (q))
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter Element " << i + 1 <<" : ";
		cin >> arr[i];
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << " : " << arr[i]<<endl;
	}
}

void sortAsc(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int linearSearch(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int n, int x) {
	int l, h, m;
	l = 0;
	h = n-1;
	m = 0;

	while (l <= n) {
		if (arr[m] == x) return m;
		m = (1 + h) / 2;
		if (arr[m] < x) {
			l = m + 1;
		}
		else if (arr[m] > x) {
			h = m - 1;
		}
	}

	return -1;
}

int jumpSearch(int arr[], int n, int x) {
	//Finding block size to be jumped
	int m = sqrt(n);

	// Finding the block where element is present (if is present)
	int k = 0;
	while (arr[min(m, n) - 1] < x) {
		k = m;
		m += sqrt(n);
		if (k >= n) return -1;
	}

	//Doing Linear Search for X block
	while (arr[k] < x) {
		k++;

		//if we reached next block or end of array, element is not present
		if (k == min(m, n)) return -1;
		
		//if elment is found
		if (arr[k] == x) return k;
	}
	return -1;
}

int interpolationSearch(int arr[], int n, int x) {
	int l, h, m;
	l = 0;
	h = n - 1;
	m = 0;

	while (1 <= h && x >= arr[l] && x <= arr[h]) {
		m = 1 + ((x - arr[l]) * (h - 1)) / (arr[h] - arr[l]);
		if (arr[m] < x) l = m + 1;
		else if (arr[x] > x) l = m - 1;
		else return m;

	}
	return -1;
}

int ternarySearch(int arr[], int n, int x) {
	int l = 0;
	int m1, m2;
	while (n >= 1) {
		m1 = 1 + (n - 1) / 3;
		m2 = n - (n - 1) / 3;

		if (x == arr[m1]) {
			return m1;
		}
		if (x == arr[m2]) {
			return m2;
		}

		if (x < arr[m1]) n = m1 - 1;
		else if (x > arr[m2]) l = m2 + 1;
		else {
			l = m1 + 1;
			n = m2 - 1;
		}

	}
	return -1;
}


int main() {
	int arr[100], isFound, n, x, ch;

	cout << "Enter n Number: "; cin >> n;
	input(arr, n);
	cout << "This is array you are Enter: " << endl;
	// sort array in ascending order
	sortAsc(arr, n);
	output(arr, n);

	do {
		cout << "1.Linear or Squential Search" << endl;
		cout << "2. Binary Search" << endl;
		cout << "3. Jump Search\n";
		cout << "4. Interpolation Search\n";
		cout << "5. Ternary Search\n";
		cout << "0. Exit"<<endl;
		cout << "Enter OP: "; cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter number to Search: "; cin >> x;
			isFound = linearSearch(arr, n, x);
			if (isFound != -1) {
				cout << "The Value " << x <<" found at the position \n" << isFound + 1;
			}
			else {
				cout << "The Value" << x << " not Found";
			}
			break;
		case 2:
			cout << "Enter number to Search: "; cin >> x;
			isFound = binarySearch(arr, n, x);
			if (isFound != -1) {
				cout << "The Value " << x << " found at the position \n" << isFound + 1;
			}
			else {
				cout << "The Value" << x << " not Found";
			}
			break;
		case 3:
			cout << "Enter number to Search: "; cin >> x;
			isFound = jumpSearch(arr, n, x);
			if (isFound != -1) {
				cout << "The Value " << x << " found at the position \n" << isFound + 1;
			}
			else {
				cout << "The Value" << x << " not Found";
			}
			break;
		case 4:
			cout << "Enter number to Search: "; cin >> x;
			isFound = interpolationSearch(arr, n, x);
			if (isFound != -1) {
				cout << "The Value " << x << " found at the position \n" << isFound + 1;
			}
			else {
				cout << "The Value" << x << " not Found";
			}
			break;
		case 5:
			cout << "Enter number to Search: "; cin >> x;
			isFound = ternarySearch(arr, n, x);
			if (isFound != -1) {
				cout << "The Value " << x << " found at the position " << isFound + 1<<endl;
			}
			else {
				cout << "The Value" << x << " not Found";
			}
			break;
		default:
			break;
		}
	} while (ch != 0);
	return 0;
}