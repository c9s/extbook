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

