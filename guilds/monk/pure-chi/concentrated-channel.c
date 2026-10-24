//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Concentrated Channel");
    addSpecification("source", "monk");
    addSpecification("description",
        "Reserve eight maximum spell points to reinforce energy attacks, at "
        "a cost of one defense.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":17
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
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
    addPrerequisite("/guilds/monk/pure-chi/flowing-current.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 8);

    addSpecification("bonus energy attack", 2);
    addSpecification("penalty to defense", 1);

    addSpecification("command template", "chi concentrated channel");
    addSpecification("use ability activate message",
        "Chi gathers sharply along ##InitiatorName##'s limbs.");
    addSpecification("use ability deactivate message",
        "The sharp energy around ##InitiatorName## disperses.");
}
