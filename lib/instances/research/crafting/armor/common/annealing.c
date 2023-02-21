//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Annealing - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of annealing metal - a heat treatment that reduces a "
        "metal's hardness and making it much easier to work.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("limited by", (["crafting type":({ "chainmail", 
        "plate armor", "splint armor", "scale armor", "helmet" })]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 1]));

    addSpecification("penalty to crafting armor class", 1);
}
