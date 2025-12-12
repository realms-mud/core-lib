//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water Blast");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "deeper understanding of how to focus and intensify water-based attacks. "
        "By studying the principles of water pressure and fluid dynamics, the "
        "aquamancer learns to deliver more powerful impacts with their "
        "offensive water magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 3
        ]));

    addPrerequisite("/guilds/aquamancer/water/splash.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Splash": 25,
        "Current": 25,
        "Talons of Water": 25,
        "Drowning Grasp": 25,
        "Toxic Waters": 25,
        "Obscuring Spray": 25,
        "Battering Waves": 25,
        "Riptide": 25,
        "Daggers of Water": 25,
        "Suffocating Depths": 25,
        "Drowning Embrace": 25,
        "Abyssal Orb": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
