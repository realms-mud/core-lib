//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Initiate's Discipline");
    addSpecification("source", "monk");
    addSpecification("description",
        "Bow at the threshold of the practice hall and "
        "set aside the need to hurry. Your first lessons "
        "teach the hands to move deliberately and the mind to listen.");

    addPrerequisite("/guilds/monk/discipline/root.c", ([
        "type":"research"
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus unarmed", 1);
}
