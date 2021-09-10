#include <iostream>
#include <string>

using namespace std;

class SLLNode {
    public:
        int value;
        SLLNode *next;
};

class DLLNode {
    public:
        int value;
        DLLNode *next;
        DLLNode *prev;
};

void setHead(SLLNode **head, int value) {
    auto *node = new SLLNode();
    node->value = value;
    node->next = *head;
    *head = node;
}

void display(SLLNode *head) {
    while (head != nullptr) {
        cout << head->value;
        head = head->next;
    }
}

void setHead(DLLNode **head, int value) {

}

// Display main menu for user input
void mainMenu() {
    cout << "Single linked list: \n IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)\n";
    cout << "Double Linked List: \n IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)\n";
    cout << "Exit Program (12)\n\n";
    cout << "Enter an option: ";
}

int load_user_menu_selection(int user_option) {
    mainMenu();
    cin >> user_option;
    return user_option;
}

int main() {
    int user_option;
    SLLNode *sllHead = nullptr;
    DLLNode *dllHead = nullptr;

    do {
        user_option = load_user_menu_selection(user_option);
    } while ((user_option < 0) || (user_option > 12));

    switch (user_option) {
        case 0:
            int headValue;
            cout << "Enter a number for a new head: \n";
            cin >> headValue;

            if (sllHead == nullptr) {
                setHead(&sllHead, headValue);
                display(sllHead);
            } else {
                cout << "hmm";
            }
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
    }
}
