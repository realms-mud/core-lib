//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aeromantic Insight");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research grants the aeromancer "
        "profound insight into the deepest mysteries of air magic. They begin "
        "to perceive air not just as an element but as a living force that "
        "permeates all things. This understanding allows them to manipulate "
        "wind with near-perfect efficiency, dramatically enhancing all abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 57
        ]));

    addPrerequisite("/guilds/aeromancer/air/tempest-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Gust": 25,
        "Zephyr": 25,
        "Cyclone": 25,
        "Tornado": 25,
        "Vortex": 25,
        "Storm Call": 25,
        "Maelstrom": 25,
        "Jetstream": 25,
        "Updraft": 25,
        "Stolen Breath": 25,
        "Noxious Breath": 25,
        "Talons of Wind": 25,
        "Buffeting Wind": 25,
        "Daggers of the Wind": 25,
        "Choking Wind": 25,
        "Disrupt Storm": 25,
        "Whirling Wind": 25,
        "Void Orb": 25,
        "Withering Air": 25,
        "Cataclysmic Tempest": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
