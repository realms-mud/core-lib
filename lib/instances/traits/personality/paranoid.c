//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "paranoid");
        addSpecification("description", "What is that thing lurking in the "
            "shadows? It's the paid assassin out to get you and yours. Never "
            "mind that you're a lowly hat weaver's apprentice - the "
            "world wishes you ill.");
        addSpecification("root", "paranoid");
        addSpecification("opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to intimidation", 1);
        "baseTrait"::reset(arg);
    }
}
