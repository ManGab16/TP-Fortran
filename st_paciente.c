/// FALTAN LOS PROTOTIPADOS!!!! PACIENTES.H




void altaPaciente(char archivo[])
{
    stPaciente paciente;
    char opc, dni[10];
    int flag;

    FILE *archi=fopen("pacientes.dat", "ab");

    if(archi)
    {
        int ultID = retornar_ultimo_id("Pacientes.dat");///-----> devuelve el ultimo id cargado en el arch.
        
        
        while(opc!=27)
        {
            stPaciente paciente;

            printf("\n\t Cargar nuevo paciente: \n\n");

            printf("DNI (char): ");
            fflush(stdin);
            gets(paciente.dni);
            strcpy(dni, paciente.dni);
            flag=validacion(dni);
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

int validacion(char dni[])
{
    int i=-1, booleana;
    FILE *archi= fopen("pacientes.dat", "rb");
    if(archi)
    {
        stPaciente p;
        while(fread(&p, sizeof(stPaciente), 1, archi))
        {
           booleana=strcmp(dni, p.dni);

            if(strcmp(p.dni, dni)==0)
            {
                i=1;
            }
        }
        fseek(archi, (-1)*sizeof(stPaciente), SEEK_CUR);
        fclose(archi);
        return i;
    }

    return i;
}


int retornar_ultimo_id (char nombreArchivo[])
{
    int ultimoId = 0;

    FILE* archi = fopen("Pacientes.dat", "rb");

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

void bajaPaciente(char DNI[]) /// TIENE QUE RECIBIR EL CHAR DNI.
{
    stPaciente paciente;
    int i=0;
    FILE *archivo=fopen("pacientes.dat", "r+b");
    if(archivo)
    {
        fread(&paciente, sizeof(stPaciente), 1, archivo);
        while(!feof(archivo) && paciente.dni!=DNI)
        {
            i++;
            fread(&paciente, sizeof(stPaciente), 1, archivo);
        }
        if(paciente.dni==DNI)
        {
            paciente.eliminado=1;
            fseek(archivo, sizeof(stPaciente)*i, SEEK_SET);
            fwrite(&paciente, sizeof(stPaciente), 1, archivo);
            printf("El paciente %s ha sido eliminado.", paciente.apellido);
        }
        fclose(archivo);
    }
}
