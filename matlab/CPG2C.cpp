//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CPG2C.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 13-May-2022 03:19:19
//

// Include Files
#include "CPG2C.h"
#include "CPG2C_data.h"
#include "CPG2C_initialize.h"
#include "CPG2C_types.h"
#include "ode45.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// 1:Single Axial CPG with Limb Model
// 2:Double Axial CPG with Limb Model
//
// Arguments    : const double d[18]
//                double tspan
//                coder::array<double, 1U> &t
//                coder::array<double, 2U> &angle
// Return Type  : void
//
void CPG2C(const double d[18], double tspan, coder::array<double, 1U> &t,
           coder::array<double, 2U> &angle)
{
  coder::array<double, 2U> rtheta;
  int b_i;
  if (!isInitialized_CPG2C) {
    CPG2C_initialize();
  }
  //  CPGModel=1;
  // Single Axial CPG with Limb Model
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Parameter Setting
  // R v Parameter Setting
  // R v Expression
  std::memset(&v[0], 0, 324U * sizeof(double));
  std::memset(&R[0], 0, 324U * sizeof(double));
  for (int i{0}; i < 18; i++) {
    if (i + 1 <= 6) {
      double b_d;
      b_d = d[i];
      R[i] = b_d * (1.0 / (std::exp(500.0 * (b_d - 3.0)) + 1.0));
      v[i] = b_d * 1.1;
    } else {
      double b_d;
      b_d = d[i];
      R[i] = b_d * (1.0 / (std::exp(500.0 * (b_d - 1.27)) + 1.0));
      v[i] = b_d * 0.65;
    }
  }
  // CPG Parameter Setting
  // others
  // w
  w.size[0] = 18;
  w.size[1] = 18;
  std::memset(&w.data[0], 0, 324U * sizeof(double));
  for (int i{0}; i < 18; i++) {
    for (int j{0}; j < 18; j++) {
      // axial
      if ((i + 1 == j) && (j + 1 <= 6)) {
        w.data[i + 18 * j] = 5.0;
      } else if ((i + 1 == j + 2) && (i + 1 <= 6)) {
        w.data[i + 18 * j] = 1.0;
      }
      // interlimb
      if ((i + 1 == j + 5) ||
          ((i + 1 == j - 3) && (j + 1 > 6) && (i + 1 > 6))) {
        w.data[i + 18 * j] = 1.0;
      }
      // axial to limb
      if (((i + 1 == 1) && ((j + 1 == 7) || (j + 1 == 8))) ||
          ((i + 1 == 4) && ((j + 1 == 9) || (j + 1 == 10)))) {
        w.data[i + 18 * j] = 2.0;
      }
      // limb to axial
      if ((((j + 1 == 7) || (j + 1 == 8)) && (i + 1 == 1)) ||
          (((i + 1 == 9) || (i + 1 == 10)) && (j + 1 == 4))) {
        w.data[i + 18 * j] = 0.0;
      }
    }
  }
  // fai
  fai.size[0] = 18;
  fai.size[1] = 18;
  std::memset(&fai.data[0], 0, 324U * sizeof(double));
  for (int i{0}; i < 18; i++) {
    for (int j{0}; j < 18; j++) {
      // axial
      if ((i + 1 == j) && (j + 1 <= 6)) {
        fai.data[i + 18 * j] = 0.41469023027385271;
      } else if ((i + 1 == j + 2) && (i + 1 <= 6)) {
        fai.data[i + 18 * j] = -0.41469023027385271;
      }
      // interlimb
      if (((i + 1 == j + 5) && (j + 1 > 6)) ||
          ((i + 1 > 6) && (i + 1 == j - 3))) {
        fai.data[i + 18 * j] = 3.1415926535897931;
      }
      // axial to limb
      if (((i + 1 == 1) && (j + 1 == 7)) || ((i + 1 == 4) && (j + 1 == 9))) {
        fai.data[i + 18 * j] = -1.0;
      }
      if (((i + 1 == 1) && (j + 1 == 8)) || ((i + 1 == 4) && (j + 1 == 10))) {
        fai.data[i + 18 * j] = 3.1415926535897931;
      }
      // limb to axial
      if ((((i + 1 == 7) || (i + 1 == 8)) && (j + 1 == 1)) ||
          (((i + 1 == 9) || (i + 1 == 10)) && (j + 1 == 4))) {
        fai.data[i + 18 * j] = 3.1415926535897931;
      }
    }
  }
  double dv[2];
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // CPG Important Differential Equation
  dv[0] = 0.0;
  dv[1] = tspan;
  coder::ode45(dv, t, rtheta);
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // n=2*CPG Number
  // m=Simulated Point Number
  angle.set_size(rtheta.size(0), 18);
  b_i = rtheta.size(0);
  for (int j{0}; j < 18; j++) {
    for (int i{0}; i < b_i; i++) {
      angle[i + angle.size(0) * j] =
          10.0 * (rtheta[i + rtheta.size(0) * j] *
                  std::cos(rtheta[i + rtheta.size(0) * (j + 18)]));
    }
  }
}

//
// File trailer for CPG2C.cpp
//
// [EOF]
//
