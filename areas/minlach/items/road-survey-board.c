//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("road survey board");
    addAlias("survey map");
    addDescriptionTemplate("a field board covered with route marks and tallies");
    addItemTemplate("The marks show the forest waystations, Minlach's watch "
        "routes, and stores set aside for local use. A sealed copy of "
        "Basil's report is addressed to Lord Argalen. A note beneath it "
        "says that Minlach's council must approve any use of town stores "
        "or watch personnel.");
}
