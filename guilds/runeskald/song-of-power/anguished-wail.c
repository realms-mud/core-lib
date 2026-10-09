//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Anguished Wail");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald lets out an anguished "
        "wail charged with runic grief, dealing heavy spiritual damage "
        "to all nearby enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 10]));
    addPrerequisite("/guilds/runeskald/song-of-power/battle-howl.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "anguished wail");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::let## out an anguished wail laced with runic grief that scours the area.");

    addSpecification("spell point cost", 38);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 50,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 90,
            "range": 90
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/song-of-power/dirge-of-ruin.c",
            "name": "Dirge of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.18
        ])
    }));
}
