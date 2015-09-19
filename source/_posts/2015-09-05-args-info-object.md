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

The code above creates the following function prototype:

~~~ .php

function sample_with_types($firstArg, stdClass $objStdClassNonNull, stdClass $objStdClass = null, stdClass & $objStdClassByRef) {
    // ...
}
~~~

It has the following effects:

~~~ .cpp
sample_with_types();                          // ok
sample_with_types(1, null);                   // error: arg #2 should be stdClass
sample_with_types(1, new stdClass, null);     // ok
sample_with_types(1, new stdClass, 1);        // error: arg #3 should be stdClass
sample_with_types(1, new stdClass, null, 2);  // error: arg #4 must be reference
~~~

