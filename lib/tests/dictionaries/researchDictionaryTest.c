//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectFalse(Dictionary.researchObject("/lib/realizations/player.c"));
    ExpectFalse(Dictionary.researchObject("/lib/not_a_file"));
    ExpectFalse(Dictionary.researchObject("/lib/modules/research.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsObjectIfValid()
{
    ExpectTrue(Dictionary.researchObject("/lib/modules/research/activeResearchItem.c"));
}
