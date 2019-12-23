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
        addSpecification("name", "lich");
        addSpecification("description", "You are a lich.");
        addSpecification("root", "undead persona");
        addSpecification("bonus resist undead", 100);
        addSpecification("bonus resist evil", 100);
        addSpecification("bonus resist slash", 50);
        addSpecification("bonus resist thrust", 75);
        addSpecification("bonus resist air", 25);
        addSpecification("bonus resist earth", 25);
        addSpecification("bonus resist fire", 25);
        addSpecification("bonus resist water", 25);
        addSpecification("bonus resist magical", 25);
        addSpecification("bonus resist energy", 25);
        addSpecification("bonus resist electricity", 25);
        "baseTrait"::reset(arg);
    }
}
