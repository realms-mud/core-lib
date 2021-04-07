//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Complex Pole Arm");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft basic pole arms like the halberd or guisarme.");
    addSpecification("research type", "granted");
    addPrerequisite("lib/instances/research/crafting/weapons/pole-arms/craftBasicPoleArm.c", (["type":"research"]));
}
