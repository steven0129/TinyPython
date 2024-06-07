#include <iostream>
#include <string>
#include <cctype>
#include "PyDictObject.h"
#include "PyStrObject.h"
#include "PyIntObject.h"
#include "PyObject.h"

using namespace std;

const char* info = "*********** Python Research ***********";
const char* prompt = ">> ";
string m_Command;
PyObject* m_LocalEnvironment;

void ExecuteCommand(const string&);
void ExecuteAdd(const string&, const string&);
PyObject* GetObjectBySymbol(const string&);
void ExecutePrint(const string);
bool isSourceAllDigit(const string& source);


int main() {
    cout << info << endl;
    cout << prompt;
    while(getline(cin, m_Command)) {
        if(m_Command.size() == 0) {
            cout << prompt;
            continue;
        } else if(m_Command == "exit") {
            return 0;
        } else {
            ExecuteCommand(m_Command);
        }

        cout << prompt;
    }
    return 0;
}

void ExecuteCommand(const string& command) {
    string::size_type pos = 0;
    if((pos = command.find("print ")) != string::npos) {
        ExecutePrint(command.substr(6));
    } else if((pos = command.find(" = ")) != string::npos) {
        string target = command.substr(0, pos);
        string source = command.substr(pos + 3);
        ExecuteAdd(target, source);
    }
}

void ExecuteAdd(const string& target, const string& source) {
    string::size_type pos;
    PyObject* strValue = NULL;
    PyObject* resultValue = NULL;
    if(isSourceAllDigit(source)) {
        PyObject* intValue = PyInt_Create(atoi(source.c_str()));
        PyObject* key = PyStr_Create(target.c_str());
        PyDict_SetItem(m_LocalEnvironment, key, strValue);
    } else if((pos = source.find("+")) != string::npos) {
        PyObject* leftObject = GetObjectBySymbol(source.substr(0, pos));
        PyObject* rightObject = GetObjectBySymbol(source.substr(pos + 1));
        if(leftObject != NULL && right != NULL && leftObject->type == rightObject->type) {
            resultValue = (leftObject->type)->add(leftObject, rightObject);
            PyObject* key = PyStr_Create(target.c_str());
            PyDict_SetItem(m_LocalEnvironment, key, resultValue);
        }

        (m_LocalEnvironment->type)->print(m_LocalEnvironment);
    }
}

PyObject* GetObjectBySymbol(const string& symbol) {
    PyObject* key = PyStr_Create(symbol.c_str());
    PyObject* value = PyDict_GetItem(m_LocalEnvironment, key);
    if(value == NULL) {
        cout << "[Error]: " << symbol << " is not defined" << endl;
        return NULL;
    }

    return value;
}

void ExecutePrint(const string symbol) {
    PyObject* object = GetObjectBySymbol(symbol);
    if(object != NULL) {
        PyTypeObject* type = object->type;
        type->print(object);
    }
}

bool isSourceAllDigit(const string& source) {
    for (char c : source) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}