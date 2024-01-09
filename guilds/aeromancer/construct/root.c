//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            "/guilds/aeromancer/forms/touch.c",
        }),
        "function must include only one of": ({
            "/guilds/aeromancer/functions/lightning.c",
            "/guilds/aeromancer/functions/shock.c",
        }),
        "effect must include any of": ({
            "/guilds/aeromancer/effects/damage-hp.c",
        }),
    ]));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
//        "/guilds/aeromancer/construct/efficient-casting.c": 10,
//        "/guilds/aeromancer/construct/efficient-casting.c": 10,
//        "/guilds/aeromancer/construct/efficient-casting.c": 10,
//        "/guilds/aeromancer/construct/efficient-casting.c": 10,
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "tree root");
    addSpecification("command name", "cast");
    addSpecification("command template", "cast aeromancer ##Value##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## a spell...");
}
