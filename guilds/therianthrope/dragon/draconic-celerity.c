//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draconic Celerity");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing mastery of the dragon form "
        "allows you to strike with surprising speed for such a massive "
        "creature.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 43
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/draconic-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Frost Claw": 1,
        "Tail Lash": 1,
        "Frost Breath": 2,
        "Soul Freeze": 2,
        "Frozen Blight": 2,
        "Glacial Tempest": 5
    ]));
}
