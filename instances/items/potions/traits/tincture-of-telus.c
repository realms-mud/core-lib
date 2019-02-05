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
        addSpecification("type", "effect");
        addSpecification("name", "Tincture of Telus");
        addSpecification("description", "You have quaffed the 'Tincture of "
            "Telus' potion and are currently benefitting from its effects.");
        addSpecification("root", "healthy");
        addSpecification("opposing root", "infirm");
        addSpecification("opinion", 10);
        addSpecification("duration", 300);
        addSpecification("bonus hit points", 100);
        addSpecification("bonus attack", 5);
        addSpecification("bonus defense", 5);
        addSpecification("expire message", "The effects of the 'Tincture of "
            "Telus' potion subside.");
        "baseTrait"::reset(arg);
    }
}
