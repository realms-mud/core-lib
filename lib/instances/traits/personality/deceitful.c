//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "deceitful");
    addSpecification("description", "You are a dishonest, mendacious "
        "person.");
    addSpecification("root", "dishonorable");
    addSpecification("opposing root", "honorable");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
    addSpecification("bonus bluff", 1);
    addSpecification("penalty to diplomacy", 2);
}
