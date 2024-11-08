//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "envious");
    addSpecification("description", "You want it all. You want it now. "
        "You covet what others have.");
    addSpecification("root", "envious");
    addSpecification("opinion", -5);
}
