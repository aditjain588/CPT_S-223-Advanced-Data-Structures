#include <iostream>
#include <fstream> 
#include<sstream>

using namespace std;

class LinkList; //We have created a linklist by name "LinkList"

class node
{
     friend class LinkList;
private:
     int data;
    node *next;    //Pointers are used to traverse the link list
public:
    node(int x=0)
    {
    data= x;
    next=NULL;
    }
};

class LinkList
{
        int count;
        node *first;
public:
    LinkList(){first = NULL;}

    void Display();
    void Sort();
    void Median();
    void Max();
    void Min();
    void Read(string file);
    void Write(string line);
    void Insert(int x);
    void InsertLast(int x);
};

void LinkList::Insert(int x) //Method to insert data into the singly linked list
{
    node *temp = new node(x);
    if(first==NULL)
        {
        first=temp;
        }

    else {
        node *prev=NULL;
        node *cur=first;
        while (cur != NULL)
        {
            if(cur->data>=temp->data){
            break;
            }
            else
            {
                prev = cur;
                cur=cur->next;
            }
        }

        if(cur==first)
        {
        temp->next=cur;
        prev->next=temp;
        }
    }
}

void LinkList::Read(string file){
    int i=0;
    count=0;
    string inside;
      std::ifstream myfile (file.c_str());
      if (myfile.is_open())
      {
            while ( getline (myfile,inside) )
            {
              stringstream geek(inside);
            geek>>i;
            InsertLast(i);
            count++;
            }
        myfile.close();
    Sort();
    Display();
     }
else cout<<"Sorry but it is unable to open the given file";

}

   void LinkList::Write(string line)
    {
        ofstream File1;
        node *temp1;
        temp1=first;
        fstream ofs;
        ofs.open(line.c_str(), ios::out | ios::trunc);
        ofs.close();
        File1.open(line.c_str());
        while(temp1!=NULL)
        {
            File1 <<temp1 -> data<<endl;
            temp1=temp1->next;
        }
        File1.close();
    }
 void LinkList::InsertLast(int x){
        node *temp = new node(x);

        if (first == NULL) // insert at 1st position if empty list
        {
            first = temp;
            return;
        }
        node *temp2 = first;
        while (temp2->next)
            temp2= temp2->next;

        temp2->next = temp;

    }


void LinkList::Display() //Method to display the given data into a singly linked list
{
    node *temp=first;
    while(temp)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    cout<<endl;
}
void LinkList::Median()
{
    node *temp;
    temp=first;
    int elements=count;
    int median=0;
        for(int y=0; y<(elements/2); y++)
        {
            if(elements % 2==0)
            {
                if((y>=elements/2)-2)
                {
                    median=median+temp->data;
                }
            else
            {
                if (y==elements/2)
                {
                    median = temp->data;
                }
            }
            temp=temp->next;
            }
        median=median/2;
        }
    cout<<"Median: "<<median<<endl;
}
void LinkList::Max()//Method to compute the maximum element in link list
    {
    int max1=0;
    node *temp=first;
    while(temp)
        {
            if(temp->next==NULL)
            {
            max1=temp->data;
            }
            temp=temp->next;
        }
    cout<<"The maximum element in the input list is "<<max1<<endl;
    }

void LinkList::Min()//Method to compute the maximum element in link list
    {
    node *temp;
    temp=first;
    int min1;
    min1=first->data;
    cout<<"The minimum element in the input list is "<<min1<<endl;

    }


void LinkList::Sort() //Method to the sort the singly linked list
{
    node *num1,*num2;
    int temp=0;
    num1=first;
    for(num1=first;num1 !=NULL; num1=num1-> next)
    {
        for (num2=num1->next;num2 != NULL; num2=num2->next)
        {
            if(num1->data > num2->data)
            {
            temp=num1->data;
            num1->data=num2->data;
            num2 ->data=temp;
            }
        }
    }
}

int main()
{
    LinkList L1; // name given to operate the listed methods above for computation

    string input1;

     int x=0;
    cout<<"Please enter the input filename\n";
    cin>>input1;
    while(1)
    {
        int j=0;
        cout<<"Press one to read the file and check its content"<<endl;
        cout<<"Press two to insert an element to the file"<<endl;
        cout<<"Press three to exit"<<endl;
        cin>>j;
        switch(j)
            {
            case 1:

            L1.Read(input1);
            L1.Min();
            L1.Max();
            L1.Median();
            break;

            case 2: cout<<"Enter the element to be inserted and display";
            cin>>x;
            L1.InsertLast(x);
            L1.Write(input1);
            L1.Display();

            L1.Min();

            L1.Max();

            L1.Median();

        case 3: return 0;

        }
}

return 0;


}
