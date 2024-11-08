//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft War Hammer");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft basic hammers such as war hammers and lucerne hammers.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c", (["type":"research"]));
}
