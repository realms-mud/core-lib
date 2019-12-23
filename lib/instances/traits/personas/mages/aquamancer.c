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
        addSpecification("name", "aquamancer");
        addSpecification("description", "You are an aquamancer.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist water", 75);
        "baseTrait"::reset(arg);
    }
}
