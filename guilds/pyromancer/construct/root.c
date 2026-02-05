//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constructed Pyromancer Spells");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of casting constructed spells that can provide "
        "complex effects.");

    addSpecification("constructed rules", ([
        "form must include only one of": ({
            "/guilds/pyromancer/forms/arc.c",
            "/guilds/pyromancer/forms/ball.c",
            "/guilds/pyromancer/forms/blade.c",
            "/guilds/pyromancer/forms/blast.c",
            "/guilds/pyromancer/forms/bolt.c",
            "/guilds/pyromancer/forms/cage.c",
            "/guilds/pyromancer/forms/cataclysm.c",
            "/guilds/pyromancer/forms/cloud.c",
            "/guilds/pyromancer/forms/coil.c",
            "/guilds/pyromancer/forms/eruption.c",
            "/guilds/pyromancer/forms/firestorm.c",
            "/guilds/pyromancer/forms/flare.c",
            "/guilds/pyromancer/forms/inferno.c",
            "/guilds/pyromancer/forms/lance.c",
            "/guilds/pyromancer/forms/orb.c",
            "/guilds/pyromancer/forms/pulse.c",
            "/guilds/pyromancer/forms/razor.c",
            "/guilds/pyromancer/forms/ring.c",
            "/guilds/pyromancer/forms/spark.c",
            "/guilds/pyromancer/forms/spear.c",
            "/guilds/pyromancer/forms/spray.c",
            "/guilds/pyromancer/forms/strike.c",
            "/guilds/pyromancer/forms/tendril.c",
            "/guilds/pyromancer/forms/touch.c",
            "/guilds/pyromancer/forms/vortex.c",
            "/guilds/pyromancer/forms/wall.c",
            "/guilds/pyromancer/forms/wave.c",
        }),
        "function must include only one of": ({
            "/guilds/pyromancer/functions/heat.c",
            "/guilds/pyromancer/functions/flame.c",
            "/guilds/pyromancer/functions/combustion.c",
            "/guilds/pyromancer/functions/scorch.c",
            "/guilds/pyromancer/functions/inferno.c",
            "/guilds/pyromancer/functions/smoke.c",
            "/guilds/pyromancer/functions/searing.c",
            "/guilds/pyromancer/functions/immolation.c",
            "/guilds/pyromancer/functions/conflagration.c",
            "/guilds/pyromancer/functions/magma.c",
            "/guilds/pyromancer/functions/hellfire.c",
        }),
        "effect must include any of": ({
            "/guilds/pyromancer/effects/damage-hp.c",
            "/guilds/pyromancer/effects/damage-sp.c",
            "/guilds/pyromancer/effects/damage-stamina.c",
            "/guilds/pyromancer/effects/add-hp.c",
            "/guilds/pyromancer/effects/add-sp.c",
            "/guilds/pyromancer/effects/add-stamina.c",
            "/guilds/pyromancer/effects/siphon-hp.c",
            "/guilds/pyromancer/effects/siphon-sp.c",
            "/guilds/pyromancer/effects/siphon-stamina.c",
            "/guilds/pyromancer/effects/enhance-attack.c",
            "/guilds/pyromancer/effects/enhance-damage.c",
            "/guilds/pyromancer/effects/enhance-defense.c",
            "/guilds/pyromancer/effects/enhance-soak.c",
            "/guilds/pyromancer/effects/enhance-dodge.c",
            "/guilds/pyromancer/effects/enhance-parry.c",
            "/guilds/pyromancer/effects/enhance-speed.c",
            "/guilds/pyromancer/effects/reduce-attack.c",
            "/guilds/pyromancer/effects/reduce-damage.c",
            "/guilds/pyromancer/effects/reduce-defense.c",
            "/guilds/pyromancer/effects/reduce-soak.c",
            "/guilds/pyromancer/effects/reduce-dodge.c",
            "/guilds/pyromancer/effects/reduce-parry.c",
            "/guilds/pyromancer/effects/apply-slow.c",
            "/guilds/pyromancer/effects/apply-enfeebled.c",
            "/guilds/pyromancer/effects/staggering-damage.c",
            "/guilds/pyromancer/effects/debilitating-damage.c",
            "/guilds/pyromancer/effects/disorienting-damage.c",
            "/guilds/pyromancer/effects/hampering-damage.c",
            "/guilds/pyromancer/effects/exhausting-damage.c",
            "/guilds/pyromancer/effects/invigorating-siphon.c",
            "/guilds/pyromancer/effects/fortifying-siphon.c",
        }),
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/pyromancer/construct/efficient-casting.c": 10,
        "/guilds/pyromancer/construct/improved-efficiency.c": 10,
        "/guilds/pyromancer/construct/expert-efficiency.c": 10,
        "/guilds/pyromancer/construct/master-efficiency.c": 10,
        "/guilds/pyromancer/construct/grandmaster-efficiency.c": 5,
        "/guilds/pyromancer/construct/legendary-efficiency.c": 5,
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "cast");
    addSpecification("command template", "cast pyromancer ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## a spell...");
}
