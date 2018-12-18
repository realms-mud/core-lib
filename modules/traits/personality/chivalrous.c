//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "chivalrous");
        addSpecification("description", "You are corteous and gallant.");
        addSpecification("root", "nice");
        addSpecification("opposing root", "jackass");
        addSpecification("opinion", 20);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
