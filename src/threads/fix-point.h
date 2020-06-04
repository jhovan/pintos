#ifndef THREADS_FIX_POINT_H_
#define THREADS_FIX_POINT_H_

#include <stdint.h>

#define FRACT_BITS 14 // Amount of bits used for the decimal part of the number 
#define F_CONST 16384 // Equivalent to 2**14

/* Convierte un entero en un numero equivalente en representacion de punto fijo 17.14 */
#define INT_TO_FIXPOINT(n)   ((n) * F_CONST )
/* Convierte una fraccion en un numero equivalente en representacion de punto fijo 17.14 */
#define FRACT_TO_FIXPOINT(n, m) (INT_TO_FIXPOINT(n) / (m))
/* Convierte un número en representacion de punto fijo 17.14 a un entero truncando su parte decimal */
#define TRUNCATE(x)     ((x) / F_CONST)
/* Convierte un número en representacion de punto fijo 17.14 a un entero redondeando */
#define ROUND(x)    ((x) >= 0 ? (((x) + F_CONST/2)/F_CONST) : (((x) - F_CONST/2)/F_CONST))
/* Suma dos números en representacion de punto fijo 17.14 */
#define ADD_FP(x, y)     ((x) + (y))
/* Suma un número en representacion de punto fijo 17.14 y un entero */
#define ADD_INT(x, n)       ((x) + INT_TO_FIXPOINT(n))
/* Resta dos números en representacion de punto fijo 17.14 */
#define SUB_FP(x, y)     ((x) - (y))
/* Resta un entero a un números en representacion de punto fijo 17.14 */
#define SUB_INT(x, n)        ((x) - INT_TO_FIXPOINT(n))
/* Multiplica dos numeros en representacion de punto fijo 17.14 */
#define MULT_FP(x, y)       ((((int64_t) x) * (y)) / F_CONST)
/* Multiplica un numero en representacion de punto fijo 17.14 por un entero*/
#define MULT_INT(x, n)        ((x) * (n))
/* Divide dos numeros en representacion de punto fijo 17.14 */
#define DIV_FP(x, y)        ((((int64_t) x) * F_CONST ) / (y))
/* Divide un numero en representacion de punto fijo 17.14 por un entero*/
#define DIV_INT(x, n)       ((x) / (n))

#endif
