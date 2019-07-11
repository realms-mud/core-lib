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
        addSpecification("type", "professional");
        addSpecification("name", "journeyman carpenter");
        addSpecification("description", "You are an adept carpenter");
        addSpecification("root", "carpenter");
        addSpecification("opinion", 1);
        addSpecification("bonus carpentry", 10);
        addSpecification("bonus wood crafting", 5);
        "baseTrait"::reset(arg);
    }
}
