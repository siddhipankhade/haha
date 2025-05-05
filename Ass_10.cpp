#include <iostream>
using namespace std;

void min_heapify(int *a, int i, int n) {
    int temp = a[i];
    int j = 2 * i;

    while (j <= n) {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = temp;
}

void max_heapify(int *a, int i, int n) {
    int temp = a[i];
    int j = 2 * i;

    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = temp;
}

void build_minheap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--)
        min_heapify(a, i, n);
}

void build_maxheap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--)
        max_heapify(a, i, n);
}

int main() {
    int n, ch;
    int a[100]; // Increased size for safety

    cout << "\nEnter number of students: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter mark of student " << i << ": ";
        cin >> a[i];
    }

    do {
        cout << "\nMenu:";
        cout << "\n1. Build Min Heap";
        cout << "\n2. Build Max Heap";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                build_minheap(a, n);
                cout << "Min Heap:\n";
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << endl;
                break;
            case 2:
                build_maxheap(a, n);
                cout << "Max Heap:\n";
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << endl;
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (ch != 3);

    return 0;
}
