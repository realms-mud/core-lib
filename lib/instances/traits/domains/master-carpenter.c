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
        addSpecification("type", "professional");
        addSpecification("name", "master carpenter");
        addSpecification("description", "You are a master carpenter");
        addSpecification("root", "carpenter");
        addSpecification("opinion", 5);
        addSpecification("bonus carpentry", 25);
        addSpecification("bonus wood crafting", 20);
        addSpecification("bonus engineering", 5);
        "baseTrait"::reset(arg);
    }
}
