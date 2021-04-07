//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "unjust");
    addSpecification("description", "You have a keen sense for what is morally right and fair.");
    addSpecification("root", "dishonorable");
    addSpecification("opposing root", "honorable");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus bluff", 1);
}
