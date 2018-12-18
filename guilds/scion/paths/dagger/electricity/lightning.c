//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Lightning Bolt");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the lightning bolt technique. By means of this, the "
            "Scion is able to use their dagger as a conduit for emitting a bolt "
            "of lightning at a foe.");

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("lib/guilds/scion/paths/dagger/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/dagger/electricity/sparks.c",
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 9
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 100);

        addSpecification("damage hit points", ({ ([
                "probability":90,
                "base damage" : 25,
                "range" : 50
            ]),
            ([
                "probability": 10,
                "base damage": 50,
                "range" : 100
            ])
        }));

        addSpecification("damage type", "electricity");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/static-charge.c",
                "name" : "Static Charge",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/electrostatic-induction.c",
                "name" : "Electrostatic Induction",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/ionization.c",
                "name" : "Ionization",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/enhanced-discharge.c",
                "name" : "Enhanced Discharge",
                "formula" : "additive",
                "base value" : 10,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/electricity/plasma-eruption.c",
                "name" : "Plasma Eruption",
                "formula" : "additive",
                "base value" : 10,
                "rate": 1.0
            ]),
            ([
                "type":"skill",
                "name" : "dagger",
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "elemental air",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"skill",
                "name" : "spellcraft",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"level",
                "name" : "level",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("cooldown", 60);
        addSpecification("event handler", "lightningEvent");
        addSpecification("command template", "lightning [at ##Target##]");
        addSpecification("use ability message",  "An intense bolt of lightning "
            "flies from ##InitiatorPossessive::Name## dagger into ##TargetName##.");
    }
}
