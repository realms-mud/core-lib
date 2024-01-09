//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Charisma");
    addSpecification("description", "You have quaffed the 'Charisma' "
        "potion and are currently benefitting from its effects.");
    addSpecification("root", "abilities");
    addSpecification("opinion", 25);
    addSpecification("duration", 180);
    addSpecification("bonus charisma", 2);
    addSpecification("expire message", "The effects of the 'Charisma' "
        "potion subside.");
}
