#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNumeroPrimo(){
    int numEvaluado;
    printf("Escriba un numero: ");
    scanf("%d", &numEvaluado);
    if (numEvaluado == 0 || numEvaluado == 1) return 1;
    for (int i = 2; i < numEvaluado; ++i){
        if (numEvaluado % i == 0){
            return 0;
        }
    }
    return 1;
}

int leapYear(){
    int numAnual;
    printf("Escriba un numero anuario: ");
    scanf("%d", &numAnual);
    if (numAnual % 400 == 0) return 1;
    else if (numAnual % 100 == 0) return 0;
    else if (numAnual % 4 == 0) return 1;
    else return 0;
}

int factorialRecursiva(int n){
    if (n==1){
        return n;
    } else {
        return n*factorialRecursiva(n-1);
    }
}

int potenciaRecursiva(int base, int exp){
    if (exp==1){
        return base;
    } else {
        return base * potenciaRecursiva(base, exp-1);
    }
}

void imprimirFibonacci(int max){
    int termino1 = 0, termino2 = 1;
    int sgteTermino = termino1 + termino2;
    printf("Series de Fibonacci: %d, %d, ", termino1, termino2);
    for (int i = 3; i <= max; ++i) {
        if (i < max) printf("%d, ", sgteTermino);
        else if (i == max) printf("%d\n", sgteTermino);
        termino1 = termino2;
        termino2 = sgteTermino;
        sgteTermino = termino1 + termino2;
    }
    return;
}

void esMayuscula(char caracter){
    if (caracter >= 'A' && caracter <= 'Z') {
        printf("La letra es mayuscula. \n");
    } else {
        printf("La letra no es mayuscula. \n");
    }
    return;
}

void esMinuscula(char caracter){
    if (caracter >= 'a' && caracter <= 'z') {
        printf("La letra es minuscula. \n");
    } else {
        printf("La letra no es minuscula. \n");
    }
    return;
}

int mayorDeTres(int num1, int num2, int num3){
    if (num1 > num2 && num1 > num3){
        return num1;
    }
    else if (num2 > num1 && num2 > num3){
        return num2;
    }
    else if (num3 > num1 && num3 > num2){
        return num3;
    }
}

void ejemploTypeCasting(){
    int a = 15, b = 2;
    char x = 'a';
    double div;
    printf("Valor implicito: %c\n", x);
    printf("Valores explicitos: %d %d\n", a, b);

    // Casting implicito
    x = x + 3;
    // Casting explicito
    div = (double) a / b;

    printf("Resultado implicito (x = x + 3): %c\n", x);
    printf("Resultado explicito (div = (double) a/b): %f\n", div);
    return;
}

void imprimirEnFormatos(int modo){
    switch(modo){
        case 1:
            for (int i = 0; i <= 10; i++){
                printf("%d ", i);
            }
            break;
        case 2:
            for (int i = 0; i <= 10; i++){
                printf("%o ", i);
            }
            break;
        case 3:
            for (int i = 0; i <= 10; i++){
                printf("%X ", i);
            }
            break;
    }
    return;
}

void exerciseSelector(int option){
    int esPrimo;
    int esLeapYear;
    int numBaseDeFactorial, numResultado1;
    int numBase, numExponente, numResultado2;
    int numNormal;
    int numMax;
    int num1, num2, num3, numResultado;
    int numModo;
    char letra1, letra2;

    switch(option){
        case 2:
            esPrimo = esNumeroPrimo();
            if (esPrimo == 1){
                printf("Ese numero es primo.");
            } else if (esPrimo == 0){
                printf("Ese numero no es primo.");
            }
            break;
        case 3:
            esLeapYear = leapYear();
            if (esLeapYear == 1){
                printf("Ese es un bisiesto.");
            } else if (esLeapYear == 0){
                printf("Ese no es un bisiesto.");
            }
            break;
        case 4:
            printf("Escribe el numero al que se le calculara el factorial: ");
            scanf("%d", &numBaseDeFactorial);
            numResultado1 = factorialRecursiva(numBaseDeFactorial);
            printf("El resultado fue: %d\n", numResultado1);
            break;
        case 5:
            printf("Escribe la base y el exponente potenciador: ");
            scanf("%d %d", &numBase, &numExponente);
            numResultado2 = potenciaRecursiva(numBase, numExponente);
            printf("El resultado fue: %d\n", numResultado2);
            break;
        case 6: // El punto 6 es lo suficientemente sencillo que no requiere de una funcion externa
            printf("Escribe un numero: ");
            scanf("%d", &numNormal);
            int numEvaluado = numNormal % 2;
            if (numEvaluado==1){
                printf("El numero es impar.");
            } else if (numEvaluado==0){
                printf("El numero es par.");
            }
            break;
        case 7:
            printf("Escriba el n-esimo valor para limitar la impresion la serie Fibonacci: ");
            scanf("%d", &numMax);
            imprimirFibonacci(numMax);
            break;
        case 8:
            scanf(" %c", &letra1);
            esMayuscula(letra1);
            break;
        case 9:
            scanf(" %c", &letra2);
            esMinuscula(letra2);
            break;
        case 10:
            printf("Escriba 3 numeros: ");
            scanf("%d %d %d", &num1, &num2, &num3);
            numResultado = mayorDeTres(num1, num2, num3);
            printf("El numero mayor de los seleccionados es %d\n", numResultado);
            break;
        case 11:
            ejemploTypeCasting();
            break;
        case 12:
            printf("Este es un selector de modos de impresion de numeros. \n - 1: Decimal\n - 2: Octal\n - 3: Hexadecimal\n");
            printf("Selecciona el modo segun lo explicado: ");
            scanf("%d", &numModo);
            imprimirEnFormatos(numModo);
            break;
        default:
            printf("Ese no es un numero valido. Intentalo de nuevo.");
            break;
    }
    return;
}

int main(){
    int exerciseOption;
    printf("Este codigo ejecuta los ejercicios de practica de C, uno a la vez. (El 1 es ignorable) \n");
    printf("Selecciona un numero desde el 2 al 12: ");
    scanf("%d", &exerciseOption);
    exerciseSelector(exerciseOption);
    return 0;
}
