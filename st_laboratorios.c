#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "laboratorios.h"
#include "../Pacientes/pacientes.h"


/// --------- ALTA DE LABORATORIOS ----------

void altaLaboratorios(char archivo[])
{
    FILE *archi;

    archi = fopen(archivo, "ab");

    FILE *pacientes=fopen("pacientes.dat", "rb");

    char opc;

    int ultID;

//    int dia, mes;

    if(archi)
    {
        if (pacientes)
        {
            ultID=ultimoIDlab(archivo);

            while(opc!='27')
            {
                stLaboratorio lab;
                stPaciente p;


                lab.idPaciente=p.idPaciente;

                printf("ANIO");
                fflush(stdin);
                scanf("%i", &lab.anio);

                printf("MES");
                fflush(stdin);
                scanf("%i", &lab.mes);

                printf("DIA");
                fflush(stdin);
                scanf("%i", &lab.dia);

                ultID++;

                printf("PRACTICA REALIZADA");
                fflush(stdin);
                scanf("%i", &lab.practicaRealizada);


                lab.baja=0;

                fwrite(&lab, sizeof (lab), 1, archi);       ///-----------------> guardar laboratorio

                printf("\nPresione ESC para salir o cualquier tecla para continuar.\n\n");
                opc=getch();
                system("cls");

            }
            fclose(pacientes);
        }
        fclose(archi);
    }
}

int ultimoIDlab(char archivo[])
{
    int uID=0;

    FILE *archi=fopen(archivo, "rb");


    if(archi)
    {
        stLaboratorio ult;
        fseek(archi, (-1)*sizeof(stLaboratorio), SEEK_END);
        if(fread(&ult, sizeof(stLaboratorio), 1, archi)>0)
        {
            uID=ult.idLab;
        }
        fclose(archi);
    }
    return uID;
}






///----------------------------------------------------


///------------- Baja Laboratorios----------------

void bajaLaboratorios(int dia, int mes, int anio)
{
    FILE *archi=fopen("laboratorio.dat", "r+b");

    stLaboratorio lab;
    if(archi)
    {
        while(fread(&lab, sizeof(stLaboratorio), 1, archi)>0)
        {
            if((lab.dia==dia) && (lab.mes==mes) && (lab.anio== anio))
            {
                fseek(archi, (-1)*sizeof(stLaboratorio), SEEK_CUR);
                lab.baja=1;
                fwrite(&lab, sizeof(stLaboratorio), 1, archi);
                printf("\n\t La practica del %i / %i / %i fue eliminada con exito.", dia, mes, anio);
            }else
            {
                printf("\n \t En la fecha %i / %i / %i no se realizo ninguna practica.", dia, mes, anio);
            }
        }
        fclose(archi);
    }
}







