//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Plate Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft plate armor.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c", (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 9]));
}
