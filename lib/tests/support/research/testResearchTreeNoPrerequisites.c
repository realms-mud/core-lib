//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("tree of researchiness");
    Description("this is the land-loving mother pigeon of all research trees");
    addResearchElement("/lib/tests/support/research/testTreeRoot.c");
    TreeRoot("/lib/tests/support/research/testTreeRoot.c");
}
