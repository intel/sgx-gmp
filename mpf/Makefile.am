## Process this file with automake to generate Makefile.in

# Copyright 1996, 1998-2002 Free Software Foundation, Inc.
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

# Include the automake definitions for building an Intel SGX trusted
# enclave library.
# - John Mechalas <john.p.mechalas@intel.com>
include $(top_srcdir)/sgx_tlib.am


#------------------------------------------------------------
# Set build flags and sources for the Intel SGX build. This
# include the architecture flags for the CPU, which libtool
# would normally take care of.
# - John Mechalas <john.p.mechalas@intel.com>
#

MPF_SOURCES= \
  init.c init2.c inits.c set.c set_ui.c set_si.c set_str.c set_d.c set_z.c \
  set_q.c iset.c iset_ui.c iset_si.c iset_str.c iset_d.c clear.c clears.c \
  get_str.c dump.c size.c eq.c reldiff.c sqrt.c random2.c \
  add.c add_ui.c sub.c sub_ui.c ui_sub.c mul.c mul_ui.c div.c div_ui.c \
  cmp.c cmp_d.c cmp_z.c cmp_si.c cmp_ui.c mul_2exp.c div_2exp.c abs.c neg.c get_d.c \
  get_d_2exp.c set_dfl_prec.c set_prc.c set_prc_raw.c get_dfl_prec.c get_prc.c \
  ui_div.c sqrt_ui.c \
  pow_ui.c urandomb.c swap.c get_si.c get_ui.c int_p.c \
  ceilfloor.c trunc.c \
  fits_sint.c fits_slong.c fits_sshort.c \
  fits_uint.c fits_ulong.c fits_ushort.c \
  fits_s.h fits_u.h

if SGX_ENABLED

AM_CFLAGS += $(CFLAGS_CPU)
AM_CPPFLAGS += -D__GMP_WITHIN_GMP -I$(top_srcdir)

noinst_LIBRARIES = libmpf.a
libmpf_a_CFLAGS = $(AM_CFLAGS)
libmpf_a_SOURCES = $(MPF_SOURCES)

else !SGX_ENABLED

AM_CPPFLAGS = -D__GMP_WITHIN_GMP -I$(top_srcdir)

noinst_LTLIBRARIES = libmpf.la
libmpf_la_SOURCES = $(MPF_SOURCES)

endif

#
#------------------------------------------------------------
