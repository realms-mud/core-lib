//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Necrotic Venom");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your venom evolves into a necrotic "
        "toxin that rots flesh and corrodes armor, making your poison "
        "attacks devastatingly effective.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 39
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/miasma.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus resist acid", 5);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 25,
        "Constrict": 20,
        "Spit Venom": 30,
        "Death Roll": 20,
        "Miasma": 30
    ]));
}
