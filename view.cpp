using namespace Gtk;

#include "ApplicationUI.h"
#include "definitions.h"

View::View(Controller& rCon)
{
	launchWindow(rCon);
}

View::launchWindow(Controller& rCont)
{
	ApplicationUI AppUI(rCont);
	Gtk::Main::run(AppUI);
}
