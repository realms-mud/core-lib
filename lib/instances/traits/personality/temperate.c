//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "temperate");
    addSpecification("description", "You tend to show moderation and "
        "restraint in all of your outward actions and interactions.");
    addSpecification("root", "kind");
    addSpecification("opposing root", "harsh");
    addSpecification("opinion", 15);
    addSpecification("opposing opinion", -5);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus etiquette", 1);
}
