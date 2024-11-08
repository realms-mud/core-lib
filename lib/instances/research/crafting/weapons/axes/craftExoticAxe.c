//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Exotic Axe");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft axes such as the panabas and sparth axe.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/weapons/axes/craftBasicAxe.c", (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 6]));
}
