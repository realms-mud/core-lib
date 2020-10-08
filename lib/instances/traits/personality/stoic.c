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
        addSpecification("type", "personality");
        addSpecification("name", "stoic");
        addSpecification("description", "You tend to not speak of or show "
            "your feelings when enduring hardships or pain.");
        addSpecification("root", "humble");
        addSpecification("opinion", 5);
        "baseTrait"::reset(arg);
    }
}
