//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flowing Current");
    addSpecification("source", "monk");
    addSpecification("description",
        "Relax the hidden knots that turn the inner stream against itself. "
        "Chi moves through the body in an unbroken ribbon, following "
        "your breath without hesitation or strain.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":5
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/essence-sensitivity.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("spell point cost", 6);
    addSpecification("cooldown", 6);

    addSpecification("bonus magical essence", 3);

    addSpecification("command template", "chi flowing current");
    addSpecification("use ability activate message",
        "A smooth current gathers within ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The current within ##InitiatorName## subsides.");
}
