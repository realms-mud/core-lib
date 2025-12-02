//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Rare Gems");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft items using precious gems such as rubies and diamonds.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("/lib/instances/research/crafting/materials/craftGems.c", (["type":"research"]));
}
