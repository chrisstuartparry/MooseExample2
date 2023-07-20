#include "Example2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Example2App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Example2App::Example2App(InputParameters parameters) : MooseApp(parameters)
{
  Example2App::registerAll(_factory, _action_factory, _syntax);
}

Example2App::~Example2App() {}

void 
Example2App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<Example2App>(f, af, s);
  Registry::registerObjectsTo(f, {"Example2App"});
  Registry::registerActionsTo(af, {"Example2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Example2App::registerApps()
{
  registerApp(Example2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Example2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Example2App::registerAll(f, af, s);
}
extern "C" void
Example2App__registerApps()
{
  Example2App::registerApps();
}
