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
        addSpecification("name", "cryomancer");
        addSpecification("description", "You are a cryomancer.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist cold", 75);
        "baseTrait"::reset(arg);
    }
}
