/*La insercion binaria mira segun la altura, osea restara la altura de los niveles
  tiene que tener un minimo la altura del arbol significa que todos los nodos deben estar completo
  si la altura es 3 entonces  2^3 = 8 osea debe tener 8 nodos en un arbol de altura 3...
  Para balancear un arvol es necesario tener una lista ordenada la cual se debera crear con una funcion
  una vez hecha hacer el arbol es sencillo, simplemente usando el numero de la mitad y repetir con la izq,der...
*/ 

int arbolBalanceado(PNODOABT T){

    int altura, numNodo;

    if(T == NULL){
        return 1;
    }

    altura = alturaAB(T);
    numNodo = numeroNodosAB(T);
    if (numNodo >= pow(2,altura))
        return 1;
    else 
        return 0;

}




