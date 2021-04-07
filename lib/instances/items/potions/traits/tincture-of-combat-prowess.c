//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Tincture of Combat Prowess");
    addSpecification("description", "You have quaffed the 'Tincture of "
        "Combat Prowess' potion and are currently benefitting from its effects.");
    addSpecification("root", "abilities");
    addSpecification("opinion", 1);
    addSpecification("duration", 180);
    addSpecification("bonus defense", 5);
    addSpecification("bonus attack", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus parry", 5);
    addSpecification("expire message", "The effects of the 'Tincture of "
        "Combat Prowess' potion subside.");
}
