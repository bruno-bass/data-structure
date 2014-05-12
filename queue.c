#include <stdio.h>
#include <stdlib.h>

		strct [3~]{
   int info;
   struct fila *prox;
};


void inserir_insert(struct fila **porta, int inserir){
   struct fila *p;
   if((p = malloc(sizeof(struct fila)))== NULL){
      printf("\n Erro ao alocar memória !\n");
   }       
   else{
      p->info = inserir;
      p->prox = *porta;
      *porta = p;
   }     
}

void imprimir(struct fila *porta){
   struct fila *p;
   if(porta == NULL){
      printf(" Vazia !");
   }         
   else{  
      p = porta;
      while(p != NULL){
         printf(" %i ",p->info);
         p = p->prox;
      }   
   }     
}

int remover_delete(struct fila **porta){
   struct fila *p, *ant;
   int removido;
   if(*porta == NULL){
      removido = 0;
   }
   else{
      p = *porta;  
      if(p->prox == NULL){
         removido = p->info;
         *porta = NULL;
         free(p);
      }           
      else{
         while(p->prox != NULL){
            ant = p;
            p = p->prox;
         }        
         removido = p->info;
         ant->prox = NULL;
         free(p);
      }
   }
   return removido;     
}

int fila_size(struct fila *porta){
   struct fila *p;
   int cont = 0;
   if(porta == NULL){
      cont = 0;      
   }
   else{
      p = porta;  
      if(p->prox == NULL){
         cont = 1;
      }
      else{
         while(p != NULL){
            cont++;
            p = p->prox;
         }
      }
   }               
   return cont;
}    

int final_rear(struct fila *porta){
   int fim;
   if(porta == NULL){
      fim = 0;
   }           
   else{
      fim = porta->info;  
   }
   return fim;
}

int comeco_front(struct fila *porta){
   struct fila *p; 
   int comeco;
   if(porta == NULL){
      comeco = 0;
   }
   else{
      p = porta;  
      while(p->prox != NULL){
         p = p->prox;
      }            
      comeco = p->info;  
   }
   return comeco;
}

int fila_clear(struct fila **porta){
   struct fila *p;
   p = *porta;
   if(p == NULL){
      return 0;
   }
   else{
      if(p->prox == NULL){
         *porta = NULL;
         free(p);
         return 1;
      }           
      else{
         while(p->prox != NULL){
            p = *porta;
            *porta = p->prox;
            free(p);
         }
       return 1;  
      }                            
   }
}
   
int main()
{
  struct fila *porta;
  int esvaziar, fim, total, opc, inserir, remocao, comeco;
  char continua;
  porta = NULL;
   
}
