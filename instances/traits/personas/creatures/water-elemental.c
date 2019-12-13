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
        addSpecification("type", "persona");
        addSpecification("name", "water elemental");
        addSpecification("description", "You are a water elemental.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist water", 100);
        addSpecification("bonus resist cold", 100);
        "baseTrait"::reset(arg);
    }
}
