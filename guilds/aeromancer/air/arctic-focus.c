//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arctic Focus");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the potency and effectiveness of their cold-based "
        "abilities, particularly enhancing the power of Arctic Blast.");

    addPrerequisite("level",
        (["type":"level",
            "guild" : "aeromancer",
            "value" : 7
        ]));
    addPrerequisite("/guilds/aeromancer/air/arctic-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast":25,
        "Frozen Path" : 25,
        "Glacial Shield" : 25,
        "Ice Storm" : 25,
        "Frostbite" : 25,
        "Cold Snap" : 25,
    ]));
    addSpecification("affected research type", "percentage");
}
