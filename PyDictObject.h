#ifndef PYDICTOBJECT
#define PYDICTOBJECT

#include "PyTypeObject.h"
#include "PyObject.h"
#include <map>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagPyDictObject {
    PyObject_HEAD;
    std::map<long, PyObject*> dict;
} PyDictObject;

PyObject* PyDict_Create();
PyObject* PyDict_GetItem(PyObject*, PyObject*);
PyObject* PyDict_SetItem(PyObject*, PyObject*, PyObject*);
static void dict_print(PyObject*);
extern PyTypeObject PyDict_Type;

#ifdef __cplusplus
}
#endif

#endif