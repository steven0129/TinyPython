#ifndef PYINTOBJECT
#define PYINTOBJECT

#include "PyObject.h"
#include "PyTypeObject.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagPyIntObject {
    PyObject_HEAD;
    int value;
} PyIntObject;

PyObject* PyInt_Create(int);
static void int_print(PyObject*);
static PyObject* int_add(PyObject*, PyObject*);
static long int_hash(PyObject*);

extern PyTypeObject PyInt_Type;

#ifdef __cplusplus
}
#endif

#endif