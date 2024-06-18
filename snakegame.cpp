#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std; 

const int length= 25;
const int breadth = 25;
 
int tails;
int x , y , coinx, coiny;
int tailx[100],taily[100];

int delay= 40;
bool gameover; 


void setup();
void sketch();
void input();
 void logic();
 int score= 0;
 
 enum direct {STOP=0, UP, DOWN, LEFT ,RIGHT};
	direct dir; 
	
void setup(){
	gameover= false;
	x= length/2;
	y = breadth/2;
	coinx=rand() % (length); 
	coiny=rand() % (breadth); 
	dir=STOP;
	
	
}

void sketch(){
	system("CLS");
 
	for(int j =0; j <breadth; j++)	{
		cout<<"#";
		
}cout<<endl;

for(int i= 0; i <length ; i ++){
for(int j =0 ; j <breadth ; j++){
	
if(j==0 || j== breadth -1){
	cout<<"#"; 
}


else if (i==x && j ==y){
	cout<<">";
}

else if(i== coinx && j==coiny){
	cout<<"o";
}
else{
	
	bool print= false; 
	for(int k= 0 ; k <tails ; k++){
		if(i==tailx[k] && j ==taily[k]){
			cout<<">";
			print= true; 
		}
	}
	if(!print)(cout<<" ");
}
}
cout<<endl;	
}

for(int j =0; j <breadth; j++)	{
		cout<<"#";
		
}cout<<endl;

 cout<<"SCORE:"<<score;

};

void  input(){
	
	 
	 	if(_kbhit()){
	 		switch(_getch()){
	 			case 'w':
	 				dir=UP;
	 				break;
	 				
	 				case 'a':
	 				dir=LEFT;
	 				break;
	 				
	 				case 'd':
	 				dir=RIGHT;
	 				break;
	 				
	 				case 's':
	 				dir=DOWN;
	 				break;
	 			
	 			default:
	 				dir=LEFT;
	 				break;
			 };
	 		
		 }
		 	 }
	 
	
void logic(){
		
		
	int	prevx=tailx[0];
	int	prevy=taily[0];
		
		tailx[0]= x;
		taily[0]=y;
		 
		 int prev2x; 
		 int prev2y ;
		 
		 for(int i = 1 ; i <tails ; i++){
		 	prev2x= tailx[i]; 
		 	prev2y= taily[i];
		 	
		 	tailx[i] = prevx; 
		 	taily[i] = prevy ;
		 	
		 	prevx= prev2x;
		 	prevy = prev2y ;
		 	
		 	
		 }
		 
		switch(dir){
	
				
			case UP:
			    x--;
				break;
				
		case DOWN:
			    x++;
				break;
				
			case LEFT:
			    y--;
				break;
				
		case RIGHT:
			   y++ ;
				break;
										
		
		
		default :
		break;		
		}
		
		
 if(x<0 || x>length || y>breadth || y<0  )
	 {
	 	gameover=true;
		 system("CLS");
		  cout<<"GAMEOVER"<<endl;
		  cout<<"your total score is:"<<score<<endl;
	 }
	 
 if(x==coinx && y == coiny)	{
 	
 	 score ++ ;
 	coinx=rand() % (length-1); 
	coiny=rand() % (breadth-1); 
	tails++;
 if(delay>10)
 delay-=5 ;
}	

for(int i =0; i <tails; i++){
	if(x==tailx[i] && y == taily[i]){
	
	 gameover=true; 
	 
	 system("CLS");
	 cout<<"GAMEOVER"<<endl;
	 cout<<"your score is : "<<score<<endl;
	 
  }
}
 

 
 }
	

int main(){
	
	setup();
	while(!gameover){
      sketch();
	 
	 input();
	 logic();
	 Sleep(delay);
	
}
	
	return 0 ;
}
