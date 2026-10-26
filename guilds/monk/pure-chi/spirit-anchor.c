//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Anchor");
    addSpecification("source", "monk");
    addSpecification("description",
        "Remember the shape of your own spirit when a foreign will "
        "presses against it. That familiar center holds fast like "
        "an anchor buried beneath the troubled surface of the sea.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":61
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
    addPrerequisite("/guilds/monk/pure-chi/etheric-poise.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("bonus resist magical", 15);
}
