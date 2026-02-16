//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frozen Heart");
    addSpecification("source", "therianthrope");
    addSpecification("description", "A core of unyielding frost beats "
        "within your dragon form, amplifying your icy attacks.");

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

    addPrerequisite("/guilds/therianthrope/dragon/soul-freeze.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus cold enchantment", 1);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 15,
        "Tail Lash": 10,
        "Frost Breath": 20,
        "Soul Freeze": 20,
        "Frozen Blight": 20,
        "Glacial Tempest": 15
    ]));
}
