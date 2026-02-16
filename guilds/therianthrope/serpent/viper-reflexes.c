//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Viper Reflexes");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The wild instincts of the serpent "
        "sharpen, granting lightning-fast reflexes and heightened combat "
        "awareness while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/serpentine-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 20,
        "Constrict": 20,
        "Spit Venom": 20,
        "Death Roll": 20,
        "Miasma": 20
    ]));
}
