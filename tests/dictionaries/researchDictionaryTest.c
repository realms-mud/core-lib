//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = clone_object("/lib/dictionaries/researchDictionary");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsNullIfNotResearchItem()
{
    ExpectFalse(Dictionary->researchObject("/obj/player.c"));
    ExpectFalse(Dictionary->researchObject("not_a_file"));
    ExpectFalse(Dictionary->researchObject("/lib/modules/research.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsObjectIfValid()
{
    ExpectTrue(Dictionary->researchObject("/lib/modules/research/activeResearchItem.c"));
}
