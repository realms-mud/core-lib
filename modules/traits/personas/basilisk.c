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
        addSpecification("name", "basilisk");
        addSpecification("description", "You are a basilisk.");
        addSpecification("root", "creature persona");
        addSpecification("bonus soak", 5);
        "baseTrait"::reset(arg);
    }
}
