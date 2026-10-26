//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reservoir Discipline");
    addSpecification("source", "monk");
    addSpecification("description",
        "Deepen the quiet pool beneath your breathing without forcing "
        "its banks. Patient practice teaches the body to shelter "
        "a fuller current without disturbing its surface.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":8
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/economical-breath.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus spell points", 25);
}
