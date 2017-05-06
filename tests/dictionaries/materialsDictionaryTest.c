//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
void BlargIsNotAValidBonus()
{
    ExpectFalse(Dictionary->isValidBonus("blarg"), "blarg is not a valid bonus type");
}


