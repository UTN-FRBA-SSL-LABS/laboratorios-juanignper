#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};    /* 200 x 3 = 600 */
    Producto p2 = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    int total = carrito_total(&c);     /* total = 1300 */
    int total_descuento = carrito_descuento(total, 10);   /* total_descuento = 1170 */
    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, total_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));   /* devuelve 0 = fallo */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
