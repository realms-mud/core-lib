//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Chimera");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of the primal "
        "chimera, gaining greater combat prowess and a more terrifying "
        "monstrous form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/searing-claws.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 25,
        "Gore": 25,
        "Fire Breath": 25,
        "Chimeric Rampage": 25,
        "Inferno": 25
    ]));
}
