AUTOMAKE_OPTIONS = 1.2 gnits

bin_PROGRAMS = indent
indent_SOURCES = args.c comments.c indent.c lexi.c parse.c backup.c globs.c io.c
noinst_HEADERS = backup.h indent.h sys.h lexi.h args.h comments.h globs.h io.h parse.h
indent_LDADD =  $(INTLLIBS)
EXTRA_DIST = @PACKAGE@.gperf @PACKAGE@-cc.gperf wildexp.c gperf.c gperf-cc.c \
	     @PACKAGE@.dsp \
	     config.h.vc++ \
	     config.h.vms


#BUILT_SOURCES = gperf.c gperf-cc.c
INCLUDES = -I. -I$(srcdir) -I.. -I../intl -I$(top_srcdir)/intl
DEFS = @DEFS@ -DLOCALEDIR=\"${localedir}\"


MAINTAINERCLEANFILES= gperf.c gperf-cc.c Makefile.in

if MAINTAINER_MODE

gperf.c: @MAINTAINER_MODE_TRUE@ indent.gperf
	gperf -D -c -l -p -t -T -g -j1 -o -K rwd -N is_reserved indent.gperf > gperf.c

gperf-cc.c: @MAINTAINER_MODE_TRUE@ indent-cc.gperf
	gperf -D -c -l -p -t -T -g -j1 -o -K rwd -N is_reserved_cc -H hash_cc indent-cc.gperf > gperf-cc.c

config.h.vc++ config.h.vms @PACKAGE@.lsm :%: Makefile %.in
	sed -e 's%!VERSION!%@VERSION@%g' $@.in > $@

@PACKAGE@.dsp: @PACKAGE@.dsp.in
	cat $< | perl -e 'while (<>) {chomp; print "$$_\015\012"; }'  > $@
endif

