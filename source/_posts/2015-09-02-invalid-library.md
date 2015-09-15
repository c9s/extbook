---
title: Extension Skeleton
categories:
- troubleshooting
---

If you encountered this error while running `make test` or loading extension:

~~~
PHP Warning:  PHP Startup: Invalid library (maybe not a PHP library) 'phpsgi.so' in Unknown on line 0
~~~


Be sure to check you defined this:

~~~c
#if COMPILE_DL_FOO
ZEND_GET_MODULE(foo)
#endif
~~~

