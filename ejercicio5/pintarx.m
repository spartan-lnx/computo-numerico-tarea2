function [ C,I ] = pintarx(funcion, derivadafun, objetivo,maxit,negRe,posRe,negIm,posIm,tamPaso,...
    raiz1, raiz2, raiz3)

k=0;
l=0;
color = 0;
for b = [negIm:+tamPaso:posIm]
    k=k+1;
    j=0;
    for a = [negRe:+tamPaso:posRe]
        j = j+1;

        [raiz,n] = metodonewton(funcion,derivadafun,a+1i*b,objetivo,maxit);
        printf("x_0 = %d %di procesado\n",a,b);

        l=l+1;
        I(l)=n; %Numero de iteraciones requeridas para ese x_0
        
        if abs(raiz - raiz1) <= objetivo
            color = 20; %encontro la raiz 1
        elseif abs(raiz - raiz2) <= objetivo
            color = 40; %encontro la raiz 2
        elseif abs(raiz - raiz3) <= objetivo
            color = 60; %encontro la raiz 3
        else
            color = 0; %no econtro ninguna raiz
        end      
        C(k,j)=color; %Codigo de color del x_0: 20 para r1,40 para r2, 60 para r3, 0 si no encontro
    end
end