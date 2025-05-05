#include<iostream>
#include<string.h>
using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class Gll {
    char ch[20];    
    int n, i;    
    node *head = NULL;

public:
    node* create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node* Gll::create() {
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void Gll::insertb() {
    if (head == NULL) {
        node *t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists.";
    }
}

void Gll::insertc() {
    if (head == NULL) {
        cout << "\nNo book exists.";
    } else {
        cout << "\nHow many chapters do you want to insert? ";
        cin >> n;
        for (i = 0; i < n; i++) {
            node *t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                node *temp = head->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Gll::inserts() {
    if (head == NULL) {
        cout << "\nNo book exists.";
    } else {
        cout << "\nEnter the name of the chapter to insert sections: ";
        char chapName[20];
        cin >> chapName;

        node *temp = head->down;
        while (temp != NULL) {
            if (strcmp(chapName, temp->name) == 0) {
                cout << "\nHow many sections do you want to insert? ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    node *t1 = create();
                    if (temp->flag == 0) {
                        temp->down = t1;
                        temp->flag = 1;
                    } else {
                        node *t2 = temp->down;
                        while (t2->next != NULL)
                            t2 = t2->next;
                        t2->next = t1;
                    }
                }
                return;
            }
            temp = temp->next;
        }
        cout << "\nChapter not found.";
    }
}

void Gll::insertss() {
    if (head == NULL) {
        cout << "\nNo book exists.";
    } else {
        cout << "\nEnter the name of the chapter to insert subsections: ";
        char chapName[20], secName[20];
        cin >> chapName;

        node *chapter = head->down;
        while (chapter != NULL) {
            if (strcmp(chapName, chapter->name) == 0) {
                if (chapter->flag == 0) {
                    cout << "\nNo sections found in this chapter.";
                    return;
                }
                cout << "\nEnter the name of the section to insert subsections: ";
                cin >> secName;

                node *section = chapter->down;
                while (section != NULL) {
                    if (strcmp(secName, section->name) == 0) {
                        cout << "\nHow many subsections do you want to insert? ";
                        cin >> n;
                        for (i = 0; i < n; i++) {
                            node *t1 = create();
                            if (section->flag == 0) {
                                section->down = t1;
                                section->flag = 1;
                            } else {
                                node *t2 = section->down;
                                while (t2->next != NULL)
                                    t2 = t2->next;
                                t2->next = t1;
                            }
                        }
                        return;
                    }
                    section = section->next;
                }
                cout << "\nSection not found.";
                return;
            }
            chapter = chapter->next;
        }
        cout << "\nChapter not found.";
    }
}

void Gll::displayb() {
    if (head == NULL) {
        cout << "\nBook does not exist.";
    } else {
        cout << "\nNAME OF BOOK: " << head->name;
        if (head->flag == 1) {
            node *chapter = head->down;
            while (chapter != NULL) {
                cout << "\n\tCHAPTER: " << chapter->name;
                if (chapter->flag == 1) {
                    node *section = chapter->down;
                    while (section != NULL) {
                        cout << "\n\t\tSECTION: " << section->name;
                        if (section->flag == 1) {
                            node *subsection = section->down;
                            while (subsection != NULL) {
                                cout << "\n\t\t\tSUBSECTION: " << subsection->name;
                                subsection = subsection->next;
                            }
                        }
                        section = section->next;
                    }
                }
                chapter = chapter->next;
            }
        }
    }
}

int main() {
    Gll g;
    int x;
    while (1) {
        cout << "\n\nEnter your choice";
        cout << "\n1. Insert book";
        cout << "\n2. Insert chapter";
        cout << "\n3. Insert section";
        cout << "\n4. Insert subsection";
        cout << "\n5. Display book";
        cout << "\n6. Exit\n";
        cin >> x;
        switch (x) {
            case 1: g.insertb(); break;
            case 2: g.insertc(); break;
            case 3: g.inserts(); break;
            case 4: g.insertss(); break;
            case 5: g.displayb(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice.";
        }
    }
    return 0;
}