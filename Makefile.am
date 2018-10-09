## Process this file with automake to generate Makefile.in


# Copyright 1991, 1993, 1994, 1996, 1997, 1999-2004, 2006-2009, 2011-2016 Free
# Software Foundation, Inc.
#
#  This file is part of the GNU MP Library.
#
#  The GNU MP Library is free software; you can redistribute it and/or modify
#  it under the terms of either:
#
#    * the GNU Lesser General Public License as published by the Free
#      Software Foundation; either version 3 of the License, or (at your
#      option) any later version.
#
#  or
#
#    * the GNU General Public License as published by the Free Software
#      Foundation; either version 2 of the License, or (at your option) any
#      later version.
#
#  or both in parallel, as here.
#
#  The GNU MP Library is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
#  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
#  for more details.
#
#  You should have received copies of the GNU General Public License and the
#  GNU Lesser General Public License along with the GNU MP Library.  If not,
#  see https://www.gnu.org/licenses/.


# The following options are the same as AM_INIT_AUTOMAKE in configure.in,
# except no $(top_builddir) on ansi2knr.  That directory is wanted for the
# Makefiles in subdirectories, but here we must omit it so automake gives
# the actual ansi2knr build rule, not "cd $(top_builddir) && make ansi2knr".
#
# AUTOMAKE_OPTIONS = 1.8 gnu no-dependencies


# Libtool -version-info for libgmp.la and libmp.la.  See "Versioning" in the
# libtool manual.
#
#	CURRENT:REVISION:AGE
#
# 1. No interfaces changed, only implementations (good): Increment REVISION.
#
# 2. Interfaces added, none removed (good): Increment CURRENT, increment
#    AGE, set REVISION to 0.
#
# 3. Interfaces removed (BAD, breaks upward compatibility): Increment
#    CURRENT, set AGE and REVISION to 0.
#
# Do this separately for libgmp, libgmpxx and libmp, and only for releases.
#
#	  GMP	   -version-info
#       release   libgmp  libgmpxx libmp
#        2.0.x      -        -       -
#        3.0      3:0:0      -     3:0:0
#        3.0.1    3:1:0      -     3:0:0
#        3.1      4:0:1      -     4:0:1
#        3.1.1    4:1:1      -     4:1:1
#        4.0      5:0:2    3:0:0   4:2:1
#        4.0.1    5:1:2    3:1:0   4:3:1
#        4.1      6:0:3    3:2:0   4:4:1
#        4.1.1    6:1:3    3:3:0   4:5:1
#        4.1.2    6:2:3    3:4:0   4:6:1
#        4.1.3    6:3:3    3:5:0   4:7:1
#        4.1.4    6:3:3    3:5:0   4:7:1	WRONG, same as 4.1.3!
#        4.2      6:0:3    3:2:0   4:4:1	REALLY WRONG, same as 4.1!
#        4.2.1    7:1:4    4:1:1   4:10:1	WRONG for libgmpxx
#        4.2.2    7:2:4    4:2:0   4:11:1
#        4.2.3    7:3:4    4:3:0   4:12:1
#        4.2.4    7:4:4    4:4:0   4:13:1
#        4.3.0    8:0:5    5:0:1   4:14:1
#        4.3.1    8:1:5    5:1:1   4:15:1	WRONG Really used same as 4.3.0
#        4.3.2    8:2:5    5:2:1   4:16:1
#        5.0.0    9:0:6    6:0:2   4:20:1	Should have been 10:0:0
#        5.0.1   10:1:0    6:1:2   4:21:1
#        5.0.2   10:2:0    6:2:2   4:22:1
#        5.0.3   10:3:0    6:3:2   4:23:1
#        5.0.4   10:4:0    6:4:2   4:24:1
#        5.0.5   10:5:0    6:5:2   4:25:1
#        5.1.0   11:0:1    7:0:3     -
#        5.1.1   11:1:1    7:1:3     -
#        5.1.2   11:2:1    7:2:3     -
#        6.0.0   12:0:2    8:0:4     -
#        6.1.0   13:0:3    9:0:5     -
#        6.1.1   13:1:3    9:1:5     -
#        6.1.2   13:2:3    9:2:5     -
#
# Starting at 3:0:0 is a slight abuse of the versioning system, but it
# ensures we're past soname libgmp.so.2, which was used on Debian GNU/Linux
# packages of gmp 2.  Pretend gmp 2 was 2:0:0, so the interface changes for
# gmp 3 mean 3:0:0 is right.
#
# We interpret "implementation changed" in item "1." above as meaning any
# release, ie. the REVISION is incremented every time (if nothing else).
# Even if we thought the code generated will be identical on all systems,
# it's still good to get the shared library filename (like
# libgmpxx.so.3.0.4) incrementing, to make it clear which GMP it's from.

# Include the automake definitions for building an Intel SGX trusted
# enclave library.
# - John Mechalas <john.p.mechalas@intel.com>
include sgx_tlib.am

LIBGMP_LT_CURRENT    = 13
LIBGMP_LT_REVISION   = 2
LIBGMP_LT_AGE        = 3

LIBGMPXX_LT_CURRENT  = 9
LIBGMPXX_LT_REVISION = 2
LIBGMPXX_LT_AGE      = 5


SUBDIRS = tests mpn mpz mpq mpf rand cxx demos tune doc
# The Intel SGX trusted C library does not have these.
# - John Mechalas <john.p.mechalas@intel.com>
if !SGX_ENABLED
	SUBDIRS += printf scanf
endif

EXTRA_DIST = configfsf.guess configfsf.sub .gdbinit INSTALL.autoconf \
	     COPYING.LESSERv3 COPYINGv2 COPYINGv3


if WANT_CXX
GMPXX_HEADERS_OPTION = gmpxx.h
endif
EXTRA_DIST += gmpxx.h

# gmp.h and mp.h are architecture dependent, mainly since they encode the
# limb size used in libgmp.  For that reason they belong under $exec_prefix
# not $prefix, strictly speaking.
#
# $exec_prefix/include is not in the default include path for gcc built to
# the same $prefix and $exec_prefix, which might mean gmp.h is not found,
# but anyone knowledgeable enough to be playing with exec_prefix will be able
# to address that.
#
includeexecdir = $(exec_prefix)/include
include_HEADERS = $(GMPXX_HEADERS_OPTION)

#------------------------------------------------------------
# Make sure the SGX build gets its own header, since gmp.h 
# has SGX-specific settings in it.
# - John Mechalas <john.p.mechalas@intel.com>
if SGX_ENABLED
nodist_includeexec_HEADERS = sgx_tgmp.h
else !SGX_ENABLED
nodist_includeexec_HEADERS = gmp.h
endif
#------------------------------------------------------------

#------------------------------------------------------------
# Set the extension to .o for Intel SGX builds and .lo otherwise (for libtool)
# - John Mechalas <john.p.mechalas@intel.com>
if SGX_ENABLED
  lib_LIBRARIES = libsgx_tgmp.a $(GMPXX_LIBRARIES_OPTION)
  O=o
else 
  lib_LTLIBRARIES = libgmp.la $(GMPXX_LTLIBRARIES_OPTION)
  O=lo
endif
#------------------------------------------------------------

BUILT_SOURCES = gmp.h
#------------------------------------------------------------
# Make sure the SGX build gets its own header, since gmp.h 
# has SGX-specific settings in it.
# - John Mechalas <john.p.mechalas@intel.com>
if SGX_ENABLED
BUILT_SOURCES += sgx_tgmp.h
endif
#------------------------------------------------------------

DISTCLEANFILES = $(BUILT_SOURCES) config.m4 @gmp_srclinks@

# Tell gmp.h it's building gmp, not an application, used by windows DLL stuff.

#------------------------------------------------------------
# For an Intel SGX build, we need to manually include the architecture 
# flags to gcc manually, as well as set per-target compilation flags.
# - John Mechalas <john.p.mechalas@intel.com>
if SGX_ENABLED

AM_CFLAGS += $(CFLAGS_CPU)

libsgx_tgmp_a_CPPFLAGS=$(AM_CPPFLAGS) -D__GMP_WITHIN_GMP
libsgx_tgmp_a_CFLAGS= $(AM_CFLAGS) -fno-builtin-memset

else !SGX_ENABLED

AM_CPPFLAGS = -D__GMP_WITHIN_GMP

endif
#------------------------------------------------------------


#------------------------------------------------------------
# Only include the object files that are valid for the Intel SGX trusted
# library. Specifically, eliminate the scanf and printf modules. This is
# more or less a brute-force approach.
# - John Mechalas <john.p.mechalas@intel.com>
#

if SGX_ENABLED

MPF_OBJECTS = mpf/libmpf_a-init$U.$O mpf/libmpf_a-init2$U.$O mpf/libmpf_a-inits$U.$O mpf/libmpf_a-set$U.$O	    \
  mpf/libmpf_a-set_ui$U.$O mpf/libmpf_a-set_si$U.$O mpf/libmpf_a-set_str$U.$O mpf/libmpf_a-set_d$U.$O	    \
  mpf/libmpf_a-set_z$U.$O mpf/libmpf_a-iset$U.$O mpf/libmpf_a-iset_ui$U.$O mpf/libmpf_a-iset_si$U.$O	    \
  mpf/libmpf_a-iset_str$U.$O mpf/libmpf_a-iset_d$U.$O mpf/libmpf_a-clear$U.$O mpf/libmpf_a-clears$U.$O	    \
  mpf/libmpf_a-get_str$U.$O mpf/libmpf_a-dump$U.$O mpf/libmpf_a-size$U.$O mpf/libmpf_a-eq$U.$O mpf/libmpf_a-reldiff$U.$O \
  mpf/libmpf_a-sqrt$U.$O mpf/libmpf_a-random2$U.$O	    \
  mpf/libmpf_a-add$U.$O mpf/libmpf_a-add_ui$U.$O mpf/libmpf_a-sub$U.$O mpf/libmpf_a-sub_ui$U.$O mpf/libmpf_a-ui_sub$U.$O \
  mpf/libmpf_a-mul$U.$O mpf/libmpf_a-mul_ui$U.$O mpf/libmpf_a-div$U.$O mpf/libmpf_a-div_ui$U.$O mpf/libmpf_a-cmp_z$U.$O  \
  mpf/libmpf_a-cmp$U.$O mpf/libmpf_a-cmp_d$U.$O mpf/libmpf_a-cmp_ui$U.$O mpf/libmpf_a-cmp_si$U.$O		    \
  mpf/libmpf_a-mul_2exp$U.$O mpf/libmpf_a-div_2exp$U.$O mpf/libmpf_a-abs$U.$O mpf/libmpf_a-neg$U.$O		    \
  mpf/libmpf_a-set_q$U.$O mpf/libmpf_a-get_d$U.$O mpf/libmpf_a-get_d_2exp$U.$O mpf/libmpf_a-set_dfl_prec$U.$O   \
  mpf/libmpf_a-set_prc$U.$O mpf/libmpf_a-set_prc_raw$U.$O mpf/libmpf_a-get_dfl_prec$U.$O               \
  mpf/libmpf_a-get_prc$U.$O mpf/libmpf_a-ui_div$U.$O mpf/libmpf_a-sqrt_ui$U.$O                         \
  mpf/libmpf_a-ceilfloor$U.$O mpf/libmpf_a-trunc$U.$O mpf/libmpf_a-pow_ui$U.$O			    \
  mpf/libmpf_a-urandomb$U.$O mpf/libmpf_a-swap$U.$O					    \
  mpf/libmpf_a-fits_sint$U.$O mpf/libmpf_a-fits_slong$U.$O mpf/libmpf_a-fits_sshort$U.$O		    \
  mpf/libmpf_a-fits_uint$U.$O mpf/libmpf_a-fits_ulong$U.$O mpf/libmpf_a-fits_ushort$U.$O		    \
  mpf/libmpf_a-get_si$U.$O mpf/libmpf_a-get_ui$U.$O					    \
  mpf/libmpf_a-int_p$U.$O

else !SGX_ENABLED

MPF_OBJECTS = mpf/init$U.$O mpf/init2$U.$O mpf/inits$U.$O mpf/set$U.$O	    \
  mpf/set_ui$U.$O mpf/set_si$U.$O mpf/set_str$U.$O mpf/set_d$U.$O	    \
  mpf/set_z$U.$O mpf/iset$U.$O mpf/iset_ui$U.$O mpf/iset_si$U.$O	    \
  mpf/iset_str$U.$O mpf/iset_d$U.$O mpf/clear$U.$O mpf/clears$U.$O	    \
  mpf/get_str$U.$O mpf/dump$U.$O mpf/size$U.$O mpf/eq$U.$O mpf/reldiff$U.$O \
  mpf/sqrt$U.$O mpf/random2$U.$O	    \
  mpf/add$U.$O mpf/add_ui$U.$O mpf/sub$U.$O mpf/sub_ui$U.$O mpf/ui_sub$U.$O \
  mpf/mul$U.$O mpf/mul_ui$U.$O mpf/div$U.$O mpf/div_ui$U.$O mpf/cmp_z$U.$O  \
  mpf/cmp$U.$O mpf/cmp_d$U.$O mpf/cmp_ui$U.$O mpf/cmp_si$U.$O		    \
  mpf/mul_2exp$U.$O mpf/div_2exp$U.$O mpf/abs$U.$O mpf/neg$U.$O		    \
  mpf/set_q$U.$O mpf/get_d$U.$O mpf/get_d_2exp$U.$O mpf/set_dfl_prec$U.$O   \
  mpf/set_prc$U.$O mpf/set_prc_raw$U.$O mpf/get_dfl_prec$U.$O               \
  mpf/get_prc$U.$O mpf/ui_div$U.$O mpf/sqrt_ui$U.$O                         \
  mpf/ceilfloor$U.$O mpf/trunc$U.$O mpf/pow_ui$U.$O			    \
  mpf/urandomb$U.$O mpf/swap$U.$O					    \
  mpf/fits_sint$U.$O mpf/fits_slong$U.$O mpf/fits_sshort$U.$O		    \
  mpf/fits_uint$U.$O mpf/fits_ulong$U.$O mpf/fits_ushort$U.$O		    \
  mpf/get_si$U.$O mpf/get_ui$U.$O					    \
  mpf/int_p$U.$O mpf/inp_str$U.$O mpf/out_str$U.$O

endif

if SGX_ENABLED

MPZ_OBJECTS = mpz/libmpz_a-abs$U.$O mpz/libmpz_a-add$U.$O mpz/libmpz_a-add_ui$U.$O			\
  mpz/libmpz_a-aorsmul$U.$O mpz/libmpz_a-aorsmul_i$U.$O mpz/libmpz_a-and$U.$O mpz/libmpz_a-array_init$U.$O	\
  mpz/libmpz_a-bin_ui$U.$O mpz/libmpz_a-bin_uiui$U.$O					\
  mpz/libmpz_a-cdiv_q$U.$O mpz/libmpz_a-cdiv_q_ui$U.$O					\
  mpz/libmpz_a-cdiv_qr$U.$O mpz/libmpz_a-cdiv_qr_ui$U.$O					\
  mpz/libmpz_a-cdiv_r$U.$O mpz/libmpz_a-cdiv_r_ui$U.$O mpz/libmpz_a-cdiv_ui$U.$O			\
  mpz/libmpz_a-cfdiv_q_2exp$U.$O mpz/libmpz_a-cfdiv_r_2exp$U.$O				\
  mpz/libmpz_a-clear$U.$O mpz/libmpz_a-clears$U.$O mpz/libmpz_a-clrbit$U.$O			\
  mpz/libmpz_a-cmp$U.$O mpz/libmpz_a-cmp_d$U.$O mpz/libmpz_a-cmp_si$U.$O mpz/libmpz_a-cmp_ui$U.$O		\
  mpz/libmpz_a-cmpabs$U.$O mpz/libmpz_a-cmpabs_d$U.$O mpz/libmpz_a-cmpabs_ui$U.$O			\
  mpz/libmpz_a-com$U.$O mpz/libmpz_a-combit$U.$O						\
  mpz/libmpz_a-cong$U.$O mpz/libmpz_a-cong_2exp$U.$O mpz/libmpz_a-cong_ui$U.$O			\
  mpz/libmpz_a-divexact$U.$O mpz/libmpz_a-divegcd$U.$O mpz/libmpz_a-dive_ui$U.$O			\
  mpz/libmpz_a-divis$U.$O mpz/libmpz_a-divis_ui$U.$O mpz/libmpz_a-divis_2exp$U.$O mpz/libmpz_a-dump$U.$O	\
  mpz/libmpz_a-export$U.$O mpz/libmpz_a-mfac_uiui$U.$O					\
  mpz/libmpz_a-2fac_ui$U.$O mpz/libmpz_a-fac_ui$U.$O mpz/libmpz_a-oddfac_1$U.$O mpz/libmpz_a-prodlimbs$U.$O	\
  mpz/libmpz_a-fdiv_q_ui$U.$O mpz/libmpz_a-fdiv_qr$U.$O mpz/libmpz_a-fdiv_qr_ui$U.$O		\
  mpz/libmpz_a-fdiv_r$U.$O mpz/libmpz_a-fdiv_r_ui$U.$O mpz/libmpz_a-fdiv_q$U.$O			\
  mpz/libmpz_a-fdiv_ui$U.$O mpz/libmpz_a-fib_ui$U.$O mpz/libmpz_a-fib2_ui$U.$O mpz/libmpz_a-fits_sint$U.$O	\
  mpz/libmpz_a-fits_slong$U.$O mpz/libmpz_a-fits_sshort$U.$O mpz/libmpz_a-fits_uint$U.$O		\
  mpz/libmpz_a-fits_ulong$U.$O mpz/libmpz_a-fits_ushort$U.$O mpz/libmpz_a-gcd$U.$O			\
  mpz/libmpz_a-gcd_ui$U.$O mpz/libmpz_a-gcdext$U.$O mpz/libmpz_a-get_d$U.$O mpz/libmpz_a-get_d_2exp$U.$O	\
  mpz/libmpz_a-get_si$U.$O mpz/libmpz_a-get_str$U.$O mpz/libmpz_a-get_ui$U.$O mpz/libmpz_a-getlimbn$U.$O	\
  mpz/libmpz_a-hamdist$U.$O							\
  mpz/libmpz_a-import$U.$O mpz/libmpz_a-init$U.$O mpz/libmpz_a-init2$U.$O mpz/libmpz_a-inits$U.$O		\
  mpz/libmpz_a-invert$U.$O			\
  mpz/libmpz_a-ior$U.$O mpz/libmpz_a-iset$U.$O mpz/libmpz_a-iset_d$U.$O mpz/libmpz_a-iset_si$U.$O		\
  mpz/libmpz_a-iset_str$U.$O mpz/libmpz_a-iset_ui$U.$O mpz/libmpz_a-jacobi$U.$O mpz/libmpz_a-kronsz$U.$O	\
  mpz/libmpz_a-kronuz$U.$O mpz/libmpz_a-kronzs$U.$O mpz/libmpz_a-kronzu$U.$O			\
  mpz/libmpz_a-lcm$U.$O mpz/libmpz_a-lcm_ui$U.$O mpz/libmpz_a-limbs_finish$U.$O			\
  mpz/libmpz_a-limbs_modify$U.$O mpz/libmpz_a-limbs_read$U.$O mpz/libmpz_a-limbs_write$U.$O	\
  mpz/libmpz_a-lucnum_ui$U.$O mpz/libmpz_a-lucnum2_ui$U.$O				\
  mpz/libmpz_a-millerrabin$U.$O mpz/libmpz_a-mod$U.$O mpz/libmpz_a-mul$U.$O mpz/libmpz_a-mul_2exp$U.$O	\
  mpz/libmpz_a-mul_si$U.$O mpz/libmpz_a-mul_ui$U.$O					\
  mpz/libmpz_a-n_pow_ui$U.$O mpz/libmpz_a-neg$U.$O mpz/libmpz_a-nextprime$U.$O			\
  mpz/libmpz_a-perfpow$U.$O mpz/libmpz_a-perfsqr$U.$O	\
  mpz/libmpz_a-popcount$U.$O mpz/libmpz_a-pow_ui$U.$O mpz/libmpz_a-powm$U.$O mpz/libmpz_a-powm_sec$U.$O	\
  mpz/libmpz_a-powm_ui$U.$O mpz/libmpz_a-primorial_ui$U.$O				\
  mpz/libmpz_a-pprime_p$U.$O mpz/libmpz_a-random$U.$O mpz/libmpz_a-random2$U.$O			\
  mpz/libmpz_a-realloc$U.$O mpz/libmpz_a-realloc2$U.$O mpz/libmpz_a-remove$U.$O mpz/libmpz_a-roinit_n$U.$O  \
  mpz/libmpz_a-root$U.$O mpz/libmpz_a-rootrem$U.$O mpz/libmpz_a-rrandomb$U.$O mpz/libmpz_a-scan0$U.$O	\
  mpz/libmpz_a-scan1$U.$O mpz/libmpz_a-set$U.$O mpz/libmpz_a-set_d$U.$O mpz/libmpz_a-set_f$U.$O		\
  mpz/libmpz_a-set_q$U.$O mpz/libmpz_a-set_si$U.$O mpz/libmpz_a-set_str$U.$O mpz/libmpz_a-set_ui$U.$O	\
  mpz/libmpz_a-setbit$U.$O							\
  mpz/libmpz_a-size$U.$O mpz/libmpz_a-sizeinbase$U.$O mpz/libmpz_a-sqrt$U.$O			\
  mpz/libmpz_a-sqrtrem$U.$O mpz/libmpz_a-sub$U.$O mpz/libmpz_a-sub_ui$U.$O mpz/libmpz_a-swap$U.$O		\
  mpz/libmpz_a-tdiv_ui$U.$O mpz/libmpz_a-tdiv_q$U.$O mpz/libmpz_a-tdiv_q_2exp$U.$O			\
  mpz/libmpz_a-tdiv_q_ui$U.$O mpz/libmpz_a-tdiv_qr$U.$O mpz/libmpz_a-tdiv_qr_ui$U.$O		\
  mpz/libmpz_a-tdiv_r$U.$O mpz/libmpz_a-tdiv_r_2exp$U.$O mpz/libmpz_a-tdiv_r_ui$U.$O		\
  mpz/libmpz_a-tstbit$U.$O mpz/libmpz_a-ui_pow_ui$U.$O mpz/libmpz_a-ui_sub$U.$O mpz/libmpz_a-urandomb$U.$O	\
  mpz/libmpz_a-urandomm$U.$O mpz/libmpz_a-xor$U.$O

else !SGX_ENABLED

MPZ_OBJECTS = mpz/abs$U.$O mpz/add$U.$O mpz/add_ui$U.$O			\
  mpz/aorsmul$U.$O mpz/aorsmul_i$U.$O mpz/and$U.$O mpz/array_init$U.$O	\
  mpz/bin_ui$U.$O mpz/bin_uiui$U.$O					\
  mpz/cdiv_q$U.$O mpz/cdiv_q_ui$U.$O					\
  mpz/cdiv_qr$U.$O mpz/cdiv_qr_ui$U.$O					\
  mpz/cdiv_r$U.$O mpz/cdiv_r_ui$U.$O mpz/cdiv_ui$U.$O			\
  mpz/cfdiv_q_2exp$U.$O mpz/cfdiv_r_2exp$U.$O				\
  mpz/clear$U.$O mpz/clears$U.$O mpz/clrbit$U.$O			\
  mpz/cmp$U.$O mpz/cmp_d$U.$O mpz/cmp_si$U.$O mpz/cmp_ui$U.$O		\
  mpz/cmpabs$U.$O mpz/cmpabs_d$U.$O mpz/cmpabs_ui$U.$O			\
  mpz/com$U.$O mpz/combit$U.$O						\
  mpz/cong$U.$O mpz/cong_2exp$U.$O mpz/cong_ui$U.$O			\
  mpz/divexact$U.$O mpz/divegcd$U.$O mpz/dive_ui$U.$O			\
  mpz/divis$U.$O mpz/divis_ui$U.$O mpz/divis_2exp$U.$O mpz/dump$U.$O	\
  mpz/export$U.$O mpz/mfac_uiui$U.$O					\
  mpz/2fac_ui$U.$O mpz/fac_ui$U.$O mpz/oddfac_1$U.$O mpz/prodlimbs$U.$O	\
  mpz/fdiv_q_ui$U.$O mpz/fdiv_qr$U.$O mpz/fdiv_qr_ui$U.$O		\
  mpz/fdiv_r$U.$O mpz/fdiv_r_ui$U.$O mpz/fdiv_q$U.$O			\
  mpz/fdiv_ui$U.$O mpz/fib_ui$U.$O mpz/fib2_ui$U.$O mpz/fits_sint$U.$O	\
  mpz/fits_slong$U.$O mpz/fits_sshort$U.$O mpz/fits_uint$U.$O		\
  mpz/fits_ulong$U.$O mpz/fits_ushort$U.$O mpz/gcd$U.$O			\
  mpz/gcd_ui$U.$O mpz/gcdext$U.$O mpz/get_d$U.$O mpz/get_d_2exp$U.$O	\
  mpz/get_si$U.$O mpz/get_str$U.$O mpz/get_ui$U.$O mpz/getlimbn$U.$O	\
  mpz/hamdist$U.$O							\
  mpz/import$U.$O mpz/init$U.$O mpz/init2$U.$O mpz/inits$U.$O		\
  mpz/invert$U.$O			\
  mpz/ior$U.$O mpz/iset$U.$O mpz/iset_d$U.$O mpz/iset_si$U.$O		\
  mpz/iset_str$U.$O mpz/iset_ui$U.$O mpz/jacobi$U.$O mpz/kronsz$U.$O	\
  mpz/kronuz$U.$O mpz/kronzs$U.$O mpz/kronzu$U.$O			\
  mpz/lcm$U.$O mpz/lcm_ui$U.$O mpz/limbs_finish$U.$O			\
  mpz/limbs_modify$U.$O mpz/limbs_read$U.$O mpz/limbs_write$U.$O	\
  mpz/lucnum_ui$U.$O mpz/lucnum2_ui$U.$O				\
  mpz/millerrabin$U.$O mpz/mod$U.$O mpz/mul$U.$O mpz/mul_2exp$U.$O	\
  mpz/mul_si$U.$O mpz/mul_ui$U.$O					\
  mpz/n_pow_ui$U.$O mpz/neg$U.$O mpz/nextprime$U.$O			\
  mpz/perfpow$U.$O mpz/perfsqr$U.$O	\
  mpz/popcount$U.$O mpz/pow_ui$U.$O mpz/powm$U.$O mpz/powm_sec$U.$O	\
  mpz/powm_ui$U.$O mpz/primorial_ui$U.$O				\
  mpz/pprime_p$U.$O mpz/random$U.$O mpz/random2$U.$O			\
  mpz/realloc$U.$O mpz/realloc2$U.$O mpz/remove$U.$O mpz/roinit_n$U.$O  \
  mpz/root$U.$O mpz/rootrem$U.$O mpz/rrandomb$U.$O mpz/scan0$U.$O	\
  mpz/scan1$U.$O mpz/set$U.$O mpz/set_d$U.$O mpz/set_f$U.$O		\
  mpz/set_q$U.$O mpz/set_si$U.$O mpz/set_str$U.$O mpz/set_ui$U.$O	\
  mpz/setbit$U.$O							\
  mpz/size$U.$O mpz/sizeinbase$U.$O mpz/sqrt$U.$O			\
  mpz/sqrtrem$U.$O mpz/sub$U.$O mpz/sub_ui$U.$O mpz/swap$U.$O		\
  mpz/tdiv_ui$U.$O mpz/tdiv_q$U.$O mpz/tdiv_q_2exp$U.$O			\
  mpz/tdiv_q_ui$U.$O mpz/tdiv_qr$U.$O mpz/tdiv_qr_ui$U.$O		\
  mpz/tdiv_r$U.$O mpz/tdiv_r_2exp$U.$O mpz/tdiv_r_ui$U.$O		\
  mpz/tstbit$U.$O mpz/ui_pow_ui$U.$O mpz/ui_sub$U.$O mpz/urandomb$U.$O	\
  mpz/urandomm$U.$O mpz/xor$U.$O mpz/out_raw$U.$O mpz/out_str$U.$O \
  mpz/inp_raw$U.$O mpz/inp_str$U.$O 

endif

if SGX_ENABLED
MPQ_OBJECTS = mpq/libmpq_a-abs$U.$O mpq/libmpq_a-aors$U.$O				\
  mpq/libmpq_a-canonicalize$U.$O mpq/libmpq_a-clear$U.$O mpq/libmpq_a-clears$U.$O			\
  mpq/libmpq_a-cmp$U.$O mpq/libmpq_a-cmp_si$U.$O mpq/libmpq_a-cmp_ui$U.$O mpq/libmpq_a-div$U.$O		\
  mpq/libmpq_a-get_d$U.$O mpq/libmpq_a-get_den$U.$O mpq/libmpq_a-get_num$U.$O mpq/libmpq_a-get_str$U.$O	\
  mpq/libmpq_a-init$U.$O mpq/libmpq_a-inits$U.$O mpq/libmpq_a-inv$U.$O		\
  mpq/libmpq_a-md_2exp$U.$O mpq/libmpq_a-mul$U.$O mpq/libmpq_a-neg$U.$O 	\
  mpq/libmpq_a-set$U.$O mpq/libmpq_a-set_den$U.$O mpq/libmpq_a-set_num$U.$O			\
  mpq/libmpq_a-set_si$U.$O mpq/libmpq_a-set_str$U.$O mpq/libmpq_a-set_ui$U.$O			\
  mpq/libmpq_a-equal$U.$O mpq/libmpq_a-set_z$U.$O mpq/libmpq_a-set_d$U.$O				\
  mpq/libmpq_a-set_f$U.$O mpq/libmpq_a-swap$U.$O

else !SGX_ENABLED

MPQ_OBJECTS = mpq/abs$U.$O mpq/aors$U.$O				\
  mpq/canonicalize$U.$O mpq/clear$U.$O mpq/clears$U.$O			\
  mpq/cmp$U.$O mpq/cmp_si$U.$O mpq/cmp_ui$U.$O mpq/div$U.$O		\
  mpq/get_d$U.$O mpq/get_den$U.$O mpq/get_num$U.$O mpq/get_str$U.$O	\
  mpq/init$U.$O mpq/inits$U.$O mpq/inv$U.$O		\
  mpq/md_2exp$U.$O mpq/mul$U.$O mpq/neg$U.$O 	\
  mpq/set$U.$O mpq/set_den$U.$O mpq/set_num$U.$O			\
  mpq/set_si$U.$O mpq/set_str$U.$O mpq/set_ui$U.$O			\
  mpq/equal$U.$O mpq/set_z$U.$O mpq/set_d$U.$O				\
  mpq/set_f$U.$O mpq/swap$U.$O mpq/inp_str$U.$O mpq/out_str$U.$O

endif

if SGX_ENABLED

MPN_OBJECTS = mpn/libmpn_a-fib_table$U.$O mpn/libmpn_a-mp_bases$U.$O

else !SGX_ENABLED

MPN_OBJECTS = mpn/fib_table$U.$O mpn/mp_bases$U.$O

endif

PRINTF_OBJECTS =							\
  printf/asprintf$U.$O printf/asprntffuns$U.$O				\
  printf/doprnt$U.$O printf/doprntf$U.$O printf/doprnti$U.$O		\
  printf/fprintf$U.$O							\
  printf/obprintf$U.$O printf/obvprintf$U.$O printf/obprntffuns$U.$O	\
  printf/printf$U.$O printf/printffuns$U.$O				\
  printf/snprintf$U.$O printf/snprntffuns$U.$O				\
  printf/sprintf$U.$O printf/sprintffuns$U.$O				\
  printf/vasprintf$U.$O printf/vfprintf$U.$O printf/vprintf$U.$O	\
  printf/vsnprintf$U.$O printf/vsprintf$U.$O				\
  printf/repl-vsnprintf$U.$O

SCANF_OBJECTS =							\
  scanf/doscan$U.$O scanf/fscanf$U.$O scanf/fscanffuns$U.$O	\
  scanf/scanf$U.$O scanf/sscanf$U.$O scanf/sscanffuns$U.$O	\
  scanf/vfscanf$U.$O scanf/vscanf$U.$O scanf/vsscanf$U.$O

if SGX_ENABLED

RANDOM_OBJECTS =							\
  rand/librandom_a-rand$U.$O rand/librandom_a-randclr$U.$O rand/librandom_a-randdef$U.$O rand/librandom_a-randiset$U.$O	\
  rand/librandom_a-randlc2s$U.$O rand/librandom_a-randlc2x$U.$O rand/librandom_a-randmt$U.$O		\
  rand/librandom_a-randmts$U.$O rand/librandom_a-rands$U.$O rand/librandom_a-randsd$U.$O rand/librandom_a-randsdui$U.$O	\
  rand/librandom_a-randbui$U.$O rand/librandom_a-randmui$U.$O

else !SGX_ENABLED

RANDOM_OBJECTS =							\
  rand/rand$U.$O rand/randclr$U.$O rand/randdef$U.$O rand/randiset$U.$O	\
  rand/randlc2s$U.$O rand/randlc2x$U.$O rand/randmt$U.$O		\
  rand/randmts$U.$O rand/rands$U.$O rand/randsd$U.$O rand/randsdui$U.$O	\
  rand/randbui$U.$O rand/randmui$U.$O

endif

# no $U for C++ files
CXX_OBJECTS =								\
  cxx/isfuns.$O cxx/ismpf.$O cxx/ismpq.$O cxx/ismpz.$O cxx/ismpznw.$O	\
  cxx/limits.$O cxx/osdoprnti.$O cxx/osfuns.$O				\
  cxx/osmpf.$O cxx/osmpq.$O cxx/osmpz.$O
#
#------------------------------------------------------------


# In libtool 1.5 it doesn't work to build libgmp.la from the convenience
# libraries like mpz/libmpz.la.  Or rather it works, but it ends up putting
# PIC objects into libgmp.a if shared and static are both built.  (The PIC
# objects go into mpz/.libs/libmpz.a, and thence into .libs/libgmp.a.)
#
# For now the big lists of objects above are used.  Something like mpz/*.lo
# would probably work, but might risk missing something out or getting
# something extra.  The source files for each .lo are listed in the
# Makefile.am's in the subdirectories.
#
# Currently, for libgmp, unlike libmp below, we're not using
# -export-symbols, since the tune and speed programs, and perhaps some of
# the test programs, want to access undocumented symbols.

#------------------------------------------------------------
# Rules for the Intel SGX build.
# - John Mechalas <john.p.mechalas@intel.com>
#
if SGX_ENABLED

libsgx_tgmp_a_SOURCES = gmp-impl.h longlong.h				\
  assert.c compat.c errno.c extract-dbl.c invalid.c memory.c		\
  mp_bpl.c mp_clz_tab.c mp_dv_tab.c mp_minv_tab.c mp_get_fns.c mp_set_fns.c \
  version.c nextprime.c primesieve.c
EXTRA_libsgx_tgmp_a_SOURCES = tal-notreent.c tal-reent.c
libsgx_tgmp_a_DEPENDENCIES = @TAL_OBJECT@		\
  $(MPF_OBJECTS) $(MPZ_OBJECTS) $(MPQ_OBJECTS)	\
  $(MPN_OBJECTS) @mpn_objs_in_libgmp@		\
  $(RANDOM_OBJECTS)
libsgx_tgmp_a_LIBADD = $(libsgx_tgmp_a_DEPENDENCIES) 

else 

libgmp_la_SOURCES = gmp-impl.h longlong.h				\
  assert.c compat.c errno.c extract-dbl.c invalid.c memory.c		\
  mp_bpl.c mp_clz_tab.c mp_dv_tab.c mp_minv_tab.c mp_get_fns.c mp_set_fns.c \
  version.c nextprime.c primesieve.c
EXTRA_libgmp_la_SOURCES = tal-debug.c tal-notreent.c tal-reent.c
libgmp_la_DEPENDENCIES = @TAL_OBJECT@		\
  $(MPF_OBJECTS) $(MPZ_OBJECTS) $(MPQ_OBJECTS)	\
  $(MPN_OBJECTS) @mpn_objs_in_libgmp@		\
  $(PRINTF_OBJECTS)  $(SCANF_OBJECTS) $(RANDOM_OBJECTS)
libgmp_la_LIBADD = $(libgmp_la_DEPENDENCIES)
libgmp_la_LDFLAGS = $(GMP_LDFLAGS) $(LIBGMP_LDFLAGS) \
  -version-info $(LIBGMP_LT_CURRENT):$(LIBGMP_LT_REVISION):$(LIBGMP_LT_AGE)

endif
#
#------------------------------------------------------------

# We need at least one .cc file in $(libgmpxx_la_SOURCES) so automake will
# use $(CXXLINK) rather than the plain C $(LINK).  cxx/dummy.cc is that
# file.

#------------------------------------------------------------
# Rules for C++ support (not currently functional).
# - John Mechalas <john.p.mechalas@intel.com>
#
if SGX_ENABLED

#if WANT_CXX
#GMPXX_LIBRARIES_OPTION = libgmpxx.a
#endif

#libsgx_tgmpxx_a_CXXFLAGS = $(AM_CXXFLAGS)
#libsgx_tgmpxx_a_SOURCES = cxx/dummy.cc
#libsgx_tgmpxx_a_DEPENDENCIES = $(CXX_OBJECTS) libgmp.a
#libsgx_tgmpxx_a_LIBADD = $(libsgx_tgmpxx_a_DEPENDENCIES)
#libsgx_tgmpxx_a_LDFLAGS = $(GMP_LDFLAGS) $(LIBGMPXX_LDFLAGS) \
#  -version-info $(LIBGMPXX_LT_CURRENT):$(LIBGMPXX_LT_REVISION):$(LIBGMPXX_LT_AGE)

else !SGX_ENABLED

if WANT_CXX
GMPXX_LTLIBRARIES_OPTION = libgmpxx.la
endif
libgmpxx_la_SOURCES = cxx/dummy.cc
libgmpxx_la_DEPENDENCIES = $(CXX_OBJECTS) libgmp.la
libgmpxx_la_LIBADD = $(libgmpxx_la_DEPENDENCIES)
libgmpxx_la_LDFLAGS = $(GMP_LDFLAGS) $(LIBGMPXX_LDFLAGS) \
  -version-info $(LIBGMPXX_LT_CURRENT):$(LIBGMPXX_LT_REVISION):$(LIBGMPXX_LT_AGE)

endif !SGX_ENABLED
#
#------------------------------------------------------------

install-data-hook:
#------------------------------------------------------------
# Supporting "make check" requires making a test suite with an
# enclave-based architecture. This would be a significant 
# amount of work, though it should probably be done at some 
# point. For now, this is left as an exercise for the reader.
# Since there's no SGX-equivalent of "make check", don't
# tell the user to do something that can't be done.
# - John Mechalas <john.p.mechalas@intel.com>
#
if !SGX_ENABLED
	@echo ''
	@echo '+-------------------------------------------------------------+'
	@echo '| CAUTION:                                                    |'
	@echo '|                                                             |'
	@echo '| If you have not already run "make check", then we strongly  |'
	@echo '| recommend you do so.                                        |'
	@echo '|                                                             |'
	@echo '| GMP has been carefully tested by its authors, but compilers |'
	@echo '| are all too often released with serious bugs.  GMP tends to |'
	@echo '| explore interesting corners in compilers and has hit bugs   |'
	@echo '| on quite a few occasions.                                   |'
	@echo '|                                                             |'
	@echo '+-------------------------------------------------------------+'
	@echo ''
endif
#
#------------------------------------------------------------


# The "test -f" support for srcdir!=builddir is similar to the automake .c.o
# etc rules, but with each foo.c explicitly, since $< is not portable
# outside an inference rule.
#
# A quoted 'foo.c' is used with the "test -f"'s to avoid Sun make rewriting
# it as part of its VPATH support.  See the autoconf manual "Limitations of
# Make".
#
# Generated .h files which are used by gmp-impl.h are BUILT_SOURCES since
# they must exist before anything can be compiled.
#
# Other generated .h files are also BUILT_SOURCES so as to get all the
# build-system stuff over and done with at the start.  Also, dependencies on
# the .h files are not properly expressed for the various objects that use
# them.

EXTRA_DIST += bootstrap.c

fac_table.h: gen-fac$(EXEEXT_FOR_BUILD)
	./gen-fac $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >fac_table.h || (rm -f fac_table.h; exit 1)
BUILT_SOURCES += fac_table.h

gen-fac$(EXEEXT_FOR_BUILD): gen-fac$(U_FOR_BUILD).c bootstrap.c
	$(CC_FOR_BUILD) `test -f 'gen-fac$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-fac$(U_FOR_BUILD).c -o gen-fac$(EXEEXT_FOR_BUILD)
DISTCLEANFILES += gen-fac$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-fac.c


fib_table.h: gen-fib$(EXEEXT_FOR_BUILD)
	./gen-fib header $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >fib_table.h || (rm -f fib_table.h; exit 1)
BUILT_SOURCES += fib_table.h

mpn/fib_table.c: gen-fib$(EXEEXT_FOR_BUILD)
	./gen-fib table $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >mpn/fib_table.c || (rm -f mpn/fib_table.c; exit 1)
BUILT_SOURCES += mpn/fib_table.c

gen-fib$(EXEEXT_FOR_BUILD): gen-fib$(U_FOR_BUILD).c bootstrap.c
	$(CC_FOR_BUILD) `test -f 'gen-fib$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-fib$(U_FOR_BUILD).c -o gen-fib$(EXEEXT_FOR_BUILD)
DISTCLEANFILES += gen-fib$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-fib.c


mp_bases.h: gen-bases$(EXEEXT_FOR_BUILD)
	./gen-bases header $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >mp_bases.h || (rm -f mp_bases.h; exit 1)
BUILT_SOURCES += mp_bases.h

mpn/mp_bases.c: gen-bases$(EXEEXT_FOR_BUILD)
	./gen-bases table $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >mpn/mp_bases.c || (rm -f mpn/mp_bases.c; exit 1)
BUILT_SOURCES += mpn/mp_bases.c

gen-bases$(EXEEXT_FOR_BUILD): gen-bases$(U_FOR_BUILD).c bootstrap.c
	$(CC_FOR_BUILD) `test -f 'gen-bases$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-bases$(U_FOR_BUILD).c -o gen-bases$(EXEEXT_FOR_BUILD) $(LIBM_FOR_BUILD)
DISTCLEANFILES += gen-bases$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-bases.c


trialdivtab.h: gen-trialdivtab$(EXEEXT_FOR_BUILD)
	./gen-trialdivtab $(GMP_LIMB_BITS) 8000 >trialdivtab.h || (rm -f trialdivtab.h; exit 1)
BUILT_SOURCES += trialdivtab.h

gen-trialdivtab$(EXEEXT_FOR_BUILD): gen-trialdivtab$(U_FOR_BUILD).c bootstrap.c
	$(CC_FOR_BUILD) `test -f 'gen-trialdivtab$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-trialdivtab$(U_FOR_BUILD).c -o gen-trialdivtab$(EXEEXT_FOR_BUILD) $(LIBM_FOR_BUILD)
DISTCLEANFILES += gen-trialdivtab$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-trialdivtab.c


mpn/jacobitab.h: gen-jacobitab$(EXEEXT_FOR_BUILD)
	./gen-jacobitab >mpn/jacobitab.h || (rm -f mpn/jacobitab.h; exit 1)
BUILT_SOURCES += mpn/jacobitab.h

gen-jacobitab$(EXEEXT_FOR_BUILD): gen-jacobitab$(U_FOR_BUILD).c
	$(CC_FOR_BUILD) `test -f 'gen-jacobitab$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-jacobitab$(U_FOR_BUILD).c -o gen-jacobitab$(EXEEXT_FOR_BUILD)
DISTCLEANFILES += gen-jacobitab$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-jacobitab.c


mpn/perfsqr.h: gen-psqr$(EXEEXT_FOR_BUILD)
	./gen-psqr $(GMP_LIMB_BITS) $(GMP_NAIL_BITS) >mpn/perfsqr.h || (rm -f mpn/perfsqr.h; exit 1)
BUILT_SOURCES += mpn/perfsqr.h

gen-psqr$(EXEEXT_FOR_BUILD): gen-psqr$(U_FOR_BUILD).c bootstrap.c
	$(CC_FOR_BUILD) `test -f 'gen-psqr$(U_FOR_BUILD).c' || echo '$(srcdir)/'`gen-psqr$(U_FOR_BUILD).c -o gen-psqr$(EXEEXT_FOR_BUILD) $(LIBM_FOR_BUILD)
DISTCLEANFILES += gen-psqr$(EXEEXT_FOR_BUILD)
EXTRA_DIST += gen-psqr.c

# Distribute mini-gmp. Test sources copied by dist-hook.
EXTRA_DIST += mini-gmp/README_GMP mini-gmp/mini-gmp.c mini-gmp/mini-gmp.h \
	      mini-gmp/tests/Makefile mini-gmp/tests/run-tests

# Avoid: CVS - cvs directories
#        *~  - emacs backups
#        .#* - cvs merge originals
#
# *~ and .#* only occur when a whole directory without it's own Makefile.am
# is distributed, like "doc" or the mpn cpu subdirectories.
#
dist-hook:
	-find $(distdir) \( -name CVS -type d \) -o -name "*~" -o -name ".#*" \
		| xargs rm -rf
	cp "$(srcdir)"/mini-gmp/tests/*.[ch] "$(distdir)/mini-gmp/tests"
#	grep -F $(VERSION) $(srcdir)/Makefile.am \
#		| grep -q "^# *$(VERSION) *$(LIBGMP_LT_CURRENT):$(LIBGMP_LT_REVISION):$(LIBGMP_LT_AGE) *$(LIBGMPXX_LT_CURRENT):$(LIBGMPXX_LT_REVISION):$(LIBGMPXX_LT_AGE)"
#	test -z "`sed -n 's/^# *[0-9]*\.[0-9]*\.[0-9]* *\([0-9]*:[0-9]*:[0-9]*\) *\([0-9]*:[0-9]*:[0-9]*\) *\([0-9]*:[0-9]*:[0-9]*\).*/A\1\nB\2\nC\3/p' $(srcdir)/Makefile.am | grep -v 'A6:3:3\|B3:5:0\|C4:7:1' | sort | uniq -d`"

.PHONY: check-mini-gmp clean-mini-gmp

check-mini-gmp:
	abs_srcdir="`cd $(srcdir) && pwd`" ; \
	$(MKDIR_P) mini-gmp/tests \
	&& cd mini-gmp/tests \
	&& TEST_LIBRARY_PATH="../../.libs"  \
	   $(MAKE) -f "$$abs_srcdir/mini-gmp/tests/Makefile" \
		VPATH="$$abs_srcdir/mini-gmp/tests" \
		srcdir="$$abs_srcdir/mini-gmp/tests" \
		MINI_GMP_DIR="$$abs_srcdir/mini-gmp" \
		LDFLAGS="-L../../.libs" \
		LIBS="-lgmp -lm" \
		CC="$(CC)" CFLAGS="$(CFLAGS)" CPPFLAGS="-I../.." check

clean-mini-gmp:
	if [ -d mini-gmp/tests ] ; then \
	  abs_srcdir="`cd $(srcdir) && pwd`" ; \
	  cd mini-gmp/tests \
	  && $(MAKE) -f "$$abs_srcdir/mini-gmp/tests/Makefile" clean ; \
	fi

clean-local: clean-mini-gmp
distclean-local: clean-mini-gmp

