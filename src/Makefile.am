AUTOMAKE_OPTIONS = 1.2 gnits

bin_PROGRAMS = indent
indent_SOURCES = indent.c args.c backup.c comments.c lexi.c parse.c globs.c code_io.c output.c utils.c
noinst_HEADERS = indent.h args.h backup.h comments.h lexi.h parse.h globs.h code_io.h output.h utils.h sys.h libgettext.h
indent_LDADD =  $(INTLLIBS)
EXTRA_DIST = @PACKAGE@.gperf @PACKAGE@-cc.gperf wildexp.c gperf.c gperf-cc.c \
	     @PACKAGE@.dsp \
	     config.h.vc++ \
	     config.h.vms


BUILT_SOURCES = gperf.c gperf-cc.c
INCLUDES = -I. -I$(srcdir) -I$(top_srcdir)/intl
DEFS = @DEFS@ -DLOCALEDIR=\"${localedir}\"
LIBS = @LIBINTL@ @LIBS@


MAINTAINERCLEANFILES= Makefile.in


gperf.c: indent.gperf
	gperf -D -c -l -p -t -T -g -j1 -o -K rwd -N is_reserved indent.gperf > gperf.c

gperf-cc.c: indent-cc.gperf
	gperf -D -c -l -p -t -T -g -j1 -o -K rwd -N is_reserved_cc -H hash_cc indent-cc.gperf > gperf-cc.c

if MAINTAINER_MODE

config.h.vc++ config.h.vms @PACKAGE@.lsm :%: Makefile %.in
	sed -e 's%!VERSION!%@VERSION@%g' $@.in > $@

@PACKAGE@.dsp: @PACKAGE@.dsp.in
	cat $< | perl -e 'while (<>) {chomp; print "$$_\015\012"; }'  > $@
endif

