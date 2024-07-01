#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

void sysfile(char const filename[]);

int main(){
  ssize_t leer;
  char* buffer = 0;
  size_t buf_size = 0;

  printf("Favor ingrese la el nombre del archivo que desea obtener la infomación \n");
  leer = getline(&buffer, &buf_size, stdin);

  if (leer <=0 ){
    printf("Al obtener la líne hubo un fallo\n");
    exit(1);
  }

  if (buffer[leer-1] == '\n'){
    buffer[leer-1] = 0;
  }

  int sys=open(buffer,O_RDONLY);
  if(sys==-1){
    printf("Lo lamento no existe | I'm sorry unexisting file\n");
    exit(1);
  }
  else{
    sysfile(buffer);
  }
  free(buffer);
  return 0;
}

void sysfile(char const filename[]){

  struct stat sysfile;

  if(stat(filename,&sysfile)==-1){
    printf("Ocurrió un error | Something happend\n");
  }

  //Accessing data members of stat struct
  printf("\nArchivo st_uid %d \n",sysfile.st_uid);
  printf("\nArchivo st_blksize %ld \n",sysfile.st_blksize);
  printf("\nArchivo st_gid %d \n",sysfile.st_gid);
  printf("\nArchivo st_blocks %ld \n",sysfile.st_blocks);
  printf("\nArchivo st_size %ld \n",sysfile.st_size);
  printf("\nArchivo st_nlink %u \n",(unsigned int)sysfile.st_nlink);
  printf("\nPermisos de usuarior\n");
  printf((sysfile.st_mode & S_IRUSR)? "r":"-");
  printf((sysfile.st_mode & S_IWUSR)? "w":"-");
  printf((sysfile.st_mode & S_IXUSR)? "x":"-");
  printf("\n");
  printf("\nPermisos de grupo\n");
  printf((sysfile.st_mode & S_IRGRP)? "r":"-");
  printf((sysfile.st_mode & S_IWGRP)? "w":"-");
  printf((sysfile.st_mode & S_IXGRP)? "x":"-");
  printf("\n");
  printf("\n Permisos de otros\n");
  printf((sysfile.st_mode & S_IROTH)? "r":"-");
  printf((sysfile.st_mode & S_IWOTH)? "w":"-");
  printf((sysfile.st_mode & S_IXOTH)? "x":"-");
  printf("\n");
}
