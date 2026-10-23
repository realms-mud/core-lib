//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Kama Foundations");
    addSpecification("description", "The discipline of sickle cuts and "
        "tiring hooks. Individual lessons require instruction and an "
        "exact kama blueprint in the primary wielded slot for use.");
    addSpecification("source", "monk");
    addSpecification("research type", "tree root");
}
