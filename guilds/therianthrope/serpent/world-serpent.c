//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "World Serpent");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your serpent form reaches mythical "
        "proportions, channeling the power of the legendary world serpent "
        "with devastating attacks and formidable defenses.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/naga-form.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 15);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 25,
        "Constrict": 25,
        "Spit Venom": 25,
        "Death Roll": 25,
        "Miasma": 25
    ]));
}
