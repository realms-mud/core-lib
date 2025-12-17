//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Realm of Nightmares");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of warping the local area into a reflection of the nightmare "
        "realm, weakening all enemies while strengthening the oneiromancer.");
    addSpecification("usage summary", "An area effect that debuffs enemies "
        "and buffs the caster");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dreamwalk.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 51
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense", 10);
    addSpecification("penalty to damage", 5);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/dream-mastery.c",
            "name": "Dream Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.40
        ]),
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "realmOfNightmaresEvent");
    addSpecification("command template", "realm of nightmares");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::warp## the very fabric of reality, transforming the "
        "area into a terrifying reflection of the nightmare realm.");
}
