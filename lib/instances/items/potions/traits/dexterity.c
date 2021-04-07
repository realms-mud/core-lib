//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Dexterity");
    addSpecification("description", "You have quaffed the 'Dexterity' "
        "potion and are currently benefitting from its effects.");
    addSpecification("root", "abilities");
    addSpecification("opinion", 1);
    addSpecification("duration", 180);
    addSpecification("bonus dexterity", 2);
    addSpecification("expire message", "The effects of the 'Dexterity' "
        "potion subside.");
}
