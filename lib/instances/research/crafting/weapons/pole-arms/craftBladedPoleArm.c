//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Bladed Pole Arm");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft basic pole arms like the bardiche or bec de corbin.");
    addSpecification("research type", "granted");
    addPrerequisite("/lib/instances/research/crafting/weapons/pole-arms/craftBasicPoleArm.c", (["type":"research"]));
}
