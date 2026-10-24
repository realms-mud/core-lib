//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sentinel Meditation");
    addSpecification("source", "monk");
    addSpecification("description",
        "Reserve ten maximum stamina to gain three defense, sacrificing two "
        "weapon attack and spending one spell point per received hit. No "
        "absorption layer is added.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":64
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/elastic-defense.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 10);

    addSpecification("bonus defense", 3);
    addSpecification("penalty to weapon attack", 2);

    addSpecification("per hit received cost", ([
        "spell points":1
    ]));

    addSpecification("command template", "chi sentinel meditation");
    addSpecification("use ability activate message",
        "##InitiatorName## enter##InitiatorReflexive## sentinel meditation.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## end##InitiatorReflexive## sentinel meditation.");
}
