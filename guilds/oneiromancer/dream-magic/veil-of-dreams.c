//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Veil of Dreams");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of wrapping themselves in a powerful veil of dream energy "
        "that provides significant protection and enhances their abilities.");
    addSpecification("usage summary", "A sustained ability providing major "
        "defensive bonuses");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-shackles.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 5);
    addSpecification("bonus resist psionic", 15);

    addSpecification("cooldown", 120);
    addSpecification("event handler", "veilOfDreamsEvent");
    addSpecification("command template", "veil of dreams");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::become## shrouded in a shimmering veil of pure dream "
        "essence.");
    addSpecification("use ability deactivate message", "The veil of dreams "
        "around ##InitiatorName## fades away like a forgotten memory.");
}
