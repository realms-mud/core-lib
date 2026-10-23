//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Tiger Claw Foundations");
    addSpecification("description", "The discipline of precise tiger-claw "
        "thrusts. Individual lessons require instruction and an exact "
        "tiger claws blueprint in the primary wielded slot for use.");
    addSpecification("source", "monk");
    addSpecification("research type", "tree root");
}
