#ifndef PYSTROBJECT
#define PYSTROBJECT

#include "PyObject.h"
#include "PyTypeObject.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagPyStrObject {
    PyObject_HEAD;
    int length;
    long hashValue;
    char value[50];
} PyStringObject;

PyObject* PyStr_Create(const char*);
static void string_print(PyObject*);
static long string_hash(PyObject*);
static PyObject* string_add(PyObject*, PyObject*);

extern PyTypeObject PyString_Type;


#ifdef __cplusplus
}
#endif

#endif