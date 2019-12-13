//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "envious");
        addSpecification("description", "You want it all. You want it now. "
            "You covet what others have.");
        addSpecification("root", "envious");
        addSpecification("opinion", -5);
        "baseTrait"::reset(arg);
    }
}
