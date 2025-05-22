# Laboratorio de OpenMP

## Descripción

Este programa demuestra el uso básico de OpenMP para paralelizar un bucle `for` y un bloque de impresión con múltiples hilos. El usuario especifica el número de hilos desde la línea de comandos. Se realiza una operación paralela simple para ilustrar cómo funciona la paralelización y la gestión de variables en memoria compartida.

---

## Compilación

Usar el siguiente comando en terminal:

```bash
gcc -fopenmp programa.c -o ejecutable
