//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("tree of researchiness");
    Description("this is the land-loving mother pigeon of all research trees");
    Source("mage guild");
    addResearchElement("/lib/tests/support/research/testTreeRoot.c");
    addResearchElement("/lib/tests/support/research/itemWithModifier.c");
    addResearchElement("/lib/tests/support/research/testLimitedByIntoxResearchItem.c");
    addResearchElement("/lib/tests/support/research/mockResearchTimed.c");
    addResearchElement("/lib/tests/support/research/testResearchA.c");
    addResearchElement("/lib/tests/support/research/testResearchB.c");
    addResearchElement("/lib/tests/support/research/testResearchC.c");
    addResearchElement("/lib/tests/support/research/testResearchD.c");
    addResearchElement("/lib/tests/support/research/testResearchE.c");
    addResearchElement("/lib/tests/support/research/testResearchF.c");
    addResearchElement("/lib/tests/support/research/testResearchG.c");
    TreeRoot("/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/testLimitedByIntoxResearchItem.c", 
        "/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/itemWithModifier.c", 
        "/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/mockResearchTimed.c", 
        "/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/testResearchA.c", 
        "/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/testResearchB.c", 
        "/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/testResearchC.c", 
        "/lib/tests/support/research/testLimitedByIntoxResearchItem.c");
    addChild("/lib/tests/support/research/testResearchD.c", 
        "/lib/tests/support/research/testLimitedByIntoxResearchItem.c");
    addChild("/lib/tests/support/research/testResearchD.c", 
        "/lib/tests/support/research/testResearchB.c");
    addChild("/lib/tests/support/research/testResearchE.c", 
        "/lib/tests/support/research/testResearchB.c");
    addChild("/lib/tests/support/research/testResearchF.c", 
        "/lib/tests/support/research/testResearchE.c");
    addChild("/lib/tests/support/research/testResearchG.c", 
        "/lib/tests/support/research/testResearchE.c");
    addChild("/lib/tests/support/research/testResearchG.c", 
        "/lib/tests/support/research/testResearchD.c");
}
