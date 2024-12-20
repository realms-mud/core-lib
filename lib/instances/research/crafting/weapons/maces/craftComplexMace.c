//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Complex Mace");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft complex maces like flanged maces and morning stars.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/weapons/maces/craftBasicMace.c", (["type":"research"]));
}
