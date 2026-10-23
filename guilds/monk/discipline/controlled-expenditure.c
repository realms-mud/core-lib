//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":10
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/discipline/students-awareness.c",
        ([ "type":"research" ]));
    addSpecification("name", "Controlled Expenditure");
    addSpecification("description", "An advanced instructor teaches economy "
        "of movement, reducing stamina expenditure by one through "
        "the normal stamina-pool modifier.");
    addSpecification("source", "monk");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("bonus reduce stamina points", 1);
}
