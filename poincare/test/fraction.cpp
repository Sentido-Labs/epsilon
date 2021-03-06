#include <quiz.h>
#include <poincare.h>
#include <ion.h>
#include <cmath>
#include <assert.h>
#include "helper.h"

using namespace Poincare;

QUIZ_CASE(poincare_fraction_evaluate) {
  Complex<float> a[1] = {Complex<float>::Float(0.5f)};
  assert_parsed_expression_evaluate_to("1/2", a, 1);

  Complex<double> b[1] = {Complex<double>::Cartesian(13.0/17.0, 1.0/17.0)};
  assert_parsed_expression_evaluate_to("(3+I)/(4+I)", b, 1);

#if MATRICES_ARE_DEFINED
  Complex<float> c[6] = {Complex<float>::Float(0.5f), Complex<float>::Float(1.0f), Complex<float>::Float(1.5f), Complex<float>::Float(2.0f), Complex<float>::Float(2.5f), Complex<float>::Float(3.0f)};
  assert_parsed_expression_evaluate_to("[[1,2][3,4][5,6]]/2", c, 6);

  Complex<double> d[6] = {Complex<double>::Cartesian(4.0/17.0, -1.0/17.0), Complex<double>::Cartesian(9.0/17.0, 2.0/17.0), Complex<double>::Cartesian(12.0/17.0, -3.0/17.0), Complex<double>::Cartesian(16.0/17.0, -4.0/17.0), Complex<double>::Cartesian(20.0/17.0, -5.0/17.0), Complex<double>::Cartesian(24.0/17.0, -6.0/17.0)};
  assert_parsed_expression_evaluate_to("[[1,2+I][3,4][5,6]]/(4+I)", d, 6);

  Complex<float> e[4] = {Complex<float>::Float(2.0f), Complex<float>::Float(-1.0f), Complex<float>::Float(1.0f), Complex<float>::Float(0.0f)};
  assert_parsed_expression_evaluate_to("[[1,2][3,4]]/[[3,4][5,6]]", e, 4);

  Complex<double> f[4] = {Complex<double>::Float(-9.0), Complex<double>::Float(6.0), Complex<double>::Float(15.0/2.0), Complex<double>::Float(-9.0/2.0)};
  assert_parsed_expression_evaluate_to("3/[[3,4][5,6]]", f, 4);

  // TODO: add this test when inverse of complex matrix is implemented
  /* Complex<double> g[4] = {Complex<double>::Cartesian(-9.0, -12.0), Complex<double>::Cartesian(6.0, 8.0), Complex<double>::Cartesian(15.0/2.0, 10.0), Complex<double>::Cartesian(-9.0/2.0, -6.0)};
  assert_parsed_expression_evaluate_to("(3+4i)/[[1,2+i][3,4][5,6]]", g, 4);*/

#endif
}
