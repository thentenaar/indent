mandir = @mandir@

man_MANS = @PACKAGE@.1

EXTRA_DIST = $(man_MANS)

# --------------- Maintainer's Section

MAINTAINERCLEANFILES = @PACKAGE@.1 Makefile.in texinfo2man 

if MAINTAINER_MODE
@PACKAGE@.1: @PACKAGE@.1.in ../doc/@PACKAGE@.texinfo texinfo2man  Makefile
	texinfo2man @PACKAGE@.1.in ../doc/@PACKAGE@.texinfo > $@

texinfo2man: texinfo2man.c
	$(CC) -g -o $@ $?
endif
