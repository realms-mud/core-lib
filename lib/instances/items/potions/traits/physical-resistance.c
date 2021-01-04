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
        addSpecification("name", "Physical Resistance");
        addSpecification("description", "You have quaffed the 'Physical "
            "Resistance' potion and are currently benefitting from its effects.");
        addSpecification("root", "resisting");
        addSpecification("opposing root", "vulnerable");
        addSpecification("opinion", 1);
        addSpecification("duration", 180);
        addSpecification("bonus resist physical", 50);
        addSpecification("expire message", "The effects of the 'Physical "
            "Resistance' potion subside.");
        "baseTrait"::reset(arg);
    }
}
