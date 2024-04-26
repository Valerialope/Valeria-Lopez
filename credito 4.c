#include <stdio.h>

void obtener_datos(double *monto, double *tasa_interes, int *tiempo) {
    printf("Ingrese el monto del credito: ");
    scanf("%lf", monto);
    printf("Ingrese la tasa de interes: ");
    scanf("%lf", tasa_interes);
    printf("Ingrese el tiempo (en años): ");
    scanf("%d", tiempo);
}

void imprimir_tabla(double monto, double tasa_interes, int tiempo) {
    double interes_anual, cuota_mensual, monto_anual = monto / tiempo;
    double monto_inicial = monto;

    printf("Año\tInteres\tCuota Mensual\n");
    for(int i = 1; i <= tiempo; i++) {
        interes_anual = monto_inicial * tasa_interes;  
        monto_inicial -= monto_anual;
        cuota_mensual = (monto_anual + interes_anual) / 12;
        printf("%d\t%.2f\t\t%.2f\n", i, interes_anual, cuota_mensual);
    }
}

int main() {
    double monto, tasa_interes;
    int tiempo;

    obtener_datos(&monto, &tasa_interes, &tiempo);
    imprimir_tabla(monto, tasa_interes, tiempo);

    return 0;
}