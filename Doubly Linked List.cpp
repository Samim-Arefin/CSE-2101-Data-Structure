#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node* head = nullptr, * tail = nullptr;

void InsertFirst(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = head;
	temp->prev = nullptr;
	if (head != nullptr)
	{
		head->prev = temp;
	}
	head = temp;
}

void InsertLast(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = nullptr;
	temp->prev = nullptr;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
	}
}

int Listsize(Node* temp)
{
	int count = 0;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void InsertPosition(int pos,int value)
{
	if (pos > Listsize(head) || pos < 0)
	{
		cout << "Invalid Position!!\n";
		return;
	}
	else if (pos == 0)
	{
		InsertFirst(value);
	}
	else if (pos == Listsize(head))
	{
		InsertLast(value);
	}
	else
	{
		Node* CurrentNode = head;
		Node* PreviousNode = new Node;
		Node* temp = new Node;
		temp->data = value;
		for (int i = 0; i < pos; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		PreviousNode->next = temp;
		temp->prev = PreviousNode;
		temp->next = CurrentNode;
		CurrentNode->prev = temp;
	}
}

void DeleteFirst()
{
	Node* temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
}

void DeleteLast()
{
	Node* CurrentNode = head;
	Node* Previousnode = new Node;
	while (CurrentNode->next != nullptr)
	{
		Previousnode = CurrentNode;
		CurrentNode = CurrentNode->next;
	}
	tail = Previousnode;
	Previousnode->next = nullptr;
	delete CurrentNode;
}

void print(Node* temp)
{
	int i = 0, size = Listsize(temp);
	while (temp != nullptr)
	{
		cout << temp->data;
		if (i + 1 < size)
		{
			cout << " ";
		}
		temp = temp->next;
		i++;
	}
}

void DeletePosition(int pos)
{
	if (pos >= Listsize(head) || pos < 0)
	{
		cout<<"Invalid Position!!\n";
	}
	else if(pos==0)
	{
		DeleteFirst();
	}
	else
	{
		Node* CurrentNode = head;
		Node* PreviousNode = new Node;
		for (int i = 0; i < pos; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		if (CurrentNode->next == nullptr)
		{
			PreviousNode->next = nullptr;
			tail = PreviousNode;
		}
		else
		{
			PreviousNode->next = CurrentNode->next;
			CurrentNode->next->prev = PreviousNode;
		}
	}
}

void reverseprint(Node* temp)
{
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
}
void Sort()
{
    Node* i=head;
    while(i!=nullptr)
    {
        Node* j=i->next;
        while(j!=nullptr)
        {
            if((i->data)>(j->data))
            {
                swap(i->data,j->data);
            }
            j=j->next;
        }
        i=i->next;
    }
}

bool Search(int num)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==num)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}


int main()
{
	cout << "Data Will be Insert at Last:\n";
	cout << "Enter List Size:\n";
	int num;
	cin >> num;
	while (num--)
	{
		int temp;
		cin >> temp;
		InsertLast(temp);
	}
	cout << "\nList Size:\n" << Listsize(head) << '\n';

	cout << "\nList Elements:\n";
	print(head);

	cout << "\n\nEnter the Number You Want to Insert at First:\n";
	int val;
	cin >> val;
	InsertFirst(val);

	cout << "\nAfter Inserting the Value at First List Elements will be:\n";
	print(head);

	cout << "\n\nInsert at Specific Position:\n";
	cout << "Enter Position & Value Which You gonna insert in this Position:\n";
	int n, pos;
	cin >> pos>>n;
	InsertPosition(pos,n);

	cout << "\nAfter Inserting the Value at Specific Position List Elements will be:\n";
	print(head);

	cout << "\n\nAfter Deleting The First Node List Elements will be:\n";
	DeleteFirst();
	print(head);

	cout << "\n\nAfter Deleting The Last Node List Elements will be:\n";
	DeleteLast();
	print(head);

	cout << "\n\nEnter The Position You want to Delete:\n";
	int p;
	cin >> p;
	DeletePosition(p);
	cout << "\nAfter Deleting The Node in Specific Position List Elements will be:\n";
	print(head);

	cout << "\n\nEnter the Number You Want to Find:\n";
	int s;
	cin>>s;
	if(Search(s))
    {
        cout<<"Number Found\n";
    }
    else
    {
        cout<<"Number Not Found!!\n";
    }

	Sort();
	cout << "\nAfter Sorting List Elements will be:\n";
	print(head);

	cout << "\n\nPrint in Reverse Order:\n";
	reverseprint(tail);
}
