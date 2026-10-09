//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Tempest");
    addSpecification("source", "mage");
    addSpecification("description", "An archmage-tier arcane attack.");

    addPrerequisite("/guilds/mage/arcane-mastery/mastery-reservoir.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 43]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 15);
    addSpecification("command template", "arcane tempest [at ##Target##]");
    addSpecification("event handler", "arcaneTempestEvent");
    addSpecification("use ability message",
        "##InitiatorName## unleash##InitiatorReflexive## an arcane tempest upon ##TargetName##.");
    addSpecification("use ability fail message",
        "You failed to unleash an arcane tempest on ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before unleashing another arcane tempest.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 50, "range": 25])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.2
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.2
        ]),
        ([
            "type": "level",
            "name": "mage",
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "research",
            "name": "Mastery Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/mastery-amplification.c"
        ]),
        ([
            "type": "research",
            "name": "Mastery Synergy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/mastery-synergy.c"
        ]),
        ([
            "type": "research",
            "name": "Mastery Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/mastery-resonance.c"
        ]),
        ([
            "type": "research",
            "name": "Mastery Confluence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/mastery-confluence.c"
        ]),
        ([
            "type": "research",
            "name": "Archmage Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/archmage-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Archmage Synergy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/arcane-mastery/archmage-synergy.c"
        ]),
    }));
}