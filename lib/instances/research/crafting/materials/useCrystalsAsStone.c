//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Substitute stones with crystals");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to use gems and crystals as substitues for "
        "stone when crafting.");
    addSpecification("research type", "granted");

    addPrerequisite("/lib/instances/research/crafting/materials/craftGems.c", (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/materials/craftStone.c", (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/materials/craftConcrete.c", (["type":"research"]));
}
