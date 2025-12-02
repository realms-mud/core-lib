//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Speed");
    addSpecification("description", "You have quaffed the 'Speed' "
        "potion and are currently benefitting from its effects.");
    addSpecification("root", "abilities");
    addSpecification("opinion", 1);
    addSpecification("duration", 180);
    addSpecification("bonus haste", 1);
    addSpecification("expire message", "The effects of the 'Speed' "
        "potion subside.");
}
