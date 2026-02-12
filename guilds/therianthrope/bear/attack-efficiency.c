//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Attack Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing familiarity with the bear "
        "form allows you to execute attacks with less effort.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 19
        ]));

    addPrerequisite("/guilds/therianthrope/bear/claw-mastery.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Bear Claws": 5,
        "Crushing Bite": 5,
        "Bear Charge": 10,
        "Maul": 10,
        "Thunderous Roar": 15
    ]));
}
