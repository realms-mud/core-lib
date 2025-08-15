//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/researchService");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsNullIfNotResearchItem()
{
    ExpectFalse(Service.researchObject("/lib/realizations/player.c"));
    ExpectFalse(Service.researchObject("/lib/not_a_file"));
    ExpectFalse(Service.researchObject("/lib/modules/research.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsObjectIfValid()
{
    ExpectTrue(Service.researchObject("/lib/modules/research/activeResearchItem.c"));
}
