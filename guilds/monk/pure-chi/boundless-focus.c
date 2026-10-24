//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boundless Focus");
    addSpecification("source", "monk");
    addSpecification("description",
        "Reserve twelve maximum spell points to sharpen spellcraft by four. "
        "Outward vigilance suffers two defense while the inner calculation "
        "is maintained.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":63
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
    addPrerequisite("/guilds/monk/pure-chi/essence-weaving.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/spirit-anchor.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 10);

    addSpecification("bonus spellcraft", 4);
    addSpecification("penalty to defense", 2);

    addSpecification("command template", "chi boundless focus");
    addSpecification("use ability activate message",
        "##InitiatorName##'s gaze turns inward in boundless focus.");
    addSpecification("use ability deactivate message",
        "##InitiatorName##'s attention returns to the world.");
}
