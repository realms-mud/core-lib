//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "knight of the storm");
        addSpecification("description", "You are a knight of the storm.");
        addSpecification("root", "fighter persona");
        "baseTrait"::reset(arg);
        addSpecification("bonus resist electricity", 50);
    }
}
