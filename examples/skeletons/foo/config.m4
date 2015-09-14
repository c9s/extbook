dnl vim:sw=2:ts=2:sts=2:
PHP_ARG_ENABLE(foo, whether to enable foo extension support,
  Make sure that the comment is aligned:
  [ --enable-foo Enable foo extension support])
PHP_NEW_EXTENSION(foo, php_foo.c, $ext_shared)
