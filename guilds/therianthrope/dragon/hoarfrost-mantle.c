//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hoarfrost Mantle");
    addSpecification("source", "therianthrope");
    addSpecification("description", "A mantle of crystalline hoarfrost clings "
        "to your dragon form, absorbing incoming blows and shielding you "
        "from harm.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 47
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/adamantine-scales.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus soak", 2);
}
