---
title: Defining ARG_INFO for object parameters
---


~~~ .cpp

// ZEND_ARG_OBJ_INFO(pass_by_ref, name, classname, allow_null)
ZEND_BEGIN_ARG_INFO_EX(arginfo_test, 0, 0, 3)
    ZEND_ARG_INFO(0, firstArg)
    ZEND_ARG_OBJ_INFO(0, objStdClassNonNull, stdClass, 0)
    ZEND_ARG_OBJ_INFO(0, objStdClass, stdClass, 1)
    ZEND_ARG_OBJ_INFO(1, objStdClassByRef, stdClass, 1)
ZEND_END_ARG_INFO()
~~~
