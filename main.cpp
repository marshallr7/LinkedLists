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
    __unused DLLNode *prev;
};

// Check if a Single Linked List is empty
bool isEmpty(SLLNode **head) {
    if (*head == nullptr) {
        return true;
    } else {
        return false;
    }
}

// Set the head of the list and update old values if applicable
void setHead(SLLNode **head, int value) {
    auto *node = new SLLNode();
    node->value = value;

    if (isEmpty(head)) {
        node->next = nullptr;
        *head = node;
    } else {
        SLLNode *tmp = *head;
        node->next = tmp;
        *head = node;
        delete tmp;
    }
}

// Set the tail to the new value and relocate pre-existing tail
void setTail(SLLNode **head, int value) {
    auto *node = new SLLNode();
    node->value = value;

    if (!isEmpty(head)) {
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

// Remove the head node and update to new head
void deleteHead(SLLNode **head) {
    if (isEmpty(head)) {
        cout << "\nHead does not exist.\n";
    } else {
        SLLNode *tmp = *head;
        tmp = tmp->next;
        *head = tmp;
        cout << "\nHead successfully deleted.\n";
    }
}

// Remove the tail node and update to new tail
void deleteTail(SLLNode **head) {
    if (isEmpty(head)) {
        cout << "\nList is empty.\n";
    } else {
        SLLNode *tmp = *head;
        while (tmp->next->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        cout << "\nTail deleted.\n";
    }
}

// Search for a value and remove it from the single linked list
void searchAndDelete(SLLNode **head, int value) {
    SLLNode *tmp = *head;
    SLLNode *prev = nullptr;

    if (isEmpty(head)) {
        cout << "\nThe list is empty, can not delete element.\n";
    }

    if (tmp->value == value) {
        cout << "\nValue was found at head, deleting head...\n";
        deleteHead(head);
        return;
    } else {
        while (tmp != nullptr && tmp->value != value) {
            prev = tmp;
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            cout << "\nThe value was not found in the list.\n";
            return;
        }

        prev->next = tmp->next;
    }
}

// display single linked list
void display(SLLNode *head) {
    cout << "\n\nList Contents: \n";
    while (head != nullptr) {
        cout << head->value << "\n\n" ;
        head = head->next;
    }
}

// display double linked list
void display(DLLNode *head) {
    cout << "\n\nList Contents: \n";
    while (head != nullptr) {
        cout << head->value << "\n" ;
        head = head->next;
    }
}

// Set double linked list head
void setHead(DLLNode **head, int value) {
    auto *node = new DLLNode();
    node->value = value;
    node->prev = nullptr;
    if (*head == nullptr) {
        node->next = nullptr;
        *head = node;
    } else {
        DLLNode *tmp = *head;
        node->next = tmp;
        *head = node;
        delete tmp;
    }
}

// set double linked list tail
void setTail(DLLNode **head, int value) {
    if (*head == nullptr) {
        cout << "The list is empty... Inserting value as head";
        setHead(head, value);
        return;
    } else {
        auto *node = new DLLNode();
        node->value = value;
        DLLNode *tmp = *head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = node;
        node->next = nullptr;
        node->prev = tmp;
    }
}

// delete head from double linked list
void deleteHead(DLLNode **head) {
    if (*head == nullptr) {
        cout << "The list is empty.";
        return;
    } else {
        DLLNode *tmp = *head;
        tmp = tmp->next;
        *head = tmp;
    }
}

// delete tail from double linked list
void deleteTail(DLLNode **head) {
    if (*head == nullptr) {
        cout << "The list is empty.";
        return;
    }
    DLLNode *tmp = *head;
    if (tmp->next == nullptr) {
        deleteHead(head);
        return;
    }
    while (tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = nullptr;
}

// search and delete a value in a double linked list
void searchAndDelete(DLLNode **head, int value) {
    if (*head == nullptr) {
        cout << "\nThe list is empty.\n";
        return;
    }
    DLLNode *tmp = *head;
    DLLNode *prev;
    if (tmp->value == value) {
        deleteHead(head);
        return;
    }
    while ((tmp->next != nullptr) && (tmp->next->value != value)) {
        tmp = tmp->next;
    }

    if (tmp->next == nullptr) {
        cout << "\nThe value was not found in the list\n";
        return;
    }

    // remove the node with value and reassign everything
    prev = tmp;
    tmp = tmp->next->next;
    tmp->prev = prev;
//    delete prev->next;
    prev->next = tmp;

}

// Display main menu for user input
void mainMenu() {
    cout << "Single linked list: \n IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)\n";
    cout << "Double Linked List: \n IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)\n";
    cout << "Exit Program (12)\n\n";
    cout << "Enter an option: ";
}

// display driver menu and load user input into memory
int load_user_menu_selection(int user_option) {
    mainMenu();
    cin >> user_option;
    return user_option;
}

int main() {
    int user_option = 0, value;
    SLLNode *sllHead = nullptr;
    DLLNode *dllHead = nullptr;

    do {
        user_option = load_user_menu_selection(user_option);
    } while ((user_option < 0) || (user_option > 12));

    while (user_option != 12) {
        switch (user_option) {
            case 0:
                cout << "\nEnter a number for a new head: \n";
                cin >> value;

                setHead(&sllHead, value);
                display(sllHead);
                break;
            case 1:
                cout << "\nEnter a number for the tail value: \n";
                cin >> value;

                setTail(&sllHead, value);
                display(sllHead);
                break;
            case 2:
                deleteHead(&sllHead);
                display(sllHead);
                break;
            case 3:
                deleteTail(&sllHead);
                display(sllHead);
                break;
            case 4:
                cout << "\nEnter a number to remove from the list: \n";
                cin >> value;
                searchAndDelete(&sllHead, value);
                display(sllHead);
                break;
            case 5:
                display(sllHead);
                break;
            case 6:
                cout << "Enter a number: ";
                cin >> value;

                setHead(&dllHead, value);
                display(dllHead);
                break;
            case 7:
                cout << "Enter a number: ";
                cin >> value;

                setTail(&dllHead, value);
                display(dllHead);
                break;
            case 8:
                deleteHead(&dllHead);
                display(dllHead);
                break;
            case 9:
                deleteTail(&dllHead);
                display(dllHead);
                break;
            case 10:
                cout << "Enter a value: \n";
                cin >> value;
                searchAndDelete(&dllHead, value);
                display(dllHead);
                break;
            case 11:
                display(dllHead);
                break;
            default:
                cout << "Error... Something went wrong...\n";
                break;
        }
        user_option = load_user_menu_selection(user_option);
    }
}
