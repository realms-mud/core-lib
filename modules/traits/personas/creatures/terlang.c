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
        addSpecification("name", "terlang");
        addSpecification("description", "You are a terlang.");
        addSpecification("root", "creature persona");
        addSpecification("bonus soak", 10);
        "baseTrait"::reset(arg);
    }
}
