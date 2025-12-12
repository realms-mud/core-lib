//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constructed Aquamancer Spells");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of casting constructed spells that can provide "
        "complex effects.");

    addSpecification("constructed rules", ([
        "form must include only one of": ({
            "/guilds/aquamancer/forms/arc.c",
            "/guilds/aquamancer/forms/ball.c",
            "/guilds/aquamancer/forms/blade.c",
            "/guilds/aquamancer/forms/blast.c",
            "/guilds/aquamancer/forms/bolt.c",
            "/guilds/aquamancer/forms/cage.c",
            "/guilds/aquamancer/forms/coil.c",
            "/guilds/aquamancer/forms/droplet.c",
            "/guilds/aquamancer/forms/geyser.c",
            "/guilds/aquamancer/forms/lance.c",
            "/guilds/aquamancer/forms/maelstrom.c",
            "/guilds/aquamancer/forms/mist.c",
            "/guilds/aquamancer/forms/orb.c",
            "/guilds/aquamancer/forms/pulse.c",
            "/guilds/aquamancer/forms/razor.c",
            "/guilds/aquamancer/forms/ring.c",
            "/guilds/aquamancer/forms/spear.c",
            "/guilds/aquamancer/forms/splash.c",
            "/guilds/aquamancer/forms/spray.c",
            "/guilds/aquamancer/forms/strike.c",
            "/guilds/aquamancer/forms/tendril.c",
            "/guilds/aquamancer/forms/touch.c",
            "/guilds/aquamancer/forms/tsunami.c",
            "/guilds/aquamancer/forms/wall.c",
            "/guilds/aquamancer/forms/waterspout.c",
            "/guilds/aquamancer/forms/wave.c",
            "/guilds/aquamancer/forms/whirlpool.c",
        }),
        "function must include only one of": ({
            "/guilds/aquamancer/functions/water.c",
            "/guilds/aquamancer/functions/chill.c",
            "/guilds/aquamancer/functions/ice.c",
            "/guilds/aquamancer/functions/steam.c",
            "/guilds/aquamancer/functions/current.c",
            "/guilds/aquamancer/functions/pressure.c",
            "/guilds/aquamancer/functions/drowning.c",
            "/guilds/aquamancer/functions/crushing.c",
            "/guilds/aquamancer/functions/tempest.c",
            "/guilds/aquamancer/functions/brine.c",
            "/guilds/aquamancer/functions/acid.c",
        }),
        "effect must include any of": ({
            "/guilds/aquamancer/effects/damage-hp.c",
            "/guilds/aquamancer/effects/damage-sp.c",
            "/guilds/aquamancer/effects/damage-stamina.c",
            "/guilds/aquamancer/effects/add-hp.c",
            "/guilds/aquamancer/effects/add-sp.c",
            "/guilds/aquamancer/effects/add-stamina.c",
            "/guilds/aquamancer/effects/siphon-hp.c",
            "/guilds/aquamancer/effects/siphon-sp.c",
            "/guilds/aquamancer/effects/siphon-stamina.c",
            "/guilds/aquamancer/effects/enhance-attack.c",
            "/guilds/aquamancer/effects/enhance-damage.c",
            "/guilds/aquamancer/effects/enhance-defense.c",
            "/guilds/aquamancer/effects/enhance-soak.c",
            "/guilds/aquamancer/effects/enhance-dodge.c",
            "/guilds/aquamancer/effects/enhance-parry.c",
            "/guilds/aquamancer/effects/enhance-speed.c",
            "/guilds/aquamancer/effects/reduce-attack.c",
            "/guilds/aquamancer/effects/reduce-damage.c",
            "/guilds/aquamancer/effects/reduce-defense.c",
            "/guilds/aquamancer/effects/reduce-soak.c",
            "/guilds/aquamancer/effects/reduce-dodge.c",
            "/guilds/aquamancer/effects/reduce-parry.c",
            "/guilds/aquamancer/effects/apply-slow.c",
            "/guilds/aquamancer/effects/apply-enfeebled.c",
            "/guilds/aquamancer/effects/staggering-damage.c",
            "/guilds/aquamancer/effects/debilitating-damage.c",
            "/guilds/aquamancer/effects/disorienting-damage.c",
            "/guilds/aquamancer/effects/hampering-damage.c",
            "/guilds/aquamancer/effects/exhausting-damage.c",
            "/guilds/aquamancer/effects/invigorating-siphon.c",
            "/guilds/aquamancer/effects/fortifying-siphon.c",
        }),
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/aquamancer/construct/efficient-casting.c": 10,
        "/guilds/aquamancer/construct/improved-efficiency.c": 10,
        "/guilds/aquamancer/construct/expert-efficiency.c": 10,
        "/guilds/aquamancer/construct/master-efficiency.c": 10,
        "/guilds/aquamancer/construct/grandmaster-efficiency.c": 5,
        "/guilds/aquamancer/construct/legendary-efficiency.c": 5,
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "cast");
    addSpecification("command template", "cast aquamancer ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## a spell...");
}
