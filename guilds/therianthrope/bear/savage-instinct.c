//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Savage Instinct");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The wild instincts of the bear sharpen, "
        "granting heightened combat awareness and strength while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/bear/ursine-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Bear Claws": 20,
        "Crushing Bite": 20,
        "Bear Charge": 20,
        "Maul": 20,
        "Thunderous Roar": 20
    ]));
}
