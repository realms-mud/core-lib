//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Annealing - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of annealing metal - a heat treatment that reduces a "
        "metal's hardness and making it much easier to work.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("blacksmithing", (["type":"skill", "value" : 1]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger", 
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow", 
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("penalty to crafting defense class", 1);
    addSpecification("penalty to crafting weapon class", 1);
}
