//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("tree of guild researchiness");
    Description("this is the land-loving mother pigeon of all research trees");
    addPrerequisite("long sword", (["type":"skill", "value" : 10]));
    addPrerequisite("test guild", (["type":"guild", "value" : ({ "test", "fake mage" })]));
    addResearchElement("/lib/tests/support/guilds/testGuildTreeRoot.c");
    addResearchElement("/lib/tests/support/guilds/testGuildItem.c");
    TreeRoot("/lib/tests/support/guilds/testGuildTreeRoot.c");
    addChild("/lib/tests/support/guilds/testGuildItem.c", "/lib/tests/support/guilds/testGuildTreeRoot.c");
}
