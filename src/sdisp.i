%feature("autodoc", "1");
%include "typemaps.i"
%include "carrays.i"
%include "cstring.i"
%include "stdint.i"

%module(docstring="Interface for libsdisp") sdisp
%{
#include "sdisp.h"
%}

%include "sdisp_config.h"
%include "sdisp.h"


