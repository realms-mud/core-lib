//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Feral Celerity");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing mastery of the chimera form "
        "allows you to strike with savage speed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 35
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/feral-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Rending Claws": 1,
        "Gore": 1,
        "Fire Breath": 2,
        "Chimeric Rampage": 2,
        "Inferno": 5
    ]));
}
