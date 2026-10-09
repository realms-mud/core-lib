//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestor's Wail");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases a chilling wail "
        "infused with ancestral sorrow, dealing spiritual damage to a "
        "target and reducing their morale.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke ancestor's wail ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::release## a haunting wail of ancestral sorrow that shakes ##TargetName## to the core.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 35,
            "range": 38
        ]),
        ([
            "probability": 25,
            "base damage": 65,
            "range": 60
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.07
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
