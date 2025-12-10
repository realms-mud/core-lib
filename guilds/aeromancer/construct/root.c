//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constructed Aeromancer Spells");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of casting constructed spells that can provide "
        "complex effects.");

    addSpecification("constructed rules", ([
        "form must include only one of": ({
            "/guilds/aeromancer/forms/arc.c",
            "/guilds/aeromancer/forms/ball.c",
            "/guilds/aeromancer/forms/blade.c",
            "/guilds/aeromancer/forms/blast.c",
            "/guilds/aeromancer/forms/bolt.c",
            "/guilds/aeromancer/forms/breath.c",
            "/guilds/aeromancer/forms/cage.c",
            "/guilds/aeromancer/forms/coil.c",
            "/guilds/aeromancer/forms/cyclone.c",
            "/guilds/aeromancer/forms/eruption.c",
            "/guilds/aeromancer/forms/gust.c",
            "/guilds/aeromancer/forms/lance.c",
            "/guilds/aeromancer/forms/mist.c",
            "/guilds/aeromancer/forms/nova.c",
            "/guilds/aeromancer/forms/orb.c",
            "/guilds/aeromancer/forms/pulse.c",
            "/guilds/aeromancer/forms/razor.c",
            "/guilds/aeromancer/forms/ring.c",
            "/guilds/aeromancer/forms/spark.c",
            "/guilds/aeromancer/forms/spear.c",
            "/guilds/aeromancer/forms/strike.c",
            "/guilds/aeromancer/forms/tornado.c",
            "/guilds/aeromancer/forms/touch.c",
            "/guilds/aeromancer/forms/vortex.c",
            "/guilds/aeromancer/forms/wall.c",
            "/guilds/aeromancer/forms/wave.c",
            "/guilds/aeromancer/forms/whip.c",
        }),
        "function must include only one of": ({
            "/guilds/aeromancer/functions/lightning.c",
            "/guilds/aeromancer/functions/shock.c",
            "/guilds/aeromancer/functions/air.c",
            "/guilds/aeromancer/functions/storm.c",
            "/guilds/aeromancer/functions/vacuum.c",
            "/guilds/aeromancer/functions/wind.c",
            "/guilds/aeromancer/functions/thunder.c",
            "/guilds/aeromancer/functions/chill.c",
            "/guilds/aeromancer/functions/pressure.c",
            "/guilds/aeromancer/functions/plasma.c",
        }),
        "effect must include any of": ({
            "/guilds/aeromancer/effects/damage-hp.c",
            "/guilds/aeromancer/effects/damage-sp.c",
            "/guilds/aeromancer/effects/damage-stamina.c",
            "/guilds/aeromancer/effects/add-hp.c",
            "/guilds/aeromancer/effects/add-sp.c",
            "/guilds/aeromancer/effects/add-stamina.c",
            "/guilds/aeromancer/effects/siphon-hp.c",
            "/guilds/aeromancer/effects/siphon-sp.c",
            "/guilds/aeromancer/effects/siphon-stamina.c",
            "/guilds/aeromancer/effects/enhance-attack.c",
            "/guilds/aeromancer/effects/enhance-damage.c",
            "/guilds/aeromancer/effects/enhance-defense.c",
            "/guilds/aeromancer/effects/enhance-soak.c",
            "/guilds/aeromancer/effects/enhance-dodge.c",
            "/guilds/aeromancer/effects/enhance-parry.c",
            "/guilds/aeromancer/effects/enhance-speed.c",
            "/guilds/aeromancer/effects/reduce-attack.c",
            "/guilds/aeromancer/effects/reduce-damage.c",
            "/guilds/aeromancer/effects/reduce-defense.c",
            "/guilds/aeromancer/effects/reduce-soak.c",
            "/guilds/aeromancer/effects/reduce-dodge.c",
            "/guilds/aeromancer/effects/reduce-parry.c",
            "/guilds/aeromancer/effects/apply-slow.c",
            "/guilds/aeromancer/effects/apply-enfeebled.c",
            "/guilds/aeromancer/effects/staggering-damage.c",
            "/guilds/aeromancer/effects/debilitating-damage.c",
            "/guilds/aeromancer/effects/disorienting-damage.c",
            "/guilds/aeromancer/effects/hampering-damage.c",
            "/guilds/aeromancer/effects/exhausting-damage.c",
            "/guilds/aeromancer/effects/invigorating-siphon.c",
            "/guilds/aeromancer/effects/fortifying-siphon.c",
        }),
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/aeromancer/construct/efficient-casting.c": 10,
        "/guilds/aeromancer/construct/improved-efficiency.c": 10,
        "/guilds/aeromancer/construct/expert-efficiency.c": 10,
        "/guilds/aeromancer/construct/master-efficiency.c": 10,
        "/guilds/aeromancer/construct/grandmaster-efficiency.c": 5,
        "/guilds/aeromancer/construct/legendary-efficiency.c": 5,
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "cast");
    addSpecification("command template", "cast aeromancer ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## a spell...");
}
