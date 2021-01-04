//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "gargoyle");
        addSpecification("description", "You are a gargoyle.");
        addSpecification("root", "creature persona");
        addSpecification("bonus defense", 6);
        "baseTrait"::reset(arg);
    }
}
