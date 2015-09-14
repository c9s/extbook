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

Here is the content of `php_foo.c`, a minimal extension source code must contains a `zend_module_entry`,
And you usually need to define `zend_function_entry` to declare your extension functions:

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
    foo_functions, // where you define your functions
    PHP_MINIT(foo),
    PHP_MSHUTDOWN(foo),
    NULL, // PHP_RINIT(foo)
    NULL, // PHP_RSHUTDOWN(foo)
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

Compile it!

~~~sh
phpize
./configure
make
~~~


