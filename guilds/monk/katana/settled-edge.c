//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":5 ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "student", "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/katana/measured-cut.c",
        ([ "type":"research" ]));
    addSpecification("name", "Settled Edge");
    addSpecification("description", "Further instruction in controlling the "
        "recovering blade grants +1 hand and a half sword while a katana "
        "occupies your primary wielded slot. Your offhand is unrestricted. "
        "Requires knowledge of Measured Cut.");
    addSpecification("source", "monk");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));
}
