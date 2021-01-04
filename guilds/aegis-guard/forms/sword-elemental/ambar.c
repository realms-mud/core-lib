//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Ambar");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a technique that allows one to project an earth-elemental "
            "energy wave known to the Aegis Guard as ambar. "
            "It is a form that can either be done by itself or as part of a "
            "combination attack.");
        addSpecification("usage summary", "A technique projecting an earth elemental "
            "energy wave");

        addPrerequisite("guilds/aegis-guard/forms/sword-mythic/mythic-root.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 11
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 25);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 15,
                "range": 15
            ]),
            ([
                "probability": 20,
                "base damage": 20,
                "range": 20
            ])
        }));
        addSpecification("damage type", "earth");

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-anwar.c",
                "name": "auth-anwar",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-celair.c",
                "name": "auth-celair",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-edlothia.c",
                "name": "auth-edlothia",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c",
                "name": "auth-eiliant",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-manadh.c",
                "name": "auth-manadh",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-elemental/angol-dagnir.c",
                "name": "auth-dagnir",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "skill",
                "name": "spirit",
                "formula": "logarithmic",
                "rate": 1.10
            ]),
            ([
                "type": "skill",
                "name": "spellcraft",
                "formula": "logarithmic",
                "rate": 1.05
            ]),
            ([
                "type": "skill",
                "name": "magical essence",
                "formula": "additive",
                "rate": 0.10
            ]),
            ([
                "type": "skill",
                "name": "evocation",
                "formula": "additive",
                "rate": 0.10
            ]), 
            ([
                "type":"attribute",
                "name": "charisma",
                "formula": "additive",
                "rate": 0.25
            ]), 
            ([
                "type": "attribute",
                "name": "intelligence",
                "formula": "additive",
                "rate": 0.5
            ]),
            ([
                "type": "attribute",
                "name": "wisdom",
                "formula": "additive",
                "rate": 0.5
            ]),
        }));

        addSpecification("cooldown", 12);
        addSpecification("event handler", "angolEvent");
        addSpecification("command template", "angol [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::arc## ##InitiatorPossessive## "
            "##InitiatorWeapon## at ##TargetName## in a masterful hewing motion.");
        addSpecification("use combination message", "##Infinitive::hew## "
            "masterfully");
    }
}
