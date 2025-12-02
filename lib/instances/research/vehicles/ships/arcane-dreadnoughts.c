//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Dreadnoughts");
    addSpecification("source", "vehicles");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to construct the ultimate fusion of magical and "
        "mundane shipbuilding - titanic vessels powered by arcane engines "
        "and protected by the most powerful enchantments known.");
    addSpecification("research type", "points");
    addSpecification("research cost", 12);
    addPrerequisite("carpentry", (["type":"skill", "value" : 18]));
    addPrerequisite("nautical skills", (["type":"skill", "value" : 15]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 12]));
    addPrerequisite("engineering", (["type":"skill", "value" : 10]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));
    addPrerequisite("arcane crafting", (["type":"skill", "value" : 10]));
    addPrerequisite("/lib/instances/research/vehicles/ships/mystical-man-of-war.c", 
        (["type":"research"]));
}
