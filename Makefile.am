## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = no-texinfo.tex

bin_PROGRAMS = indent
indent_SOURCES = args.c comments.c indent.c lexi.c parse.c backup.c globs.c io.c
noinst_HEADERS = backup.h indent.h sys.h lexi.h args.h comments.h globs.h io.h parse.h

info_TEXINFOS = indent.texinfo
man_MANS = indent.1

BUILT_SOURCES = indent.1 README ChangeLog gperf.c gperf-cc.c indent.html indent_foot.html indent_toc.html
EXTRA_DIST = $(BUILT_SOURCES) indent.gperf indent-cc.gperf ChangeLog-1990 ChangeLog-1998

lexi.o: $(srcdir)/lexi.c $(srcdir)/sys.h config.h $(srcdir)/indent.h @MAINTAINER_MODE_TRUE@ gperf.c gperf-cc.c
	$(COMPILE) -c $(srcdir)/lexi.c

gperf.c: @MAINTAINER_MODE_TRUE@ indent.gperf
	gperf -D -c -p -t -T -g -j1 -o -K rwd -N is_reserved indent.gperf > gperf.c

gperf-cc.c: @MAINTAINER_MODE_TRUE@ indent-cc.gperf
	gperf -D -c -p -t -T -g -j1 -o -K rwd -N is_reserved_cc -H hash_cc indent-cc.gperf > gperf-cc.c

DISTCLEANFILES=config.cache config.log config.h

# --------------- Maintainer's Section

MAINTAINERCLEANFILES=aclocal.m4 Makefile.in config.h.in stamp-h.in configure \
	ChangeLog texinfo2man indent.1 gperf.c gperf-cc.c \
	indent-1.spec index.html cvslog-*.html indent.html indent_*.html

## Use -g when in maintainer mode
if MAINTAINER_MODE
CFLAGS=-g
else
CFLAGS=@CFLAGS@
endif

## Bug in automake: Can't use `if MAINTAINER_MODE'
@MAINTAINER_MODE_TRUE@include $(srcdir)/maintMakefile

## Can't put this in the maintMakefile for some reason.
maintainer-clean-local:
	echo "all:" > Makefile
	echo -e "\tautoheader" >> Makefile
	echo -e "\tautomake --foreign" >> Makefile
	echo -e "\taclocal" >> Makefile
	echo -e "\tautoconf" >> Makefile
	echo -e "\tautoheader" >> Makefile
	echo -e "\tconfigure --enable-maintainer-mode --prefix=/home/carlo" >> Makefile
