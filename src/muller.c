#include "../include/muller.h"
#include "../include/main.h"
#include "../include/funciones.h"

int metodomuller(double calculos[][4], double x0, double x1, double x2, double objetivo, int maxit)
{
    double a,b,c,fx0,fx1,fx2,ddx2x1,ddx2x0;
    double disc;
    int i;
    
    do {
        fx0 = funcion_dificil(x0);
        fx1 = funcion_dificil(x1);
        fx2 = funcion_dificil(x2);

        c = fx2;
        a = (1/(fx1-fx0))*((fx2-fx1)/(x2-x1)-(fx2-fx0)/(x2-x0));
        b = (fx2-fx1)/(x2-x1) + a*(x2-x1);

        disc = sqrt(pow(b,2) -4*a*c);

        actualizartablamuller(i++, calculos,x0,x1,x2,fx2);
        x0 = x1;
        x1 = x2;

        if (b < disc)
        {
            x2 += (-b - disc)/(2*a); 
        }
        else 
        {
            x2 += (-b + disc)/(2*a);
        } 
    }while(fabs(fx2) > objetivo && i < maxit);   
    return i;
}

void actualizartablamuller(int i, double calculos[][4], double x0, double x1, double x2, double fx2)
{
    calculos[i][0] = x0;
    calculos[i][1] = x1;
    calculos[i][2] = x2;
    calculos[i][3] = fx2;
}

void mostrartablamuller(int n, double calculos[][4], int cifras_significativas)
{
    int i;
    switch(cifras_significativas)
    {
        case 13:
        {
            printf("it\tx0\t\t\tx1\t\t\tx2\t\t\tfx2\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.13g\t\t%-8.13g\t\t%-8.13g\t\t%-8.13g\n",i,calculos[i][0],calculos[i][1],
                    calculos[i][2],calculos[i][3]);
            }
            break;
        }
        default:
        {
            printf("it\tx0\t\t\tx1\t\tx2\t\tfx2\n");
            for(i = 0; i < n; i++)
            {
                printf("%d\t%-8.13g\t\t%-8.13g\t\t%-8.13g\t\t%-8.13g\n",i,calculos[i][0],calculos[i][1],
                    calculos[i][2],calculos[i][3]);
            }
            break;
        }
    }
}

void guardartablamullerlatex(int n, double calculos[][4], int cifras_significativas, char nombre[])
{
    int i;
    FILE* archivo = fopen(nombre,"w+");
    
    fprintf(archivo,"\\begin{center}\n");
    fprintf(archivo,"\\begin{tabular}{c c c c c}\n");
    fprintf(archivo,"it & $x_{i-2}$ & $x_{i-1}$ & $x_i$ & $f(x_i)$\\\\\n");

    switch(cifras_significativas)
    {
        case 13:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.13g & %.13g & %.13g & %.13g\\\\\n",i,calculos[i][0],calculos[i][1],
                    calculos[i][2],calculos[i][3]);
            }
            break;
        }
        default:
        {
            for(i = 0; i < n; i++)
            {
                fprintf(archivo,"%d & %.13g & %.13g & %.13g & %.13g\\\\\n",i,calculos[i][0],calculos[i][1],
                    calculos[i][2],calculos[i][3]);
            }
            break;
        }
    }
    fprintf(archivo,"\\end{tabular}\n");
    fprintf(archivo,"\\end{center}");
    fclose(archivo);   
}