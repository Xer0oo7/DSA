#include <stdio.h>

struct Term {
int coeff;
int exp;
};

int main() {
struct Term poly1[10], poly2[10], result[20];
int n1, n2, n3 = 0;
int i = 0, j = 0;

printf("Enter number of terms in 1st polynomial: ");
scanf("%d", &n1);
for (int k = 0; k < n1; k++) {
printf("Enter coefficient and exponent for term %d: ", k + 1);
scanf("%d %d", &poly1[k].coeff, &poly1[k].exp);
}

printf("Enter number of terms in 2nd polynomial: ");
scanf("%d", &n2);
for (int k = 0; k < n2; k++) {
printf("Enter coefficient and exponent for term %d: ", k + 1);
scanf("%d %d", &poly2[k].coeff, &poly2[k].exp);
}

while (i < n1 && j < n2) {
if (poly1[i].exp == poly2[j].exp) {
result[n3].coeff = poly1[i].coeff + poly2[j].coeff;
result[n3].exp = poly1[i].exp;
i++; j++;
} else if (poly1[i].exp > poly2[j].exp) {
result[n3] = poly1[i];
i++;
} else {
result[n3] = poly2[j];
j++;
}
n3++;
}

while (i < n1) result[n3++] = poly1[i++];
while (j < n2) result[n3++] = poly2[j++];

printf("\nSum of polynomials: ");
for (int k = 0; k < n3; k++) {
printf("%dx^%d", result[k].coeff, result[k].exp);
if (k != n3 - 1) printf(" + ");
}
printf("\n");

return 0;
}