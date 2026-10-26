//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Steady Practice");
    addSpecification("source", "monk");
    addSpecification("description",
        "Return to the practice floor when yesterday's "
        "enthusiasm has faded. In quiet repetition, "
        "the body learns a steadiness that excitement cannot teach.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("bonus heal stamina", 1);
}
