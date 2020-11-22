#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head = nullptr, * tail = nullptr;

void InsertFirst(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = temp;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		temp->next = head;
		tail->next = temp;
		head = temp;
	}
}

void InsertLast(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = temp;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->next = head;
		tail = tail->next;
	}
}

int Listsize(Node* temp)
{
	int count = 0;
	do
	{
		count++;
		temp = temp->next;
	} while (temp!= head);
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
		temp->next = CurrentNode;
	}
}

void DeleteFirst()
{
	Node* temp = head;
	head = head->next;
	tail->next = head;
	delete temp;
}

void DeleteLast()
{
	Node* CurrentNode = head;
	Node* PreviousNode = new Node;
	while (CurrentNode->next != head)
	{
		PreviousNode = CurrentNode;
		CurrentNode = CurrentNode->next;
	}
	tail = PreviousNode;
	PreviousNode->next = head;
	delete CurrentNode;
}

void DeletePosition(int pos)
{
	if (pos >= Listsize(head) || pos < 0)
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
		Node* CurrentNode = head;
		Node* PreviousNode = new Node;
		for (int i = 0; i < pos; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		if (CurrentNode->next == head)
		{
			tail = PreviousNode;
			PreviousNode->next = head;
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
	int i = 0, size = Listsize(head);
	do
	{
		cout << temp->data;
		if (i + 1 < size)
		{
			cout << " ";
		}
		temp = temp->next;

	} while (temp != head);
}

void reverseprint(Node* temp)
{
	Node* NextNode = temp;
	Node* CurrentNode = temp;
	Node* PreviosNode = nullptr;
	Node* TempNode = new Node;
	int count = 0;
	do
	{
		NextNode = NextNode->next;
		CurrentNode->next = PreviosNode;
		PreviosNode = CurrentNode;
		CurrentNode = NextNode;
		if (count == 0)
		{
			TempNode = PreviosNode;
		}
		count++;

	} while (NextNode != head);
	head = PreviosNode;
	TempNode->next = head;
	int i = 0, size = Listsize(head);
	do
	{
		cout << PreviosNode->data;
		if (i + 1 < size)
		{
			cout << " ";
		}
		PreviosNode = PreviosNode->next;
		i++;
	} while (PreviosNode != head);
}

void Sort()
{
    Node* i=head;

    do
    {
        Node* j=i->next;
        while(j!=head)
        {
            if((i->data)>(j->data))
            {
                swap(i->data,j->data);
            }
            j=j->next;
        }
      i=i->next;
    }while(i!=head);
}

bool Search(int num)
{
    Node* temp=head;
    do
    {
        if(temp->data==num)
        {
            return true;
        }
        temp=temp->next;

    }while(temp!=head);

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
	reverseprint(head);
}
