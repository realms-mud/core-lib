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
        addSpecification("name", "shadow");
        addSpecification("description", "You are a shadow.");
        addSpecification("root", "undead persona");
        addSpecification("bonus resist undead", 100);
        addSpecification("bonus resist evil", 100);
        addSpecification("bonus resist physical", 100);
        "baseTrait"::reset(arg);
    }
}
