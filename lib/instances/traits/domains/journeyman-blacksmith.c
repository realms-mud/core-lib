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
        addSpecification("name", "journeyman blacksmith");
        addSpecification("description", "You are an adept blacksmith");
        addSpecification("root", "blacksmith");
        addSpecification("opinion", 1);
        addSpecification("bonus blacksmithing", 10);
        addSpecification("bonus metal crafting", 5);
        "baseTrait"::reset(arg);
    }
}
