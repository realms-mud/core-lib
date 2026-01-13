//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Purge Affliction");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of using sacred fire to burn away disease afflicting "
        "a target.");
    addSpecification("usage summary", "Removes disease effects");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/cleansing-fire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("remove modifier", "disease");

    addSpecification("modifiers", ({ 
        ( [
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
            "name": "Healing Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 35);
    addSpecification("event handler", "purgeAfflictionEvent");
    addSpecification("command template", "purge affliction [from ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## purging flames upon ##TargetName##, burning "
        "away the disease afflicting ##TargetObjective##.");
}
