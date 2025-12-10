//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gale Force");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of how to amplify the power of area-effect wind attacks. "
        "By understanding how to sustain and feed a growing wind pattern, "
        "the aeromancer can create storms that grow stronger as they expand "
        "rather than dissipating.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 11
        ]));

    addPrerequisite("/guilds/aeromancer/air/cyclone.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Cyclone": 25,
        "Tornado": 25,
        "Hurricane": 25,
        "Storm Call": 25,
        "Updraft": 25,
        "Maelstrom": 25,
        "Disrupt Storm": 25,
        "Whirling Wind": 25,
        "Withering Air": 25,
        "Cataclysmic Tempest": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
