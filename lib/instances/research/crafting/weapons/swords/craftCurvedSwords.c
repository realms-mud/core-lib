//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Curved Swords");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft scimitars, cutlasses, and sabers out of "
        "typical bladed weapon materials such as iron, bronze, and steel.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/swords/craftBasicSwords.c", 
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/weapons/common/annealing.c",
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 5]));
}
