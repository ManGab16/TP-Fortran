#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct
{
    int idPaciente;
    char nombre[30];
    char apellido[30];
    int dni;
    char movil[12];
    stObrasocial obSocial[20];
    int eliminado;


}StPaciente;

#endif // PACIENTE_H_INCLUDED
