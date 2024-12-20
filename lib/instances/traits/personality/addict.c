//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "addict");
    addSpecification("description", "You are prone to compulsive or obsessive behavior "
        "be it toward a substance, habit, or activity.");
    addSpecification("root", "addict");
    addSpecification("opinion", -5);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to intimidation", 1);
    addSpecification("penalty to etiquette", 1);
    addSpecification("penalty to bluff", 1);
}
