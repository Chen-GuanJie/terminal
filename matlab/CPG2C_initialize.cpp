//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CPG2C_initialize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 13-May-2022 03:19:19
//

// Include Files
#include "CPG2C_initialize.h"
#include "CPG2C_data.h"
#include "CPG2C_types.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void CPG2C_initialize()
{
  fai.size[0] = 0;
  fai.size[1] = 0;
  w.size[0] = 0;
  w.size[1] = 0;
  std::memset(&R[0], 0, 324U * sizeof(double));
  std::memset(&v[0], 0, 324U * sizeof(double));
  isInitialized_CPG2C = true;
}

//
// File trailer for CPG2C_initialize.cpp
//
// [EOF]
//
