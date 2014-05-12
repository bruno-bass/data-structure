#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct pilha{
   int info;
   struct pilha *prox;
};

void intro(){
   printf("================================================================================");
   printf(" :::::::::::::::::::::::::: Seja bem-vindo ao DEV C++ ::::::::::::::::::::::::: ");
   printf("================================================================================\n");
}

void inserir_push(struct pilha **topo, int insira){
   struct pilha *p;
   if((p = malloc (sizeof(struct pilha)))== NULL){
      printf(" \n Erro de alocação !");
   }
   else{
      p->info = insira;
      p->prox = *topo;
      *topo = p;
   }          
}

void imprimir(struct pilha *topo){
   struct pilha *p;
   if(topo == NULL){
      printf(" Vazia !");
   }
   else{
      p = topo;
      while(p != NULL){
         printf(" %i ",p->info);
         p = p->prox;
      }
   }                 
}     

int remover_pop(struct pilha **topo){
   struct pilha *p;
   int removido;
   p = *topo;
   if(p == NULL){
      removido = 0; 
   }
   else{
      if(p->prox == NULL){
         removido = p->info;
         *topo = NULL;
         free(p);
      }           
      else{
         if(p->prox != NULL){  
            removido = p->info;  
            *topo = p->prox;  
            free(p);
         }   
      }   
   }     
   return removido;
}

int buscar(struct pilha *topo){
   struct pilha *p;
   int buscado;
   printf("\n Busque o : ");
   fflush(stdin);
   scanf("%i",&buscado);
   p = topo;
   while(p != NULL){
      if(p->info == buscado){
         return 1;                         
      }
      else{
         p = p->prox;
      }        
   }                        
   return 0;
}

int contar(struct pilha *topo){
   struct pilha *p;
   int cont = 0;
   if(topo == NULL){
      cont = 0;
   }
   else{
      p = topo;
      if(p->prox == NULL){
         cont = 1;
      }
      else{
         while(p != NULL){
            cont = cont + 1;
            p = p->prox;
         }
      }              
   }     
   return cont;
}

int mostre_top(struct pilha *topo){
   int top;
   if(topo == NULL){
      top = 0;
   }
   else{
      top = topo->info;
   }
   return top;
}

int clear(struct pilha **topo){
   struct pilha *p;
   p = *topo;
   if(p == NULL){
      return 0;
   }
   else{
      if(p->prox == NULL){
         *topo = NULL;
         free(p);
         return 1;
      }           
      else{
         while(p->prox != NULL){
            p = *topo;
            *topo = p->prox;
            free(p);
         }
       return 1;  
      }                            
   }
}

int menu(){
   int option;
   printf("--------------------------------------------------------------------------------"); 
   printf("                                       MENU");
   printf("\n--------------------------------------------------------------------------------"); 
   printf("\n  1 - Inserir elemento\n");
   printf("\n  2 - Imprimir pilha\n");
   printf("\n  3 - Remover elemento\n");
   printf("\n  4 - Buscar elemento\n");
   printf("\n  5 - Contar elementos da pilha\n");
   printf("\n  6 - Elemento do topo da pilha\n");
   printf("\n  7 - Esvaziar pilha\n");
   printf("\n  0 - Sair\n");
   printf("\n--------------------------------------------------------------------------------");
   printf(" Escolha uma opção válida : ");
   fflush(stdin);
   scanf("%i",&option); 
   printf("--------------------------------------------------------------------------------\n");
   return option;
}

int main(){
   setlocale(LC_ALL, "Portuguese");
   struct pilha *topo;
   int opc, insira, remocao, total, search, top, esvaziar;
   char continua = 's';
   topo = NULL;
   do{
      system("cls");  
      intro();
      opc = menu();
      switch(opc){
         case 0:
            system("cls");
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                SAIR DO PROGRAMA                                ");
            printf("--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'S';break;
         case 1:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                    INSERINDO                                   ");  
            printf("--------------------------------------------------------------------------------\n");
            printf(" Inserir o : ");
            fflush(stdin);
            scanf("%i",&insira);
            inserir_push(&topo, insira);
            continua = 'N';break;
         case 2:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                    IMPRIMIR                                    ");  
            printf("-------------------------------------------------------------------------------- >>>>>>>>>> Pilha ->");  
            imprimir(topo);
            printf("\n--------------------------------------------------------------------------------\n");  
            system("PAUSE");
            continua = 'N';break;     
         case 3:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                     REMOVER                                    ");  
            printf("-------------------------------------------------------------------------------- >>>>>>>>>>");
            remocao = remover_pop(&topo);
            if(remocao == 0){
               printf(" Pilha -> Vazia !\n");
            }                        
            else{
               printf(" Elemento removido : %i \n",remocao);
            }
            printf("--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'N';break;  
         case 4:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                      BUSCAR                                    ");  
            printf("--------------------------------------------------------------------------------");
            search = buscar(topo);
            if(search == 1){
               printf("\n--------------------------------------------------------------------------------");
               printf(" >>>>>>>>>> Elemento Encontrado !");
               printf("\n--------------------------------------------------------------------------------\n");
            }
            else{
               printf("\n--------------------------------------------------------------------------------");
               printf(" >>>>>>>>>> Elemento Inexistente !");
               printf("\n--------------------------------------------------------------------------------\n");
            }              
            system("PAUSE");
            continua = 'N';break; 
         case 5:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                     CONTAR                                     ");  
            printf("-------------------------------------------------------------------------------- >>>>>>>>>>");
            total = contar(topo);
            if(total == 0){
               printf(" Pilha -> Vazia !\n");
            }   
            else{
               if(total >= 1){
                  printf(" Número de elementos : %i\n",total);
               }
            }
            printf("--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'N';break;
         case 6:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                      TOPO                                      ");  
            printf("-------------------------------------------------------------------------------- >>>>>>>>>>");
            top = mostre_top(topo);
            if(top == 0){
               printf(" Pilha -> Vazia !");
            }       
            else{
               printf(" Elemento do topo : %i",top);
            }
            printf("\n--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'N';break;
         case 7:
            system("cls");  
            intro();
            printf("--------------------------------------------------------------------------------");
            printf("                                     ESVAZIAR                                   ");  
            printf("-------------------------------------------------------------------------------- >>>>>>>>>>");
            esvaziar = clear(&topo);
            if(esvaziar == 0){
               printf(" Pilha -> Vazia !");
            }            
            else{
               printf(" Pilha Apagada Com Sucesso !");
            }
            printf("\n--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'N';break;    
         default:
            system("cls");
            intro();     
            printf("--------------------------------------------------------------------------------");
            printf("                                 OPÇÃO INVÁLIDA                                 ");
            printf("--------------------------------------------------------------------------------\n");
            system("PAUSE");
            continua = 'N';break;               
      }
   } 
   while(continua != 'S' && continua != 's');  
      return 0;   
}
