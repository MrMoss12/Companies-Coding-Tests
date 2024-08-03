#include <stdio.h>

// Función para calcular las maneras de subir N escalones
int climbStairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    int ways[n+1];
    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {
        ways[i] = ways[i-1] + ways[i-2];
    }

    return ways[n];
}

int main() {
    int n;
    scanf("%d", &n); // Leer el número de escalones desde el input estándar

    int result = climbStairs(n);
    printf("%d\n", result); // Imprimir el número de maneras distintas

    return 0;
}
