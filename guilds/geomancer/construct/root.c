//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constructed Geomancer Spells");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of casting constructed spells that can provide "
        "complex effects.");

    addSpecification("constructed rules", ([
        "form must include only one of": ({
            "/guilds/geomancer/forms/arc.c",
            "/guilds/geomancer/forms/ball.c",
            "/guilds/geomancer/forms/blade.c",
            "/guilds/geomancer/forms/blast.c",
            "/guilds/geomancer/forms/bolt.c",
            "/guilds/geomancer/forms/burst.c",
            "/guilds/geomancer/forms/cage.c",
            "/guilds/geomancer/forms/cataclysm.c",
            "/guilds/geomancer/forms/cloud.c",
            "/guilds/geomancer/forms/coil.c",
            "/guilds/geomancer/forms/eruption.c",
            "/guilds/geomancer/forms/avalanche.c",
            "/guilds/geomancer/forms/lance.c",
            "/guilds/geomancer/forms/orb.c",
            "/guilds/geomancer/forms/pebble.c",
            "/guilds/geomancer/forms/pulse.c",
            "/guilds/geomancer/forms/quake.c",
            "/guilds/geomancer/forms/razor.c",
            "/guilds/geomancer/forms/ring.c",
            "/guilds/geomancer/forms/spear.c",
            "/guilds/geomancer/forms/spray.c",
            "/guilds/geomancer/forms/strike.c",
            "/guilds/geomancer/forms/tendril.c",
            "/guilds/geomancer/forms/touch.c",
            "/guilds/geomancer/forms/vortex.c",
            "/guilds/geomancer/forms/wall.c",
            "/guilds/geomancer/forms/wave.c",
        }),
        "function must include only one of": ({
            "/guilds/geomancer/functions/stone.c",
            "/guilds/geomancer/functions/earth.c",
            "/guilds/geomancer/functions/gravel.c",
            "/guilds/geomancer/functions/weight.c",
            "/guilds/geomancer/functions/crystal.c",
            "/guilds/geomancer/functions/sand.c",
            "/guilds/geomancer/functions/entombing.c",
            "/guilds/geomancer/functions/crushing.c",
            "/guilds/geomancer/functions/tectonic.c",
            "/guilds/geomancer/functions/magma.c",
            "/guilds/geomancer/functions/seismic.c",
        }),
        "effect must include any of": ({
            "/guilds/geomancer/effects/damage-hp.c",
            "/guilds/geomancer/effects/damage-sp.c",
            "/guilds/geomancer/effects/damage-stamina.c",
            "/guilds/geomancer/effects/add-hp.c",
            "/guilds/geomancer/effects/add-sp.c",
            "/guilds/geomancer/effects/add-stamina.c",
            "/guilds/geomancer/effects/siphon-hp.c",
            "/guilds/geomancer/effects/siphon-sp.c",
            "/guilds/geomancer/effects/siphon-stamina.c",
            "/guilds/geomancer/effects/enhance-attack.c",
            "/guilds/geomancer/effects/enhance-damage.c",
            "/guilds/geomancer/effects/enhance-defense.c",
            "/guilds/geomancer/effects/enhance-soak.c",
            "/guilds/geomancer/effects/enhance-dodge.c",
            "/guilds/geomancer/effects/enhance-parry.c",
            "/guilds/geomancer/effects/enhance-speed.c",
            "/guilds/geomancer/effects/reduce-attack.c",
            "/guilds/geomancer/effects/reduce-damage.c",
            "/guilds/geomancer/effects/reduce-defense.c",
            "/guilds/geomancer/effects/reduce-soak.c",
            "/guilds/geomancer/effects/reduce-dodge.c",
            "/guilds/geomancer/effects/reduce-parry.c",
            "/guilds/geomancer/effects/apply-slow.c",
            "/guilds/geomancer/effects/apply-enfeebled.c",
            "/guilds/geomancer/effects/staggering-damage.c",
            "/guilds/geomancer/effects/debilitating-damage.c",
            "/guilds/geomancer/effects/disorienting-damage.c",
            "/guilds/geomancer/effects/hampering-damage.c",
            "/guilds/geomancer/effects/exhausting-damage.c",
            "/guilds/geomancer/effects/invigorating-siphon.c",
            "/guilds/geomancer/effects/fortifying-siphon.c",
        }),
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/geomancer/construct/efficient-casting.c": 10,
        "/guilds/geomancer/construct/improved-efficiency.c": 10,
        "/guilds/geomancer/construct/expert-efficiency.c": 10,
        "/guilds/geomancer/construct/master-efficiency.c": 10,
        "/guilds/geomancer/construct/grandmaster-efficiency.c": 5,
        "/guilds/geomancer/construct/legendary-efficiency.c": 5,
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "cast");
    addSpecification("command template", "cast geomancer ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## a spell...");
}
