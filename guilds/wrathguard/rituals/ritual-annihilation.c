//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "ritual annihilation");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Wrathguard brings the full power "
        "of the ritual canon to bear in a single annihilating strike, "
        "reducing the target to ruin in the Queen's name.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 145);
    addSpecification("cooldown", 34);
    addSpecification("command template", "ritual annihilation at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bring## ritual annihilation "
        "down upon ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 215, "range": 155])
    }));
    addSpecification("modifiers", ({
        (["type": "skill", "name": "spellcraft", "formula": "additive",
            "rate": 0.45]),
        (["type": "skill", "name": "theology", "formula": "additive",
            "rate": 0.45]),
        (["type": "skill", "name": "evocation", "formula": "additive",
            "rate": 0.35]),
        (["type": "attribute", "name": "wisdom", "formula": "additive",
            "rate": 0.3]),
        (["type": "attribute", "name": "intelligence", "formula": "additive",
            "rate": 0.25]),
        (["type": "level", "name": "Wrathguard", "formula": "additive",
            "rate": 2.6])
    }));
    addPrerequisite("/guilds/wrathguard/rituals/rite-of-ruin.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Wrathguard", "value": 67]));
}
