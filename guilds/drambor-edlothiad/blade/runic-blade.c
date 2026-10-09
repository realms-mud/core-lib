//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Runic Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "inscribe temporary arcane runes along their blade, each rune "
        "detonating on impact for additional magical damage.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spell-weave.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 120);
    addSpecification("duration", 90);
    addSpecification("bonus attack", 6);
    addSpecification("bonus magical attack", 8);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": "/guilds/drambor-edlothiad/blade/spell-weave.c",
            "name": "spell-weave",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.10]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "runic blade");
    addSpecification("use ability message", "Glowing runes flare to life along "
        "##InitiatorPossessive## blade, each one pulsing with arcane power.");
}
