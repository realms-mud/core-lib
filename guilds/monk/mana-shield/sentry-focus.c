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
        "Rest your attention on the shield's outer edge. Small ripples "
        "become clear warnings, and your hands begin to answer them "
        "before conscious thought can name the danger.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
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

    addSpecification("bonus defense", 4);

    addSpecification("command template", "chi sentry focus");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into a sentry's "
        "watch.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the sentry's watch.");
}
