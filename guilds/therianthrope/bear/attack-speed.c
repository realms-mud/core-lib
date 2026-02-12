//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Attack Speed");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing mastery of the bear form "
        "allows you to strike faster in combat.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addPrerequisite("/guilds/therianthrope/bear/attack-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Bear Claws": 1,
        "Crushing Bite": 1,
        "Bear Charge": 2,
        "Maul": 5,
        "Thunderous Roar": 10
    ]));
}
