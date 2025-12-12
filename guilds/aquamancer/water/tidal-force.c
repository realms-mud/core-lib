//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Force");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with "
        "understanding of the immense power contained within ocean tides. "
        "By learning to harness these forces, the aquamancer can dramatically "
        "enhance their area-effect water spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 11
        ]));

    addPrerequisite("/guilds/aquamancer/water/whirlpool.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Whirlpool": 25,
        "Waterspout": 25,
        "Maelstrom": 25,
        "Tempest Call": 25,
        "Great Maelstrom": 25,
        "Disrupt Tempest": 25,
        "Whirling Waters": 25,
        "Cataclysm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
