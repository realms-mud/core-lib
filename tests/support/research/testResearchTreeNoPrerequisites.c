//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    researchTree::init();
    Name("tree of researchiness");
    Description("this is the land-loving mother pigeon of all research trees");
    addResearchElement("lib/tests/support/research/testTreeRoot.c");
    TreeRoot("lib/tests/support/research/testTreeRoot.c");
}

