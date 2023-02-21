//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "test 1");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "jackass");
    addSpecification("opposing root", "nice");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
    addSpecification("cost", -1);
}
