//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "cold-hearted");
    addSpecification("description", "You lack affection and warmth "
        "toward other people.");
    addSpecification("root", "cold");
    addSpecification("opposing root", "warm");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
}
