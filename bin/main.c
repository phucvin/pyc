#define PY_SSIZE_T_CLEAN
#include <Python.h>

inline PyObject *PYC_Print(PyObject *o) {
  PyObject_Print(o, stdout, Py_PRINT_RAW);
  printf("\n");
  Py_INCREF(Py_None);
  return Py_None;
}

PyObject *fib_0(PyObject *n_1) {
  PyObject *boolop_2;
  PyObject *compare_4 = n_1;
  PyObject *num_5 = PyLong_FromLong(0);
  compare_4 = PyObject_RichCompare(compare_4, num_5, Py_EQ);
  boolop_2 = compare_4;
  if (PyObject_IsTrue(compare_4)) {
    goto done_or_3;
  }
  PyObject *compare_6 = n_1;
  PyObject *num_7 = PyLong_FromLong(1);
  compare_6 = PyObject_RichCompare(compare_6, num_7, Py_EQ);
  boolop_2 = compare_6;
  if (PyObject_IsTrue(compare_6)) {
    goto done_or_3;
  }
done_or_3:

  if (PyObject_IsTrue(boolop_2)) {

    return n_1;
  }

  PyObject *binop_8;
  PyObject *binop_9;
  PyObject *num_10 = PyLong_FromLong(1);
  binop_9 = PyNumber_Subtract(n_1, num_10);
  PyObject *call_result_11 = fib_0(binop_9);
  PyObject *binop_12;
  PyObject *num_13 = PyLong_FromLong(2);
  binop_12 = PyNumber_Subtract(n_1, num_13);
  PyObject *call_result_14 = fib_0(binop_12);
  binop_8 = PyNumber_Add(call_result_11, call_result_14);

  return binop_8;
}

PyObject *main_1() {
  PyObject *num_2 = PyLong_FromLong(40);
  PyObject *call_result_3 = fib_0(num_2);
  PyObject *call_result_4 = PYC_Print(call_result_3);
  // noop to hide unused warning
  call_result_4 += 0;
  return Py_None;
}

int main(int argc, char *argv[]) {
  Py_Initialize();

  // Initialize globals, if any.

  PyObject *r = main_1();
  return PyLong_AsLong(r);
}