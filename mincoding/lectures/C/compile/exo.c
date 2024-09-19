#include <stdio.h>

//int __attribute__((weak)) ga = 22;
int ga __attribute__((weak)); = 22;

//#pragma comment(linker, "/alternatename:ga=_pDefaultWeakValue")
//https://stackoverflow.com/questions/2290587/gcc-style-weak-linking-in-visual-studio