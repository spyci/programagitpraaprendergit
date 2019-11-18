#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
	if(argc!=2){ cout<<"Uso: $./a.out 0 p/ Linux e 1 p/ Windows"<<endl; return 0;}
	string clear[2];
	clear[0] = {"clear"};
	clear[1] = {"cls"};
	string mkdir[2];
	mkdir[0] = "mkdir";
	mkdir[1] = "md";
	string touch[2];
	touch[0] = "touch tutorial.cpp";
	touch[1] = "type nul > tutorial.cpp";
	int c=0;	
	if(*argv[1]=='1') c=1;
	string s;	
	//Verifica se git está instalado
	cout<<clear[c]<<endl;
	system(clear[c].c_str());
        cout<<"Bem vind@ ao tutorial de git por Gustavo e Thiago V."<<endl
	<<"Se você chegou ate, voce já sabe usar git clone, porem git pode ser\n usado tanto remotamente(em um servidor) quanto localmente"<<endl
	<<"Vamos aprender a usar o git localmente agora\nVou criar um novo diretorio para comecar"<<endl;
	string dir = mkdir[c] + " tutgit";
	system(dir.c_str());
	string append = "cd tutgit/ && ";
	cout<<"Para começar um novo diretorio git, digite <<git init>>"<<endl;
	
	do{
		cout<<">> ";
		getline(cin, s);
	} while(s!="git init");
	s=append+s;
	system(s.c_str());
	
	system(clear[c].c_str());
	cout<<"Eu vou criar um novo arquivo \"tutorial.cpp\" para comecar-mos a mecher com git"<<endl;
	touch[c]= append+touch[c];
	system(touch[c].c_str());
	
	cout<<"Adicione a mudanca na lista de mudancas do git usando <<git add \"nome do arquivo\" no caso tutorial.cpp"<<endl;
	
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git add tutorial.cpp");
	
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());
	cout<<"Voce tambem pode usar git add . para adicionar todas as mudancas em todos os arquivos do diretorio atual"<<endl;
	cout<<"Antes de enviar uma mudanca, voce precisa de um usuario e um e-mail para te diferenciar de outras pessoas que podem usar o mesmo diretorio git\n"<<"Vamos definir o usuario: use <<git config --global user.name \"Seu nome\">>"<<endl;
	
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s.find("git config --global user.name")== string::npos);
       	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout<<"Agora o e-mail. Use <<git config --global user.email \"seuemail@email.com\""<<endl;
	
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s.find("git config --global user.email") == string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout<<"Voce agora pode usar <<git commit>> para confirmar as mudancas no codigo. Use <<git commit -m \"sua mensagem\">>\npara fazer anotacoes sobre suas mudancas no codigo (voce e obrigado a comentar)"<<endl;

	do{
		cout<<">> ";
		getline(cin,s);
	} while (s.find("git commit -m")==string::npos);	
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout<<"voce concluiu a primeira parte"<<endl;
		
                                                                                                                 
	
}
