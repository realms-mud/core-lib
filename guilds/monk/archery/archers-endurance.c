//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Archer's Endurance");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let the bow arm soften after each release without surrendering "
        "its readiness. Long afternoons at the butts teach the body "
        "how to rest within the rhythm of its labor.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":54
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "senior disciple",
        "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/draw-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus heal stamina rate", 4);
}
