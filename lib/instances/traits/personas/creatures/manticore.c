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
        addSpecification("name", "manticore");
        addSpecification("description", "You are a manticore.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus soak", 3);
        "baseTrait"::reset(arg);
    }
}
