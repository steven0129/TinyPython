#ifndef PYTYPEOBJECT
#define PYTYPEOBJECT

#include "PyObject.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*PrintFun)(PyObject* object);
typedef PyObject* (*AddFun)(PyObject* left, PyObject* right);
typedef long (*HashFun)(PyObject* object);

typedef struct tagPyTypeObject {
    PyObject_HEAD;
    const char* name;
    PrintFun print;
    AddFun add;
    HashFun hash;
} PyTypeObject;

extern PyTypeObject PyType_Type;

#ifdef __cplusplus
}
#endif

#endif