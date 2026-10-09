//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Evasive Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an attack performed from the evasive roll, using the momentum "
        "of the dodge itself to power a blade strike from an unexpected "
        "angle.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":21]));
    addPrerequisite("/guilds/league-of-assassins/evasion/combat-rolling.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({"dagger","short sword"})]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 14);
    addSpecification("command template", "evasive strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::spin## out of a "
        "dodge and drive a blade into ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability":80,"base damage":18,"range":22]),
        (["probability":20,"base damage":30,"range":40])
    }));
    addSpecification("damage type", "thrust");
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));
}
