//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sentry Focus");
    addSpecification("source", "monk");
    addSpecification("description",
        "Reserve six maximum stamina for watchful defense. Gain two defense; "
        "this is not another ward.");

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
        "value":6
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "initiate",
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 6);

    addSpecification("bonus defense", 2);

    addSpecification("command template", "chi sentry focus");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into a sentry's "
        "watch.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the sentry's watch.");
}
