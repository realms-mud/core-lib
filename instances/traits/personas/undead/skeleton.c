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
        addSpecification("name", "skeleton");
        addSpecification("description", "You are a skeleton.");
        addSpecification("root", "undead persona");
        addSpecification("bonus resist undead", 100);
        addSpecification("bonus resist evil", 100);
        addSpecification("bonus resist slash", 50);
        addSpecification("bonus resist thrust", 75);
        "baseTrait"::reset(arg);
    }
}
