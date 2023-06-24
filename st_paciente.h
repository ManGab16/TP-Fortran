#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct
{
int idPaciente; /// campo único y autoincremental
char nombre[30];
char apellido[30];
char dni[10];
char movil[12];
int eliminado; /// 0 si está activo ó 1 si está eliminado
}stPaciente;

///--------PROTOTIPADO-------

void altaPaciente(char archivo[]);

int validacion (char archivo[], char dni[]);

int retornar_ultimo_id(char archivo[]);

void bajaPaciente(char archivo[], char dni[]);


/** En Main: 

    char archivo[]="pacientes.dat"; /// ----> "pacientes.dat"
    altaPaciente(archivo);

    return 0;

**/

#endif // PACIENTES_H_INCLUDED
