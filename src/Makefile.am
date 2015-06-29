AUTOMAKE_OPTIONS = 1.2 gnits

bin_PROGRAMS = indent
indent_SOURCES = indent.c args.c backup.c comments.c lexi.c parse.c globs.c code_io.c output.c utils.c handletoken.c
noinst_HEADERS = indent.h args.h backup.h comments.h lexi.h parse.h globs.h code_io.h output.h utils.h sys.h libgettext.h handletoken.h
indent_LDADD =  $(INTLLIBS)
EXTRA_DIST = @PACKAGE@.gperf @PACKAGE@-cc.gperf wildexp.c gperf.c gperf-cc.c \
	     @PACKAGE@.dsp \
	     config.h.vc++ \
	     config.h.vms


BUILT_SOURCES = gperf.c gperf-cc.c
AM_CPPFLAGS = -I. -I$(srcdir) -I$(top_srcdir)/intl
DEFS = @DEFS@ -DLOCALEDIR=\"${localedir}\"
LIBS = @LIBINTL@ @LIBS@


MAINTAINERCLEANFILES= Makefile.in libgettext.h

AM_CFLAGS=-ansi -pedantic -Wall -Werror -Wredundant-decls -Wshadow
AM_CFLAGS+=-Wstrict-prototypes -Wmissing-prototypes -Wnested-externs
AM_CFLAGS+=-Wmissing-declarations -Wcomment -Wbad-function-cast
AM_CFLAGS+=-Wcast-align -I.

## Use -g when in maintainer mode
if MAINTAINER_MODE
AM_CFLAGS += -g
endif

gperf.c: indent.gperf
	@gperf -D -c -l -p -t -T -g -j1 -o -K rwd\
	       -L ANSI-C -N is_reserved indent.gperf > gperf.c
	@sed -ie 's/index/idx/g' gperf.c

gperf-cc.c: indent-cc.gperf
	@gperf -D -c -l -p -t -T -g -j1 -o -K rwd\
	       -L ANSI-C -N is_reserved_cc -H hash_cc\
	       indent-cc.gperf > gperf-cc.c
	@sed -ie 's/index/idx/g' gperf-cc.c

if MAINTAINER_MODE

config.h.vc++ config.h.vms @PACKAGE@.lsm :%: Makefile %.in
	sed -e 's%!VERSION!%@VERSION@%g' $@.in > $@

@PACKAGE@.dsp: @PACKAGE@.dsp.in
	cat $< | perl -e 'while (<>) {chomp; print "$$_\015\012"; }'  > $@
endif

