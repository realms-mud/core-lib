//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aquamantic Insight");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents a transcendent "
        "understanding of water magic. The aquamancer perceives the flow of "
        "water in all things - in the air, in the earth, in living creatures. "
        "This profound insight allows them to manipulate water with godlike "
        "precision and power.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 57
        ]));

    addPrerequisite("/guilds/aquamancer/water/ocean-mastery.c",
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
