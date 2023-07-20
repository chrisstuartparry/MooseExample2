//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "Example2TestApp.h"
#include "Example2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
Example2TestApp::validParams()
{
  InputParameters params = Example2App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Example2TestApp::Example2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  Example2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

Example2TestApp::~Example2TestApp() {}

void
Example2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  Example2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"Example2TestApp"});
    Registry::registerActionsTo(af, {"Example2TestApp"});
  }
}

void
Example2TestApp::registerApps()
{
  registerApp(Example2App);
  registerApp(Example2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
Example2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Example2TestApp::registerAll(f, af, s);
}
extern "C" void
Example2TestApp__registerApps()
{
  Example2TestApp::registerApps();
}
