//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanctified Restoration");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ferianth's blessing to purge multiple "
        "afflictions from an ally at once.");
    addSpecification("usage summary", "Removes multiple debuffs");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/flame-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 75
        ])
    }));

    addSpecification("remove modifier", ({ "poison", "disease", "slow", 
        "enfeebled", "paralysis", "cursed" }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
            "name": "Healing Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
            "name": "Purifying Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 100);
    addSpecification("event handler", "sanctifiedRestorationEvent");
    addSpecification("command template", "sanctified restoration [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ferianth's sanctified restoration upon "
        "##TargetName##! Sacred fire purges all afflictions from "
        "##TargetPossessive## body.");
}
