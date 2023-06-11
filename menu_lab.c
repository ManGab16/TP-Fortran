 void gotoxy(int x,int y)
 {
     HANDLE manipulador;
     COORD coordenada;
     manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
     coordenada.X=x;
     coordenada.Y=y;
     SetConsoleCursorPosition(manipulador,coordenada);
 }

 void centrar_texto(const char *texto, int y)
 {
     int size_texto = strlen(texto);
     gotoxy(40-(size_texto/2),y);
     printf("%s",texto);

 }
