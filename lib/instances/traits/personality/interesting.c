//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "interesting");
    addSpecification("description", "You can easily catch and hold the "
        "attention of those around you.");
    addSpecification("root", "interesting");
    addSpecification("opinion", 5);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus bluff", 1);
}
