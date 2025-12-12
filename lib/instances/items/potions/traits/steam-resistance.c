//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Steam Resistance");
    addSpecification("description", "You have quaffed the 'Steam "
        "Resistance' potion and are currently benefitting from its effects.");
    addSpecification("root", "resisting");
    addSpecification("opposing root", "vulnerable");
    addSpecification("opinion", 1);
    addSpecification("duration", 180);
    addSpecification("bonus resist steam", 50);
    addSpecification("expire message", "The effects of the 'Steam "
        "Resistance' potion subside.");
}
