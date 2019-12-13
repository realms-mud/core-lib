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
        addSpecification("type", "effect");
        addSpecification("name", "Wisdom");
        addSpecification("description", "You have quaffed the 'Wisdom' "
            "potion and are currently benefitting from its effects.");
        addSpecification("root", "abilities");
        addSpecification("opinion", 1);
        addSpecification("duration", 180);
        addSpecification("bonus wisdom", 2);
        addSpecification("expire message", "The effects of the 'Wisdom' "
            "potion subside.");
        "baseTrait"::reset(arg);
    }
}
