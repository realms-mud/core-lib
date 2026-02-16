//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ouroboros");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You embody the eternal cycle of the "
        "ouroboros, the serpent that consumes itself and is reborn. Your "
        "venom becomes a force of entropy and renewal.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/basilisk-gaze.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points", 10);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal spell points rate", 3);
    addSpecification("bonus heal stamina rate", 3);
    addSpecification("bonus resist poison", 10);
    addSpecification("bonus resist disease", 5);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 30,
        "Spit Venom": 35,
        "Miasma": 35,
    ]));
}
