//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "honest");
    addSpecification("description", "You are sincere in your speech and try not to deceive others.");
    addSpecification("root", "honorable");
    addSpecification("opposing root", "dishonorable");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -5);
    addSpecification("bonus persuasion", 1);
    addSpecification("penalty to bluff", 1);
}
