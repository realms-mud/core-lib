//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Disrupt Inferno");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of disrupting enemy defenses with chaotic fire.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 33
        ]));

    addPrerequisite("/guilds/pyromancer/fire/great-inferno.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Great Inferno": 25,
        "Whirling Flames": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
