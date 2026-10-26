//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inner Refuge");
    addSpecification("source", "monk");
    addSpecification("description",
        "Withdraw your attention to the quiet place behind the breath. "
        "While the shield bears the clamor around you, your inner current "
        "flows clear again, like a spring sheltered beneath stone.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":42
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/restorative-watch.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("spell point cost", 6);
    addSpecification("cooldown", 8);

    addSpecification("bonus heal spell points", 6);
    addSpecification("penalty to damage", 2);

    addSpecification("command template", "chi inner refuge");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into inner refuge.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## leave##InitiatorReflexive## the inner refuge.");
}
