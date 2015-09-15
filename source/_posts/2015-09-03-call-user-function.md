---
title: calling user functions
---

``` .cpp

// retval_ptr is used for the return value of the function call.
zval *retval_ptr;

// params for the function call.
zval ***params;

// just one parameter
int n_params = 1;

// status is used for detecting function call's return status 
int status;

// the function call (callback)
zval *cb_array;

if (!cb_array || !zend_is_callable(cb_array, IS_CALLABLE_CHECK_NO_ACCESS, NULL TSRMLS_CC)) {
    php_error_docref(NULL TSRMLS_CC, E_WARNING, "First argument is expected to be a valid callback");
    zval_dtor(value);
    Z_TYPE_P(value) = IS_NULL;
    return;
}

params = safe_emalloc(sizeof(zval **), n_params, 0);
params[0] = &value;


// You can replace EG(function_table) with the function table of a class entry if you're calling a class method.
/* function table, object ptr, cb_array = callback, n_params, params */
status = call_user_function_ex(EG(function_table), NULL, cb_array, &retval_ptr, n_params, params, 0, NULL TSRMLS_CC);

// free the params
efree(params);

// copy retval zval to the zval we need to use.
if (status == SUCCESS && retval_ptr != NULL) {
    if (retval_ptr != value) {
        zval_dtor(value);
        COPY_PZVAL_TO_ZVAL(*value, retval_ptr);
    } else {
        zval_ptr_dtor(&retval_ptr);
    }
} else {
    zval_dtor(value);
    Z_TYPE_P(value) = IS_NULL;
}

```
