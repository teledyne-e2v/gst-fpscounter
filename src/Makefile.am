# Note: plugindir is set in configure

##############################################################################
# TODO: change libgstplugin.la to something else, e.g. libmysomething.la     #
##############################################################################
plugin_LTLIBRARIES = libgstfpscounter.la

##############################################################################
# TODO: for the next set of variables, name the prefix if you named the .la, #
#  e.g. libmysomething.la => libmysomething_la_SOURCES                       #
#                            libmysomething_la_CFLAGS                        #
#                            libmysomething_la_LIBADD                        #
#                            libmysomething_la_LDFLAGS                       #
##############################################################################

## Plugin 1

# sources used to compile this plug-in
libgstfpscounter_la_SOURCES = gstfpscounter.c gstfpscounter.h

# compiler and linker flags used to compile this plugin, set in configure.ac
libgstfpscounter_la_CFLAGS = $(GST_CFLAGS)
libgstfpscounter_la_LIBADD = $(GST_LIBS)
libgstfpscounter_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstfpscounter_la_LIBTOOLFLAGS = --tag=disable-static

# headers we need but don't want installed
noinst_HEADERS = gstfpscounter.h
