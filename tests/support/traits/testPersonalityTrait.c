//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "test 1");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "jackass");
        addSpecification("opposing root", "nice");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}
