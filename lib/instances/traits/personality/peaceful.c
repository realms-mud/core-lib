//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "peaceful");
    addSpecification("description", "You default to a rather tranquil, "
        "calm demeanor.");
    addSpecification("root", "peaceful");
    addSpecification("opinion", 10);
    addSpecification("bonus diplomacy", 1);
}
