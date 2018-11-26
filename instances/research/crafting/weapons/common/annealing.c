//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Annealing - Weapons");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of annealing metal - a heat treatment that reduces a "
            "metal's hardness and making it much easier to work.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("penalty to crafting defense class", 1);
        addSpecification("penalty to crafting weapon class", 1);
    }
}
