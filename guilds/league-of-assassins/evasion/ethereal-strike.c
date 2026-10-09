//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Ethereal Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an attack that emerges from the wind dancer or ghost form "
        "evasive state, using the assassin's heightened evasive "
        "momentum to deliver a devastating single strike.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":61]));
    addPrerequisite("/guilds/league-of-assassins/evasion/wind-dancer.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({"dagger","short sword"})]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 20);
    addSpecification("command template", "ethereal strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::materialize## "
        "from evasive motion, blade striking ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability":75,"base damage":35,"range":45]),
        (["probability":25,"base damage":60,"range":80])
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
            "rate": 0.25
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
            "rate": 0.65
        ]),
    }));
}
