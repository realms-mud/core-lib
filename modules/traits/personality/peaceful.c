//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "peaceful");
        addSpecification("description", "You default to a rather tranquil, "
            "calm demeanor.");
        addSpecification("root", "peaceful");
        addSpecification("opinion", 10);
        addSpecification("bonus diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
