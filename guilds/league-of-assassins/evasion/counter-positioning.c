//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Counter Positioning");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to use an enemy's attack to drive a repositioning "
        "maneuver, ending up behind or to the flank of the attacker "
        "and delivering a disorienting strike from the new angle.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":47]));
    addPrerequisite("/guilds/league-of-assassins/evasion/evasive-strike.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({"dagger","short sword"})]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 16);
    addSpecification("command template", "counter position ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::use## ##TargetName##'s "
        "attack to slip behind them.");
    addSpecification("damage hit points", ({
        (["probability":80,"base damage":28,"range":35]),
        (["probability":20,"base damage":48,"range":60])
    }));
    addSpecification("damage type", "thrust");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "dagger",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "weapon damage",
            "name": "blade",
            "types": ({"dagger","short sword"}),
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.55
        ]),
    }));
}
