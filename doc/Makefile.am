## Process this file with automake to produce Makefile.in.

info_TEXINFOS = indent.texinfo

docdir = $(prefix)/doc/@PACKAGE@
dvidir = $(docdir)
psdir = $(docdir)
pdfdir = $(docdir)
htmldir = $(docdir)
HTMLSTYLE = monolithic

AUTOMAKE_OPTIONS = 1.2 gnits

EXTRA_DIST = @PACKAGE@.html

SED = sed
RM = rm -f

MAKEINFO = env LANG= LANGUAGE= @MAKEINFO@

all-local: html
install-data-local: install-html
installdirs-local: installdirs-html
uninstall-local: uninstall-html

html: html-$(HTMLSTYLE)
install-html: install-html-$(HTMLSTYLE)
uninstall-html: uninstall-html-$(HTMLSTYLE)

TEXI2HTML = @TEXI2HTML@

# BUILT_SOURCES = @PACKAGE@.1 @PACKAGE@.html @PACKAGE@_toc.html
html-monolithic: @PACKAGE@.html
html-split: @PACKAGE@_toc.html

@PACKAGE@.html: version.texi $(@PACKAGE@_TEXINFOS)
	$(TEXI2HTML) -expandinfo -number -monolithic `if test -f @PACKAGE@.texinfo; then echo @PACKAGE@.texinfo; else echo $(srcdir)/@PACKAGE@.texinfo; fi`

@PACKAGE@_toc.html: version.texi $(@PACKAGE@_TEXINFOS)
	case "$(TEXI2HTML)" in \
	  *"/missing texi2html") \
	     $(TEXI2HTML) -expand info -number -nomenu -split section `if test -f @PACKAGE@.texinfo; then echo @PACKAGE@.texinfo; else echo $(srcdir)/@PACKAGE@.texinfo; fi` || exit 0 ;; \
	  *) $(RM) @PACKAGE@_*.html ; \
	     $(TEXI2HTML) -expand info -number -nomenu -split section `if test -f @PACKAGE@.texinfo; then echo @PACKAGE@.texinfo; else echo $(srcdir)/@PACKAGE@.texinfo; fi` ;; \
	esac

install-html-monolithic: @PACKAGE@.html
	$(mkinstalldirs) $(DESTDIR)$(htmldir)
	$(INSTALL_DATA) `if test -f @PACKAGE@.html; then echo .; else echo $(srcdir); fi`/@PACKAGE@.html $(DESTDIR)$(htmldir)/@PACKAGE@.html

install-html-split: @PACKAGE@_toc.html
	$(mkinstalldirs) $(DESTDIR)$(htmldir)
	for file in `if test -f @PACKAGE@_toc.html; then echo .; else echo $(srcdir); fi`/@PACKAGE@*.html; do \
	  $(INSTALL_DATA) $$file $(DESTDIR)$(htmldir)/`basename $$file`; \
	done

installdirs-html:
	$(mkinstalldirs) $(DESTDIR)$(htmldir)

uninstall-html-monolithic:
	$(RM) $(DESTDIR)$(htmldir)/@PACKAGE@.html

uninstall-html-split:
	$(RM) $(DESTDIR)$(htmldir)/@PACKAGE@_*.html

# Documentation in Portable Document Format.

TEXI2PDF = @TEXI2PDF@
SUFFIXES = .pdf

.texinfo.pdf:
	TEXINPUTS=.:$$TEXINPUTS \
	MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2PDF) $<

pdf: @PACKAGE@.pdf

CLEANFILES = @PACKAGE@.pdf

# --------------- Maintainer's Section

MAINTAINERCLEANFILES = Makefile.in version.texi stamp.vti indent*.html
