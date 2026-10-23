//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":10 ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/bludgeon/measured-impact.c",
        ([ "type":"research" ]));
    addSpecification("name", "Settled Guard");
    addSpecification("description", "Further instruction in recovering "
        "after Measured Impact grants +1 parry while a staff, mace, or "
        "hammer occupies your primary wielded slot. Normal equipment "
        "rules still determine whether an offhand item can be used.");
    addSpecification("source", "monk");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("bonus parry", 1);
    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
}
