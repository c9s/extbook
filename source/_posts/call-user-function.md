---
title: call_user_function_ex
---

~~~c
	zval *retval_ptr;
	zval ***args;
	int status;
    zval *option_array;

	if (!option_array || !zend_is_callable(option_array, IS_CALLABLE_CHECK_NO_ACCESS, NULL TSRMLS_CC)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "First argument is expected to be a valid callback");
		zval_dtor(value);
		Z_TYPE_P(value) = IS_NULL;
		return;
	}

	args = safe_emalloc(sizeof(zval **), 1, 0);
	args[0] = &value;
	
    // function table, object ptr, option_array = callback, n_params, params
	status = call_user_function_ex(EG(function_table), NULL, option_array, &retval_ptr, 1, args, 0, NULL TSRMLS_CC);

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

	efree(args);
~~~
