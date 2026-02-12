//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Claw Mastery");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your mastery of the bear form enhances "
        "the power and efficiency of your claw and bite attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addPrerequisite("/guilds/therianthrope/bear/bear-charge.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Bear Claws": 10,
        "Crushing Bite": 10,
        "Bear Charge": 10,
        "Maul": 10,
        "Thunderous Roar": 5
    ]));
}
