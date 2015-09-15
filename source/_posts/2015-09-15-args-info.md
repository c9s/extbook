---
title: Defining ARG_INFO
---

The code below presents: `($environment, $response)`

~~~c
// ZEND_BEGIN_ARG_INFO_EX(name, _unused, return_reference, required_num_args)
ZEND_BEGIN_ARG_INFO_EX(arginfo_middleware_call, 0, 0, 2)
	ZEND_ARG_INFO(0, environment)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()
~~~

The code below presents: `(array & $environment, array $response)`

~~~c
ZEND_BEGIN_ARG_INFO_EX(arginfo_middleware_call, 0, 0, 2)
    // ZEND_ARG_ARRAY_INFO(pass_by_ref, name, allow_null)
    ZEND_ARG_ARRAY_INFO(1, environment, 0)
    ZEND_ARG_ARRAY_INFO(0, response, 0)
ZEND_END_ARG_INFO()
~~~

