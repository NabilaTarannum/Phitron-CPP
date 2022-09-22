#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int _value)
    {
        this->value = _value;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void display(Node *node)
{
    while (node != NULL)
    {
        cout << node->value;
        if (node->Next != NULL)
            cout << " -> ";
        node = node->Next;
    }
    cout << endl
         << endl;
}

void insertAtTail(Node *&head, int _value)
{
    Node *newNode = new Node(_value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
        temp = temp->Next;
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int _value)
{
    Node *newNode = new Node(_value);
    newNode->Next = head;
    head = newNode;
}

int countlength(Node *&head)
{
    int count = 0;
    while (head != NULL)
        count++,
            head = head->Next;
    return count;
}

void insertionAtSpecificPosition(Node *&head, int position, int _value)
{
    int i = 0;
    Node *temp = head;
    while (i < position - 2)
        temp = temp->Next, i++;
    Node *newNode = new Node(_value);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
        return -1;
    while (temp->value != key)
    {
        if (temp->Next == NULL)
            return -1;
        temp = temp->Next,
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int count = 1, flag = 0, size = countlength(head), position[size + 1], k = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count, k++, flag = 1;
        }
        temp = temp->Next, count++;
    }
    if (flag == 0)
        cout << "Value not found" << endl;
    else
    {
        position[0] = k;
        cout << "Value found at position : ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ", ";
            else
                cout << endl;
        }
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    int count = 1, k = 1;
    Test T;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count, k++;
        }
        temp = temp->Next, count++;
    }
    T.position[0] = k;
    return T;
}

void searchByValueUnique(Node *&head, int searchValue, int _value)
{
    // step 1 : Search the Position of the search value
    int position = searchByValueUnique(head, searchValue);
    // step 2 : Insert the value at the position + 1
    insertionAtSpecificPosition(head, position + 1, _value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
        cout << "The list is empty" << endl;
}

int main()
{
    Node *head = NULL;
    int choice, value, position, searchValue;
    cout << "Choice 1 : Insertion at head" << endl
            << "Choice 2 : Insertion at tail" << endl
            << "Choice 3 : Insertion at Specific Position" << endl
            << "Choice 4 : Search a value (Unique list)" << endl
            << "Choice 5 : Search a value (Duplicate enabled list)" << endl
            << "Choice 6 : Insertion after a specific value (Unique list)" << endl
            << "Choice 7 : Insertion after a specific value (Duplicate enabled list) not found" << endl
            << "Choice 8 : Deletion at head" << endl
            << "Choice 0 : Exit" << endl
            << endl
            << "Choice (1/2/3/4/5/6/0) ? : ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value for Insertion at head: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value for Insertion at tail : ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired position : ";
            cin >> position;
            cout << "Enter the value for Insertion at Specific Position : ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to Search (Unique list) : ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position == -1)
                cout << "Value not found" << endl;
            else
                cout << "Value found at position " << position << endl;
            break;
        case 5:
            cout << "Enter the value to Search (Duplicate enabled list) : ";
            cin >> value;
            // searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
                cout << "Value not found" << endl;
            else
            {
                cout << "Value found at position : ";
                for (int i = 1; i < T.position[0]; i++)
                {
                    cout << T.position[i];
                    if (i < T.position[0] - 1)
                        cout << ", ";
                    else
                        cout << endl;
                }
            }
            break;
        case 6:
            cout << "Enter the value to search : ";
            cin >> searchValue;
            cout << "Enter the value to Insertion after a specific value (Unique list) : ";
            cin >> value;
            searchByValueUnique(head, searchValue, value);
            break;
        case 7:
            cout << "Not completed" << endl;
            break;
        case 8:
            deletionAtHead(head);
            break;
        default:
            cout << "Wrong choice" << endl;
            break;
        }
        cout << "Next Choice (1/2/3/4/5/6/0) ? : ";
        cin >> choice;
    }
    cout << endl
            << "Linked List : ";
    display(head);
    cout << "Length of Linked List : " << countlength(head) << endl;
    return 0;
}