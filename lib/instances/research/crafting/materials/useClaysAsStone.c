//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Substitute stones with clays");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to use clays as substitues for "
        "stone when crafting.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/materials/craftClay.c", (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/materials/craftStone.c", (["type":"research"]));
}
