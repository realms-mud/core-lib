//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inner Discipline");
    addSpecification("source", "monk");
    addSpecification("description",
        "Find the quiet place within that does not answer "
        "every voice that calls to it. There your own "
        "thoughts remain familiar, even under another will's pressure.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":55
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/adepts-focus.c", ([
        "type":"research"
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus resist psionic", 3);
}
