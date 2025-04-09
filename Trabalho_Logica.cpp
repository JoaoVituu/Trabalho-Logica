#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

//Declaração
char c;
char pilha[100], polonesa[100], interpretacao[100];
char True[]="True",False[]="False";
int topo2=0, i, topo = 0;
char formula[] = "(( ( P & Q ) = ( < ( R & S ) ) ) > ( S | Q ))";

//Conversão para polonesa
static void Notacao_Polonesa()
{
    for(i = 0; i < 100; i++)
    {   
        if(formula[i] == 'P' || formula[i] == 'Q' || formula[i] == 'R' || formula[i] == 'S')
        {
            polonesa[topo2] = formula[i];
            topo2++;
        }
        if(formula[i] == '&' || formula[i] == '|' || formula[i] == '>' || formula[i] == '<' || formula[i] == '=')
        {
            pilha[topo] = formula[i];
            topo++;
        }
        if(formula[i] == ')')
        {   
            for(topo; topo >= 0; topo--)
            {

                if(pilha[topo] != '\0')
                {
                    polonesa[topo2] = pilha[topo];
                    topo2++;
                    pilha[topo] = '\0';
                }
            }
            topo=0;
        }
        if(formula[i] == '\0')
        {
            i = 101;
        }
    }
}

//Interpretação
static void Interpreta_formula()
{
    bool P=true, Q=false, R=true, S=false, I, passa;  
    for(i=0; i<100;i++)
    {
        if(polonesa[i] == '\0')
        {
            i=101;
        }
        if(polonesa[i] == 'P')
        {
            polonesa[i] = P;
        }
        if(polonesa[i] == 'Q')
        {
            polonesa[i] = Q;
        }
        if(polonesa[i] == 'R')
        {
            polonesa[i] = R;
        }
        if(polonesa[i] == 'S')
        {
            polonesa[i] = S;
        }
        if(polonesa[i] == '&')
        {
            if( polonesa[i-2] == false||polonesa[i-1] == false)
            {
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=false;
                polonesa[i] = I;
                polonesa[i-2] = '\0';
            }
            else{
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=true;
                polonesa[i] = I;
                polonesa[i-2] = '\0';
            }
        }
        if(polonesa[i] == '|')
        {
            if(polonesa[i-2] == false && polonesa[i-1] == false)
            {
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=false;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
            else{
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=true;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
        }
        if(polonesa[i] == '>')
        {
            if(polonesa[i-2] == true && polonesa[i-1] == false)
            {   
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=false;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
            else{
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=true;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
        }
        if(polonesa[i] == '<')
        {
            if(polonesa[i-1] == false)
            {   
                I=true;
                polonesa[i]=I;
            }
            else{
                I=false;
                polonesa[i]=I;
            }
            if(polonesa[i-2] != '\0')
            {
                passa = polonesa[i-2];
                polonesa[i-1] = passa;
                polonesa[i-2] = '\0';
            }
            else{
                polonesa[i-1] = '\0';
            }
        }
        if(polonesa[i] == '=')
        {
            if(polonesa[i-2] != polonesa[i-1])
            {
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=false;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
            else{
                if(polonesa[i-3] != '\0')
                {
                    passa = polonesa[i-3];
                    polonesa[i-1] = passa;
                    polonesa[i-3] = '\0';
                }
                else{
                    polonesa[i-1] = '\0';
                }
                I=true;
                polonesa[i]=I;
                polonesa[i-2] = '\0';
            }
        }
    }
    switch(I)
    {
        case 0:
        strcpy(interpretacao,False);
        break;
        case 1:
        strcpy(interpretacao,True);
        break;
    }
}
  
//Código principal 
int main()
{
    printf("Notacao canonica (entrada): %s\n",formula);  

    Notacao_Polonesa();
    printf("Notacao Polonesa (pos): %s\n",polonesa);
    
    Interpreta_formula();
    printf("Resultado: %s", interpretacao);
}