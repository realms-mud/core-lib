//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Venomous Mastery");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have reached a pinnacle of "
        "understanding of the serpent's venomous nature, enhancing all "
        "poison-based attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 21
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/death-roll.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 20,
        "Constrict": 20,
        "Spit Venom": 20,
        "Death Roll": 20,
        "Miasma": 20
    ]));
}
