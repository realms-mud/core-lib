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
        addSpecification("name", "geomancer");
        addSpecification("description", "You are a geomancer.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist earth", 75);
        "baseTrait"::reset(arg);
    }
}
