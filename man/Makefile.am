mandir = @mandir@

bin_PROGRAMS = texinfo2man
texinfo2man_SOURCES = texinfo2man.c
man_MANS = @PACKAGE@.1

EXTRA_DIST = $(man_MANS) @PACKAGE@.1.in

# --------------- Maintainer's Section

MAINTAINERCLEANFILES = @PACKAGE@.1 Makefile.in texinfo2man 

@PACKAGE@.1: @PACKAGE@.1.in ../doc/@PACKAGE@.texinfo texinfo2man  Makefile
	texinfo2man @PACKAGE@.1.in ../doc/@PACKAGE@.texinfo > $@

