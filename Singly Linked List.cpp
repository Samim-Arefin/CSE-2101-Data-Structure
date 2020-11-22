#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* head = nullptr, * tail = nullptr;

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

void InsertLast(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

void InsertFirst(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void InsertPosition(int pos,int data)
{
	if (pos > Listsize(head) || pos < 0)
	{
		cout << "Invalid Position!!\n";
		return;
	}
	else if(pos==0)
	{
		InsertFirst(data);
	}
	else if (pos == Listsize(head))
	{
		InsertLast(data);
	}
	else
	{
		Node* PreviousNode = new Node;
		Node* temp = new Node;
		Node* CurrentNode = head;
		for (int i = 0; i < pos; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		temp->data = data;
		PreviousNode->next = temp;
		temp->next = CurrentNode;
	}
}

void DeleteFirst()
{
	Node* temp = head;
	head= head->next;
	delete temp;
}

void DeleteLast()
{
	Node* PreviousNode = new Node;
	Node* CurrentNode = head;
	while (CurrentNode->next != nullptr)
	{
		PreviousNode = CurrentNode;
		CurrentNode = CurrentNode->next;
	}
	tail = PreviousNode;
	PreviousNode->next = nullptr;
	delete CurrentNode;

}

void DeletePosition(int pos)
{
	if (pos >= Listsize(head) || pos < 0 )
	{
		cout << "Invalid Position!!\n";
		return;
	}
	else if (pos == 0)
	{
		DeleteFirst();
	}
	else
	{
		Node* PreviousNode = new Node;
		Node* CurrentNode = head;
		for (int i = 0; i < pos; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		if (CurrentNode->next == nullptr)
		{
			tail = PreviousNode;
			PreviousNode->next = nullptr;
			delete CurrentNode;
		}
		else
		{
			PreviousNode->next = CurrentNode->next;
		}
	}
}

void print(Node* temp)
{
	int i = 0;
	int size = Listsize(head);
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
	cout << "\n";
}

void reverseprint(Node* temp)
{
	Node* CurrentNode = head;
	Node* NextNode = head;
	Node* PreviosNode = nullptr;
	while (NextNode != nullptr)
	{
		NextNode = NextNode->next;
		CurrentNode->next = PreviosNode;
		PreviosNode = CurrentNode;
		CurrentNode = NextNode;
	}
	head = PreviosNode;
	int size = Listsize(head);
	int i = 0;
	while (PreviosNode != nullptr)
	{
		cout << PreviosNode->data;
		if (i + 1 < size)
		{
			cout << " ";
		}
		PreviosNode = PreviosNode->next;
		i++;
	}
	cout << "\n";

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
	int size;
	cin >> size;
	while (size--)
	{
		int num;
		cin >> num;
		InsertLast(num);
	}
	cout << "\nList Size:\n"<< Listsize(head) << '\n';

	cout << "\nList Elements:\n";
	print(head);

	cout << "\n\nEnter the Number You Want to Insert at First:\n";
	int num;
	cin >> num;
	InsertFirst(num);

	cout << "\nAfter Inserting the Value at First List Elements will be:\n";
	print(head);


	cout << "\n\nInsert at Specific Position:\n";
	cout << "Enter Position & Value Which You gonna insert in this Position:\n";
	int value, pos;
	cin >>pos>>value;
	InsertPosition(pos,value);

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
	reverseprint(head);
}
