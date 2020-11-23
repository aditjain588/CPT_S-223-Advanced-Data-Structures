#include<iostream>
#include<queue>
#include<iterator>
#include<string>
#include<stdio.h>

using namespace std;

int ticks=1;
class Process;
class jobs{
	friend class Process;
	friend class comparator;
	private:
		string j_des;
		int nticks;
		int nproc;
	public :
		jobs(string a, int b, int c){
			j_des=a;
			nticks=b;
			nproc=c;
		}
};

class comparator{ //comparasion class for queue.
	public:
		int operator()(const jobs &q, const jobs &w){
			if(q.nticks==w.nticks){
				return q.nproc>w.nproc;
			}
			return q.nticks>w.nticks;
		}
};
class Process{
	private:
		priority_queue<jobs,vector<jobs>,comparator> que;
		int n;
		int p;
	public:
		Process(int proc){
			n=1;
			p=proc;
		}
		void InsertJob(string a,int b, int c);
		void View(int flag);
};
void Process::InsertJob(string a,int b, int c){
	cout<<"Ticks number: "<<ticks++<<endl;
	que.push(jobs(a,b,c)); // to push a job in the priority queue
	n++;
	cout<<"Insertion successful"<<endl;
}
void Process::View(int flag){
	if(que.empty()){ 	// if there's no job is stacked
		return;
	}

	else if(flag==1){ // if all the jobs needs to be executed at once
		while(!que.empty()){
			cout<<"Ticks number: "<<ticks++<<endl;
			jobs temp=que.top();
			cout<<"Job Description :" << temp.j_des<<endl;
			cout<<"Number of ticks :"<< temp.nticks<<endl;
			cout<<"Number of Processors :"<< temp.nproc<<endl;
			for(int i=0;i<temp.nticks; i++){
				cout<<"Ticks number: "<<ticks++<<endl;
			}
			que.pop();
		}
	}
	//if one of the job needs to be executed
	else{
		cout<<"Ticks number: "<<ticks++<<endl;
		jobs temp=que.top();
		cout<<"Job Description :" << temp.j_des<<endl;
		cout<<"Number of ticks :"<< temp.nticks<<endl;
		cout<<"Number of Processors :"<< temp.nproc<<endl;
		for(int i=0;i<temp.nticks; i++){
			cout<<"Ticks number: "<<ticks++<<endl;
		}
		que.pop();
	}
}
int main(){

	string a;int b; int c; int processors;

	cout<<"Ticks number: "<<ticks++<<endl;
	cout<<"Enter number of processor"<<endl;
	cin>>processors;
	cout<<"Ticks number: "<<ticks++<<endl;
	Process p(processors);

		cout<<"Ticks number: "<<ticks++<<endl;

                cout<<"Enter a new job"<<endl;
                cout<<"Ticks number: "<<ticks++<<endl;
				cout<<"Enter Job Description"<<endl;
				cin>>a;
				cout<<"Enter Number of ticks required"<<endl;
				cin>>b;
				cout<<"Enter number of processors required"<<endl;
				cin>>c;
				cout<<"Ticks number: "<<ticks++<<endl;
				if(c>processors){
				int check=0;
				cout<<"Ticks number: "<<ticks++<<endl;
				while(check==0){
					cout<<"Ticks number: "<<ticks++<<endl;
					cout<<"Invalid number of processors, it shouldn't be more than "<<processors<<endl;
					cout<<"Enter number of processors required"<<endl;
					cin>>c;
					cout<<"Ticks number: "<<ticks++<<endl;
					if(c<processors){
						check=1;
						}
					}
				}
				cout<<"Ticks number: "<<ticks++<<endl;
				p.InsertJob(a,b,c);

			cout<<"Executing the job ";
				p.View(0);

	cout<<"Ticks number: "<<ticks++<<endl;
	cout<<"Job Done"<<endl;
	return 0;
}
