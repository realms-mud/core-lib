//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Toxic Waters");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of infusing water with harmful substances. The aquamancer "
        "learns to taint their water magic with toxins that cause ongoing "
        "damage and weaken victims, enhancing drowning-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 15
        ]));

    addPrerequisite("/guilds/aquamancer/water/drowning-grasp.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Drowning Grasp": 25,
        "Suffocating Depths": 25,
        "Drowning Embrace": 25,
        "Abyssal Orb": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
