// Jogo.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "windows.h"
#include "tchar.h"
#include "conio.h"
using namespace std;

struct stats{
	int frc, des, cor, PV, PVt;
	int inc, atq, def, dano, abs;
	int pts, ptt, nvl, xpa, xpp, grn;
};

struct itens{
	int cur, man, ant;
	int arm, amd, pes, mao, cab;
};

void z(){
	_getch();
	system("cls");
}

void get(char &opc){
	opc=_getch();
	system("cls");
}

char menu_principal(){
	char opc;
	cout<<"\n1. Fazer Ficha"<<endl;
	cout<<"2. Lutar"<<endl;
	cout<<"3. Descansar"<<endl;
	cout<<"4. Status"<<endl;
	cout<<"0. Sair"<<endl;
	get(opc);
		switch(opc){
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
			case '3':
				return 3;
				break;
			case '4':
				return 4;
				break;
			case '0':
				return 0;
				break;
		}
	return -1;
}

char menu_batalha(){
	char opc;
	cout<<"\n1. Atacar"<<endl;
	cout<<"2. Defender"<<endl;
	cout<<"3. Fujir"<<endl;
	get(opc);
		switch(opc){
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
			case '3':
				return 3;
				break;
		}
	return -1;
}

char menu_ficha2(){
	cout<<"Ficha já está pronta! Se deseja refazer a ficha digite 1."<<endl;
	cout<<"Se deseja voltar digite 2."<<endl;
	char opc;
	get(opc);
		switch(opc){
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
		}
	return -1;
}

char menu_ficha(){
	char opc;
	cout<<"\nEscolha uma opção:"<<endl;
	get(opc);
		switch(opc){
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
			case '3':
				return 3;
				break;
		}
	return -1;
}

/*int menu_loja(stats jog){
	char opc;
	int x;
	cout<<"\n1. Itens"<<endl;
	cout<<"2. Equipamentos"<<endl;
	cout<<"0. Voltar"<<endl;
	get(opc);
		switch(opc){
			case '1':
				
				break;
			case '2':
				cout<<"\n1. Arma"<<endl;
				cout<<"2. Armadura"<<endl;
				cout<<"3. Elmo"<<endl;
				cout<<"4. Luvas"<<endl;
				cout<<"5. Botas"<<endl;
				cout<<"0. Voltar"<<endl;
				cout<<"\nEscolha uma opção:"<<endl;
				get(opc);
				switch(opc){
					case '1':
						return 1;
						break;
					case '2':
						return 2;
						break;
					case '3':
						return 3;
						break;
					case '4':
						return 4;
						break;
					case '5':
						return 5;
						break;
					case '0':
						return 0;
					break;
				}
				break;
			case '0':
				return 0;
				break;
		}

	return -1;

}*/

int menu_invent(itens &ivt){
	int x;
	cout<<"1. Orbe Vital...: "<<ivt.cur<<endl;
	cout<<"2. Prisma Etéreo: "<<ivt.man<<endl;
	cout<<"3. Antidoto.....: "<<ivt.ant<<endl;
	cout<<"0. Voltar."<<endl;
	cin>>x;
	return x;
}

void intro(){
	cout<<"Inicializando rotinas..."<<endl;
	cout<<"Funções biológicas: 100%"<<endl;
	cout<<"Funções neurais: 100%"<<endl;
	cout<<"Estado psicológico: Estável"<<endl;
	cout<<"Seja bem vindo, usuário!"<<endl;
	z();
}

void zero_stats(stats &x){
	x.frc=0;
	x.des=0;
	x.cor=0;
	x.pts=10+(x.nvl*2);
	x.ptt=10+(x.nvl*2);
	x.xpp=(x.nvl+1)*100;
	x.grn=0;
	x.PV=(x.cor+1)*5;
	x.PVt=x.PV;
}

void inm_stats(stats &inm){
	do{
		if(inm.pts>0){
			inm.frc++;
			inm.pts--;
		}
		if(inm.pts>0){
			inm.des++;
			inm.pts--;
		}
		if(inm.pts>0){
			inm.cor++;
			inm.pts--;
		}
	}while(inm.pts!=0);
	inm.PV=(inm.cor+1)*5;
}

void exibe_stats (stats x){
	cout<<"\nNível: "<<x.nvl<<endl;
	cout<<"For: "<<x.frc<<endl;
	cout<<"Des: "<<x.des<<endl;
	cout<<"Cor: "<<x.cor<<endl;
	cout<<"PVs: "<<x.PV<<"/"<<x.PVt<<endl;
	cout<<"Exp: "<<x.xpa<<"/"<<x.xpp<<endl;
	cout<<"Grana: "<<x.grn<<endl;
}

void distribuir_pontos (stats &jog){
	int opc;
	cout<<"\nVocê possui "<<jog.pts<<" pontos para distribuir entre suas características:"<<endl;
	cout<<"\n1 - Força: Capacidade de causar dano, levantar peso\ne carregar equipamentos."<<endl;
	cout<<"\n2 - Destreza: Capacidade de acertar golpes, evitar ataques\ne capacidade de usar habilidades manuais."<<endl;
	cout<<"\n3 - Corpo: Capacidade de receber dano e resistir a envenenamentos\ne efeitos diversos."<<endl;

	do{
		opc=menu_ficha();
		switch(opc){
			case 1:
				if(jog.frc>=jog.nvl+10) cout<<"Característica maximizada.\nNão pode possuir mais pontos até que se passe de nível!"<<endl;
				else{
					jog.frc++;
					jog.pts--;
				}
				break;
			case 2:
				if(jog.des>=jog.nvl+10) cout<<"Característica maximizada.\nNão pode possuir mais pontos até que se passe de nível!"<<endl;
				else{
					jog.des++;
					jog.pts--;
				}
				break;
			case 3:
				if(jog.cor>=jog.nvl+10) cout<<"Característica maximizada.\nNão pode possuir mais pontos até que se passe de nível!"<<endl;
				else{
					jog.cor++;
					jog.pts--;
				}
				break;
			default:
				cout<<"Opção inválida!"<<endl;
		}
		cout<<"\nFor: "<<jog.frc<<endl;
		cout<<"Des: "<<jog.des<<endl;
		cout<<"Cor: "<<jog.cor<<endl;
		cout<<"\nPontos Restantes: "<<jog.pts<<endl;
	}while(jog.pts!=0);
	z();
}

void levelup(stats &jog){
	jog.nvl++;
	jog.xpp+=(jog.nvl+1)*100;
	jog.pts+=2;
	distribuir_pontos(jog);
}

int grana(int x){
	int grana=0;
	while(x!=0){
		grana=grana+((rand()%10)+1);
		x--;
	}
	return grana;
}

void jog_ataque(stats jog, stats &inm){
	int dano;
	jog.atq=jog.des+((rand()%10)+1);
	inm.def=inm.des+2;
	if(jog.atq==jog.des+10){
		jog.dano=(jog.frc*2)+((rand()%10)+1);
		inm.abs=inm.cor+((rand()%10)+1);
		dano=jog.dano-inm.abs;
		if(dano<1) dano=1;
		inm.PV-=dano;
		if(inm.PV<1) inm.PV=0;
		cout<<"Acerto crítico! Personagem causou "<<dano<<" de dano!"<<endl;
	}
	else if(jog.atq>=inm.def){
		jog.dano=jog.frc+((rand()%10)+1);
		inm.abs=inm.cor+((rand()%10)+1);
		dano=jog.dano-inm.abs;
		if(dano<1) dano=1;
		inm.PV-=dano;
		if(inm.PV<1) inm.PV=0;
		cout<<"Personagem acertou e causou "<<dano<<" de dano!"<<endl;
	}
	else cout<<"Personagem errou o ataque..."<<endl;
}

void inm_ataque(stats &jog, stats inm){
	int dano;
	inm.atq=inm.des+((rand()%10)+1);
	jog.def=jog.des+2;
	if(inm.atq==inm.des+10){
		inm.dano=(inm.frc*2)+((rand()%10)+1);
		jog.abs=jog.cor+((rand()%10)+1);
		dano=inm.dano-jog.abs;
		if(dano<1) dano=1;
		jog.PV-=dano;
		if(jog.PV<1) jog.PV=0;
		cout<<"Acerto crítico! Inimigo causou "<<dano<<" de dano!"<<endl;
	}
	else if(inm.atq>=jog.def){
		inm.dano=inm.frc+((rand()%10)+1);
		jog.abs=jog.cor+((rand()%10)+1);
		dano=inm.dano-jog.abs;
		if(dano<1) dano=1;
		jog.PV-=dano;
		if(jog.PV<1) jog.PV=0;
		cout<<"Inimigo acertou e causou "<<dano<<" de dano!"<<endl;
		}
	else cout<<"Inimigo errou o ataque..."<<endl;
}

void batalha_teste (stats &jog, stats inm){
	int dano, opc, auxPV, grnMais;
	srand(time(0));
	jog.inc=jog.des+((rand()%10)+1);
	inm.inc=inm.des+((rand()%10)+1);
	if(jog.inc>inm.inc)	cout<<"Personagem ganhou iniciativa!"<<endl;
	else{
		cout<<"Inimigo ganhou iniciativa!"<<endl;
		inm_ataque(jog,inm);
	}
	while(jog.PV>0&&inm.PV>0){
		opc=menu_batalha();
		switch(opc){
			case 1:
				jog_ataque(jog,inm);
				if(inm.PV<1){
					inm.PV=0;
					break;
				}
				inm_ataque(jog,inm);
					break;
			case 2:
				jog.def=jog.des+4;
				inm.atq=inm.des+((rand()%10)+1);
				if(inm.atq==inm.des+10){
					inm.dano=(inm.frc*2)+((rand()%10)+1);
					jog.abs=jog.cor+jog.des+((rand()%10)+1);
					dano=inm.dano-jog.abs;
					if(dano<1) dano=1;
					jog.PV-=dano;
					if(jog.PV<1) jog.PV=0;
					cout<<"Acerto crítico! Inimigo causou "<<dano<<" de dano!"<<endl;
				}
				if(jog.PV<1) break;
				else if(inm.atq>=jog.def){
					inm.dano=inm.frc+((rand()%10)+1);
					jog.abs=jog.cor+jog.des+((rand()%10)+1);
					dano=inm.dano-jog.abs;
					if(dano<1) dano=0;
					jog.PV-=dano;
					if(jog.PV<1) jog.PV=0;
					if (dano>0) cout<<"Inimigo acertou e causou "<<dano<<" de dano!"<<endl;
					else cout<<"Personagem bloqueou o ataque..."<<endl;
				}
				else cout<<"Inimigo errou o ataque..."<<endl;
					break;
			case 3:
				jog.PV-=inm.frc;
				cout<<"Personagem levou "<<inm.frc<<" de dano enquanto fugia..."<<endl;
				cout<<"Personagem fugiu."<<endl;
				auxPV=jog.PV;
				inm.PV=0;
					break;
			default:
				cout<<"\nOpção inválida!"<<endl;
			}
			exibe_stats(jog);
			if(opc==3) jog.PV=0;
	}
	z();
	if(inm.PV<1&&jog.PV<1) jog.PV=auxPV;
	else if(inm.PV<1){
		cout<<"Ganhou a luta!"<<endl;
		cout<<"Recebeu "<<(inm.ptt*3)+(inm.nvl*10)<<" pontos de experiência!"<<endl;
		grnMais=grana(inm.ptt);
		cout<<"...e "<<grnMais<<" de grana!"<<endl;
		jog.xpa+=(inm.ptt*3)+(inm.nvl*10);
		jog.grn+=grnMais;
		if(jog.xpa>=jog.xpp) levelup(jog);
	}
	else cout<<"Perdeu a luta!"<<endl;
	z();
}

/*void invent (stats &jog, itens &ivt){
	int opc;
	opc=menu_invent(ivt);
	do{
		switch(opc){
			case 1:
				jog.PV+=10;
				if (jog.PV>(jog.cor+1)*5)
					jog.PV=(jog.cor+1)*5;
				ivt.cur--;
				break;
			case 2:
				cout<<"Você não possui mana..."<<endl;
				break;
			case 3:
				cout<<"Você não está envenenado..."<<endl;
				break;
			case 0:
				cout<<"Voltando..."<<endl;
				break;
			default:
				cout<<"Opção inválida!"<<endl;
		}
	}while(opc!=0);
}*/

int main(){
	stats jog, inm;
//	itens ivt;
	int opc;
	char aux;
	jog.nvl=0;
	jog.xpa=0;
	zero_stats(jog);
	_tsetlocale(LC_ALL, _T("portuguese_portugal"));
	intro();
	do{
		opc=menu_principal();
		switch(opc){
			case 1: //FAZER FICHA
				if(jog.frc>0||jog.des>0||jog.cor>0){
					do{
					opc=menu_ficha2();
						switch(opc){
								case 1:
									zero_stats(jog);
									distribuir_pontos(jog);
									jog.PV=(jog.cor+1)*5;
									jog.PVt=jog.PV;
									break;
								case 2:
									cout<<"Voltando..."<<endl;
									break;
								default:
									cout<<"Opção inválida!"<<endl;
						}
						z();
					}while(opc!=1&&opc!=2);
				}
				else {
					distribuir_pontos(jog);
					jog.PV=(jog.cor+1)*5;
					jog.PVt=jog.PV;
				}
					break;
			case 2: //LUTAR
				if(jog.frc==0&&jog.des==0&&jog.cor==0) cout<<"Ficha ainda não foi feita!"<<endl;
				else{
					cout<<"Insira nível do inimigo: "<<endl;
					cin>>inm.nvl;
					while(inm.nvl<0){
						cout<<"Nível do inimigo não pode ser menor que zero!"<<endl;
						cout<<"Insira novo nível..."<<endl;
						cin>>inm.nvl;
					}
					zero_stats(inm);
					inm_stats(inm);
					batalha_teste(jog, inm);
				}
					break;
			case 3: //DESCANSAR
				jog.PV=(jog.cor+1)*5;
				jog.PVt=jog.PV;
				cout<<"Pontos de Vida recuperados!"<<endl;
				z();
					break;
			case 4: //STATUS
				exibe_stats(jog);
				z();
					break;
			/*case 5: //LOJA DE ITENS
				z();
					break;*/
			case 0:
				cout<<"Saindo..."<<endl;
					break;
			default:
				cout<<"Opção invalida!"<<endl;
		}
	}while(opc!=0);
    system ("pause");
    return 0;
}
