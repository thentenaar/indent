## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = no-texinfo.tex

SUBDIRS = intl src doc po man

BUILT_SOURCES = 

EXTRA_DIST = 	README \
		config/config.rpath config/mkinstalldirs \
		ChangeLog-1990 ChangeLog-1998 ChangeLog-2001 \
		miscel/make-decc.com miscel/vaxc-make.com miscel/gnuc-make.com \
		aclocal/UTIMBUF.m4 \
		miscel/Makefile.mingw32 \
		miscel/makefile.watcom \
		miscel/README.vc++ \
		miscel/README.VMS \
		bootstrap \
		regression

DISTCLEANFILES=config/config.cache config/config.log config.h

ps:
	cd doc && $(MAKE) @PACKAGE@.ps

pdf:
	cd doc && $(MAKE) @PACKAGE@.pdf

html:
	cd doc && $(MAKE) html

html-split:
	cd doc && $(MAKE) html-split

# --------------- Maintainer's Section

MAINTAINERCLEANFILES = intl/* aclocal.m4 Makefile.in config.h.in stamp-h1 stamp-h.in configure \
	@PACKAGE@-1.spec \
	@PACKAGE@.lsm indent-2.spec .gdbinit \
	INSTALL ABOUT-NLS 

## Use -g when in maintainer mode
if MAINTAINER_MODE
CFLAGS=-g -I.
else
CFLAGS=@CFLAGS@ -I.
endif

if MAINTAINER_MODE
README: Makefile miscel/README.in configure.ac
	sed -e 's%!VERSION!%@VERSION@%g'  miscel/$@.in > $@


miscel/Makefile.mingw32 miscel/makefile.watcom :%: %.in
	cat $@.in | perl -e 'while (<>) {chomp; print "$$_\015\012"; }'  > $@

miscel/README.vc++ miscel/README.VMS @PACKAGE@.lsm :%: Makefile %.in
	sed -e 's%!VERSION!%@VERSION@%g' $@.in > $@

tar:
	$(MAKE) dist
	install -D @PACKAGE@-@VERSION@.tar.gz $(REDHAT)/SOURCES/@PACKAGE@-@VERSION@.tar.gz

WWWDIR=/home/david/www/@PACKAGE@
REDHAT:=$(shell grep '^%_topdir' rpm/macros | cut -d \  -f 2)
SPECFILE=@PACKAGE@-${shell echo "@VERSION@" | cut -d. -f1}.spec

rpm: tar $(SPECFILE)
	rpm --rcfile=/usr/lib/rpm/rpmrc:rpm/rpmrc --target=$(TARGET) --sign --clean -ba $(SPECFILE)

$(SPECFILE): rpm/$(SPECFILE).in configure.ac
	cvs commit rpm/$(SPECFILE).in
	sed -e 's/!VERSION!/@VERSION@/g' rpm/$(SPECFILE).in | grep -B2000 '!CHANGELOG!' | grep -v '!CHANGELOG!' > $(SPECFILE)
	echo -n "%changelog" >> $(SPECFILE)
	cvs log rpm/$(SPECFILE).in | \
	  grep -A2000 '^-----' | \
	  egrep -v '^-----|^=====|^revision' | \
	  awk -F'[ ;]' --assign lastdate="" '{ if ($$0~/^date: /) { \
	    if (lastdate != $$2) { \
	      lastdate=$$2; \
	      printf("\n* "); \
	      system("echo -n `date --date \""$$2" "$$3"\" \"+%a %b %d %Y\"`"); \
	      printf(" $(AUTHOR)\n"); \
	    } \
	  } else if ($$0~/^[A-Z]/) { printf("- %s\n", $$0); } else if ($$0~/./) { printf("  %s\n", $$0); } else {print} }' >> $(SPECFILE)
	grep -A2000 '!CHANGELOG!' rpm/$(SPECFILE).in | grep -v '!CHANGELOG!' >> $(SPECFILE)

endif


ACLOCAL_AMFLAGS = -I m4
