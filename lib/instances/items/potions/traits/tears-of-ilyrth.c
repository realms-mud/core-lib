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
        addSpecification("type", "effect");
        addSpecification("name", "Tears of Ilyrth");
        addSpecification("description", "You have quaffed the 'Tears of "
            "Ilyrth' potion and are currently benefitting from its effects.");
        addSpecification("root", "healthy");
        addSpecification("opposing root", "infirm");
        addSpecification("opinion", 10);
        addSpecification("duration", 300);
        addSpecification("bonus hit points", 100);
        addSpecification("bonus spell points", 100);
        addSpecification("bonus defense", 5);
        addSpecification("expire message", "The effects of the 'Tears of "
            "Ilyrth' potion subside.");
        "baseTrait"::reset(arg);
    }
}
