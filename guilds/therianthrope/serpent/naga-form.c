//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Naga Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of the ancient "
        "naga, gaining tremendous combat prowess and a more terrifying "
        "serpentine form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/spit-venom.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 25,
        "Constrict": 25,
        "Spit Venom": 25,
        "Death Roll": 25,
        "Miasma": 25
    ]));
}
