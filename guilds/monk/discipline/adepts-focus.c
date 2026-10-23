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
        "value":20
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/disciples-insight.c",
        ([ "type":"research" ]));
    addSpecification("name", "Adept's Focus");
    addSpecification("source", "monk");
    addSpecification("description", "Deliberate concentration improves "
        "your understanding and control of magical techniques.");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 2);
}
