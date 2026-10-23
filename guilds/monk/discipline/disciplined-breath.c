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
        "value":5
    ]));
    addPrerequisite("/guilds/monk/discipline/root.c",
        ([ "type":"research" ]));
    addSpecification("name", "Disciplined Breath");
    addSpecification("source", "monk");
    addSpecification("description", "Measured breathing helps you recover "
        "stamina between exertions and establishes the discipline expected "
        "of a student.");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal stamina rate", 1);
}
