//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earthen Might");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "deeper understanding of how to focus and intensify earth-based attacks. "
        "By studying the principles of tectonic pressure and geological force, "
        "the geomancer learns to deliver more powerful impacts with their "
        "offensive earth magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 3
        ]));

    addPrerequisite("/guilds/geomancer/earth/tremor.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Tremor": 25,
        "Fissure": 25,
        "Talons of Earth": 25,
        "Grasping Earth": 25,
        "Quicksand": 25,
        "Dust Shroud": 25,
        "Battering Stones": 25,
        "Upheaval": 25,
        "Daggers of Earth": 25,
        "Entombing Depths": 25,
        "Entombing Embrace": 25,
        "Abyssal Stone": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
