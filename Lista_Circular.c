#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
//Cauê Mendonça Magela do Ó
//rgm : 43558

struct Lseo
{
    int valor;
    struct Lseo *prox;
};
void inserir(int x, struct Lseo **ant, struct Lseo **ptr){
    struct Lseo *pt = malloc(sizeof(struct Lseo));
    pt->valor = x;
    pt->prox = *ptr;
    *ant = pt;
}
int main()
{
    char string[50];
    int valor, resp, contr, width, height, textwidth, textheight;
    struct Lseo *ant;
    struct Lseo *ptr;
    struct Lseo *prox;
    struct Lseo *ptlista = NULL;
    struct Lseo *final = NULL;
    struct Lseo *pt = NULL;
    struct Lseo *desalocar = NULL;
    gfx_init(1280, 720, "Lista circular simplesmente encadeada");
    gfx_set_color(255, 255, 255);
    do {
        printf("1-Busca\n2-insercao\n3-remocao\n4-sair\n");
        scanf("%d", &resp);


        switch (resp) {
            case 1:
                printf("Informe o numero que sera buscado\n");
                scanf("%d", &valor);
                contr = 0;
                pt = ptlista;
                if(pt->valor == valor){
                    contr = 1;
                    printf("O valor esta na lista\n");
                }
                pt = pt->prox;
                while ((pt != ptlista) && (contr == 0)){
                    if(pt->valor == valor){
                        contr = 1;
                        printf("O valor esta na lista\n");
                    }
                    pt = pt->prox;
                }
                if(contr == 0){
                    printf("O valor nao esta na lista\n");
                }
                break;
            case 2:
                printf("Informe o numero que sera inserido\n");
                scanf("%d", &valor);
                contr = 0;
                if (ptlista == NULL) {
                    contr = 1;
                    inserir(valor, &ptlista, &ptlista);
                    final = ptlista;
                } else {
                    pt = ptlista;
                    if(pt->valor == valor){
                        contr = 1;
                        printf("Valor ja esta na lista\n");
                    }
                    if ((pt->valor > valor)) {
                        contr = 1;
                        inserir(valor, &ptlista, &ptlista);
                        final->prox = ptlista;
                    } else {
                        if(pt->prox == NULL){
                            contr = 1;
                            inserir(valor, &ant, &ptlista);
                            pt->prox = ant;
                            final = ant;
                        }else {
                            if (pt->prox != ptlista) {
                                prox = pt->prox;
                            }
                            if (pt->valor == valor) {
                                contr = 1;
                                printf("Valor ja esta na lista\n");
                                break;
                            } else {
                                if (pt->valor < valor) {
                                    if (prox->valor > valor) {
                                        contr = 1;
                                        inserir(valor, &ant, &prox);
                                        pt->prox = ant;
                                        final = ant;
                                    } else {
                                        ptr = pt;
                                        pt = pt->prox;
                                    }
                                } else {
                                    ptr = pt;
                                    pt = pt->prox;
                                }
                            }
                            while ((pt != ptlista) && (contr == 0)) {
                                if (pt->prox != NULL) {
                                    prox = pt->prox;
                                }
                                if (pt->valor == valor) {
                                    contr = 1;
                                    printf("Valor ja esta na lista\n");
                                    break;
                                } else {
                                    if (pt->valor < valor) {
                                        if (prox->valor > valor) {
                                            contr = 1;
                                            inserir(valor, &ant, &prox);
                                            pt->prox = ant;
                                            final = ant;
                                        } else {
                                            ptr = pt;
                                            pt = pt->prox;
                                        }
                                    } else {
                                        ptr = pt;
                                        pt = pt->prox;
                                    }
                                }
                            }
                        }
                        if(contr == 0){
                            inserir(valor, &ant, &ptlista);
                            ptr->prox = ant;
                            final = ant;
                        }
                    }
                }
                break;
            case 3:
                printf("Informe o numero que sera removido\n");
                scanf("%d", &valor);
                contr = 0;
                ant = NULL;
                pt = ptlista;
                if(pt->valor == valor){
                    contr = 1;
                    ptlista = pt->prox;
                    final->prox = pt->prox;
                    printf("O valor retirado foi = %d\n", pt->valor);
                    free(pt);
                }else {
                    ant = pt;
                    pt = pt->prox;
                }
                while ((pt != ptlista) && (contr == 0)){
                    if(pt->valor == valor){
                        contr = 1;
                        ant->prox = pt->prox;
                        printf("O valor retirado foi = %d\n", pt->valor);
                        free(pt);
                    }else {
                        ant = pt;
                        pt = pt->prox;
                    }
                }
                if(contr == 0){
                    printf("O valor nao esta na lista\n");
                }
        }
        gfx_clear();
        width = 30;
        height = 0;
        if(ptlista != NULL){
            pt = ptlista;
    	    if(pt != final){
                sprintf(string, "%d -> ", pt->valor);
            }else{
            	 sprintf(string, "%d ", pt->valor);
            }
    	    gfx_get_text_size(string, &textwidth, &textheight);
  	    if(width+textwidth <= 1280){
                gfx_text(width, height, string);
                width += textwidth;
            }else{
               height += textheight;
               gfx_text(0, height, string);
               width = textwidth;
    	    }
    	    if(pt->prox != NULL){
    	        pt = pt->prox;
    	        while (pt != ptlista){
    	            if(pt != final){
                        sprintf(string, "%d -> ", pt->valor);
            	    }else{
            	        sprintf(string, "%d ", pt->valor);
            	    }
    	    	    gfx_get_text_size(string, &textwidth, &textheight);
    	    	    if(width+textwidth <= 1280){
    	            	gfx_text(width, height, string);
    	     	    	width += textwidth;
    	    	    }else{
    	            	height += textheight;
    	            	gfx_text(10, height, string);
    	            	width = textwidth + 10;
    	    	    }
                   pt = pt->prox;
    	    	}
    	    }
    	}
    	gfx_line(width, height+(textheight/2), width+30, height+(textheight/2));
        gfx_line(width+30, height+(textheight/2), width+30, height+textheight+10);
        gfx_line(width+30, height+textheight+10, 5, height+textheight+10);
        gfx_line(5, height+textheight+10, 5, textheight/2);
        gfx_line(5, textheight/2, 25, textheight/2);
        gfx_line(25, height+(textheight/2), 20, 5);
        gfx_line(25, height+(textheight/2), 20, textheight-5);
    	gfx_paint();

    }while(resp != 4);
    pt = ptlista->prox;
    while (pt != ptlista){
        desalocar = pt;
        pt = pt->prox;
        free(desalocar);
    }
    free(ptlista);
    gfx_quit();
    return 0;
}
