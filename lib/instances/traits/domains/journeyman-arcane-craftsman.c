//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "journeyman arcane craftsman");
    addSpecification("description", "You are an adept arcane craftsman");
    addSpecification("root", "arcane craftsman");
    addSpecification("opinion", 1);
    addSpecification("bonus engineering", 10);
    addSpecification("bonus mathematics", 5);
    addSpecification("bonus physics", 5);
    addSpecification("bonus spellcraft", 5);
}
