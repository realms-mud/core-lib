//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("deferred lessons");
    Description("A path-only curriculum for lazy-loading regressions.");
    Source("test");
    deferResearchLoading();
    addResearchElement("/lib/tests/support/research/testTreeRoot.c");
    addResearchElement(
        "/lib/tests/support/research/teacherRequiredPointsResearch.c");
    TreeRoot("/lib/tests/support/research/testTreeRoot.c");
    addChild("/lib/tests/support/research/teacherRequiredPointsResearch.c",
        "/lib/tests/support/research/testTreeRoot.c");
}
