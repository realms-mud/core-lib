//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "drunk");
    addSpecification("description", "You are drunk.");
    addSpecification("root", "biological");
    addSpecification("opinion", -25);
    addSpecification("bonus heal spell points", 10);
    addSpecification("penalty to defense", 3);
    addSpecification("penalty to wisdom", 1);
    addSpecification("penalty to dexterity", 2);
    addSpecification("duration", 300);
    addSpecification("expire message", "You are no longer drunk.");
}
