#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pacientes.h"


void altaPaciente(char archivo[])
{
    char opc, dni[10];
    int flag;

    FILE *archi=fopen(archivo, "ab");

    if(archi)
    {
        int ultID = retornar_ultimo_id(archivo);///-----> devuelve el ultimo id cargado en el arch.


        while(opc!=27)
        {
            stPaciente paciente;

            printf("\n\t Cargar nuevo paciente: \n\n");

            printf("DNI (char): ");
            fflush(stdin);
            gets(paciente.dni);
            strcpy(dni, paciente.dni);
            flag=validacion(archivo, dni);
            if(flag==-1)
            {
                ultID++;
                paciente.idPaciente=ultID;///-----> incrementa en 1 el id.

                printf("\nNOMBRE: ");
                fflush(stdin);
                gets(paciente.nombre);

                printf("\nAPELLIDO: ");
                fflush(stdin);
                gets(paciente.apellido);

                printf("\nMOVIL (char): ");
                fflush(stdin);
                gets(paciente.movil);

                paciente.eliminado=0;
            }else
            {
                printf("\n El paciente ya existe.");
            }



            fwrite(&paciente, sizeof(stPaciente), 1, archi);

            printf("\nPresione ESC para salir o cualquier tecla para agregar otra persona.\n\n");
            opc=getch();
            system("cls");
        }
         fclose(archi);
    }
}

///------->FUNCION QUE HAGA DE FLAG PARA FIJARSE QUE NO EXISTA ESE PACIENTE
///       |
///       v

int validacion(char archivo[], char dni[])
{
    int i=-1;       ///-------------------------------> Se asigna -1 al flag
    FILE *archi= fopen(archivo, "rb");
    if(archi)
    {
        stPaciente p;
        while(fread(&p, sizeof(stPaciente), 1, archi))
        {


            if(strcmp(p.dni, dni)==0)       ///--------------> Se comparan los DNI, si son iguales el FLAG cambia a 1.
            {
                i=1;
            }
        }
        fseek(archi, (-1)*sizeof(stPaciente), SEEK_CUR);
        fclose(archi);
    }

    return i;               ///--------------> Si devuelve -1 el DNI ingresado no existe, continua con la carga del paciente.
                            ///--------------> Si devuelve 1 el DNI ingresado ya existe, por lo tanto frena la carga del paciente.
}

///--------> ID AUTOINCREMENTAL.

int retornar_ultimo_id (char nArchivo[])
{
    int ultimoId = 0;

    FILE* archi = fopen(nArchivo, "rb");

    if (archi)
        {
        stPaciente ult;

        fseek(archi, (-1) * sizeof(stPaciente), SEEK_END);

        if (fread(&ult, sizeof(stPaciente), 1, archi) > 0)
            {
            ultimoId = ult.idPaciente;
            }
        }

    return ultimoId;
}



///FIN DE ALTA DE PACIENTE.


///------- BAJA PACIENTE --------

void bajaPaciente(char archivo[], char DNI[]) /// DNI COMO CAMPO DE BUSQUEDA,
{
    stPaciente paciente;
    FILE *archi=fopen( archivo, "r+b");
    if(archi)
    {
        while(fread(&paciente, sizeof(stPaciente), 1, archi)>0)             /// Recorre el archivo, cuando encuntra el DNI, modifica el campo de eliminados
        {
            if(strcmp(DNI, paciente.dni)==0)
            {
                fseek(archi, (-1)* sizeof(stPaciente), SEEK_CUR);
                paciente.eliminado=1;
                fwrite(&paciente, sizeof(stPaciente), 1, archi);
                printf("\n\t El paciente %s %s ha sido eliminado.", paciente.nombre, paciente.apellido);
            }
            else{
                printf("\n\t No se ha encontrado al paciente.");
            }
        }
        fclose(archi);
    }
}
