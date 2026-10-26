//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Circulation");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let the inner current travel where pain has broken its course. "
        "With every measured breath, warmth gathers beneath old bruises "
        "and the body quietly begins to mend.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":33
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/returning-current.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 8);

    addSpecification("bonus heal hit points", 5);
    addSpecification("penalty to damage", 2);

    addSpecification("command template", "chi balanced circulation");
    addSpecification("use ability activate message",
        "A gentle repairing rhythm settles within ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The repairing rhythm within ##InitiatorName## ends.");
}
