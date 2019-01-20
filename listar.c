#include <dirent.h> //Estructura utilizada para leer los datos de un directorio
#include <unistd.h> //Para lecturas de entradas de los directorios
#include <sys/types.h> //Necesaria para apertura, lectura y cierre del directorio

main()
{
	DIR *punt_dir; //Puntero a directorio
	struct dirent *reg_dir; //Puntero a estructura dirent para almacenar la info. del directorio
	off_t pos; //Posición del fichero en el directorio
	punt_dir=opendir("/root"); //Apertura del directorio deseado apuntado por puntero punt_dir
	if (punt_dir!=NULL) //Si no hay ningún error
	{
		while ((reg_dir=readdir(punt_dir)) != NULL) //Mientras no hay error se lee una entrada del directorio
		{											//y se almacena en la estructura reg_dir
			pos=telldir(punt_dir); //Posición del puntero en el fichero del directorio
			printf(" Nombre: %s :\n",reg_dir->d_name);	//Visualiza Posición y Nombre de entrada 
		}																	//en el directorio
		closedir(punt_dir); //Una vez leidas todas las entradas del directorio, se cierra
	}
}

