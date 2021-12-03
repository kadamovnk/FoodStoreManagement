using namespace std;

struct bucket
{
    int data;
    bucket* link;
};

struct bucket* top;

void bpush(int data)
{
	struct bucket* temp;
	temp = new bucket();
	if (!temp)
    {
		cout << "\nHeap Overflow";
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}

int isEmpty()
{
	return top == NULL;
}

int peek()
{
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}


void bpop()
{
	struct bucket* temp;

	if (top == NULL)
    {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else
	{

		temp = top;
		top = top->link;
		temp->link = NULL;

		// release memory of top node
		free(temp);
	}
		cout<<"\t\t---=== Your Trolley No is :"<<top->data<<" ===---\n"<<endl;
}

void bdisplay()
{
	struct bucket* temp;


	if (top == NULL)
    {
		cout << "\nStack Underflow";
		exit(1);
	}
	else
	{
		temp = top;
		while (temp != NULL)
        {
            cout << temp->data << " ";
			temp = temp->link;
		}
	}
}
