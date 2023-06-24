#ifndef LABORATORIOS_H_INCLUDED
#define LABORATORIOS_H_INCLUDED

///-----Prototipado----------

typedef struct
{
    int idLab;
    int idPaciente;         /// campo comun a pacientes.
    int anio;               /// ------------------------------------------------------>
    int mes;                /// 1 a 12.----------------------------------------------->  FECHA DEL ESTUDIO
    int dia;                /// 1 a depende mes.-------------------------------------->
    int practicaRealizada;  /// campo comun a practicas.(1 a 10)
    int baja;               /// 0 o -1.
}stLaboratorio;

void altaLaboratorios(char archivo[]);
//void fMes(int mes);
//void fDia(int dia);

int ultimoIDlab(char archivo[]);

void bajaLaboratorios(int dia, int mes, int anio);

#endif // LABORATORIOS_H_INCLUDED
