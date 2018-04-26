#include<iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include "controls.h"
#include <thread>
#include <string>
using namespace std;



string map_string;
int map_width=0,map_length=1;
void error(){
	exit(1);
}

class transform{
	public:
		int x,y;
		transform():x{x},y{y}{}
		transform(int x,int y){
			this->x = x;
			this->y = y;
		}
};
class model{
	public:
		map<transform*,char> textures;
};
class thing{
	public:
		transform transf;
		model mod;
};

class live : public thing{
	private:
		int age;
		float mhp=10,hp=10,mstamina=10,stamina=10,mnen=10,nen=10;
	public:
		float getNen(){
			return nen;
		}
		void setNen(float nen){
			this->nen = nen;
		}
};
class animal: public live{

};

class human: public animal{

};
human player;
void input(){
char button;
	
	system("/bin/stty raw");
	while((button=getchar())!='p'){
		//putchar(button);
		
		switch(button){
			case controls::up:
				player.transf.y +=1;cout <<"up";

				break;
			case controls::down:
				player.transf.y -=1;
				break;
			case controls::right:
				player.transf.x +=1;cout <<"right";
				break;
			case controls::left:
				player.transf.x -=1;
				break;
		}
	}
	system("/bin/stty cooked");

}
void start(){
	ifstream x;
	map_string="";
	char tempc;
	int temp_mapw=0;
	x.open("map.txt");
	if(x.is_open()){
		while(x.good()){
			tempc = (char)x.get();
		 	map_string += tempc;
			if(tempc == '\n'){
				map_length++;
				if(map_width<temp_mapw){
					map_width = temp_mapw;
				}
				temp_mapw=0;	
			}else{
				temp_mapw++;
			}
		}
		x.close();		
	}else{
		
		error();
	}
	cout << endl<< map_width <<endl<<map_length<<endl;
	cout << map_string;
	model& m = player.mod;
	transform& t=player.transf;
	t.x = 20;
	t.y = 10;
	transform* tempt= new transform(0,0);
	char c{'Y'};
	m.textures.insert(pair<transform*,int>(tempt,c));
	
}
void render(){
	// map_length-player.transf.y
	cout << "\033["<< player.transf.y<<"A";
	cout << "\033["<< player.transf.x<<"C";
	//player.transf.x
}
void loop(){
	while(1){
		render();					
	}
}

int main(){
	start();
	thread in(input);
	loop();	
	in.detach();
}
