//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water Mastery");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research represents a significant "
        "milestone in the aquamancer's journey - true mastery over water itself. "
        "Through extensive practice and meditation, the aquamancer learns to "
        "sense and manipulate water with unprecedented precision, dramatically "
        "enhancing all water-based abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 19
        ]));

    addPrerequisite("/guilds/aquamancer/water/whirlpool.c",
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
