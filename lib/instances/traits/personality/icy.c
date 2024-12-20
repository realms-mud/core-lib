//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "icy");
    addSpecification("description", "You lack affection and warmth "
        "toward other people with an almost simmering disdain.");
    addSpecification("root", "cold");
    addSpecification("opposing root", "warm");
    addSpecification("opinion", -10);
    addSpecification("opposing opinion", -15);
    addSpecification("penalty to diplomacy", 1);
}
