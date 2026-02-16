//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rime Mastery");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have reached a pinnacle of "
        "understanding of the silver dragon's icy nature, enhancing all "
        "cold-based attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 39
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/wyrms-cunning.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 20,
        "Tail Lash": 20,
        "Frost Breath": 20,
        "Soul Freeze": 20,
        "Frozen Blight": 20,
        "Glacial Tempest": 20
    ]));
}
