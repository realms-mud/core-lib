//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestral Wrath");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels the rage of "
        "their ancestors into a thunderous shout, dealing spiritual damage "
        "to a single foe and reducing their morale.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 5]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-blessing.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke ancestral wrath ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## the rage of the ancestors upon ##TargetName##.");

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 22,
            "range": 28
        ]),
        ([
            "probability": 25,
            "base damage": 50,
            "range": 45
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.06
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
