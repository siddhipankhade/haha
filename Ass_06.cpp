#include<iostream>
#include<iomanip> // For setw
using namespace std;

class flight {
    int m[10][10], n;
    string v[20];

public:
    void getgraph();
    void display();
};

void flight::getgraph() {
    char ch;
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter names of cities: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) {
                m[i][j] = 0;
                continue;
            }
            cout << "Is there a direct path from " << v[i] << " to " << v[j] << "? (y/n): ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter time (in minutes) to reach " << v[j] << " from " << v[i] << ": ";
                cin >> m[i][j];
            } else if (ch == 'n' || ch == 'N') {
                m[i][j] = 0;
            } else {
                cout << "Invalid input! Assuming no path.\n";
                m[i][j] = 0;
            }
        }
    }
}

void flight::display() {
    cout << "\nFlight Time Adjacency Matrix (in minutes):\n\n";
    cout << setw(12) << " ";

    for (int j = 0; j < n; j++) {
        cout << setw(12) << v[j];
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(12) << v[i];
        for (int j = 0; j < n; j++) {
            cout << setw(12) << m[i][j];
        }
        cout << "\n";
    }
}

int main() {
    flight f;
    f.getgraph();
    f.display();
    return 0;
}
