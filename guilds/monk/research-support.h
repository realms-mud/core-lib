//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef MonkResearchSupport
#define MonkResearchSupport

protected void monkResearch(string name, string description, int level,
    int cost, string parent, mapping limiter)
{
    string *ranks = ({ "student", "disciple", "adept", "senior disciple",
        "master candidate", "master" });
    int tier = level >= 30 ? 5 : level >= 25 ? 4 : level >= 20 ? 3 :
        level >= 15 ? 2 : level >= 10 ? 1 : 0;
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":level ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":ranks[tier..]
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    if (parent)
    {
        addPrerequisite(parent, ([ "type":"research" ]));
    }
    addSpecification("name", name);
    addSpecification("description", description);
    addSpecification("source", "monk");
    addSpecification("research type", "points");
    addSpecification("research cost", cost);
    addSpecification("teacher required", 1);
    if (mappingp(limiter) && sizeof(limiter))
    {
        addSpecification("limited by", limiter);
    }
}
#endif
