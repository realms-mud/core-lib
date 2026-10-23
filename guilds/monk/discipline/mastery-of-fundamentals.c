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
        "value":30
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/inner-discipline.c",
        ([ "type":"research" ]));
    addSpecification("name", "Mastery of Fundamentals");
    addSpecification("source", "monk");
    addSpecification("description", "Years of deliberate practice refine "
        "your unarmed technique. This is a modest improvement to the "
        "fundamentals, not a replacement for specialized kata.");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus unarmed", 3);
}
