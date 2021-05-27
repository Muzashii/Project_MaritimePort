#include <iostream>

using namespace std;
#include <locale>
#include <cstring>

#define NUM 100
#define CHAR 30

int main()
{
    setlocale(LC_ALL,"");

    int n,ind=0,opc,i,inf=0;
    int codi_iden[NUM],id_busca;
    char CNPJ[NUM][CHAR],destino[NUM][CHAR],cnpj_busca[CHAR],porto_busca[CHAR],estado[NUM][CHAR];
    float valor_con[NUM];

    do{
            //Menu de escolha
            system("cls");
            cout<<" 0- Encerrar o programa"<<endl;
            cout<<" 1- Cadastra entrada de conteiner no armazém"<<endl;
            cout<<" 2- Consulta informações de conteiner (por ID ou por CNPJ)"<<endl;
            cout<<" 3- Gera uma lista de contêineres selecionados pelo porto destino"<<endl;
            cout<<" 4- Retira os contêineres para serem embarcados em um navio(em função do porto destino)"<<endl;
            cout<<" 5- Gera relatório de todos contêineres que já foram embarcados"<<endl;
            cout<<"Digite oque deseja fazer : ";
            cin>>n;

            //cadastro dos conteineres
            if(n == 1){
            cout<<"Informe código de dentificação do conteiner: ";
            cin>>codi_iden[ind];
            cin.ignore();
            cout<<"CNPJ da empresa proprietária da carga do conteiner: ";
            cin.getline(CNPJ[ind],CHAR);
            cout<<"Destino da carga do counteiner : ";
            cin.getline(destino[ind],CHAR);
            cout<<"Informe valor declarado no seguro do conteiner: ";
            cin>>valor_con[ind];
            strcpy(estado[ind],"Aguardando");
            ind ++;
        }

        //busca de conteineres por ID ou CNPJ
        if (n==2){
            if (ind!=0){
                do{
                    cout<<"Escolha como deseja procurar informações do conteiner: "<<endl;
                    cout<<"0-  Voltar"<<endl;
                    cout<<"1- ID"<<endl;
                    cout<<"2- CNPJ"<<endl;
                    cout<<"Opção :  ";
                    cin>>opc;
                    if(opc == 1){
                        cout<<"Digite o código de identificação do conteiner : ";
                        cin>>id_busca;
                        for (i=0;i<ind;i++){
                            if (id_busca == codi_iden[i]){
                                cout<<"************************** Informações sobre o Conteiner ***********************************"<<endl;
                                cout<<"     ID : "<<codi_iden[i]<<"             CNPJ : "<<CNPJ[i]<<"            Destino : "<<destino[i] <<"             Valor : "<<valor_con[i]<<"      Estado: "<<estado[i]<<endl;
                                cout<<"*************************************************************************************************"<<endl;
                                system("pause");
                            }
                        }

                    }
                    else if(opc == 2){
                    cin.ignore();
                    cout<<"Digite o CNPJ do proprietário do conteiner : ";
                    cin.getline(cnpj_busca,CHAR);
                    for (i=0;i<ind;i++){
                            if (strcmp(cnpj_busca,CNPJ[i])==0){
                                cout<<"************************** Informações sobre o Conteiner ***********************************"<<endl;
                                cout<<"     ID : "<<codi_iden[i]<<"             CNPJ : "<<CNPJ[i]<<"            Destino : "<<destino[i] <<"             Valor : R$"<<valor_con[i]<<"      Estado : "<<estado[i]<<endl;
                                cout<<"*************************************************************************************************"<<endl;
                                system("pause");
                            }
                        }
                    }
                    else if(opc != 0){
                        cout<<"Erro : numero invalido"<<endl;
                        system("pause");
                    }
                }while(opc != 0);
            }
            else{
                cout<<"Erro : nenhum counteiner registrado"<<endl;
                cout<<"Cadastre um conteiner antes de consultar as informaçoes"<<endl;
                system("pause");
            }
        }

        //Busca de conteineres pelo porto destino
        if(n==3){
            if(ind != 0){
                cin.ignore();
                cout<<"Informe o porto destino do conteiner: ";
                cin.getline(porto_busca,CHAR);
                cout<<"*************************************************************************************************"<<endl;
                cout<<"                                      Informações sobre o Conteiner para "<<porto_busca<<"                                                  "<<endl;
                for(i=0;i<ind;i++){
                    if(strcmp(porto_busca,destino[i])==0){
                        cout<<"     ID : "<<codi_iden[i]<<"             CNPJ : "<<CNPJ[i]<<"            Valor : R$"<<valor_con[i] <<"       Estado: "<<estado[i]<<endl;
                        inf++;
                    }
                }
                if(inf ==0){
                    cout<<"Erro: nenhum conteiner encontrado para "<<porto_busca;
                }
                cout<<"*************************************************************************************************"<<endl;
                system("pause");
            }
            else{
                cout<<"Erro : nenhum counteiner registrado"<<endl;
                cout<<"Cadastre um conteiner antes de consultar as informaçoes"<<endl;
                system("pause");
            }

        }
        //Embarcar os conteineres
        if(n==4){
            if(ind != 0){
                inf = 0;
                cin.ignore();
                cout<<"Informe porto destino de conteineres a serem embarcados: ";
                cin.getline(porto_busca,CHAR);
                 for(i=0;i<ind;i++){
                    if(strcmp(porto_busca,destino[i])==0){
                        strcpy(estado[i],"Embarcado");
                        inf++;
                    }
                }
                if(inf ==0){
                    cout<<"Erro: nenhum conteiner encontrado para "<<porto_busca<<endl;
                    system("pause");
                }

            }
            else{
                cout<<"Erro : nenhum counteiner registrado"<<endl;
                cout<<"Cadastre um conteiner antes de consultar as informaçoes"<<endl;
                system("pause");
            }

        }

        //Lista dos conteineres Embarcados
        if(n==5){
            if(ind != 0){
                inf = 0;
                cout<<"************************** Lista de conteineres ja Embarcados ***********************************"<<endl;
                 for(i=0;i<ind;i++){
                    if(strcmp(estado[i],"Embarcado")==0){
                        cout<<"     ID : "<<codi_iden[i]<<"             CNPJ : "<<CNPJ[i]<<"            Valor : R$"<<valor_con[i] <<"       Destino: "<<destino[i]<<endl;
                        inf++;
                    }
                }
                system("pause");
                if(inf ==0){
                    cout<<"Erro: nenhum conteiner no estado EMBARCADO" <<endl;
                    system("pause");
                }

            }
            else{
                cout<<"Erro : nenhum counteiner registrado"<<endl;
                cout<<"Cadastre um conteiner antes de consultar as informaçoes"<<endl;
                system("pause");
            }

        }


            if (n>5||n<0){
                 cout<<"Error: numero invalido "<<endl;
                 system("pause");
            }
    }while(n!=0);

}
