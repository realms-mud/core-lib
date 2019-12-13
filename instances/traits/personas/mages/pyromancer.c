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
        addSpecification("name", "pyromancer");
        addSpecification("description", "You are a pyromancer.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist fire", 75);
        "baseTrait"::reset(arg);
    }
}
