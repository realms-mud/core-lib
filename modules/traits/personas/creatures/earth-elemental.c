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
        addSpecification("type", "persona");
        addSpecification("name", "earth elemental");
        addSpecification("description", "You are an earth elemental.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist earth", 100);
        addSpecification("bonus resist physical", 50);
        "baseTrait"::reset(arg);
    }
}
