#ifndef PYOBJECT
#define PYOBJECT

#ifdef __cplusplus
extern "C" {
#endif

#define PyObject_HEAD \
    int refCount;\
    struct tagPyTypeObject *type

#define PyObject_HEAD_INIT(typePtr)\
    0, typePtr

typedef struct tagPyObject {
    PyObject_HEAD;
} PyObject;

#ifdef __cplusplus
}
#endif

#endif