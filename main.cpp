#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]){
	//Verificação se o usuário está utilizando Linux ou Windows
	if(argc!=2){
		cout<<"Uso: $./a.out 0 p/ Linux e 1 p/ Windows"<<endl;
		return 0;
	}

	string clear[2];
	clear[0] = {"clear"};
	clear[1] = {"cls"};

	string mkdir[2];
	mkdir[0] = "mkdir";
	mkdir[1] = "md";

	string touch[2];
	touch[0] = "touch tutorial.cpp";
	touch[1] = "type nul > tutorial.cpp";

	string touch1[2];
	touch1[0] = "touch TesteDeBranch.cpp";
	touch1[1] = "type nul > TesteDeBranch.cpp";


	int c = 0;
	if(*argv[1] == '1') c = 1;

	string s;

	//Verifica se git está instalado
	cout<<clear[c]<<endl;
	system(clear[c].c_str());

	cout << "Se você chegou ate, voce já sabe usar git clone, porem git pode ser\nusado tanto remotamente(em um servidor) quanto localmente" << endl;
	cout << "Vamos aprender a usar o git localmente agora\nVou criar um novo diretorio chamado \"tutgit\" para comecar" << endl;

	//Criando novo diretório "tutgit"
	string dir = mkdir[c] + " tutgit";
	system(dir.c_str());

	string append = "cd tutgit/ && ";
	cout<<"Para começar um novo diretorio git, digite <<git init>>"<<endl;

	//Lê comando digitado pelo usuário e verifica se é igual ao esperado
	do{
		cout<<">> ";
		getline(cin, s);
	} while(s!="git init");
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//Cria novo arquivo "tutorial.cpp"
	cout<<"Vou criar um novo arquivo \"tutorial.cpp\" para comecarmos a mexer com git"<<endl;
	touch[c]= append+touch[c];
	system(touch[c].c_str());

	//git add
	cout<<"Adicione a mudanca na lista de mudancas do git usando <<git add \"nome do arquivo\", no caso tutorial.cpp"<<endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git add tutorial.cpp");

	s = append+s;
	system(s.c_str());
	system(clear[c].c_str());
	cout << "Voce tambem pode usar <<git add .>> para adicionar todas as mudancas em todos os arquivos do diretorio atual" << endl;
	cout << "Antes de enviar uma mudanca, voce precisa de um usuario e um e-mail para te diferenciar de outras pessoas que podem usar o mesmo diretorio git\nVamos definir o usuario: use <<git config --global user.name \"Seu nome\">>" << endl;

	//Configuração do user.name
	do{
		cout<<">> ";
		getline(cin,s);
	}while(s.find("git config --global user.name")== string::npos);
    s = append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//Configuração do user.email
	cout<<"Agora o e-mail. Use <<git config --global user.email \"seuemail@email.com\""<<endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s.find("git config --global user.email") == string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//git status
	cout << "Para olhar qual o status dos arquivos e diretórios no git\nUtilize o comendo <<git status>>" << endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git status");
	s=append+s;
	system(s.c_str());
	cout << "Note que avisa que não foi feito commit no arquivo \"tutorial.cpp\"" << endl;

	//git commit
	cout<<"Voce agora pode usar <<git commit>> para confirmar as mudancas no codigo. Use <<git commit -m \"sua mensagem\">>\npara fazer anotacoes sobre suas mudancas no codigo (voce e obrigado a comentar)"<<endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while (s.find("git commit -m")==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//FIM DA PRIMEIRA PARTE: user.name, user.email, status, init, add, commit
	cout<<"Voce concluiu a primeira parte"<<endl;

	//git branch
	cout << "Para a segunda parte: " << endl;
	cout << "Pense em \"branch\" como uma linha do tempo, que contem todo o histórico de commits" << endl;
	cout << "Até o presente momento você trabalhou apenas na branch master, a principal" << endl;
	cout << "Para criar uma nova branch, digite o comando <<git branch \"nome da branch\">>" << endl;

	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git branch"==string::npos);
	string branch_name;
	for(int i = 11; i < s.size(); i++){
		branch_name=branch_name+s[i];
	}
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout << "A branch " << branch_name << " foi criada.\nNeste momento há duas branchs, a criada e \"master\", que é a original" << endl;
	cout <<"A nova inicia exatamente do mesmo ponto que a master, ambas podem ser alteradas sem que ocorra interferencia" << endl;

	//git checkout
	cout << "\nPara mover entre diferentes branchs utiliza-se o comando <<git checkout \"nome da branch\">>" << endl;
	cout << "Vá para a branch \"" << branch_name << "\", digitando <<git checkout " << branch_name << ">>" << endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git checkout"==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//Criando arquivo "TesteDeBranch.cpp" na branch criada pelo usuário
	touch1[c]= append+touch1[c];
	system(touch1[c].c_str());

	cout << "Foi criado na nova branch um arquivo chamado \"TesteDeBranch.cpp\". Primeiro adicione e depois commit-o." << endl;
	cout << "Adicione: \n";
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git add TesteDeBranch.cpp" and s!="git add .");
	s = append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout << "Commit: \n";
	do{
		cout<<">> ";
		getline(cin,s);
	} while (s.find("git commit -m")==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout << "Vá para a branch \"master\", digitando <<git checkout master>>"<< endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git checkout"==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	cout << "Note que após mudar para a branch principal e fazer git status, o arquivo \"TesteDeBranch.cpp\" não está presente" << endl;
	s = append+"git status";
	system(s.c_str());
	system(clear[c].c_str());

	//git merge
	cout << "Após fazer todas as alterações necessárias na branch criada, você pode juntar ela com qualquer outra branch utilizando" << endl;
	cout << "utilizando o comando <<git merge \"branch que voce quer unir\">>" << endl;
	cout << "Neste caso digite <<git merge " << branch_name << ">>" << endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git merge"==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());

	//git branch -d
	cout << "Para apagar uma branch, utiliza-se o comando <<git branch -d \"nome da branch\">>" << endl;
	cout << "Neste caso digite <<git branch -d " << branch_name << ">>" << endl;
	do{
		cout<<">> ";
		getline(cin,s);
	} while(s!="git branch -d"==string::npos);
	s=append+s;
	system(s.c_str());
	system(clear[c].c_str());


	return 0;
}
