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

// Set the head of the list and update old values if applicable
void setHead(SLLNode **head, int value) {
    auto *node = new SLLNode();
    node->value = value;

    if (head == nullptr) {
        node->next = nullptr;
        *head = node;
    } else {
        SLLNode *tmp = *head;
        node->next = tmp;
        *head = node;
        delete tmp;
    }
}

void setTail(SLLNode **head, int value) {
    cout << "in method";
    auto *node = new SLLNode();
    node->value = value;

    if (*head != nullptr) {
        SLLNode *tmp = *head;
        while (tmp->next != nullptr) {
            cout << "Searching for tail";
            tmp = tmp->next;
        }
        tmp->next = node;
        cout << "\nAdded " << value << " to the end of the list.\n";
    } else {
        cout << "\nList is empty, inserting value at head...\n";
        setHead(head, value);
    }
}

void deleteHead(SLLNode **head) {
    if (*head == nullptr) {
        cout << "\nHead does not exist.\n";
    } else {
        SLLNode *tmp = *head;
        tmp = tmp->next;
        *head = tmp;
        cout << "\nHead successfully deleted.\n";
    }
}

void deleteTail(SLLNode **head) {
    if (*head == nullptr) {
        cout << "\nList is empty.\n";
    } else {
        SLLNode *tmp = *head;
        while (tmp->next != nullptr) {
        }
    }
}

void display(SLLNode *head) {
    cout << "List Contents: \n";
    while (head != nullptr) {
        cout << head->value << "\n" ;
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

    while (user_option != 12) {
        switch (user_option) {
            case 0:
                int headValue;
                cout << "Enter a number for a new head: \n";
                cin >> headValue;

                setHead(&sllHead, headValue);
                display(sllHead);
                break;
            case 1:
                int tailValue;
                cout << "Enter a number for the tail value: \n";
                cin >> tailValue;

                setTail(&sllHead, tailValue);
                display(sllHead);
                break;
            case 2:
                deleteHead(&sllHead);
                display(sllHead);
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
            default:
                cout << "Error... Something went wrong...";
                break;
        }
        user_option = load_user_menu_selection(user_option);
    }
}
