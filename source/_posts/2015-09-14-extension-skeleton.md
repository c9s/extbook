---
title: Extension Skeleton
categories:
- extension
---
To create an extension, you will need at least three files:

- `config.m4`
- `ext_foo.c`
- `ext_foo.h`

Here is a initial content of `config.m4`:

~~~m4
dnl vim:sw=2:ts=2:sts=2:
PHP_ARG_ENABLE(foo, whether to enable foo extension support,
  [--enable-foo Enable foo extension support])
PHP_NEW_EXTENSION(foo, php_foo.c, $ext_shared)
~~~


here is the content of `php_foo.h`:

~~~c
#ifndef _PHP_FOO_H
#define _PHP_FOO_H
#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#ifdef ZTS
    #warning php_ext_uv module will *NEVER* be thread-safe
    #include <TSRM.h>
#endif

#include <php.h>

extern zend_module_entry foo_module_entry;

PHP_FUNCTION(foo_hello);

#endif
~~~


here is the content of `php_foo.c`:

~~~c
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

~~~

