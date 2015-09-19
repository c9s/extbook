---
title: Parse Callable Parameter
---

The code below is from php-src (`ext/standard/basic_functions.c`)

~~~ .cpp
zval *retval_ptr = NULL;
zend_fcall_info fci;
zend_fcall_info_cache fci_cache;

if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "f*", &fci, &fci_cache, &fci.params, &fci.param_count) == FAILURE) {
    return;
}

fci.retval_ptr_ptr = &retval_ptr;

if (zend_call_function(&fci, &fci_cache TSRMLS_CC) == SUCCESS && fci.retval_ptr_ptr && *fci.retval_ptr_ptr) {
    COPY_PZVAL_TO_ZVAL(*return_value, *fci.retval_ptr_ptr);
}

if (fci.params) {
    efree(fci.params);
}
~~~
