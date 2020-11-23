#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>
#include<vector>
#include<stdio.h>
#include<fstream>

using namespace std;

class Board;
class Player{
    friend class Board;
    private:
        int id;
        int x;
	int y;

    public:
        Player(int i, int X, int Y){
            id=i;
	    x=X; y=Y;
        }
    };
class Board{
    private:
        vector<Player> TheGame;
	int n;
	int m;
	fstream fil;
    public:
	Board(int players,int blocks){
		n=players;
		m=blocks;
	fil.open("testfile.txt");

	}
        void Insert(int i, int x, int y);
        void Remove(Player *t);
        void Move();
        void PrintAll();

    };
void Board::Insert(int id, int x, int y){
	int flag=0;

	if(fil.is_open()){
	 if(TheGame.size()==0){ //if no player is in the game
                Player *temp;
		temp=new Player(id,x,y);
                TheGame.push_back(*temp);

            }
	else{
		for (Player it : TheGame) {

                    int X,Y;
                    Player *o;
                    o=&it;

                    X=o->x;
                    Y=o->y;
                	if(o->id==id || X==x && Y==y){
                    flag=1;
                        	if(o->id==id){  //checking that the ID is not occupied
                           		 cout<<"Invalid Id"<<" Choose another Id"<<endl;
					fil<<"Invalid Id"<<" Choose another Id"<<endl;
					n--;
                        	}
                        	else{
                            		cout<<"Invalid Co-ordinates to start choose different coordinates"<<endl;
					fil<<"Invalid Co-ordinates to start choose different coordinates"<<endl;
					n--;
                        	}
                	}
            	}
		if(flag==0){
		Player *temp;
		temp=new Player(id,x,y);
                TheGame.push_back(*temp);
		}
	}
	}

}
void Board::Remove(Player *t){
        int x=t->x;
        int y=t->y;
        int i=t->id;
	int count=0;

	if(fil.is_open()){
       	for (Player it : TheGame) {
                    int X,Y;
		    Player *o;
		    o=&it;
                    X=o->x;
                    Y=o->y;
                    if(X==x && Y==y && o->id!=i){
                        int c=o->id;
                        TheGame.erase(TheGame.begin()+count);
                        cout<<"Player "<<c<<" eliminated"<<endl;
			fil<<"Player "<<c<<" eliminated"<<endl;
			n--;
                    }
		count++;
        }
	}

}
void Board::Move(){

	if(fil.is_open()){
		while(n>0){
			if(n==1){
				vector<Player>::iterator itr;
				itr=TheGame.begin();
				cout<<"Winnner is "<<itr->id<<endl;
				fil<<"Winnner is "<<itr->id<<endl;
				fil.close();
				n=0;
			}

			else{
				vector<Player>::iterator itr;
				itr=TheGame.begin();
				int count=0;
				 	Player *o;

                    			int X,Y,loopx,loopy,M;
                    			X=itr->x;
                    			Y=itr->y;
					M=m;
					int nextx=X; int nexty=Y;
					cout<<"if you want to move vertically, you can move in the forward till ("<<X<<","<<m<<")"<<endl;
					multimap<int,int> possiblepos;
					int temp2=1;
					for(int temp1=1;temp1!=m+1;temp1++){
						possiblepos.insert(pair <int, int>(X,temp1));
					}

					cout<<"if you want to move vertically, you can move in the backward till ("<<X<<","<<1<<")"<<endl;
					cout<<"if you want to move horizontal, you can move in the left till ("<<1<<","<<Y<<")"<<endl;
					for(int temp1=1;temp1!=m+1;temp1++){
						if(temp1==X){
							continue;
						}
						possiblepos.insert(pair <int, int>(temp1,Y));

					}

					cout<<"if you want to move horizontal, you can move in the right till ("<<m<<","<<Y<<")"<<endl;
					loopx=X;
					loopy=Y;
					for(int i=X-1; i>0;i--){
						loopy--;
						if(loopy==0 || i==0){
							if(i==0){i++;}
							else{loopy++;}
							break;
						}
						possiblepos.insert(pair <int, int>(i,loopy));
						nextx=i;  nexty=loopy;
					}

					cout<<"if you want to move diagonally, you can move in up-left way ("<<nextx<<","<<nexty<<")"<<endl;
					loopx=X;
					loopy=Y;
					for(int i=X+1; i<m+1;i++){
						loopy--;
						if(loopy==0 || i==m+1){
							if(i==m+1){i--;}
							else{loopy++;}
							break;
						}
						possiblepos.insert(pair <int, int>(i,loopy));
						nextx=i;  nexty=loopy;
					}

					cout<<"if you want to move diagonally, you can move in down-left way ("<<nextx<<","<<nexty<<")"<<endl;
					loopx=X;
					loopy=Y;
					for(int i=X-1; i>0;i--){
						loopy++;
						if( loopy>m || i==0){
							if(i==0){i++;}
							else{loopy--;}
							break;
						}
						possiblepos.insert(pair <int, int>(i,loopy));
						nextx=i;  nexty=loopy;
					}
					cout<<"if you want to move diagonally, you can move in up-right way ("<<nextx<<","<<nexty<<")"<<endl;
					loopx=X;
					loopy=Y;
					for(int i=X+1; i<m+1;i++){
						loopy++;
						if(loopy==m+1 || i==m+1){
							if(i==m+1){i++;}
							else{loopy--;}
							break;
							}
						possiblepos.insert(pair <int, int>(i,loopy));
						nextx=i;  nexty=loopy;
					}
					cout<<"if you want to move diagonally, you can move in down-right way ("<<nextx<<","<<nexty<<")"<<endl;
					int j=1;
					while(j){
						cout<<"Enter Co-ordinates you want to move to "<<itr->id<<endl;
						cout<<"Enter value of X-axis "<<endl;
						cin>>nextx;
						if(nextx<1 || nextx>m){
							cout<<"Invalid value re-enter the  X-axis value less than "<<m<<" and greater than 1"<<endl;
							cin>>nextx;
						}
						cout<<"Enter value of Y-axis "<<endl;
						cin>>nexty;
						if(nexty<1 || nexty>m){
							cout<<"Invalid value re-enter the  Y-axis value less than "<<m<<" and greater than 1"<<endl;
							cin>>nexty;
						}
						int flag=0;
						for (auto iter : possiblepos) {
								if(iter.first==nextx && iter.second==nexty){
								Player *temp;
								temp=new Player(itr->id,nextx,nexty);
                						TheGame.push_back(*temp);
								TheGame.erase(TheGame.begin()+count);
								Remove(temp);
								PrintAll();
								j=0;
								flag=1;
								break;
							}

						}
						if(flag==0){
							cout<<"Invalid move"<<endl;
							fil<<"Invalid move"<<endl;
						}
					}
				}
			}
		}

}
 void Board::PrintAll(){

	if(fil.is_open()){
	 for (Player it : TheGame) {
		Player *o;
		o=&it;
		cout<<"ID "<<o->id<<" Position ("<<o->x<<","<<o->y<<")"<<endl;
		fil<<"ID "<<o->id<<" Position ("<<o->x<<","<<o->y<<")"<<endl;
	}
	}

}
int main(){
int p,x,y,s,n=0,check=1;

while(check==1){
cout<<"How many Players do you want in the game?"<<endl;
cin>>p;

cout<<"Enter size of square checkered board"<<endl;
cin>>s;

if(p>s){
	cout<<"Number of players can't be more than the size of Checkered board"<<endl;

}
else{
	cout<<"Welcome players!"<<endl;
	check=0;
}
}
Board B(p,s);

	B.Insert(1,3,2);	//syntax: Insert(ID, x, y)
	B.PrintAll();
	B.Insert(2,4,3);
	B.PrintAll();
	B.Insert(3,4,6);
	B.PrintAll();
	B.Insert(4,5,7);
	B.PrintAll();
	B.Insert(5,6,3);
	B.PrintAll();
	B.Insert(6,8,2);
	B.PrintAll();
	B.Insert(7,9,3);
	B.PrintAll();
	B.Insert(8,9,8);
	B.PrintAll();
	B.Insert(3,7,6);	// should fail because player 3 is already there
	B.PrintAll();
	B.Insert(10,9,8);
	B.PrintAll();
	B.Move();

return 0;
}
