//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    addSpecification("type", "personality");
    addSpecification("name", "charming");
    addSpecification("description", "You are a pleasant person and, darn it, people like you.");
    addSpecification("root", "nice");
    addSpecification("opposing root", "jackass");
    addSpecification("bonus charisma", 1);
    addSpecification("opinion", 20);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 2);
    "baseTrait"::init();
}

