/*
**所有方法均排偶
*/
#ifndef GETPRIME_H
#define GETPRIME_H

#ifdef SIMPLE
void getPrime_simple(int n);
#endif

#ifdef SQRT
void getPrime_sqrt(int n);
#endif

#ifdef ERATOSTHENES
void getPrime_eratosthenes(int n);
#endif

#ifdef LINEAR
void getPrime_linear(int n);
#endif

#ifdef SEGMENT
void getPrime_segment(int n);
#endif

#ifdef EULER
void getPrime_euler(int n);
#endif

#ifdef BITMAP
void getPrime_bitwise(int n);
#endif

#ifdef PARALLEL
void getPrime_parallel(int n);
#endif

#endif