#include<iostream>
#include<fstream> //library fsrream is used to read input file
#include<string>
#include<time.h> // library time.h is used to compute execution time

using namespace std;

int maxsubsum1 (int a[],int l) //First Algorithm
	{
		int maxSum=0;
		int size=l;

		for(int i=0;i<size;i++)
		{
			for( int j=i;j<size;j++)
			{
			    int thissum=0;

				for(int k=i;k<=j;k++)
					thissum+=a[k];

                if(thissum>maxSum)
                    maxSum=thissum;
			}
		}


	cout<<"MaxSum computed from first algorithm is :"<< maxSum<<endl;
	return maxSum;
	}

int maxsubsum2(int a[] ,int l) //Second Algorithm
	{
	int maxSum=0;
	int size=l;
	for(int i=0;i<size;i++)
		{
		int thissum=0;
		for(int j=i;j<size; j++)
			{
				thissum += a[j];
			if(thissum >maxSum)
				{
				maxSum=thissum;
				}
			}
		}
		cout<<"MaxSum computed from second algorithm is :" << maxSum<< endl;
		return maxSum;
}

int max3(int maxleftsum , int maxrightsum , int maxbordersum) //Third Algorithm
	{
		if(maxleftsum>maxrightsum && maxleftsum<maxbordersum)
		{
			return maxleftsum;
		}
		else if(maxbordersum>maxrightsum && maxleftsum<maxbordersum)
		{
			return maxbordersum;
		}
		else if (maxbordersum<maxrightsum && maxleftsum<maxrightsum)
		{
			return maxrightsum;
		}
		else if (maxbordersum==maxrightsum && maxleftsum<maxrightsum)
		{
			return maxrightsum;
		}
		else if ( maxbordersum==maxrightsum && maxleftsum>maxrightsum)
		{
			return maxleftsum;
		}
		else if ( maxbordersum < maxrightsum && maxleftsum==maxrightsum)
		{
			return maxrightsum;
		}
		else if ( maxbordersum > maxrightsum && maxleftsum==maxrightsum)
		{
			return maxbordersum;
		}
		else
		{
			return maxleftsum;
		}
	}
int maxsumrec(int a[],int left,int right)
	{
	if ( left==right)
		{
			if(a[left]>0)
			{
				return a[left];
			}
			else
			{
				return 0;
			}
		}
	int center = (left+right)/2;
	int maxleftsum = maxsumrec(a,left,center);
	int maxrightsum = maxsumrec(a,center+1,right);

	int maxleftbordersum=0, leftbordersum=0;
	for(int i=center+1; i<left; i++)
		{
			leftbordersum+=a[i];
			if(leftbordersum>maxleftbordersum)
			{
				maxleftbordersum=leftbordersum;
			}
		}



	int maxrightbordersum=0, rightbordersum=0;
	for(int j=center+1; j<right; j++)
		{
			rightbordersum+=a[j];
			if(rightbordersum>maxrightbordersum)
			{
				maxrightbordersum=rightbordersum;
			}
		}
	return max3(maxleftsum,maxrightsum,maxleftbordersum+maxrightbordersum);
}

void maxsubsum3(int a[],int l)

	{
		cout << "MaxSum computed from third algorithm is :" <<maxsumrec(a,0,l) << endl;
	}

int maxsubsum4(int a[],int l) // Fourth Algorithm
	{
		int maxSum=0, thissum=0;
		for(int j=0;j<l;j++)
			{
				thissum +=a[j];
				if(thissum > maxSum)
				{
					maxSum=thissum;
				}
				else if(thissum<0)
				{
					thissum=0;
				}
			}
	cout<<"MaxSum computed from fourth algorithm is :" << maxSum << endl;
	return maxSum;

}

int main()
	{
		clock_t tStart,tStart1,tStart2,tStart3;
		ifstream myfile;
		int a[10000];
		string filename;
		cout<<"Please enter the file name:" <<endl;
		cin>>filename; //The name of the input file

		ifstream ifs;
		ifs.open(filename.c_str(), ios::in | ios::trunc);
		ifs.close();
		myfile.open(filename.c_str());

		if(myfile.bad())
			return(1);
		int i=0;
		while(myfile)
			{
				myfile >>a[i];
				i++;
			}
		i=i-1;
		myfile.close();
		cout<<"The numbers that have been extracted are" << endl;
	for(int j=0;j<i;j++)
		{
			cout<<a[j] << endl;
		}



        tStart = clock(); // Computing the execution time of algorithms
		maxsubsum1(a,i);
		printf("time_insert: %.9fms\n" ,(double)(clock() - tStart) / ( CLOCKS_PER_SEC*1000));

		tStart1 = clock();
		maxsubsum2(a,i);
		printf("time_insert: %.9fms\n" ,(double)(clock() - tStart1) / ( CLOCKS_PER_SEC*1000));

		tStart2=clock();
		maxsubsum3(a,i);
		printf("time_insert: %.9fms\n" ,(double)(clock() - tStart2) / ( CLOCKS_PER_SEC*1000));

		tStart3=clock();
		maxsubsum4(a,i);
		printf("time_insert: %.9fms\n" ,(double)(clock() - tStart3) / ( CLOCKS_PER_SEC*1000));





		return(0);
	}


