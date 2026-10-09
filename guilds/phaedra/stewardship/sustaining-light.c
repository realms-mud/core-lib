//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "sustaining light");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels a sustaining "
        "light that both restores an ally's vitality and grants "
        "them a brief burst of renewed energy.");
    addPrerequisite("/guilds/phaedra/stewardship/restorative-presence.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/stewardship/rallying-word.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 15]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 18);
    addSpecification("command template", "sustaining light on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::suffuse## ##TargetName## "
        "with sustaining golden light.");
    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 25,
            "range": 22
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/restorative-presence.c",
            "name": "Restorative Presence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/scholars-acumen.c",
            "name": "Scholar's Acumen",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.42
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
