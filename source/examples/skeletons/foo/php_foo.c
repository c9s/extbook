#include "php_foo.h"

PHP_MINIT_FUNCTION(foo);
PHP_MSHUTDOWN_FUNCTION(foo);
PHP_MINFO_FUNCTION(foo);

#if COMPILE_DL_FOO
ZEND_GET_MODULE(foo)
#endif


static const zend_function_entry foo_functions[] = {
    PHP_FE(foo_hello, NULL)
    PHP_FE_END
};

zend_module_entry foo_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "Foo",
    foo_functions,
    PHP_MINIT(foo),
    PHP_MSHUTDOWN(foo),
    NULL,
    NULL,
    PHP_MINFO(foo),
#if ZEND_MODULE_API_NO >= 20010901
    "0.1",
#endif
    STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(foo) {
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(foo) {
    return SUCCESS;
}

PHP_MINFO_FUNCTION(foo) {
}

PHP_FUNCTION(foo_hello) {
    RETURN_TRUE;
}


