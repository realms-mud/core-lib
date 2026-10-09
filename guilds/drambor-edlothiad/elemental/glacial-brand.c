//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Glacial Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a deep frost enchantment, encasing their blade in glacial "
        "ice that numbs and slows enemies.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/frost-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 60);
    addSpecification("bonus cold enchantment", 5);
    addSpecification("bonus cold attack", 5);

    addSpecification("command template", "glacial brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade sheathes itself in glacial ice, the cold so intense it burns.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::allow## the glacial brand to melt away, warmth returning to the steel.");
}
