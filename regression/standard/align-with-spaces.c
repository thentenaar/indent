static void
really_long_function_decl (const char *string_here, int integer_here,
                           unsigned long xxx)
{
	if (errno == ENOMEM) {
		ERROR ("unable to allocate memory for a new xxx "
		       "because %s", strerror (errno));
	}
}
