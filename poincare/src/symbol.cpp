#include <poincare/symbol.h>
#include <poincare/context.h>
#include <stdlib.h>
#include "layout/string_layout.h"
extern "C" {
#include <assert.h>
}

Symbol::Symbol(const char * name) {
  size_t length = strlen(name);
  m_name = (char *)malloc(sizeof(char)*length+1);
  memcpy(m_name, name, length);
  m_name[length] = 0;
}

Symbol::~Symbol() {
  free(m_name);
}

float Symbol::approximate(Context& context) {
  return context[m_name]->approximate(context);
}

Expression::Type Symbol::type() {
  return Expression::Type::Symbol;
}

ExpressionLayout * Symbol::createLayout() {
  size_t length = strlen(m_name);
  return new StringLayout(m_name, length);
}

Expression * Symbol::clone() {
  return new Symbol(m_name);
}

bool Symbol::valueEquals(Expression * e) {
  assert(e->type() == Expression::Type::Symbol);
  return (strcmp(m_name, ((Symbol *)e)->m_name) == 0);
}