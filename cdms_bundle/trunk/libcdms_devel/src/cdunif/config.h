/* src/config.h.  Generated from config.h.in by configure.  */
/* src/config.h.in.  Generated from configure.ac by autoheader.  */

/* little_endian machine */
#define BYTEORDER 0

/* Enable geotiff */
#define GEOTIFF 0

/* Define if GetFile has a short prototype */
/* #undef GETFILE_SHORT_PROTOTYPE */

/* Machine is a Cray */
#define GRADS_CRAY 0

/* Obsolete feature description string */
#define GRADS_DESC 

/* Machine is 64-bit HP */
#define GRADS_HP64 0

/* GrADS version */
#define GRADS_VERSION "2.0.a8"

/* Enable grib2 */
#define GRIB2 1

/* Enable printim using zlib, libpng, and libgd */
#define GXPNG 1

/* Enable netcdf4 */
/* #undef HAVENETCDF4 */

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* Define to 1 if you have the `gdCompareInt' function. */
/* #undef HAVE_GDCOMPAREINT */

/* Define to 1 if you have the <hdf4_netcdf.h> header file. */
#define HAVE_HDF4_NETCDF_H 1

/* Define to 1 if you have the <history.h> header file. */
/* #undef HAVE_HISTORY_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define if you have a readline compatible library */
#define HAVE_LIBREADLINE 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <readline.h> header file. */
/* #undef HAVE_READLINE_H */

/* Define if your readline library has \`add_history' */
#define HAVE_READLINE_HISTORY 1

/* Define to 1 if you have the <readline/history.h> header file. */
#define HAVE_READLINE_HISTORY_H 1

/* Define to 1 if you have the <readline/readline.h> header file. */
#define HAVE_READLINE_READLINE_H 1

/* Define to 1 if you have the <shapefil.h> header file. */
/* #undef HAVE_SHAPEFIL_H */

/* Define to 1 if you have the `SimpleGetFile' function. */
/* #undef HAVE_SIMPLEGETFILE */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtod' function. */
#define HAVE_STRTOD 1

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <tiffio.h> header file. */
/* #undef HAVE_TIFFIO_H */

/* Define to 1 if you have the <tiff.h> header file. */
/* #undef HAVE_TIFF_H */

/* Define to 1 if you have the <udunits.h> header file. */
/* #undef HAVE_UDUNITS_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <zlib.h> header file. */
/* #undef HAVE_ZLIB_H */

/* Define if hdf prefixes netcdf symbols by sd */
#define HDF_HAVE_NETCDF 

/* A macro that append sd_ to netcdf symbols if needed */
#define HDF_NETCDF_NAME(name) sd_ ## name

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "jma@iges.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "GrADS"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "GrADS 2.0.a8"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "grads"

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.0.a8"

/* Enable command line editing */
#define READLINE 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable OPeNDAP for grids */
/* #undef USEDAP */

/* Use GetFile from freq */
/* #undef USEFREQ */

/* Enable OPeNDAP for station data */
#define USEGADAP 0

/* Enable GUI widgets */
#define USEGUI 0

/* Enable hdf4 */
#define USEHDF 1

/* Enable hdf5 */
#define USEHDF5 0

/* Enable netcdf */
#define USENETCDF 0

/* Enable shapefile */
#define USESHP 0

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */
