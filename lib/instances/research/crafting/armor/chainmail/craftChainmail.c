//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Chainmail");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft chainmail armor.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/armor/craftArmor.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 5]));
}
