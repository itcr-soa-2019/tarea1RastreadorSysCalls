# Tarea Corta #1
TAREA 1: RASTREADOR DE “System Calls”

El proposito de esta tarea individual es darle familiaridad con el ambiente Linux y aplicaciones de Sistemas Operativos.

Toda la programacion debe realizarse en C sobre Linux. Su programa tendra la misión de poner a ejecutar a otro programa (digamosle Prog), pasarle los argumentos seleccionados por el usuario y rastrear todos los system calls utilizados por Prog.

La sintaxis de ejecucion desde línea de comando es:
```
rastreador [opciones rastreador] Prog
[opciones de Prog]
```
Las opciones de rastreador son:

* **-v** desplegará un mensaje cada vez que detecte un System Call de Prog . Se debe desplegar la mayor cantidad posible de detalles respecto a cada System Call.
* **-V** sera idéntico a la opción -v , pero hará una pausa hasta que el usuario presione cualquier tecla para continuar la ejecucion de Prog .

## Como ejecutar el rastreador 
Este se distribuye en una carpeta con el siguiente contenido:
* Makefile
* LICENSE
* /src
* /bin
Para ejecutar el programa debe ejecutar el comando ```make``` en la raiz de la carpeta del proyecto.
```bash
$ make
```
Esto deberá generar el archivo compilado en la carpeta /bin.

Para ejecutar el programa desde la carpeta del proyecto:
```bash
$./bin/rastreador [opciones rastreador] PROG [opciones de prog]
```
### Ejemplo de Ejecución
Verificamos las llamadas del sistema del comando ```date -u ``` para mostrar la fecha del sistema en utc.
```bash
>$ ./bin/rastreador -v date -u

sáb 16 feb 03:46:15 UTC 2019
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         1           read
  0.00    0.000000           0         1           write
  0.00    0.000000           0         5           close
  0.00    0.000000           0         4           fstat
  0.00    0.000000           0         8           mmap
  0.00    0.000000           0         4           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         3         3 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0         1           clock_gettime
  0.00    0.000000           0         4         1 openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    37         4 total
```
