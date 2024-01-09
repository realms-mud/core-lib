//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "superstitious");
    addSpecification("description", "You tend to believe in supernatural "
        "causes that lead to the consequences of an action taken.");
    addSpecification("root", "superstitious");
    addSpecification("opinion", -5);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to intimidation", 1);
    addSpecification("penalty to bluff", 1);
}
