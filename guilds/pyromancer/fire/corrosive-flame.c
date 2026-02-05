//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Corrosive Flame");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of imbuing flames with corrosive properties.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 17
        ]));

    addPrerequisite("/guilds/pyromancer/fire/ash-cloud.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ash Cloud": 25,
        "Immolating Depths": 25,
        "Immolating Embrace": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
