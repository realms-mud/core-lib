//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wail of the Fallen");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes a devastating "
        "wail that channels the grief of all fallen warriors, dealing "
        "spiritual damage to all nearby enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 9]));
    addPrerequisite("/guilds/runeskald/song-of-power/anguished-wail.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing wail of the fallen");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a wail of fallen warriors that echoes through the area.");

    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 50,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 95,
            "range": 90
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.09
        ])
    }));
}
