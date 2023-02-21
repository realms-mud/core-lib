//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "test 2");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "nice");
    addSpecification("opposing root", "jackass");
    addSpecification("opinion", 15);
    addSpecification("opposing opinion", -5);
    addSpecification("cost", 1);
}
