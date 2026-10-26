//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unfettered Flow");
    addSpecification("source", "monk");
    addSpecification("description",
        "Unclench the muscles that labor even when no task calls on them. "
        "Freed of that hidden burden, breath and motion find "
        "their way back to an effortless accord.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":67
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
    addPrerequisite("/guilds/monk/pure-chi/deep-recollection.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("bonus recover stamina points", 5);
}
