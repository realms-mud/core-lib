//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Slumber Ward");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of wrapping themselves in protective dream energy that "
        "deflects attacks and clouds the minds of enemies.");
    addSpecification("usage summary", "A sustained defensive ability that "
        "improves defense");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-touch.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);

    addSpecification("bonus defense", 3);
    addSpecification("bonus soak", 5);

    addSpecification("cooldown", 60);
    addSpecification("event handler", "slumberWardEvent");
    addSpecification("command template", "slumber ward");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::wrap## ##InitiatorReflexive## in a shimmering veil of "
        "dream energy.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "dream ward dissipates into wisps of fading light.");
}
