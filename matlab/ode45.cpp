//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ode45.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 13-May-2022 03:19:19
//

// Include Files
#include "ode45.h"
#include "CPG2C_data.h"
#include "CPG2C_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <math.h>

// Function Declarations
static int div_nde_s32_floor(int numerator);

static double rt_powd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : int numerator
// Return Type  : int
//
static int div_nde_s32_floor(int numerator)
{
  int b_numerator;
  if ((numerator < 0) && (numerator % 36 != 0)) {
    b_numerator = -1;
  } else {
    b_numerator = 0;
  }
  return numerator / 36 + b_numerator;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : const double tspan[2]
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
namespace coder {
void ode45(const double tspan[2], ::coder::array<double, 1U> &varargout_1,
           ::coder::array<double, 2U> &varargout_2)
{
  static const double dv[36]{0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             0.001,
                             3.1415926535897931,
                             0.001,
                             3.1415926535897931,
                             3.1415926535897931,
                             0.001,
                             3.1415926535897931,
                             0.001,
                             0.001,
                             3.1415926535897931,
                             0.001,
                             3.1415926535897931};
  static const double varargin_2[36]{0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     3.1415926535897931,
                                     0.0,
                                     3.1415926535897931,
                                     3.1415926535897931,
                                     0.0,
                                     3.1415926535897931,
                                     0.0,
                                     0.0,
                                     3.1415926535897931,
                                     0.0,
                                     3.1415926535897931};
  static const double x[21]{0.2,
                            0.075,
                            0.225,
                            0.97777777777777775,
                            -3.7333333333333334,
                            3.5555555555555554,
                            2.9525986892242035,
                            -11.595793324188385,
                            9.8228928516994358,
                            -0.29080932784636487,
                            2.8462752525252526,
                            -10.757575757575758,
                            8.9064227177434727,
                            0.27840909090909088,
                            -0.2735313036020583,
                            0.091145833333333329,
                            0.0,
                            0.44923629829290207,
                            0.65104166666666663,
                            -0.322376179245283,
                            0.13095238095238096};
  static const double b[7]{0.0012326388888888888,
                           0.0,
                           -0.0042527702905061394,
                           0.036979166666666667,
                           -0.05086379716981132,
                           0.0419047619047619,
                           -0.025};
  static const double b_b[7]{-2.859375,
                             0.0,
                             4.0431266846361185,
                             -3.90625,
                             2.7939268867924527,
                             -1.5714285714285714,
                             1.5};
  static const double c_b[7]{3.0833333333333335,
                             0.0,
                             -6.2893081761006293,
                             10.416666666666666,
                             -6.8773584905660377,
                             3.6666666666666665,
                             -4.0};
  static const double d_b[7]{-1.1328125,
                             0.0,
                             2.6954177897574123,
                             -5.859375,
                             3.7610554245283021,
                             -1.9642857142857142,
                             2.5};
  array<double, 2U> tout;
  array<double, 2U> yout;
  double f[252];
  double youtnew[144];
  double f0[36];
  double y[36];
  double ynew[36];
  double ystage[36];
  double absh;
  double absx;
  double hmax;
  double t;
  double tdir;
  double temp;
  double tfinal;
  int b_i;
  int b_ncols;
  int exponent;
  int i;
  int ncols;
  int nout;
  boolean_T Done;
  boolean_T MinStepExit;
  tfinal = tspan[1];
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  std::memset(&f0[0], 0, 36U * sizeof(double));
  // r:drdtheta(1-18)
  // theta:drdtheta(19-36)
  for (i = 0; i < 18; i++) {
    f0[i] = 5.0 * (R[i] - varargin_2[i]);
    temp = 0.0;
    for (int j{0}; j < 18; j++) {
      temp += w.data[j + w.size[0] * i] * varargin_2[j] *
              std::sin((varargin_2[j + 18] - varargin_2[i + 18]) -
                       fai.data[i + fai.size[0] * j]);
    }
    f0[i + 18] = 6.2831853071795862 * v[i] + temp;
  }
  tout.set_size(1, 200);
  for (b_i = 0; b_i < 200; b_i++) {
    tout[b_i] = 0.0;
  }
  yout.set_size(36, 200);
  for (b_i = 0; b_i < 7200; b_i++) {
    yout[b_i] = 0.0;
  }
  nout = 0;
  tout[0] = 0.0;
  temp = std::abs(tspan[1]);
  hmax = std::fmin(temp, std::fmax(0.1 * temp, 3.5527136788005009E-15 *
                                                   std::fmax(0.0, temp)));
  absh = std::fmin(hmax, temp);
  temp = 0.0;
  for (ncols = 0; ncols < 36; ncols++) {
    yout[ncols] = varargin_2[ncols];
    absx = std::abs(f0[ncols] / dv[ncols]);
    if (std::isnan(absx) || (absx > temp)) {
      temp = absx;
    }
  }
  temp /= 0.20095091452076641;
  if (absh * temp > 1.0) {
    absh = 1.0 / temp;
  }
  absh = std::fmax(absh, 7.90505033345994E-323);
  t = 0.0;
  std::copy(&varargin_2[0], &varargin_2[36], &y[0]);
  std::memset(&f[0], 0, 252U * sizeof(double));
  std::copy(&f0[0], &f0[36], &f[0]);
  tdir = tspan[1];
  if (!std::isnan(tspan[1])) {
    if (tspan[1] < 0.0) {
      tdir = -1.0;
    } else {
      tdir = (tspan[1] > 0.0);
    }
  }
  MinStepExit = false;
  Done = false;
  int exitg1;
  do {
    double d;
    double h;
    double h_tmp;
    double hmin;
    double mxerr;
    double tnew;
    int outidx;
    boolean_T NoFailedAttempts;
    exitg1 = 0;
    absx = std::abs(t);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        temp = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        temp = std::ldexp(1.0, exponent - 53);
      }
    } else {
      temp = rtNaN;
    }
    hmin = 16.0 * temp;
    absh = std::fmin(hmax, std::fmax(hmin, absh));
    h = tdir * absh;
    mxerr = tfinal - t;
    d = std::abs(mxerr);
    if (1.1 * absh >= d) {
      h = mxerr;
      absh = d;
      Done = true;
    }
    NoFailedAttempts = true;
    int Bcolidx;
    int exitg2;
    do {
      exitg2 = 0;
      Bcolidx = 0;
      for (int j{0}; j < 5; j++) {
        Bcolidx += j;
        std::copy(&y[0], &y[36], &ystage[0]);
        if (!(h == 0.0)) {
          b_i = 36 * j + 1;
          for (ncols = 1; ncols <= b_i; ncols += 36) {
            absx = h * x[Bcolidx + div_nde_s32_floor(ncols - 1)];
            i = ncols + 35;
            for (outidx = ncols; outidx <= i; outidx++) {
              b_ncols = outidx - ncols;
              ystage[b_ncols] += f[outidx - 1] * absx;
            }
          }
        }
        // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        std::memset(&f[j * 36 + 36], 0, 36U * sizeof(double));
        // r:drdtheta(1-18)
        // theta:drdtheta(19-36)
        for (i = 0; i < 18; i++) {
          b_ncols = i + 36 * (j + 1);
          f[b_ncols] = 5.0 * (R[i] - ystage[i]);
          temp = 0.0;
          for (ncols = 0; ncols < 18; ncols++) {
            temp += w.data[ncols + w.size[0] * i] * ystage[ncols] *
                    std::sin((ystage[ncols + 18] - ystage[i + 18]) -
                             fai.data[i + fai.size[0] * ncols]);
          }
          f[b_ncols + 18] = 6.2831853071795862 * v[i] + temp;
        }
      }
      tnew = t + h;
      std::copy(&y[0], &y[36], &ynew[0]);
      if (!(h == 0.0)) {
        for (ncols = 0; ncols <= 180; ncols += 36) {
          absx = h * x[(Bcolidx + div_nde_s32_floor(ncols)) + 5];
          b_i = ncols + 36;
          for (outidx = ncols + 1; outidx <= b_i; outidx++) {
            b_ncols = (outidx - ncols) - 1;
            ynew[b_ncols] += f[outidx - 1] * absx;
          }
        }
      }
      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      std::memset(&f[216], 0, 36U * sizeof(double));
      // r:drdtheta(1-18)
      // theta:drdtheta(19-36)
      for (i = 0; i < 18; i++) {
        f[i + 216] = 5.0 * (R[i] - ynew[i]);
        temp = 0.0;
        for (int j{0}; j < 18; j++) {
          temp += w.data[j + w.size[0] * i] * ynew[j] *
                  std::sin((ynew[j + 18] - ynew[i + 18]) -
                           fai.data[i + fai.size[0] * j]);
        }
        f[i + 234] = 6.2831853071795862 * v[i] + temp;
      }
      for (b_i = 0; b_i < 36; b_i++) {
        mxerr = 0.0;
        for (i = 0; i < 7; i++) {
          mxerr += f[b_i + 36 * i] * b[i];
        }
        ystage[b_i] = mxerr;
      }
      if (Done) {
        tnew = tfinal;
      }
      h_tmp = tnew - t;
      mxerr = 0.0;
      for (ncols = 0; ncols < 36; ncols++) {
        absx = std::abs(ystage[ncols]);
        temp = std::abs(y[ncols]);
        h = std::abs(ynew[ncols]);
        if ((temp > h) || std::isnan(h)) {
          if (temp > 0.001) {
            absx /= temp;
          } else {
            absx /= 0.001;
          }
        } else if (h > 0.001) {
          absx /= h;
        } else {
          absx /= 0.001;
        }
        if ((absx > mxerr) || std::isnan(absx)) {
          mxerr = absx;
        }
      }
      h = absh * mxerr;
      if (!(h <= 0.001)) {
        if (absh <= hmin) {
          MinStepExit = true;
          exitg2 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            absh = std::fmax(
                hmin, absh * std::fmax(0.1, 0.8 * rt_powd_snf(0.001 / h, 0.2)));
          } else {
            absh = std::fmax(hmin, 0.5 * absh);
          }
          h = tdir * absh;
          Done = false;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    if (MinStepExit) {
      exitg1 = 1;
    } else {
      double fhBI3[36];
      double fhBI4[36];
      double toutnew[4];
      double tref[3];
      outidx = nout + 1;
      mxerr = t + h_tmp * 0.25;
      tref[0] = mxerr;
      toutnew[0] = mxerr;
      mxerr = t + h_tmp * 0.5;
      tref[1] = mxerr;
      toutnew[1] = mxerr;
      mxerr = t + h_tmp * 0.75;
      tref[2] = mxerr;
      toutnew[2] = mxerr;
      toutnew[3] = tnew;
      for (b_i = 0; b_i < 36; b_i++) {
        ystage[b_i] = f[b_i] * h_tmp;
        mxerr = 0.0;
        d = 0.0;
        absx = 0.0;
        for (i = 0; i < 7; i++) {
          temp = f[b_i + 36 * i];
          mxerr += temp * (h_tmp * b_b[i]);
          d += temp * (h_tmp * c_b[i]);
          absx += temp * (h_tmp * d_b[i]);
        }
        fhBI4[b_i] = absx;
        fhBI3[b_i] = d;
        f0[b_i] = mxerr;
      }
      for (int j{0}; j < 3; j++) {
        absx = (tref[j] - t) / h_tmp;
        for (ncols = 0; ncols < 36; ncols++) {
          youtnew[ncols + 36 * j] =
              (((fhBI4[ncols] * absx + fhBI3[ncols]) * absx + f0[ncols]) *
                   absx +
               ystage[ncols]) *
                  absx +
              y[ncols];
        }
      }
      std::copy(&ynew[0], &ynew[36], &youtnew[108]);
      nout += 4;
      if (nout + 1 > tout.size(1)) {
        b_ncols = tout.size(1);
        tout.set_size(1, tout.size(1) + 200);
        ncols = yout.size(1);
        yout.set_size(36, yout.size(1) + 200);
        for (int j{0}; j < 200; j++) {
          tout[b_ncols + j] = 0.0;
          for (i = 0; i < 36; i++) {
            yout[i + 36 * (ncols + j)] = 0.0;
          }
        }
      }
      for (ncols = 0; ncols < 4; ncols++) {
        b_ncols = ncols + outidx;
        tout[b_ncols] = toutnew[ncols];
        for (int j{0}; j < 36; j++) {
          yout[j + 36 * b_ncols] = youtnew[j + 36 * ncols];
        }
      }
      if (Done) {
        exitg1 = 1;
      } else {
        if (NoFailedAttempts) {
          temp = 1.25 * rt_powd_snf(h / 0.001, 0.2);
          if (temp > 0.2) {
            absh /= temp;
          } else {
            absh *= 5.0;
          }
        }
        t = tnew;
        for (i = 0; i < 36; i++) {
          y[i] = ynew[i];
          f[i] = f[i + 216];
        }
      }
    }
  } while (exitg1 == 0);
  if (nout + 1 < 1) {
    b_ncols = -1;
  } else {
    b_ncols = nout;
  }
  varargout_1.set_size(b_ncols + 1);
  for (b_i = 0; b_i <= b_ncols; b_i++) {
    varargout_1[b_i] = tout[b_i];
  }
  if (nout + 1 < 1) {
    b_ncols = -1;
  } else {
    b_ncols = nout;
  }
  varargout_2.set_size(b_ncols + 1, 36);
  for (b_i = 0; b_i < 36; b_i++) {
    for (i = 0; i <= b_ncols; i++) {
      varargout_2[i + varargout_2.size(0) * b_i] = yout[b_i + 36 * i];
    }
  }
}

} // namespace coder

//
// File trailer for ode45.cpp
//
// [EOF]
//
