#include <iostream>
#include <string>
using namespace std;

int counter = 1;

class XO{
private:
	char table[3][3];
	string name[2];
public:
	XO(){
		int l = 0;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				table[i][j]=char(49+l);
				l++;
			}
		}
	}

	void CoutTable(){
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				cout<<"| "<<table[i][j]<<" |";
			}
			cout<<endl;
		}

	}
	void SetName(){
		cout<<"Введите имя 1 игрока(X):\n";
		cin>>name[0];
		cout<<"Введите имя 2 игрока(O):\n";
		cin>>name[1];
		cout<<"Приятного времяпровождения "<<name[0]<<" и "<<name[1]<<endl;
	}

	bool Input(){
		if(counter %2 != 0){
			cout<<name[0]<<" ваш ход: ";
			counter++;
		}else{
			cout<<name[1]<<" ваш ход: ";
			counter++;
		}
		
		int n;
		cin>>n;
		if(n < 1 || n > 9)
			return false;

		int i,j;

		switch (n){
			case 1:
				i=0;
				j=0;
				break;
			case 2:
				i=0;
				j=1;
				break;
			case 3:
				i=0;
				j=2;
				break;
			case 4:
				i=1;
				j=0;
				break;
			case 5:
				i=1;
				j=1;
				break;
			case 6:
				i=1;
				j=2;
				break;
			case 7:
				i=2;
				j=0;
				break;
			case 8:
				i=2;
				j=1;
				break;
			case 9:
				i=2;
				j=2;
				break;
	}
	if(table[i][j] == 'O'  || table[i][j] == 'X')
		return false;
	if((counter-1) %2 != 0){
		table[i][j]='X';
	}else{
		table[i][j]='O';
	}

		return true;
	}
	bool win(){
		for(int i = 0;i<3;i++){
			if((table[i][0]==table[i][1])&&(table[i][0]==table[i][2]))//по горизонтали
				return true;
			else if((table[0][i] == table[1][i])&&(table[0][i]==table[2][i]))//по вертикали
				return true;
			else if((table[0][0]==table[1][1])&&(table[0][0]==table[2][2]) || (table[0][2]==table[1][1] && table[0][2]==table[2][0]))//по диагоналям
				return true;
		}

		return false;
	}

	bool AllFill(){
		if(((table[0][0] =='X') || (table[0][0] == 'O'))&&((table[0][1] =='X') || (table[0][1] == 'O'))&&((table[0][2] =='X') || (table[0][2] == 'O'))&&((table[1][0] =='X') || (table[1][0] == 'O'))&&((table[1][1] =='X') || (table[1][1] == 'O'))&&((table[1][2] =='X') || (table[1][2] == 'O'))&&((table[2][0] =='X') || (table[2][0] == 'O'))&&((table[2][1] =='X') || (table[2][1] == 'O'))&&((table[2][2] =='X') || (table[2][2] == 'O'))){
			return true;
		}else{
			return false;
		}
		
	}

	string GetName1(){
		return name[0];
	}
	string GetName2(){
		return name[1];
	}
};

int main(){
	system("chcp 1251");
	system("cls");
	XO Igra;
	Igra.SetName();
	while(!Igra.win()){
		
		system("cls");
		Igra.CoutTable();
		
		if(!Igra.Input()){
			cout<<"Вы ввели неверные данные повторите!"<<endl;
			counter--;
			system("pause");
		}
		if(Igra.AllFill()){
			
			break;
		}

	}
	system("cls");
	Igra.CoutTable();

	if(!Igra.win()){
		if(Igra.AllFill()){
			system("cls");
			Igra.CoutTable();
			cout<<"Ничья\n";
		}
	}


	if(Igra.win()){
		if(counter %2 == 0){
			cout<<"Победил "<<Igra.GetName1()<<endl;
		}else{
			cout<<"Победил "<<Igra.GetName2()<<endl;
	
		}
	}
	

	system("pause");
	return 0;
}