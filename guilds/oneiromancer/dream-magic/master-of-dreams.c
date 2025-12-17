//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master of Dreams");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "mastery over the realm of dreams. Their connection to the oneiric "
        "plane has become absolute, greatly enhancing all their abilities.");

    addPrerequisite("/guilds/oneiromancer/dream-magic/oneiric-apocalypse.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus mind", 5);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus magical essence", 3);
    addSpecification("bonus spell points", 25);
    addSpecification("bonus heal spell points", 3);
    addSpecification("bonus heal spell points rate", 1);

    addSpecification("affected research", ([
        "Dream Touch": 25,
        "Phantasmal Bolt": 25,
        "Nightmare Bolt": 25,
        "Oneiric Blast": 25,
        "Dream Rend": 25,
        "Dream Tempest": 20,
        "Mental Annihilation": 20,
        "Dream Cataclysm": 20
    ]));
    addSpecification("affected research type", "percentage");
}
