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
        addSpecification("name", "keeper of the night");
        addSpecification("description", "You are a keeper of the night.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist undead", 100);
        addSpecification("bonus resist evil", 100);
        addSpecification("bonus resist electricity", 25);
        "baseTrait"::reset(arg);
    }
}
