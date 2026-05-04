#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *nombre[]);
void BuscarNombreporPalabra(char *nombre[]);

int main() {
    char Buff[50], *nombres[5];

    printf("Ingrese el nombre de 5 personas:\n");

    for (int i = 0; i < 5; i++) 
    {
        printf("Nombre %d: ", i + 1);
        fflush(stdin);
        gets(Buff);

        nombres[i] =(char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
    }
    
    MostrarPersonas(nombres);
    BuscarNombreporPalabra(nombres);  
    
    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    
    printf("---------------Fin del Programa---------------");
    getchar();
    return 0;
}

void MostrarPersonas(char *nombre[])
{
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        puts(nombre[i]);
        //printf("%d: %s",i+1, nombre[i]);
        printf("\n");
    }
}

void BuscarNombreporPalabra(char *nombre[])
{
    char buffNombre[50], *encontrado;
    int flag = 0;
    while (flag != 1)
    {
        printf("---------------Ingrese el nombre que desee buscar:---------------\n");
        fflush(stdin);
        gets(buffNombre);
        
        for (int i = 0; i < 5; i++)
        {
            if (strstr(nombre[i],buffNombre) != NULL)
            {
                flag = 1;
                printf("El nombre encontrado es:\t");
                puts(nombre[i]);
                i=4;
            }else
            {
                flag = -1;
            }
        }
        if (flag == -1)
        {
            puts("-1");
            printf("-----------------ERROR Ingrese un nombre valido-----------------\n");

        }

    }
    
}


// acceder a un array con arimetrica de punteros *(p+i)
// acceder a un array con notacion subindexada array[i] p[i] (no modifica el puntero)
// p++ modifica el puntero *(p+i) = p[i] no

/*
Ejemplo de aritmetica de punteros. ARREGLO y PUNTERO
#include <stdio.h> 

const int DIM= 5;

void main()
{
  int  *pENT;//puntero a entero
  int Arr_Ent[DIM]; //arreglo de enteros
  int i; //entero


  printf("Asignamos y mostramos los elementos con notacion subindexada Arr_Ent[i]\r\n"); 
  printf("___________________________________________________________________\r\n\r\n"); 
  //Se carga el vector con notacion subindexada
  for (i=0; i<DIM;i++) printf("%4d", Arr_Ent[i]=i*10); 
  printf("\r\n\r\n"); getchar();

  pENT=Arr_Ent;// es lo mismo que pENT=&Arr_Ent[0] la dire del primer elemento  
  printf("----------------------------------------------------------------\r\n\r\n"); 
  printf("El primer elemento del arreglo  *pENT = %4d\r\n", *pENT);
  getchar();
    
  printf("Mostramos los elementos del arreglo con notacion *pENT++\r\n"); 
  printf("___________________________________________________________\r\n\r\n"); 
  
  for (i=0; i<DIM;i++) printf("%4d", *pENT++);//Idem a *(pENT++)
  // El puntero queda fuera del arreglo. 
  printf("\r\n\r\n"); 
  printf("*pENT++  Utiliza lo referenciado y luego incrementa la direccion.\r\n\r\n"); 
  printf("El puntero queda afuera del arreglo *pENT = %4d \r\n\r\n", *pENT);
  printf("------------------------------------------------------------\r\n\r\n"); 
  getchar();
    
  printf("\r\n");
  
  pENT=&Arr_Ent[4];//pEnt tiene la direccion del ultimo elemento
  printf("pENT=&Arr_Ent[4];  Es el utimo elemento ->  %4d \r\n\r\n", *pENT);
  printf("Mostramos los elementos desde el final con notacion *pENT--\r\n");
  printf("____________________________________________________________\r\n\r\n"); 
  
  for (i=0; i<DIM;i++) printf("%4d", *pENT--);//muestra y decrementa
  printf("\r\n"); getchar();

  printf("--------------------------------------------------\r\n\r\n");  
  pENT=&Arr_Ent[0];// pEnt tiene la direccion del primer elemento del arreglo
  printf("pENT=&Arr_Ent[0]; el primer elemento *pENT = %4d \r\n\r\n", *pENT);
  printf("--------------------------------------------------\r\n\r\n");
  printf("Mostramos dos veces el primer elemento del arreglo\r\n\r\n");
  printf("1er elemento %4d, ",(*pENT)++); // utiliza lo referenciado 
  
  
  //luego incrementa lo referenciado pero sigue en el mismo lugar
  printf("incrementado %8d\r\n\r\n", *pENT); 
  printf("(*pENT)++ Utiliza lo referenciado y luego incrementa lo referenciado. \r\n");
  printf("Pero sigue en el mismo lugar\r\n\r\n\r\n");
  printf("--------------------------------------------------\r\n\r\n");
  getchar();
    
  printf("\r\n");
  printf("El arreglo con el 1er.elem. modificado en 1 con notacion (*pENT)++ \r\n\r\n");
  printf("_______________________________________________________________\r\n\r\n"); 
  for (i=0; i<DIM;i++) 
  {
	   (*pENT)++;// utiliza lo referenciado y luego lo incrementa
      printf("%4d",*pENT++); // utiliza lo referenciado e incrementa la direccion
  }
  printf("\r\n"); 
  printf("---------------------------------------------------------------------\r\n\r\n");
  getchar();
  
  printf("\r\n");
  printf("++(*(pENT++))Incrementa, utiliza y vuelve a incrementar la direccion\r\n");
  pENT=Arr_Ent;// pENT tiene la dirección de primer elemento del arreglo 
  printf("Nuevamente el arreglo con notacion ++(*(pENT++))\r\n\r\n");
  printf("_________________________________________________\r\n\r\n"); 
  
  for (i=0; i<DIM;i++) printf("%4d",++(*(pENT++)));
  printf("\r\n\r\n"); 
  printf("--------------------------------------\r\n\r\n");
  getchar();
  pENT=Arr_Ent;// pENT tiene la dirección de primer elemento del arreglo 
 
  printf("\r\n");
  printf("El arreglo con notacion subindexada pENT[i] \r\n");
  printf("_____________________________________________\r\n\r\n"); 
  for (i=0; i<DIM;i++) printf("%4d",pENT[i]);
  printf("\r\n\r\n"); 
  printf("------------------------------------\r\n\r\n");
  getchar();
  
  printf("\r\n");
  printf("El arreglo con notacion *(pENT+i)\r\n");
  printf("__________________________________\r\n\r\n"); 
  for (i=0; i<DIM;i++) printf("%4d",*(pENT+i));
  printf("\r\n\r\n"); getchar();
}


*/