//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aquatic Flow");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents an advanced "
        "understanding of water's natural flow patterns. The aquamancer learns "
        "to work with water's inherent tendencies rather than against them, "
        "dramatically improving the efficiency and power of all water magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 33
        ]));

    addPrerequisite("/guilds/aquamancer/water/water-channeling.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Splash": 25,
        "Current": 25,
        "Whirlpool": 25,
        "Waterspout": 25,
        "Maelstrom": 25,
        "Tempest Call": 25,
        "Great Maelstrom": 25,
        "Riptide": 25,
        "Geyser": 25,
        "Talons of Water": 25,
        "Battering Waves": 25,
        "Daggers of Water": 25,
        "Disrupt Tempest": 25,
        "Whirling Waters": 25,
        "Abyssal Orb": 25,
        "Withering Waters": 25,
        "Cataclysm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
